#include <iostream>//For output to screen
#include <vector>//For vector class
#include <fstream>//For file stream
#include <algorithm>//For sorting algorithm
using namespace std;

/*
	This function simply prints the vector v in order
	for the user to see the algorithms progress
*/
void vectorPrint(vector<int>&v) {
	for (const int& i : v) cout << i << ' ';
	cout << endl;
}

/*
	The HavelHakimi function follows the Havel-Hakimi Theorem.
	The function is recursive 
*/
bool HavelHakimi(vector<int>&v)
{
	if (v.size() == 0) return true;
	int counter = 0;
	int firstElement = v[0];
	v.erase(v.begin());
	while (counter < firstElement)
	{
		v[counter]--;
		if (v[counter] == -1) return false;
		counter++;
	}
	vectorPrint(v);
	return HavelHakimi(v);
}

int main()
{
	vector<int>degSeq;
	ifstream inFS;
	int buffer;

	//Put degree sequence in a text for example
	inFS.open("DegreeSequence.txt");
	
	while (!(inFS.eof()))
	{
		inFS >> buffer;
		degSeq.push_back(buffer);
	}

	//Maybe write sorting algorithm from scratch instead of using from algorithm library.
	sort(degSeq.begin(), degSeq.end(),greater<int>());
	vectorPrint(degSeq);

	if (degSeq[0] >= degSeq.size())
	{
		cout << "Sequence is not graphical.  First integer is larger than the length of the sequence." << endl;
		system("pause");
		return -1;
	}
	else if (!HavelHakimi(degSeq))
	{
		cout << "Sequence is not graphical.  Negative number has been reached in Havel Hakimi function" << endl;
		system("pause");
		return -2;
	}
	else
	{
		cout << "Sequence is graphical."<<endl;
		system("pause");
		return 0;
	}
}
