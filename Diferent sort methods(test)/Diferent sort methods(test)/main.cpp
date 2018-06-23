#include "resours.h"

void Insertion_Sort(unique_ptr<int[]>&, int);
unique_ptr<int[]> Selection_Sort(unique_ptr<int[]>, int);

int main()
{
	int Num_el(0);
	cout << "Enter # of elements : ";
	cin >> Num_el;

	unique_ptr<int[]> Array(new int[Num_el]);
	
#ifdef DEBUG
	cout << "\nArray constructed\n";
#endif 

	for (int i(0); i < Num_el; i++) { Array[i] = rand() % Num_el; };

#ifdef DEBUG
	cout << "\nArray inicialized\n";
#endif 

	for (int i(0); i < Num_el; i++) { cout<<Array[i]<<" "; };
	cout << "\n\nChoose a method of sorting :\n1-Isertion sort\n2-Selection sort\n5-Exit\n";
	int choice(0);
	
		cin >> choice;
		switch (choice)
		{
		case 1:
			Insertion_Sort(Array, Num_el);
			break;
		case 2:
			Array = Selection_Sort(move(Array), Num_el);
		case 5:
			break;
		default:
			break;
		}
	
	
	
	

	
	for (int i(0); i < Num_el; i++) { cout << Array[i] << " "; };
	cout << "\n";

	system("pause");
	return 0;
}

void Insertion_Sort(unique_ptr<int[]>& Array, int Num_el) {

	int Current(Num_el);
	int tmp(0);
	for (int i(0); i < Num_el; i++) {
		int j(i);
		while (j>0 && Array[j]<Array[j - 1])
		{
			tmp = Array[j];
			Array[j] = Array[j - 1];
			Array[j - 1] = tmp;
			j--;
		}
	}

#ifdef DEBUG
	cout << "\nSorted Array :			Insertion Sort\n";
#endif
}

unique_ptr<int[]> Selection_Sort(unique_ptr<int[]> Array, int Num_el) {

	unique_ptr<int[]> Result(new int[Num_el]);
	int Min_ind(0);
	int Current_ind(0);
	for (int i(0); i < Num_el; i++) {
		Current_ind = 0;
		while (Current_ind<Num_el){
			if (Array[Current_ind] <= Array[Min_ind]) Min_ind = Current_ind; 
			Current_ind++;
		}
		Result[i] = Array[Min_ind];
		Array[Min_ind] = Num_el + 1;
	}

#ifdef DEBUG
	cout << "\nSorted Array :			Selection Sort\n";
#endif
	return Result;
}