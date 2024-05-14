/*
	Concepts in the program
	
	=> concept of class and object
	=> encapsulation
	=> class inheritance
	=> Polymorphism
*/
#include <iostream> 
#include<limits>
#include<string> 
#include <fstream>	
#include <unistd.h> 
#include <iomanip>  
#include <ctime>	
using namespace std;

// base class
class Customer 
{
	protected:
		string customer_Name; 
	    int vehicle_model;
	    string vehicle_Number;
	    public:
	    	
	    	virtual void data()=0;
	    	virtual void invoiceAmount()=0;
	    	virtual void invoiceRecord()=0;
	    
};
class carrental : public Customer 
{
	int numberOfDays;
	int rental_Fee;
	char str[200];		
	public:	
		carrental();
		void fileReader(char carFile[20]);
		void data();
		void invoiceAmount();	 
		void invoiceRecord(); 		
};
carrental::carrental(){
	numberOfDays = 0;
	rental_Fee = 0;
}		
void carrental::fileReader(char carFile[200])
{
	ifstream inputFile;
	inputFile.open(carFile); 
	if(!inputFile){
		cout << "Error in printing file. File not found!" << endl;
	}
	while(inputFile) {
		inputFile.getline(str, 200);  
		if(inputFile) 
			cout << str << endl;
		}
}
		
void carrental::data(){
	system("CLS");
	cout << "\n\n\t\t\t\tPlease Enter your Name: "; 	
  	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,customer_Name);
	cout<<endl;
	do{
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\t\t\t\tChoose a Car from the options below. \n ";
	    cout <<	"\t\t\t\tChoose a number corresponding to the car you want to Select." << endl; 
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
		cout << "\t\t\t\t1. Toyota Innova 2019.Per Day cost=3000"<<endl;
	    cout << "\t\t\t\t2. Hyundai Verna 2019.Per Day Cost=1500"<<endl;
	    cout << "\t\t\t\t3. Ford EcoSport 2020.Per Day Cost=2000"<<endl;
	    cout << endl;
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\n\t\t\t\tChoose: ";
	    cin >> vehicle_model;
	    cout << endl;
	 			
	 	switch(vehicle_model){
	 		case 1:
	 			system("CLS");
	 			cout<<"You have choosed Toyota model 2021"<<endl;
	 			fileReader("ToyotaInnova.txt");
				sleep(2);
				break;
			case 2:
				system("CLS");
	  			cout<<"You have choosed Hyundai model 2019"<<endl;
				fileReader("HyundaiVerna.txt");
		     	sleep(2);
				break;	
			case 3:
		     	system("CLS");
		     	cout<<"You have choosed Ford model 2020"<<endl;
			    fileReader("FordEcosport.txt");
		     	sleep(2);
		   		break;  			
			default:
		     	cout<<"Invaild Car Model. Please try again!"<<endl;
		}
	}while(vehicle_model < 1 && vehicle_model > 3);
	
	cout<<"________________________________________________________________________________________________"<<endl;
  	cout << "Please provide following information:"<<endl; 
	cout<<"Please enter the car No. : ";
	cin >> vehicle_Number;
	cout<<"Number of days you wish to rent the car : ";
	cin >> numberOfDays;
	cout<<endl;
}

void carrental::invoiceAmount()
{
	
	system ("CLS");
	cout<<"Calculating rent. Please wait......"<<endl;
	sleep(1);
	if(vehicle_model == 1)
		rental_Fee = numberOfDays*3000;
	if(vehicle_model == 2)
		rental_Fee = numberOfDays*1500;
	if(vehicle_model == 3)
		rental_Fee = numberOfDays*2000;
}
	   
