#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> parityVec;

int _get_parity(int i) {
  int result = 0;
  while (i > 0) {
    result ^= 1;
    i &= (i-1); // i & (i-1) erases the lowest bit of i
  }
  return result;
}

void init_parity_cache() {
  if (parityVec.empty()) {
    cout << "Initializing parity cache ... ";
    for (int i = 0; i < 0x10000; ++i) {
      parityVec.push_back(_get_parity(i));
    }
    cout << "done." << endl;
  }
}

int parity_cache(int num) {
  return parityVec[num];
}

// the parity of a number is 1 if it has an odd number of 1's
// otherwise it is 0
int parity(int num) {
  int result = 0;
  while (num > 0) {
    auto masked = num & 0xFFFF;
    auto mask_parity = parity_cache(masked);
    if (result == 0) {
      result = mask_parity;
    }
    else {
      result = 1 - mask_parity;
    }
    num >>= 16;
  }
  return result;
}

int main(int argc, char* argv[]) {
  init_parity_cache();
  string numStr;
  while (true) { 
    cout << "Enter an number or 'q' to exit: ";
    cin >> numStr;
    if (numStr == "q") {
      break;
    }
    else {
      int num = 0;
      istringstream iss(numStr);
      iss >> num;
      if (iss.bad()) {
	cout << numStr << " is not a number." << endl;
      }
      else {
	cout << "The parity of " << num << " is: " 
	     << parity(num) << endl;
      }
    }
  }
  return 0;
}
