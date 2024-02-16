#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "date.h"
#include "strutils.h"
#include "Reservation.h"


using namespace std;











/*
struct infos
{
	string botid;
	string boatname;
	string boatcolor;
	string sailorid;
	string sailorname;
	string sailorank;
	string sailorage;
	string reservationdate;
};
*/

int main(){
	int deger;
	cout << "Enter filename for reservation database: ";
	string filename;
	cin >> filename;
	ifstream input1,input2,input3;
	input1.open(filename.c_str());
	string fileboat = "Boats.txt";
	string filesailors = "Sailors.txt";
	input2.open(fileboat.c_str());
	input3.open(filesailors.c_str());
	if (input1.fail() || input2.fail() || input3.fail())
	{
		cout << "Cannot open the files. Exiting..."<<endl;
		cout <<endl;
	}
	else
	{

		
		string s1,s2,s3;
		int counter =0,linecounter=0;
		string line;
		/*
		while (getline(input1,line))
		{
			linecounter++;
		}
		input1.clear();
		input1.seekg(0);
		vector<infos> matches(linecounter);
		*/
		//vector<Reservation> myvector;
		string islem,sid,bid,rdate,rdate2;
		Reservations rez;
		Reservation dez;
		double c,d;
		string b,f,g;
		int idx1,idx2,e,a;
		int day,month,year,day1,month1,year1;
		string bid1,bname1,bcolor1;
		string sid1,sname1,rating1,age1;
		while (getline(input1,s1))// add icin while
		{
			istringstream parse1(s1);
			parse1 >>islem >> sid >>bid >> rdate>>rdate2;
			//cout << " "<<islem <<" "<< sid<<" " << bid<<" " << rdate<<" " << rdate2<<endl;
			if (islem == "A")
			{

				//rdate olusturucu
				idx1 = rdate.find('-');//4
				idx2 = rdate.find("-",idx1+1);//7
				day = atoi(rdate.substr(idx2+1,2));
				month =atoi(rdate.substr(idx1+1,2));
				year = atoi(rdate.substr(0,idx1));
				Date d11(month,day,year);
				while (getline(input2,s2))
					{
						istringstream parse2(s2);
						parse2 >> bid1 >> bname1 >> bcolor1;
						if (bid == bid1)
						{
							e =atoi(bid);
							g =bname1;
							f =bcolor1;
						}	
					}
				while (getline(input3,s3))
					{
						istringstream parse3(s3);
						parse3 >> sid1 >> sname1 >> rating1 >>age1;
						if (sid== sid1)
						{
							a =atoi(sid1);
							b = sname1;
							c =atof(age1);
							d = atof(rating1);
							
						}	
					}
				Sailor s11(a,  b, c, d);
				Boat b11(e, g, f);
				Reservation r(d11,s11,b11);
				Date t;
				//cout << r.sp.ip <<endl;
				rez.AddReservation(r,b11,s11,t);
				input2.clear();
				input3.clear();
				input2.seekg(0);
				input3.seekg(0);
			}
			if (islem == "D")
			{
				idx1 = rdate.find('-');
				idx2 = rdate.find("-",idx1+1);
				day = atoi(rdate.substr(idx2+1,2));
				month =atoi(rdate.substr(idx1+1,2));
				year = atoi(rdate.substr(0,idx1));
				Date d111(month,day,year);
				Boat bey;
				Sailor zey;
				if (sid == "0" && rdate == "0000-00-00")
				{
					rez.DeleteReservationsB(atoi(bid),bey);
				}
				else if (bid == "0" && rdate == "0000-00-00")
				{
					rez.DeleteReservationsS(atoi(sid),zey);	
				}
				else
				{
					rez.DeleteReservations(atoi(bid),atoi(sid),d111,rdate,zey,bey);
				}

			}
			if (islem == "F")
			{
				if (sid=="0" && bid== "0")
				{
					idx1 = rdate.find('-');
					idx2 = rdate.find("-",idx1+1);
					day = atoi(rdate.substr(idx2+1,2));
					month =atoi(rdate.substr(idx1+1,2));
					year = atoi(rdate.substr(0,idx1));
					Date start(month,day,year);
					idx1 = rdate2.find('-');
					idx2 = rdate2.find("-",idx1+1);
					day = atoi(rdate2.substr(idx2+1,2));
					month =atoi(rdate2.substr(idx1+1,2));
					year = atoi(rdate2.substr(0,idx1));
					Date finish(month,day,year);
					cout << "Find Results:"<<endl;
					vector<Reservation> aaa = rez.FindReservations1(start,finish,rdate,rdate2,deger);
					if (deger!=0)
					{
						rez.ReservationPrinter(aaa);
					}
					cout <<endl;
				}
				if (sid == "0" && bid!="0")
				{
					while (getline(input2,s2))
					{
						istringstream parse2(s2);
						parse2 >> bid1 >> bname1 >> bcolor1;
						if (bid == bid1)
						{
							e =atoi(bid);
							g =bname1;
							f =bcolor1;
						}	
					}
					input2.clear();
					input2.seekg(0);
					Boat b1122(e, g, f);
					idx1 = rdate.find('-');
					idx2 = rdate.find("-",idx1+1);
					day = atoi(rdate.substr(idx2+1,2));
					month =atoi(rdate.substr(idx1+1,2));
					year = atoi(rdate.substr(0,idx1));
					Date tarih(month,day,year);
					cout << "Find Results:"<<endl;
					vector<Reservation> bbb = rez.FindReservations2(b1122,tarih,rdate,deger);
					if (deger!=0)
					{
						rez.ReservationPrinter(bbb);
					}
					cout <<endl;



				}
				if (bid == "0" && sid != "0")
				{
					while (getline(input3,s3))
					{
						istringstream parse3(s3);
						parse3 >> sid1 >> sname1 >> rating1 >>age1;
						if (sid== sid1)
						{
							a =atoi(sid1);
							b = sname1;
							c =atof(age1);
							d = atof(rating1);
							
						}	
					}
					int idx11,idx22;
					int day1,month1,year1;
					input3.clear();
					input3.seekg(0);
					idx11 = rdate.find('-');
					idx22 = rdate.find("-",idx11+1);
					day1 = atoi(rdate.substr(idx22+1,2));
					month1 =atoi(rdate.substr(idx11+1,2));
					year1 = atoi(rdate.substr(0,idx11));
					Date tarih1122(month1,day1,year1);
					Sailor s1122(a,  b, c, d);
					//cout << s1122.np << endl;
					cout << "Find Results:"<<endl;
					vector<Reservation> ccc = rez.FindReservations3(s1122,tarih1122,rdate,deger);
					if (deger!=0)
					{
						rez.ReservationPrinter(ccc);
						
					}
					cout <<endl;

				}

			
			
			
		}//if F son

	}//while son

}//else son

			

			
		/*
				for (int i = 0; i < rez.my.size(); i++)
			{
				cout << rez.my[i].sp.ip << endl;
				cout << rez.my[i].bp.ip << endl;
				cout << rez.my[i].dp << endl;
			
			}
			



	






















	






















		

		
	
while (getline(input1,s1)){
	istringstream parse1(s1);
	parse1 >>islem >> sid >>bid >> rdate;
	if (islem == "D")
	{
				idx1 = rdate.find('-');
				idx2 = rdate.find("-",idx1+1);
				day = atoi(rdate.substr(idx2+1,2));
				month =atoi(rdate.substr(idx1+1,2));
				year = atoi(rdate.substr(0,idx1));
				Date d111(month,day,year);
		if (sid == "0" && rdate == "0000-00-00")
		{
			rez.DeleteReservationsB(atoi(bid));
		}
		else if (bid == "0" && rdate == "0000-00-00")
		{
			rez.DeleteReservationsS(atoi(sid));	
		}
		else
		{
			rez.DeleteReservations(atoi(bid),atoi(sid),d111,rdate);
		}

	}
}//delete sonu
input1.clear();
input1.seekg(0);


		
		
		
		//printer
		for (int i = 0; i < rez.my.size(); i++)
		{
			cout << rez.my[i].sp.ip << endl;
		}
		
















	}//else kapanis



		// Siralama(matches, olusturdugum vector)
for (int i = 1; i < matches.size(); i++)
{
    for (int a = i; a > 0; a--)
    {
        if (matches[a].reservationdate < matches[a-1].reservationdate)
        {
            string temp1 = matches[a].botid;
			string temp2 = matches[a].boatname;
			string temp3 = matches[a].boatcolor;
			string temp4 = matches[a].sailorid;
			string temp5 = matches[a].sailorname;
			string temp6 = matches[a].sailorank;
			string temp7 = matches[a].sailorage;
			string temp8 = matches[a].reservationdate;
            matches[a].reservationdate = matches[a-1].reservationdate;
			matches[a].boatname = matches[a-1].boatname;
			matches[a].boatcolor = matches[a-1].boatcolor;
			matches[a].sailorid = matches[a-1].sailorid;
			matches[a].sailorname = matches[a-1].sailorname;
			matches[a].sailorank = matches[a-1].sailorank;
			matches[a].sailorage = matches[a-1].sailorage;
			matches[a].reservationdate = matches[a-1].reservationdate;
            matches[a-1].reservationdate = temp8;
			matches[a-1].sailorage = temp7;
			matches[a-1].sailorank = temp6;
			matches[a-1].sailorname = temp5;
			matches[a-1].sailorid = temp4;
			matches[a-1].boatcolor = temp3;
			matches[a-1].boatname = temp2;
			matches[a-1].botid = temp1;
        }       
    }    
}
for (int i = 1; i < matches.size(); i++)
{
    for (int a = i; a > 0; a--)
    {
        if (matches[a].reservationdate == matches[a-1].reservationdate)
        {
			if (matches[a].sailorname < matches[a-1].sailorname){
				string temp1 = matches[a].botid;
				string temp2 = matches[a].boatname;
				string temp3 = matches[a].boatcolor;
				string temp4 = matches[a].sailorid;
				string temp5 = matches[a].sailorname;
				string temp6 = matches[a].sailorank;
				string temp7 = matches[a].sailorage;
				string temp8 = matches[a].reservationdate;
				matches[a].reservationdate = matches[a-1].reservationdate;
				matches[a].boatname = matches[a-1].boatname;
				matches[a].boatcolor = matches[a-1].boatcolor;
				matches[a].sailorid = matches[a-1].sailorid;
				matches[a].sailorname = matches[a-1].sailorname;
				matches[a].sailorank = matches[a-1].sailorank;
				matches[a].sailorage = matches[a-1].sailorage;
				matches[a].reservationdate = matches[a-1].reservationdate;
				matches[a-1].reservationdate = temp8;
				matches[a-1].sailorage = temp7;
				matches[a-1].sailorank = temp6;
				matches[a-1].sailorname = temp5;
				matches[a-1].sailorid = temp4;
				matches[a-1].boatcolor = temp3;
				matches[a-1].boatname = temp2;
				matches[a-1].botid = temp1;
			
			
			}
            
        }       
    }    
}



		//yazma baslangic
		for (unsigned int i = 0; i < matches.size(); i++)
		{
			if (matches[i].sailorage.find(".") != string::npos)
			{
				int idx = matches[i].sailorage.find(".");
				if (matches[i].sailorage.at(idx+1) == '0')
				{
					matches[i].sailorage = matches[i].sailorage.substr(0,idx);
				}
			}
			if (matches[i].sailorank.find(".")!= string::npos)
			{
				int idx = matches[i].sailorank.find(".");
				if (matches[i].sailorank.at(idx+1) == '0')
				{
					matches[i].sailorank = matches[i].sailorank.substr(0,idx);
				}
			}
			if (matches[i].reservationdate.length()!=0 && matches[i].sailorname.length()!=0 && matches[i].sailorage.length()!=0 && matches[i].sailorank.length()!=0 && matches[i].boatname.length()!=0 && matches[i].boatcolor.length()!=0)
			{
				cout << matches[i].reservationdate <<" -> " << matches[i].sailorname << "("<< matches[i].sailorage << ","<< matches[i].sailorank << ") has reserved "<< matches[i].boatname << "(" << matches[i].boatcolor << ")" << endl;
			}
			
		}
		// yazma bitis


		input1.close();
		input2.close();
		input3.close();
		
	}


*/
	


return 0;
}