void carrental::invoiceRecord(){
	system("CLS");
	time_t now  = time(0);	 
	char *date = ctime(&now);
	cout << setw(80) << date << endl;
	cout << "\n\t\t                       Vehicle RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<"#1001"<<" |"<<endl;  
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<customer_Name<<" |"<<endl;
	cout << "\t\t	| Bike Model  "<<"					|"<< setw(10) <<vehicle_model<<" |"<<endl;
	cout << "\t\t	| Bike No.  "<<"					|"<< setw(10) <<vehicle_Number<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<numberOfDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rental_Fee<<" |"<<endl;
	cout << "\t\t	| Caution Money  "<<"				|"<< setw(10) <<"0"<<" |"<<endl;
	cout << "\t\t	| Advanced  "<<"					|"<< setw(10) <<"0"<<" |"<<endl;
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << rental_Fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signture."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	***********************************************************" << endl;

	system("PAUSE");
	system ("CLS");
	
}
class bikerental : public Customer
{
	int numberofDays;
	int rental_fee;
	char str2[200];
	public:
		bikerental();
		void fileReader(char bikeFile[20]);
		void data();
		void invoiceAmount();
		void invoiceRecord();
};
bikerental::bikerental()
{
	numberofDays=0;
	rental_fee=0;
}
void bikerental::fileReader(char bikeFile[20])
{
	ifstream inputFile;
	inputFile.open(bikeFile); 
	if(!inputFile){
		cout << "Error in printing file. File not found!" << endl;
	}
	while(inputFile)
	{
		inputFile.getline(str2, 200);  
		if(inputFile) 
			cout << str2 << endl;
	}
}
void bikerental::data()
{
	system("CLS");
	cout << "\n\n\t\t\t\tPlease Enter your Name: "; 	//taking data from the user
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,customer_Name);
	cout<<endl;
	do{
		
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\t\t\t\tChoose a bike from the options below. \n ";
	    cout <<	"\t\t\t\tChoose a number corresponding to the bike you want to Select." << endl; 
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
		cout << "\t\t\t\t1. Hero Splender 2019. Per Day cost=200"<<endl;
	    cout << "\t\t\t\t2. Bajaj Pulsar 2019. Per Day cost=400"<<endl;
	    cout << "\t\t\t\t3. Yamaha MT-07 2020. Per Day cost=1000"<<endl;
	    cout << endl;
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\n\t\t\t\tChoose: ";
	    cin >> vehicle_model;
	    cout << endl;
	 			
	 	switch(vehicle_model){
	 		case 1:
	 			system("CLS");
	 			cout<<"You have choosed Hero Splender 2019"<<endl;
	 			fileReader("herosplender.txt");
				sleep(2);
				break;
			case 2:
				system("CLS");
	  			cout<<"You have choosed Bajaj Pulsar 2019"<<endl;
				fileReader("bajajpulsar.txt");
		     	sleep(2);
				break;	
			case 3:
		     	system("CLS");
		     	cout<<"You have choosed Yamaha MT-07 2020"<<endl;
			    fileReader("yamahaMT.txt");
		     	sleep(2);
		   		break;  			
			default:
		     	cout<<"Invaild Bike Model. Please try again!"<<endl;
		}
	}while(vehicle_model < 1 && vehicle_model > 3);
	
	cout<<"________________________________________________________________________________________________"<<endl;
  	cout << "Please provide following information:"<<endl;
	cout<<"Please enter the Bike No. : ";
	cin >> vehicle_Number;
	cout<<"Number of days you wish to rent the bike : ";
	cin >> numberofDays;
	cout<<endl;
}
void bikerental::invoiceAmount()
{
	sleep(1);
	system ("CLS");
	cout<<"Calculating rent. Please wait......"<<endl;
	sleep(1);
	if(vehicle_model == 1)
		rental_fee = numberofDays*200;
	if(vehicle_model == 2)
		rental_fee = numberofDays*400;
	if(vehicle_model == 3)
		rental_fee = numberofDays*1000;
}
void bikerental::invoiceRecord()
{
	time_t now  = time(0);	 
	char *date = ctime(&now);
	system ("CLS");
	cout << setw(60) << date << endl;
	cout << "\n\t\t                       Vehicle RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<"#1001"<<" |"<<endl;  
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<customer_Name<<" |"<<endl;
	cout << "\t\t	| Bike Model  "<<"					|"<< setw(10) <<vehicle_model<<" |"<<endl;
	cout << "\t\t	| Bike No.  "<<"					|"<< setw(10) <<vehicle_Number<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<numberofDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rental_fee<<" |"<<endl;
	cout << "\t\t	| Caution Money  "<<"				|"<< setw(10) <<"0"<<" |"<<endl;
	cout << "\t\t	| Advanced  "<<"					|"<< setw(10) <<"0"<<" |"<<endl;
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << rental_fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signture."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	***********************************************************" << endl;

	system("PAUSE");
	system ("CLS");
	
}
int main()
{
	int choice;
	cout<<"\n\n\n\n\t\t\tWelcome!\n";
	cout<<"\t\t\tWhat type of vehicle You need\n\t\t\tEnter 1 for Car and 2 for bike:";
	cin>>choice;
	Customer *c;
	if(choice==1)
	{
		carrental crent;	 
		c=&crent;
		c->data();
		c->invoiceAmount();
		c->invoiceRecord();
	}
	else if(choice==2)
	{
		bikerental brent;	
		c=&brent;
		c->data();
		c->invoiceAmount();
		c->invoiceRecord();
	}
	else
	{
		cout<<"Wrong Input";
	}
	return 0;
}

