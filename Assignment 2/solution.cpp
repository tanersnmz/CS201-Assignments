#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

bool kelimechecker(const string & kelime) {

bool value = true;
for (unsigned int a = 0; a < kelime.length(); a++)
{
   char harf = kelime.at(a);
   if (!(harf >=97 && harf <=122)) {
       value = false;
   }
}
return value;
}

string cizgiolustur(const string & kelime) {

string kelimecizgili = "";
for (unsigned int i = 0; i < kelime.length(); i++)
{
	kelimecizgili += "-";
}

return kelimecizgili;

}

bool birikichecker(const int & a) {

	
	if ((a == 1) || (a ==2))
	{
		return true;
	}

	else
	{
		return false;
	}
	
}

void loser(int & counter, const string & player2,string & tahminler,const string & a, const string & cizgilikelime ) {

	if (counter == 0)
	{
		cout << "You have no free guess left." << endl;
		cout << "The word is: " << cizgilikelime << endl;
		tahminler += a;
		counter++;
		
	}
	else if (counter == 1)
	{
		cout << "You have lost a leg!" << endl;
		cout << "The word is: " << cizgilikelime << endl;
		counter++;
	}
	else if (counter == 2)
	{
		cout << "You have lost a leg!" << endl;
		cout << "The word is: " << cizgilikelime << endl;
		counter++;
	}
	else if (counter == 3)
	{
		cout << "You have lost an arm!" << endl;
		cout << "The word is: " << cizgilikelime << endl;
		counter++;
	}
	else if (counter == 4)
	{
		cout << "You have lost an arm!" << endl;
		cout << "The word is: " << cizgilikelime << endl;
		counter++;
	}
	else if (counter == 5)
	{
		cout << "You have lost a head! GAME OVER!" << endl;
		cout << player2 << " lost the game :(";
		counter++;
	}

}


string replacer(string & cizgilikelime, const string & kelime, const string & harf) {

	char ch = harf[0];
	for (unsigned int i = 0; i < kelime.length(); i++)
	{
		if (kelime.at(i) == ch)
		{
			cizgilikelime.at(i) = ch;
		}
	}
	return cizgilikelime;



}


int main() {
	string tahminler = "";
	int counter =0;
	cout << "Welcome to the HANGMAN GAME" << endl;
	cout << "---------------------------" << endl;
	string player1,player2;
	cout << "Player one, please enter your name: ";
	cin >> player1;
	cout << "Player two, please enter your name: ";
	cin >> player2;
	cout << "OK " << player1 << " and " << player2 << "." << " Let's start the game!" << endl;
	string kelime;
	cout << player1 << ", please input the word you want " << player2 << " to guess: ";
	cin >> kelime;
	kelime = LowerString(kelime);
	while (kelimechecker(kelime) == false)
	{
		cout << "Invalid word! Try again." << endl;
		cout << player1 << ", please input the word you want " << player2 << " to guess: ";
		//string kelimetahmin;
		cin >> kelime;
		kelime = LowerString(kelime);
		if (kelimechecker(kelime))
		{
			break;
		}
	}
	cout << player2 << ", you have 1 free guess, after that you will lose limbs!"<< endl;
	string cizgilikelime = cizgiolustur(kelime);
	cout << "The word is: " << cizgilikelime << endl;
	while (counter !=6)
	{
		cout << player2 << ", do you want to guess the word(1) or guess a letter(2)? ";
		string sayi;
		cin >> sayi;
		int nsayi = atoi(sayi);
		if (birikichecker(nsayi))
		{
			if (nsayi == 1)
			{
				cout << "Your guess: ";
				string wordgues;
				cin >> wordgues;
				wordgues = LowerString(wordgues);
				if (kelimechecker(wordgues))
				{
					if (wordgues == kelime)
					{
						cout << "The word is: " << kelime<< endl;
						cout << "Congratulations " <<  player2 << ", you won!" << endl;
						cout << player2 <<  " won the game!";
						break;

					}
					else
					{
						loser(counter,player2,tahminler,"",cizgilikelime);
					}
				}
				else
				{
					cout << "Invalid entry! Try again." << endl;
					cout <<"The word is: " << cizgilikelime << endl;
					
				}
			}
			
			else if (nsayi ==2)
			{
				cout << "Your guess: ";
				string harf;
				cin >> harf;
				harf = LowerString(harf);
				if ((harf.length()==1) && (kelimechecker(harf)))
				{
					
					//tahminler += harf;
					
					
					if (tahminler.length() == 0)
					{
						if (kelime.find(harf) != string::npos)
						{
							replacer(cizgilikelime, kelime, harf);
							if (cizgilikelime == kelime)
							{
								cout << "The word is: " << kelime << endl;
								cout << "Congratulations " <<  player2 << ", you won!" << endl;
								cout << player2 <<  " won the game!";
								break;
							}
							else
							{
								cout << "The word is: " << cizgilikelime << endl;
							tahminler+= harf;
							//counter++;
							}
							
						}
						else if(kelime.find(harf) == string::npos )
						{
						loser(counter,player2,tahminler,harf,cizgilikelime);
						}
						else
						{
							loser(counter,player2,tahminler,harf,cizgilikelime);
						}
					}
					else if (tahminler.find(harf) != string::npos && tahminler.length() != 0 )
					{
						cout << "Guess entered before! Try again." << endl;
						cout << "The word is: " << cizgilikelime << endl;

					}
					else if (tahminler.find(harf) == string::npos && kelime.find(harf) != string::npos)
					{
							replacer(cizgilikelime, kelime, harf);
							if (cizgilikelime == kelime)
							{
								cout << "The word is: " << kelime << endl;
								cout << "Congratulations " <<  player2 << ", you won!" << endl;
								cout << player2 <<  " won the game!";
								break;
							}
							else
							{
								cout << "The word is: " << cizgilikelime << endl;
							tahminler+= harf;
							//counter++;
							}
					}
					else if(kelime.find(harf) == string::npos )
					{
						loser(counter,player2,tahminler,harf,cizgilikelime);
					}
				}
				
				
				else
				{
					cout << "Invalid entry! Try again." << endl;
					cout << "The word is: " << cizgilikelime << endl;

				}
			}


		}
		else
		{
			cout << "Invalid option!" << endl;
			cout << "The word is: " << cizgilikelime << endl;
		}
	}
	
	













	return 0;
}