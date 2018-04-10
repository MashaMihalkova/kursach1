#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "zdanie.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string word_in,file_in;
	file_in= "C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\one.txt";
	//ofstream ffout("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt");
	ifstream in(file_in.c_str(), ios::in);
	if (!in.good())
	{
		cout << "Файл не найден.\n";
		exit(1);
	}

	ofstream fout("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\two.txt");
	
	//factory list(in);
	factory list; 
	string type;
	string otobraj;
	cout << "File or Console ";cin >>otobraj;
	


	char choice = 0;
	do
	{
		

		system("cls");

		if (choice == 'a' || choice == 'A')
		{
			cout << "Input zdanie type (panel , cottage , )  ->";
			string type;
			cin >> type;
			if (otobraj == "File") {
				//list.Add(type, cin); 
				//ifstream ffout("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt");

				list.Add(type, in);
				list.Save(type, fout);
					

			}
			else {
				//getline(cin, type);
				list.Add(type, cin);
			}
		}
		
		
		else if (choice == 'p' || choice == 'P')
		{
			cout << "Input zdanie type (panel , cottage , )  ->";

			//	getline(cin, type);
			cin >> type;
			if (otobraj == "File")
			{	
				ifstream in(file_in.c_str(), ios::in);
				while (in >> word_in)
				{
					//fpin >> word_in;
					if (word_in == type)
					{
						while (word_in != ";") {
							cout << word_in << endl;
							in >> word_in;
						}
					}
				}
			}
			else {
				list.Print(type, cout);
				/*for (auto v : list.list) 
				{ 

				//	v->Print(type,*list.list);
				};*/
			}
		}

		else if (choice == 's' || choice == 'S')
		{
			//ofstream fpout("one.txt");
			list.Save(type, fout);
		}

		else if (choice == 'n' || choice == 'N')
		{
			cout << "Input zdanie type (panel , cottage ,)  ->";
			string type;
			cin >> type;
			//getline(cin, type);
		//	cout << "Number of documents: " << list.Size(type) << endl;
		}

		cout << endl <<
			"A - add new element to list" << endl
			<< "P - print list of zdanie" << endl
			<< "S - save list of zdanie into file" << endl
			<< "N - number of zdanie" << endl
			<< "Q - quit" << endl;

	

  } while ((choice = getch()) != 'q' && choice != 'Q');
  in.close();
  fout.close();
}