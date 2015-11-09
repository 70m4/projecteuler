#include "iostream"
#include <stdlib.h> 
using namespace std;
class dragon {
public:
	dragon(int level, int steps){
		string init = "Fa";
		int x = 0;
		int y = 0;
		int direction = 0;
		cout << "level=" << level << "steps=" << steps << endl;
		derive(init, level, x, y, steps, direction);
		cout << endl;
		getCoordinate(x, y);
	}
private:
	void getCoordinate(int x, int y){
		cout << "x=" << x << "y=" << y << endl; 
	}
	
	int derive(string instructions, int level, int &x, int &y, int &steps, int &direction) {
		//cout << instructions  << ", l " << level << endl;
		for (size_t s = 0;s<instructions.size();s++) {
			//cout << "to decode: " << instructions[s] << ", l " << level  << endl;
			if(steps == 0)return 0;
			if(instructions[s] == 'F' and steps != 0) {
				//cout << "F" << " -----> dir:" << direction % 4<< endl;
				steps--;
				if(direction % 4 == 0 or direction % 4 == -4) {
					y++;
				} else if(direction % 4 == 1 or direction % 4 == -1) {
					x++;
				} else if(direction % 4 == 2 or direction % 4 == -2) {
					y--;
				} else if(direction % 4 == 3 or direction % 4 == -3) {
					x--;
				}
				//draw
				//getCoordinate(x,y); 
			} else if(instructions[s] == 'R') {
				//cout << "R"<< endl;
				direction++;
			} else if(instructions[s] == 'L') {
				//cout << "L"<< endl;
				direction--;
			} else if(instructions[s] == 'a' and level != 0) {
				//cout << "a " << level << endl;
				derive("aRbFR",level-1,x,y,steps,direction);
			} else if(instructions[s] == 'b' and level != 0) {
				//cout << "b " << level << endl; 
				derive("LFaLb",level-1,x,y,steps, direction);
			}
		}
//cout << "return" << endl;
		return 0;
	}
};

int main(int argc, char *argv[]) {
	cout << "Let's go" << endl;
	if(argc == 3){
		int level = atoi(argv[1]);
		int steps = atoi(argv[2]);
		dragon d(level,steps);
	} else
		dragon d2(50,1000000000);
		
	return 0;
}

//D10 at 500 -> (18,16)




