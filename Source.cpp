//#pragma comment(linker,"/STACK:200000000000")
#include <iostream>
#include <time.h>
#include <list>
#include <utility> 

using namespace std;

int t = 50;
int flag = 0, x, y, a;
int counter = 0;

class species {
public:
	int vision, stamina, original_stamina, food, pos;
	string status;
	pair<int, int>coord;
	species() {
		vision = 5;
		original_stamina = 50;
		stamina = 50;
		food = 0;
		status = "ALIVE";
	}
	species(int v, int s) {
		vision = v;
		stamina = s;
	}
};

//int move(int, int, int, int);
list<species>skills;

class environment {
	int population = 1, food = 400, size = 100;

public:
	int location[102][102];
	//int** location = new int* [size + 5];
	environment() {
		//cin >> population >> food>> vision;
		for (int i = 1; i <= population; i++) {
			species s;
			skills.push_back(s);
		}
		/*for (int i = 0; i < (size + 5); i++) {
			location[i] = new int[size + 5];
		}*/
		for (int i = 1; i <= 3; i += 1) {
			day();
			night();
			cout << "End of Day " << i << "\n";
		}
	}
	void day();
	void night();
};

void environment::day() {
	srand(time(NULL));
	for (int i = 0; i < (size + 2); i++) {
		for (int j = 0; j < (size + 2); j++) {
			location[i][j] = 0;
		}
	}
	for (int i = 0; i < food; i++) {
		x = rand() % size + 1;
		y = rand() % size + 1;
		location[rand() % size + 1][rand() % size + 1] = 1;

	}
	x = rand() % 4 + 1;
	for (list<species>::iterator i = skills.begin(); i != skills.end(); i++, x++) {
		switch (x) {
		case 1:
			(*i).coord = make_pair(rand() % size + 1, 0);
			break;
		case 3:
			(*i).coord = make_pair(rand() % size + 1, size + 1);
			break;
		case 2:
			(*i).coord = make_pair(size + 1, rand() % size + 1);
			break;
		case 4:
			(*i).coord = make_pair(0, rand() % size + 1);
			break;
		}
		(*i).pos = x;
		if (x == 4) {
			x = 0;
		}
	}
	/*for (list<species>::iterator i = skills.begin(); i != skills.end(); i++) {
		cout << ((*i).coord).first << " "<< ((*i).coord).second<" ";
	}*/
	for (int k = 0; k < t; k++) {
		for (list<species>::iterator i = skills.begin(); i != skills.end(); i++) {
			if ((*i).status == "DEAD" || (*i).stamina <= 0) {
				continue;
			}
			while (true) {
				//a = rand() % 8 + 1;
				x = ((*i).coord).first;
				y = ((*i).coord).second;
				a = (rand() % 5 != 0) ? ((rand() % 3 + (2 * (*i).pos + 2) % 8)) : ((rand() % 5 < 4) ? ((rand() % 2) * 4 + 2 * (*i).pos + 1) % 8 : (-(rand() % 3) + (2 * (*i).pos)) % 8);
				flag = 0;
				switch (a) {
				case 1:
					if ((--y) > 0) {
						flag = 1;
						--(((*i).coord).second);
					}
					break;
				case 2:
					if ((--y) > 0 && (++x) < (size + 1)) {
						flag = 1;
						--(((*i).coord).second);
						++(((*i).coord).first);
					}
					break;
				case 3:
					if ((++x) < (size + 1)) {
						flag = 1;
						++(((*i).coord).first);
					}
					break;
				case 4:
					if ((++y) < (size + 1) && (++x) < (size + 1)) {
						flag = 1;
						++(((*i).coord).second);
						++(((*i).coord).first);
					}
					break;
				case 5:
					if ((++y) < (size + 1)) {
						flag = 1;
						++(((*i).coord).second);
					}
					break;
				case 6:
					if ((++y) < (size + 1) && (--x) > 0) {
						flag = 1;
						++(((*i).coord).second);
						--(((*i).coord).first);
					}
					break;
				case 7:
					if ((--x) > 0) {
						flag = 1;
						--(((*i).coord).first);
					}
					break;
				case 0:
					if ((--x) > 0 && (--y) > 0) {
						flag = 1;
						--(((*i).coord).second);
						--(((*i).coord).first);
					}
					break;
				}
				if (flag == 1) {
					break;
				}
			}
			//cout << ((*i).coord).first << " " << ((*i).coord).second << " ";
			//cout << endl;
			if (location[((*i).coord).first][((*i).coord).second] == 1) {
				++((*i).food);
				location[((*i).coord).first][((*i).coord).second] = 0;
			}
			--((*i).stamina);
			if ((*i).stamina == 0 && ((*i).food) == 0) {
				(*i).status = "DEAD";
				population--;
			}
		}
	}
	for (list<species>::iterator i = skills.begin(); i != skills.end(); i++) {
		cout << (*i).food << " " << (*i).status << "\n";
	}
}

void environment::night() {
	int rep;
	list<species>::iterator j = skills.end();
	for (list<species>::iterator i = skills.begin(); i != j; i++) {
		(*i).stamina = (*i).original_stamina;
		if ((*i).status != "DEAD") {
			(*i).food--;
		}
		else {
			continue;
		}
		if ((*i).food == 0) {
			continue;
		}
		rep = (rand() % (*i).food) ? 1 : 0;
		if (rep == 1) {
			(*i).food--;
			population++;
			species s;
			skills.push_front(s);
		}
	}
	cout << "Population:" << population << "\n";
}
int main() {
	srand(time(NULL));
	environment obj1;
	cout << "\nDolesh 1901CS20\nRishav 1901CS46\n";
}