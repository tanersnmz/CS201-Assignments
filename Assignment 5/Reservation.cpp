#include "Reservation.h"
#include <vector>
#include <string>
#include <iostream>
#include "date.h"
#include "strutils.h"
using namespace std;

void Reservations::AddReservation(Reservation r,Boat b,Sailor s, Date d)
{
	//cout << d << endl;
		reservations.push_back(r);
		reservations.shrink_to_fit();
		my.push_back(r);

}


bool Reservations::DeleteReservationsB(int botid,Boat b)
{
	bool deger= true;
	unsigned int i = 0;
	int counter =0;
	int caz = reservations.size();
	while (i < reservations.size())
	{
		if (botid==reservations[i].bp.ip)
		{
		
			counter++;
			/*
			Reservation last(reservations[reservations.size()-1].dp , reservations[reservations.size()-1].sp , reservations[reservations.size()-1].bp);
			Reservation mine(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			reservations[i]= last;
			reservations[reservations.size()-1] =mine;
			reservations.pop_back();
			*/
			
			reservations.erase(reservations.begin()+i);
				/*
			Reservation last(reservations[reservations.size()-1].dp , reservations[reservations.size()-1].sp , reservations[reservations.size()-1].bp);
			Reservation mine(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			reservations[i]= last;
			reservations[reservations.size()-1] =mine;
			reservations.pop_back();
			*/
						reservations.shrink_to_fit();
			//caz--;
			
		}
		//reservations.shrink_to_fit();
		i++;
			
	}
	/*
	for (int a = 0; a < my.size(); a++)
	{
		if (botid==my[a].bp.ip)
		{
			
			Reservation last(my[my.size()-1].dp , my[my.size()-1].sp , my[my.size()-1].bp);
			Reservation mine(my[a].dp,my[a].sp,my[a].bp);
			my[a]= last;
			my[my.size()-1] =mine;
			my.pop_back();
			
			
		}
	}
	*/
	if (counter ==0)
	{
		cout <<"Error: Could not delete reservation for boat id " << botid <<endl;
		cout <<endl;
		deger= false;
		
	}
	return deger;
}

bool Reservations::DeleteReservationsS(int sailorid,Sailor s)
{
	bool deger =true;
	unsigned int i = 0;
	int counter=0;
	int caz =reservations.size();
	while (i < reservations.size())
	{
		if (sailorid==reservations[i].sp.ip)
		{
			
			//cout << sailorid <<" " <<i <<" "<< reservations[i].sp.ip <<" "<< reservations[i].bp.ip<<" "<<reservations[i].bp.np<< " " << reservations[i].dp<< endl;
			

			counter++;
			/*
			Reservation last(reservations[reservations.size()-1].dp , reservations[reservations.size()-1].sp , reservations[reservations.size()-1].bp);
			Reservation mine(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			reservations[i]= last;
			reservations[reservations.size()-1] =mine;
			reservations.pop_back();
			*/
			//reservations.shrink_to_fit();
			
						reservations.erase(reservations.begin()+i);
							/*
			Reservation last(reservations[reservations.size()-1].dp , reservations[reservations.size()-1].sp , reservations[reservations.size()-1].bp);
			Reservation mine(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			reservations[i]= last;
			reservations[reservations.size()-1] =mine;
			reservations.pop_back();
			*/
						reservations.shrink_to_fit();
						
					//caz--;
			
			
		}
		
		i++;
			
	}
	/*
		for (int a = 0; a < my.size(); a++)
	{
		if (sailorid==my[a].sp.ip)
		{
			
			Reservation last(my[my.size()-1].dp , my[my.size()-1].sp , my[my.size()-1].bp);
			Reservation mine(my[a].dp,my[a].sp,my[a].bp);
			my[a]= last;
			my[my.size()-1] =mine;
			my.pop_back();
		}
	}
	*/
	if (counter ==0)
	{
		cout <<"Error: Could not delete reservation for sailor id " << sailorid <<endl;
		deger =false;
		cout <<endl;
		
	}
	return deger;

}

bool Reservations::DeleteReservations(int botid, int sailorid, Date dater,string dateyazi,Sailor s, Boat b)
{
	bool deger=true;
	int counter=0;
	unsigned int i = 0;
	int caz = reservations.size();
	while (i < reservations.size())
	{

		if (botid== reservations[i].bp.ip && sailorid== reservations[i].sp.ip && dater == reservations[i].dp)
		{
			counter++;
			/*
			Reservation last(reservations[reservations.size()-1].dp , reservations[reservations.size()-1].sp , reservations[reservations.size()-1].bp);
			Reservation mine(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			reservations[i]= last;
			reservations[reservations.size()-1] =mine;
			reservations.pop_back();
			*/
		
						reservations.erase(reservations.begin()+i);
							/*
		
			reservations.pop_back();
			*/
						reservations.shrink_to_fit();
							/*
			Reservation last(reservations[reservations.size()-1].dp , reservations[reservations.size()-1].sp , reservations[reservations.size()-1].bp);
			Reservation mine(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			reservations[i]= last;
			reservations[reservations.size()-1] =mine;
			reservations.pop_back();
			*/
			//caz--;
		}
		
		
		i++;
	}
	/*
		for (int a = 0; a < my.size(); a++)
	{
		if (botid== my[a].bp.ip && sailorid== my[a].sp.ip && dater == my[a].dp)
		{
			
			Reservation last(my[my.size()-1].dp , my[my.size()-1].sp , my[my.size()-1].bp);
			Reservation mine(my[a].dp,my[a].sp,my[a].bp);
			my[a]= last;
			my[my.size()-1] =mine;
			my.pop_back();
		}
	}
	*/
	if (counter ==0)
	{
		cout <<"Error: Could not delete reservation " << "\""<< sailorid << " " << botid << " " << dateyazi << "\""<< endl;
		cout <<endl;
		deger= false;
		
	}
return deger;

}




