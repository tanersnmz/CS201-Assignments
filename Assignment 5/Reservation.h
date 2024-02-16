#ifndef Reservation_h
#define Reservation_h
#include <iostream>
#include <vector>
#include <string>
#include "date.h"
using namespace std;

class Sailor
{
	public:
		Sailor(int, string , double , double );
	
		Sailor()
		{
			id = 0;
			name = "Jane Doe";
			age = 0;
			rank = 0;
		}
		
		int ip;
		string np;
		double ap;
		double rp;
	private:
		int id;
		string name;
		double age;
		double rank;
};

class Boat
{
	public:
		Boat(int, string , string);
		
		Boat()
		{
			id = 0;
			name = "Default";
			color = "Default";
		}
		
		int ip;
		string np;
		string cp;
	private:
		int id;
		string name;  
		string color;
};

class Reservation
{
	public:
		Reservation(Date , Sailor , Boat);
		
		Reservation()
		{
			Sailor s;
			sailor = s;
			Boat b;
			boat = b;
			Date d(1,1,1900);
			resDate = d;
		}
		
		Date dp;
		Sailor sp;
		Boat bp;
		

	private:
		Date resDate;
		Sailor sailor;
		Boat boat;
};

class Reservations
{
	public:

			void AddReservation(Reservation,Boat,Sailor,Date);
			bool DeleteReservationsB(int,Boat);
			bool DeleteReservationsS(int,Sailor);
			bool DeleteReservations(int , int , Date,string,Sailor,Boat);
			vector<Reservation> FindReservations1(Date, Date,string,string,int &);
			vector<Reservation> FindReservations2(Boat,Date,string,int &);
			vector<Reservation> FindReservations3(Sailor,Date,string,int &);
			vector <Reservation> my;//kopy
			void ReservationPrinter( vector<Reservation> &);
			
		
			
		

	private:
		vector<Reservation> reservations;
	
};

#endif

