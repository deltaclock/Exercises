#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//creating struct char type
#pragma pack(4)
struct var{
 char value;
 char* val;
};
int main() {
	struct var a; // instance 1
	struct var b; // instance 2
	struct var c; // instance 3
	struct var d; // instance 4
	//giving values
a.value = 'A';
b.value = 'B';
c.value = 'C';
d.value = 'D';
 //casting objects
  char* v1 = reinterpret_cast<char*>(&a.value);
  char* v2 = reinterpret_cast<char*>(&b.value);
  char* v3 = reinterpret_cast<char*>(&c.value);
  char* v4 = reinterpret_cast<char*>(&d.value);
  //writing to .bin
ofstream wr ("ex.bin", ios::out | ios::app | ios::binary);
  wr << v1;
  wr << v2;
  wr << v3;
  wr << v4;
  wr.close();

  streampos size;
  char * buffer;
  ifstream rd ("ex.bin", ios::in|ios::binary|ios::ate);
  if (rd.is_open())
  {
    size = rd.tellg();
    buffer = new char [size];
    rd.seekg (0, ios::beg);
    rd.read (buffer, size);
		rd.close();

    cout << "content in memory \n";
		//cout << buffer;
	struct var e; // instance new
	e.val = buffer;
	cout << e.val;
	std::cout << " " << '\n';
  delete[] buffer;
  }
  else cout << "Unable to open file \n";
  return 0;
}