vector<Reservation> Reservations::FindReservations1(Date start, Date finish,string starts,string finishs,int & deger){
	vector <Reservation> findings1;
	int counter=0;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].dp<=finish && reservations[i].dp>=start)
		{
			deger =1;
			counter++;
			//cout << start <<" "<< finish << endl;
			//Reservation(Date , Sailor , Boat);
			//cout << reservations[i].dp << " -> "<< reservations[i].sp.np <<"("<< reservations[i].sp.ap <<","<<reservations[i].sp.rp << ")" <<" has reserved "<<reservations[i].bp.np<<"("<<reservations[i].bp.cp<<")"<<endl;
			Reservation a(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			findings1.push_back(a);
			
			
		}
	}
	if (counter==0)
	{
		cout << "Error: No matching reservation found between dates " << starts <<" & " << finishs <<endl;
		deger =0;


	}
	findings1.shrink_to_fit();
		return findings1;
	
}
vector<Reservation> Reservations::FindReservations2(Boat b,Date d,string dater,int & deger){
		vector <Reservation> findings2;
	int counter=0;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].bp.ip == b.ip && reservations[i].dp==d && b.cp.length()!=0)
		{
			deger =1;
			counter++;
			Reservation a(reservations[i].dp,reservations[i].sp,reservations[i].bp);
			findings2.push_back(a);
		
			
		}
	}
	if (counter==0)
	{
		cout << "Error: No matching reservation found for boat id " << b.ip <<" on " << dater <<endl;
		deger =0;

	}
		findings2.shrink_to_fit();
		return findings2;
	
	


}
vector<Reservation> Reservations::FindReservations3(Sailor s,Date d,string dater,int & deger){
int counter=0;
vector <Reservation> findings3;
//cout << s.ip << d <<endl;
//cout << s.np <<endl;


for (int i = 0; i < reservations.size(); i++)
{
	
	//cout << reservations[i].sp.ip <<endl;
	//cout << my[i].sp.ip <<endl;

	if (reservations[i].sp.ip==s.ip && d==reservations[i].dp)
	{
		deger =1;
		counter++;
		Reservation a(reservations[i].dp,reservations[i].sp,reservations[i].bp);
		findings3.push_back(a);
	
		

	}

}
	if (counter==0)
	{
		cout << "Error: No matching reservation found for sailor id " << s.ip <<" on " << dater <<endl;
		deger =0;

	}
		findings3.shrink_to_fit();
return findings3;
}
void Reservations::ReservationPrinter( vector<Reservation> & v){
	/*
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].bp.cp.length() ==0 || v[i].sp.np.length()==0)
		{
			v.erase(v.begin()+i);
		}
	}
	*/
	
	
	for (int i = 1; i <v.size() ; i++)
{
    for (int a = i; a > 0; a--)
    {
        if (v[a].dp < v[a-1].dp)
        {
			Reservation initial(v[a].dp,v[a].sp,v[a].bp);
			v[a] = v[a-1];
			v[a-1] =initial;

        }       
    }    
}
for (int i = 1; i < v.size(); i++)
{
    for (int a = i; a > 0; a--)
    {
        if (v[a].dp == v[a-1].dp)
        {
			if (v[a].sp.np < v[a-1].sp.np){

				Reservation initial(v[a].dp,v[a].sp,v[a].bp);
				v[a] = v[a-1];
				v[a-1] =initial;
			
			
			}
            
        }       
    }    
}




	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].bp.cp.length()!=0 && v[i].sp.np.length()!=0 && v[i].bp.np.length()!=0)
		{
			cout << v[i].dp << " -> "<< v[i].sp.np <<"("<< v[i].sp.ap <<","<<v[i].sp.rp << ")" <<" has reserved "<<v[i].bp.np<<"("<<v[i].bp.cp<<")"<<endl;
		}
		
	}



}
Sailor::Sailor(int id1, string name1, double age1, double rank1) {

			id = id1;
			ip=id1;
			name = name1;
			np=name1;
			age = age1;
			ap=age1;
			rank = rank1;
			rp=rank1;
}

Boat::Boat(int i, string n, string c){
	id = i;
	ip=i;
	name = n;
	np =n;
	color = c;
	cp=c;



}

Reservation::Reservation(Date resDate1, Sailor sailor1, Boat boat1){
		resDate=resDate1;
		dp=resDate1;
		sailor=sailor1;
		sp=sailor1;
		boat=boat1;
		bp=boat1;

}