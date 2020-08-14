
#include <iostream>
#include "RTree.h"
using namespace std;


int main(int argc,char* argv[])
{
    string fileName = argv[0];
    setlocale(0, "");
    if (argc != 4) {
        cout << "Check parametres!" << endl;
    }
  
    double latitude = atof(argv[1]);
    double longitude = atof(argv[2]);
    long int size = atof(argv[3]);
    RTree tree;
    tree.readingFile(fileName);
    tree.findPlaces(latitude, longitude, size, tree.root->children[0]);
    tree.findPlaces(latitude, longitude, size, tree.root->children[1]);
   /* tree.findPlaces(50.39195, 30.45944, 500, tree.root->children[0]);
    tree.findPlaces(50.39195, 30.45944, 500, tree.root->children[1]);
    tree.findPlaces(48.50099, 35.95139, 500, tree.root->children[0]);
    tree.findPlaces(48.50099, 35.95139, 500, tree.root->children[1]);
    */
    return 0;

}

