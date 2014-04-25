/* Max Savage/Adam Wells Minigolf Rendering
  atwells@ucsc.edu, msavage@ucsc.edu
*/

#include <string>
#include "reader.h"

reader::reader(ifstream &file) {
	string line, test;
	int totalSize = 0, i = 0, length = 0;
	bool hasTile = false, hasTee = false, hasCup = false;
	float size, id, cup[4], tee[4];		//initialize variables, check if file is open and good, if so parse
	if(file.is_open()) {
		if(file.good()) {
			while(getline(file, line)) {
				++totalSize;					//get number of tiles minus tee and cup
			}
			file.clear();						//clear and reset stream position
			file.seekg(0);
			float tiles[totalSize - 2];		//tile array is the number of lines minus cup and tee lines
			while(getline(file, line)) {
				istringstream iss(line);
				iss >> test;					//check what type of line this is 

				//tile case
				if(test == "tile") {
					if(hasTile != true) {
						hasTile = true;	//check to ensure that at least one tile is in this course
					}
					iss >> id;					//acquire id 
					iss >> size;				//acquire size
					if(size < 3) {
						cout << "A tile is too small.";
						return;
					}
					float tile[(int)size*4];	//create tile array of size equal to tile's vert count times 4 plus 2 minus the id and edge count
					tile[0] = id;
					tile[1] = size;				//we already know first two values
					length = size;
					for(i = 2; i < length; i++) {
						iss >> tile[i];			//load in remaining values
					}
				}

				//cup case
				if(test == "cup") {
					if(hasCup == true) {
						cout << "Too many cup usages.";
						return;					//can only have at most one cup or it won't make sense
					}
					hasCup = true;				//since we didn't have a cup before, now we do
					for(i = 0; i < 4; i++) {
						iss >> cup[i];			//load in cup values
					}
				}

				//tee case
				if(test == "tee") {
					if(hasTee == true) {
						cout << "Too many tee usages.";
						return;					//can only have at most one tee or it won't make sense
					}
					hasTee = true;				//since we didn't have a tee before, now we do
					for(i = 0; i < 4; i++) {
						iss >> tee[i];			//load in tee values
					}
				}

				//error case
				else {
					cout << "Mismatch vertex/neighbor count to provided size or no initial reference to a tile type... fix it!";
					return;						//catch cases where provided tile/cup/tee size does not match the number of values
												//required to make such a size a valid object, or initial case is bad
				}
			}
		if(hasTile =! true || hasCup != true || hasTee != true) {
			cout << "Missing a cup, a tee, or a tile to work with.";
		}
		cout << "Probably a successful load.";
		file.close();
		} 
	else { cout << "no file detected"; }
	}
}
