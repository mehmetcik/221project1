#include <iostream>
#include <string>
using namespace std;
int main()
{
  cout << "Enter your name\n";
  string name;
  string last;
  getline(cin, name);
  cout << "Last?\n";
  getline (cin, last);
  cout << "Hello " << name << " " << last
       << " - welcome to C++\n";
  return 0;
}
