#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


// the parity of a number is 1 if it has an odd number of 1's
// otherwise it is 0
int swap(int num, int i, int j) {
  int iVal = 1 << i;
  int jVal = 1 << j;
  num ^= iVal;
  num ^= jVal;
  return num;
}

string to_bin(int num) {
  string str;
  const string bit[] = {"0", "1"};
  if (num == 0) {
    str = "0";
  }
  while (num != 0) {
    str = bit[num & 1] + str;
    num >>= 1;
  }
  return str;
}

int main(int argc, char* argv[]) {
  string numStr;
  string iStr, jStr;
  cout << 10 << "=" << to_bin(10) << endl; 
  while (true) { 
    cout << "Enter an number, i and j (separated by spaces) or 'q' to exit: ";
    cin >> numStr;
    if (numStr == "q") {
      break;
    }
    else {
      int num = 0;
      istringstream issNum(numStr);
      issNum >> num;
      int i = 0;
      int j = 0;
      cin >> i >> j;
      cout << "Swapping bits " << i << " and " << j << " of "
           << to_bin(num) 
           << " is: " << to_bin(swap(num, i ,j)) << endl;
    }
  }
  return 0;
}
