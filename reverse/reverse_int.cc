#include <iostream>
#include <sstream>

using namespace std;

int reverse(int num) {
  int r = 0;
  while (num > 0) {
    int digit = num % 10;
    r = r*10 + digit;
    num /= 10;
  }
  return r;
}

int main(int argc, char* argv[]) {
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
	cout << "The reverse of " << num << " is: " 
	     << reverse(num) << endl;
      }
    }
  }
  return 0;
}
