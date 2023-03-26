#include <iostream>
#include "iomanip"
using namespace std;

const int row = 10;
const int col = 10;
int horCoord_1;
int verCoord_1;
int horCoord_2;
int verCoord_2;
int count = 0;
unsigned char coordH;
unsigned char coordV;
char field_1[row][col];
char field_2[row][col];

void initialization(char array[][col]) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      array[i][j] = ' ';
    }
  }
  count = 48;
  for (int i = 0; i < row; ++i) {
    array[0][i] = (char) count;
    count++;
  }
  count = 48;
  for (int i = 0; i < col; ++i) {
    array[i][0] = (char) count;
    count++;
  }
}

bool print(char array[][col]) {
  int sunkenShip = 0;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (array[i][j] == 'X') sunkenShip++;
      cout << setw(4) << array[i][j];
    }
    cout << endl;
  }
  if (sunkenShip == 20) return false;
  else return true;
}

void input_check_numbers() {
  while (true) {
    cout << setw(4) << "Input horizontal coordinate:  ";
    cin >> coordH;
    cout << setw(4) << "Input vertical coordinate:  ";
    cin >> coordV;
    if (coordH < '1' || coordV < '1' || coordH > '9' || coordV > '9') {
      cout << "Enter Error!" << endl;
      continue;
    } else break;
  }
}

void arrangement_1(char array[][col]) {
  count = 0;
  cout << "Arrangement ships < 1 > " << endl;
  do {
    input_check_numbers();
    horCoord_1 = static_cast<int>(coordH - '0');
    verCoord_1 = static_cast<int>(coordV - '0');
    if (array[horCoord_1][verCoord_1] != ' ') {
      cout << "Place is taken!" << endl;
      continue;
    } else {
      array[horCoord_1][verCoord_1] = '@';
    }
    print(array);
    count++;
  } while (count < 4);
}

bool check_coordinate(char array[][col], int size) {
  if (horCoord_1 == horCoord_2 || verCoord_1 == verCoord_2) {
    if (horCoord_1 == horCoord_2) {
      for (int i = verCoord_1; i <= verCoord_2; ++i) {
        if ((array[horCoord_1][i] != ' ') && (verCoord_2 - verCoord_1 != size)) {
          cout << "Coordinates incorrect 1!" << endl;
          return false;
        }
      }
    } else if (verCoord_1 == verCoord_2) {
      for (int i = horCoord_1; i <= horCoord_2; ++i) {
        if ((array[i][verCoord_1] != ' ') && (horCoord_2 - horCoord_1 != size)) {
          cout << "Coordinates incorrect 2!" << endl;
          return false;
        }
      }
    }
  } else {
    cout << "Coordinates incorrect!" << endl;
    return false;
  }
  return true;
}

void placing_ship(char array[][col], char symbol) {
  if (horCoord_1 == horCoord_2) {
    for (int i = verCoord_1; i <= verCoord_2; ++i) {
      array[horCoord_1][i] = symbol;
    }
  } else if (verCoord_1 == verCoord_2) {
    for (int i = horCoord_1; i <= horCoord_2; ++i) {
      array[i][verCoord_1] = symbol;
    }
  }
}

void arrangement_2_3_4(char array[][col]) {
  count = 0;
  while (count < 3) {
    cout << "Input coordinate 1 < 2 > ship: " << endl;
    input_check_numbers();
    horCoord_1 = static_cast<int>(coordH - '0');
    verCoord_1 = static_cast<int>(coordV - '0');
    cout << "Input coordinate 2 < 2 > ship: " << endl;
    input_check_numbers();
    horCoord_2 = static_cast<int>(coordH - '0');
    verCoord_2 = static_cast<int>(coordV - '0');
    if (!(check_coordinate(array, 1)))continue;
    placing_ship(array, '@');
    cout << endl;
    print(array);
    count++;
  }
  count = 0;
  while (count < 2) {
    cout << "Input coordinate 1 < 3 > ship: " << endl;
    input_check_numbers();
    horCoord_1 = static_cast<int>(coordH - '0');
    verCoord_1 = static_cast<int>(coordV - '0');
    cout << "Input coordinate 2 < 3 > ship: " << endl;
    input_check_numbers();
    horCoord_2 = static_cast<int>(coordH - '0');
    verCoord_2 = static_cast<int>(coordV - '0');
    if (!(check_coordinate(array, 2)))continue;
    placing_ship(array, '@');
    cout << endl;
    print(array);
    count++;
  }
  count = 0;
  while (count < 1) {
    cout << "Input coordinate 1 < 4 > ship: " << endl;
    input_check_numbers();
    horCoord_1 = static_cast<int>(coordH - '0');
    verCoord_1 = static_cast<int>(coordV - '0');
    cout << "Input coordinate 2 < 4 > ship: " << endl;
    input_check_numbers();
    horCoord_2 = static_cast<int>(coordH - '0');
    verCoord_2 = static_cast<int>(coordV - '0');
    if (!(check_coordinate(array, 3)))continue;
    placing_ship(array, '@');
    cout << endl;
    print(array);
    count++;
  }
}

int check_coord_battle(char field1[][col], char field2[][col]) {
  do {
    input_check_numbers();
    horCoord_1 = static_cast<int>(coordH - '0');
    verCoord_1 = static_cast<int>(coordV - '0');
    if (field_2[horCoord_1][verCoord_1] == '@') {
      cout << "HIT!" << endl;
      field1[horCoord_1][verCoord_1] = 'X';
      field2[horCoord_1][verCoord_1] = 'X';
      print(field1);
      if (!(print(field1))) {
        cout << "Game over!" << endl;
        return -1;
      }
      continue;
    } else {
      cout << "Shot off target!" << endl;
      field1[horCoord_1][verCoord_1] = '+';
      field2[horCoord_1][verCoord_1] = '+';
    }
    print(field2);
    break;
  } while (true);
  return 1;
}

int main() {

  initialization(field_1);
  cout << "Gamer 1 arrangement ships " << endl;
  print(field_1);
  arrangement_1(field_1);
  arrangement_2_3_4(field_1);

  initialization(field_2);
  cout << "Gamer 2 arrangement ships " << endl;
  print(field_2);
  arrangement_1(field_2);
  arrangement_2_3_4(field_2);

  cout << "Start the battle!" << endl;
  while (true) {
    cout << "Gamer 1 turn" << endl;
    if(check_coord_battle(field_1, field_2) == -1)break;
    cout << "Gamer 2 turn" << endl;
    if(check_coord_battle(field_2, field_1) == -1)break;
  }

}
