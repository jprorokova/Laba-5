
#include <iostream>
using namespace std;


int main(int argc,char* argv[])
{
    string db = argv[0];
    setlocale(0, "");
    if (argc != 4) {
        cout << "Check parametres!" << endl;
    }
  
    double latitude = atof(argv[1]);
    double longitude = atof(argv[2]);
    long int size = atof(argv[3]);

}

