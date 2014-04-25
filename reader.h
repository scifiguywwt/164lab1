/* Max Savage/Adam Wells Minigolf Rendering
  , atwells@ucsc.edu
*/
#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class reader {
public:
	reader(ifstream&);						//build tile array from read in file
	float tiles[], tile[], cup[], tee[];	//array of tiles, tiles, cup location, tee location

private:
	int totalSize, i, length;
	float id, size;
	bool hasTile, hasTee, hasCup;
	string line, test;
};
#endif