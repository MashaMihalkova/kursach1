#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "factory.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string word_in,file_in, file_in2;
	fstream filestr("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt", fstream::in | fstream::out);
	file_in= "C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\one.txt";
	file_in2 = "C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt";
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
	//cout << "File or Console ";cin >>otobraj;
	


	char choice = 0;
	do
	{
		system("cls");

		if (choice == 'a' || choice == 'A')
		{
			cout << "File or Console "; cin >> otobraj;

			cout << "Input zdanie type (panel , cottage , )  ->";
			int kol=0;
			string type;
			cin >> type;
			if (otobraj == "File") {
			
				fstream filestr("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt", fstream::in | fstream::out);
				while (filestr >> word_in)
				{
					//fpin >> word_in;
					if (word_in == type)
					{
							while (word_in != ";") {
								filestr >> word_in;
							}
							kol++;
						}
						else {
							while (word_in != ";")
								filestr >> word_in;
						}
					
				}
			filestr.close();
			fstream filestr1("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt", fstream::in | fstream::out);

				string id;
				cout<<"number of characteristics = " << kol<<endl<<"Choose charachteristic ->";
				cin >> id;
				list.Add_file(type, id, filestr1);
				filestr1.close();
			}
			else {
				//getline(cin, type);
				list.Add(type, cin);
			}
		}
		
		
		else if (choice == 'p' || choice == 'P')
		{
			cout << "File or Console "; cin >> otobraj;

			cout << "Input zdanie type (panel , cottage , )  ->";
			cin >> type;
			
			if (otobraj == "File")
			{
				fstream filestr("C:\\Users\\marus\\Desktop\\GUAP\\3,5\\Kursach_Kuritsin\\docmanager_peredel\\tree.txt", fstream::in | fstream::out);
				while (filestr >> word_in)
				{
					if (word_in == type)
					{
						while (word_in != ";") {
							cout << word_in << endl;
							filestr >> word_in;
						}
					}
				}
				filestr.close();
			}
			else {
				list.Print(type, cout);
			}
		}

		else if (choice == 's' || choice == 'S')
		{
			list.Save(type, fout);
		}

		else if (choice == 'n' || choice == 'N')
		{
			cout << "Input zdanie type (panel , cottage ,)  ->";
			string type;
			cin >> type;

			
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