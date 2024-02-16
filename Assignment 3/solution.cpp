#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



using namespace std;
string satirsonukelime(string anskeyline){
	
			string sonkelime ="";
			for (int i = anskeyline.length()-1; i >=0; i--)
			{
				
				if (anskeyline.at(i) != ' ')
				{
					sonkelime = anskeyline.at(i)+sonkelime;
				}
				else
				{
					break;
				}
			}
	return sonkelime;





}
void puanhesapla(string fname,string lname,string ans1,string ans2,string ans3,string ans4,string ans5,string ans6, ifstream & ianswerkey){
string answerkeyline;
int counter =0;
int puan =0;
while (getline(ianswerkey,answerkeyline))
{
	//cout << answerkeyline.length() << endl;
	counter++;
	if (counter ==1)
	{
		int idx1 = answerkeyline.find(ans1)+1; //6
		if (idx1==0)
		{
			puan+=1;
		}
		else
		{
			int cikar1 =0;
			for (int i = 0; i < idx1-1; i++)
			{
				if (isalpha(answerkeyline.at(i)))
				{
					cikar1++;
				}
			}
			int cevap1 = idx1-cikar1;
			puan += cevap1;

			
		}
		
	}
	if (counter ==2)
	{
		int idx2 = answerkeyline.find(ans2)+1; //5
		if (idx2==0)
		{
			puan+=1;
		}
		else
		{
			int cikar2 =0;
			for (int i = 0; i < idx2-1; i++)
			{
				if (isalpha(answerkeyline.at(i)))
				{
					cikar2++;
				}
			}
			int cevap2 = idx2-cikar2;
			puan += cevap2;
			
		}
		
	}
	if (counter ==3)
	{
		int idx3 = answerkeyline.find(ans3)+1; //24
		if (idx3==0)
		{
			puan+=1;
		}
		else
		{
			int cikar3 =0;
			for (int i = 0; i < idx3-1; i++)
			{
				if (isalpha(answerkeyline.at(i)))
				{
					cikar3++;
				}
			}
			int cevap = idx3-cikar3;
			puan += cevap;
			
		}
		
	}
	if (counter ==4)
	{
		int idx4 = answerkeyline.find(ans4)+1; //5
		if (idx4==0)
		{
			puan+=1;
		}
		else
		{
				int cikar4 =0;
			for (int i = 0; i < idx4-1; i++)
			{
				if (isalpha(answerkeyline.at(i)))
				{
					cikar4++;
				}
			}
			int cevap4 = idx4-cikar4;
			puan += cevap4;
			
		}
		
	}
	if (counter ==5)
	{
		int idx5 = answerkeyline.find(ans5)+1; //5
		if (idx5==0)
		{
			puan+=1;
		}
		else
		{
			int cikar5 =0;
			for (int i = 0; i < idx5-1; i++)
			{
				if (isalpha(answerkeyline.at(i)))
				{
					cikar5++;
				}
			}
			int cevap5 = idx5-cikar5;
			puan += cevap5;
			
		}
		
	}
	if (counter ==6)
	{
		int idx6 = answerkeyline.find(ans6)+1; //5
		if (idx6==0)
		{
			puan+=1;
		}
		else
		{
			int cikar6 =0;
			for (int i = 0; i < idx6-1; i++)
			{
				if (isalpha(answerkeyline.at(i)))
				{
					cikar6++;
				}
			}
			int cevap6 = idx6-cikar6;
			puan += cevap6;
			
		}
	}
		
	
	
}

if (puan <10)
{

	cout << "Oh! we have " << fname << " " << lname << " under the sorting hat. " << fname << ", you scored " << puan << " points, you are a Hufflepuff!" << endl; 
}
else if (puan >= 10 && puan <15)
{
	cout << "Oh! we have " << fname << " " << lname << " under the sorting hat. " << fname << ", you scored " << puan << " points, you are a Ravenclaw!" << endl; 
}
else if (puan >= 15 && puan <21)
{
	cout << "Oh! we have " << fname << " " << lname << " under the sorting hat. " << fname << ", you scored " << puan << " points, you are a Gryffindor!" << endl; 
}
else if(puan >=21)
{
	cout << "Oh! we have " << fname << " " << lname << " under the sorting hat. " << fname << ", you scored " << puan << " points, you are a Slytherin!" << endl; 
}
ianswerkey.clear();
ianswerkey.seekg(0);








}

int main(){
	cout << "Hello and welcome to the Hogwarts house sorting hat program!" << endl;
	cout << "When I call your name, you'll come forth, I shall place the sorting hat on your head, and you will be sorted into your houses."<< endl;
	cout << "Enter the name of the key file: ";
	string answerkey;
	cin >> answerkey;
	ifstream ianswerkey;
	ianswerkey.open(answerkey);
	while (ianswerkey.fail())
	{
		cout << "Error: Cannot open file " <<answerkey << endl;
		cout << "Enter the name of the key file: ";
		cin >> answerkey;
		ianswerkey.open(answerkey);
	}
	ifstream ianswers;
	cout << "Enter the name of the answer file: ";
	string answers;
	cin >> answers;
	ianswers.open(answers);
	while (ianswers.fail())
	{
		cout << "Error: Cannot open file " <<answers << endl;
		cout << "Enter the name of the answer file: ";
		cin >> answers;
		ianswers.open(answers);
	}
	string line;
	while (getline(ianswers,line))
	{
		istringstream parse(line);
		string fname,lname,ans1,ans2,ans3,ans4,ans5,ans6;
		parse >> fname >> lname >> ans1 >> ans2 >> ans3 >> ans4 >> ans5 >> ans6;
		if (fname.length() !=0 && lname.length() !=0 && ans1.length() !=0 && ans2.length() !=0 && ans3.length() !=0 && ans4.length() !=0 && ans5.length() !=0 && ans6.length() !=0 )
		{
			puanhesapla(fname,lname,ans1, ans2, ans3, ans4, ans5, ans6,ianswerkey);
		}
		



		
		
		
	}








	ianswerkey.close();
	ianswers.close();











return 0;
}