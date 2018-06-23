#include <iostream>
#include <memory>
using namespace std;
int sum(int*,int);
int The_B_S(int*, int,bool);


int main() {

	int Num_el(0);
	cout << "Enter Number of elements : ";
	cin >> Num_el;

	int *  Array = new int[Num_el];
	cout << "\n";
	for (int i(0); i < Num_el; i++) { Array[i] = rand() % Num_el; cout << " " << Array[i]; }

	int choice(0);
	while (choice != 100) {
		
		cout << "\n1-Sum of Elements\n2-The Bigest\n3-The Smallest\n6-Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nSum = " << sum(Array, Num_el - 1) << "\n";
			break;
		case 2:
			cout << "\nThe Bigest = " << The_B_S(Array, Num_el-1, true) << "\n";
			break;
		case 3:
			cout << "\nThe Smallest = " << The_B_S(Array, Num_el-1, false) << "\n";
			break;
		case 6:
			choice = 100;
			break;
		default:
			break;
		}
	}
	

	system("Pause");
	delete[] Array;
	return 0;
}

int sum(int* Array,int Num_el ) {
	int Sum(Array[Num_el]);
	//int i(Num_el);
	if (Num_el != 0 )
		return Sum +=sum(Array,Num_el-1) ;
	else
		return Sum ;
}

int The_B_S(int* Array, int Num_el, bool Up_Down) {
	int Currrent_el(Array[Num_el]);

	if (Num_el != 0 && Up_Down == true) {
		return Currrent_el > The_B_S(Array, Num_el - 1, Up_Down) ? Currrent_el : The_B_S(Array, Num_el - 1, Up_Down);
	}
	else if (Num_el != 0 && Up_Down == false) {
		return Currrent_el < The_B_S(Array, Num_el - 1, Up_Down) ? Currrent_el : The_B_S(Array, Num_el - 1, Up_Down);
	}
	else {
		return Array[Num_el];
	}

}