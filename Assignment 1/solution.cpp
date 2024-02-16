#include <iostream>
#include <string>

using namespace std;


void getInput(string name,double & lungrep, double & lungmin, double & pushrep,double & pushmin,double & pullrep,double & pullmin,double & liftrep,double & liftmin,double & liftweight) {

	cout << "Lunges: ";
	cin >> lungmin >> lungrep;
	cout << "Push Ups: ";
	cin >> pushmin>> pushrep;
	cout << "Pull Ups: ";
	cin >> pullmin >> pullrep;
	cout << name << ", please enter minutes, repetitions and lifted weight in a week for the activities below." << endl;
	cout << "Weight Lifting: ";
	cin >> liftmin >> liftrep >> liftweight;

}

bool inputCheck(double weight,double liftweight,double lungrep, double  lungmin, double  pushrep,double pushmin,double  pullrep,double  pullmin,double  liftrep,double  liftmin) {
	if (weight < 30)
	{
		cout << "Weight out of range!" << endl;
		return false;
	}
	else if (liftweight <= 0 || liftweight > 35 )
	{
		cout << "Lifted weight out of range!" << endl;
		return false;
	}
	else if (lungrep <0 || pushrep <0 || pullrep<0  || liftrep<0 || pushrep >50 || pullrep>50 || liftrep>50 || lungrep>50)
	{
		cout << "Reps out of range!" << endl;
		return false;
	}
	else if (lungmin <0||pushmin<0 ||pullmin<0 ||liftmin <0|| lungmin> 2000|| pushmin> 2000|| pullmin> 2000 ||liftmin> 2000)
	{
		cout << "Minute out of range!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

void calculateMET(double & lungmet,double & pushmet,double & pullmet , double lungrep,double pushrep,double pullrep) {
	if (lungrep < 15)
	{
		lungmet = 3;
	}
	if (lungrep >= 15 && lungrep <30)
	{
		lungmet = 6.5;
	}
	if (lungrep >=30)
	{
		lungmet = 10.5;
	}
	if (pushrep < 15)
	{
		pushmet = 4;
	}
	if (pushrep >= 15)
	{
		pushmet = 7.5;
	} 
	if (pullrep<25)
	{
		pullmet = 5;
	}
	if (pullrep>=25)
	{
		pullmet =9;
	}
	
}

void calculateWeightLiftMET(double & liftmet, double liftrep,double liftweight) {
	if (liftweight <5 && liftrep < 20)
	{
		liftmet = 3;
	}
	if (liftweight < 5 && (liftrep >= 20 && liftrep <40))
	{
		liftmet = 5.5;
	}
	if (liftweight<5 && liftrep >= 40)
	{
		liftmet = 10;
	}
	if ((liftweight >=5 && liftweight < 15) && liftrep < 20)
	{
		liftmet = 4;
	}
	if ((liftweight >=5 && liftweight < 15) && (liftrep>=20 && liftrep <40))
	{
		liftmet = 7.5;
	}
	if ((liftweight >=5 && liftweight < 15) && liftrep >= 40)
	{
		liftmet = 12;
	}
	if (liftweight>=15 && liftrep < 20)
	{
		liftmet = 5;
	}
	if (liftweight>=15 &&  (liftrep>=20 && liftrep <40))
	{
		liftmet = 9;
	}
	if (liftweight>=15 &&  liftrep>=40)
	{
		liftmet = 13.5;
	}

}
void displayResults(double burngoal, double difference, double total, double weight, double lungmet, double pushmet,double pullmet, double liftmet,double lungcalories, double pushcalories, double  pullcalories, double liftcalories ){
	if (burngoal == total)
	{
		cout << "From lunges, you burned " << lungcalories << " calories." <<endl;
		cout << "From push ups, you burned " << pushcalories << " calories." <<endl;
		cout << "From pull ups, you burned " << pullcalories << " calories." <<endl;
		cout << "From weight lifting, you burned " << liftcalories <<" calories." << endl;
		cout << "You burned " << total << " calories." << endl;
		cout << endl;
		cout << "Congratulations! You have reached your goal!" << endl;
	}
	else if (total > burngoal)
	{
		cout << "From lunges, you burned " << lungcalories << " calories." <<endl;
		cout << "From push ups, you burned " << pushcalories << " calories." <<endl;
		cout << "From pull ups, you burned " << pullcalories << " calories." <<endl;
		cout << "From weight lifting, you burned " << liftcalories <<" calories." << endl;
		cout << "You burned " << total << " calories." << endl;
		cout << endl;
		cout << "You have surpassed your goal! You can eat something worth " << -1*difference << " calories :)"<< endl;
	}
	else
	{
		cout << "From lunges, you burned " << lungcalories << " calories." <<endl;
		cout << "From push ups, you burned " << pushcalories << " calories." <<endl;
		cout << "From pull ups, you burned " << pullcalories << " calories." <<endl;
		cout << "From weight lifting, you burned " << liftcalories <<" calories." << endl;
		cout << "You burned " << total << " calories." << endl;
		cout << endl;
		cout << "You did not reach your goal by " << difference << " calories." << endl; 
		cout << "You need to do lunges " << 200*difference/(lungmet*weight*3.5) << " minutes more to reach your goal or," << endl; 
		cout << "You need to do push ups " << 200*difference/(pushmet*weight*3.5)<< " minutes more to reach your goal or," << endl; 
		cout << "You need to do pull ups "<< 200*difference/(pullmet*weight*3.5)<< " minutes more to reach your goal or," << endl; 
		cout <<"You need to do weight lifting "<< 200*difference/(liftmet*weight*3.5)<< " minutes more to reach your goal." << endl; 
	}


}
void computeResults(double weight,double lungmet,double pushmet,double  pullmet,double lungrep,double pushrep,double pullrep,double liftmet,double liftrep,double liftweight,double burngoal,double pullmin,double pushmin,double liftmin,double lungmin) {
		calculateMET(lungmet,pushmet,pullmet,lungrep,pushrep,pullrep);
		calculateWeightLiftMET(liftmet,liftrep,liftweight);
		double lungcalories,pushcalories,pullcalories,liftcalories;
		lungcalories = lungmin*(weight*lungmet*3.5)/200;
		pushcalories = pushmin*(weight*pushmet*3.5)/200;
		pullcalories = pullmin*(weight*pullmet*3.5)/200;
		liftcalories = liftmin*(weight*liftmet*3.5)/200;
		double total = lungcalories + pushcalories + pullcalories + liftcalories;
		double difference = burngoal - total;
		displayResults(burngoal, difference,  total,  weight,  lungmet,  pushmet, pullmet,  liftmet, lungcalories,  pushcalories,   pullcalories,  liftcalories );





}

int main() {

	string name;
	double weight;
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Welcome " << name << ", please enter your weight(kg): ";
	cin >> weight;
	cout << name << ", please enter minutes and repetitions in a week for the activities below." << endl;
	double lungrep,lungmin,pushrep,pushmin,pullrep,pullmin,liftrep,liftmin,liftweight;
	getInput(name,lungrep,  lungmin, pushrep, pushmin, pullrep, pullmin, liftrep, liftmin, liftweight);
	cout << name << ", please enter your weekly calorie burn goal: ";
	double burngoal;
	cin >> burngoal;
	bool inputcheckresult =inputCheck(weight,liftweight, lungrep,   lungmin,   pushrep, pushmin,  pullrep,  pullmin,  liftrep,  liftmin);
	if (inputcheckresult)
	{
		double lungmet,pushmet,pullmet,liftmet;
		lungmet= 0;
		liftmet= 0;
		pushmet= 0;
		pullmet = 0;
		computeResults( weight, lungmet, pushmet,  pullmet, lungrep, pushrep, pullrep, liftmet, liftrep, liftweight, burngoal,pullmin, pushmin, liftmin,lungmin);

	}









	return 0;
}