#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <algorithm>
#include <cmath>
#include<cstring>
#include<stdio.h>
#include <sstream>

using namespace std;

struct seats{
	 string row; 
	 string TypeOfClass; 
	 string seats;
};

class Flight{
	private:
		struct details{
			string FlightNum; 
		    string DateTime; 
	    	string DAirport;
	    	string AAirport; 
	        vector<seats>seatList;
		};
		
	public:
		struct details flight;    //common struct
	    Flight(string a,string b,string c,string d,vector<seats> v){
	   	    flight.FlightNum=a;
	   	    flight.DateTime=b;
	   	    flight.DAirport=c;
	   	    flight.AAirport=d;
	   	    flight.seatList=v;  
	   }
	   void displayAvailableFlights();
	   int searchFlight(string data);
	   int searchNumberOfSeats(int data1,string data);	
	   int seatBooking(string FlightData,string rowData,string seatData);
	   void exit(ofstream &File);
		
		
};
vector<Flight>planes;

//displayAvailableFlights Flight class public function
void Flight::displayAvailableFlights(){
////	cout<<"YES"<<endl;
//	cout<<flight.FlightNum<<endl;
//	cout<<flight.DateTime<<endl;
//	cout<<flight.DAirport<<endl;
//	cout<<flight.AAirport<<endl;
	//seats
	int count=0;
	int Ecount=0;  //Total Number of E Class seats in Plane
	int Bcount=0;  //Total Number of B Class seats in Plane
	int count1=0;  //Number of E Class seats in row by row
	int count2=0;  //Number of B Class seats in row by row
	int i=0;
	while(i!=flight.seatList.size()){
  //       cout<<flight.seatList[i].row<<":"<<flight.seatList[i].TypeOfClass<<":"<<flight.seatList[i].seats<<endl;
           if(flight.seatList[i].TypeOfClass=="E"){
           	    int j=0;	           //10 E AB
		        while(flight.seatList[i].seats[j]!='\0'){
		 //       	cout<<flight.seatList[i].seats<<endl;
		        	if(flight.seatList[i].seats[j]!='0'&&flight.seatList[i].seats[j]!='O'){
		        	   count1++;
		        	   Ecount++;
					}
		   	        j++;

		        }
		   }
		   else if(flight.seatList[i].TypeOfClass=="B"){
           	    int j=0;	           //10 E AB
		        while(flight.seatList[i].seats[j]!='\0'&&flight.seatList[i].seats[j]!='O'){
		   	        count2++;
		   	        j++;
		   	        Bcount++;
		        }
		   }
//		   if(count1!=0||count2!=0){
//		   	  cout<<flight.seatList[i].row<<" Has "<<count1<<" Number of seats in Class E"<<endl;
//		      cout<<flight.seatList[i].row<<" Has "<<count2<<" Number of seats in Class B"<<endl;
//		   }
	
		   count1=0;
		   count2=0;
		   i++;
     } 
     count=Ecount+Bcount;
     //check seat is available
     if(count!=0){
   	   cout<<flight.FlightNum<<endl;
	   cout<<flight.DateTime<<endl;
	   cout<<flight.DAirport<<endl;
	   cout<<flight.AAirport<<endl;
	   //seats
	   int count=0;
	   int Ecount=0;  //Total Number of E Class seats in Plane
	   int Bcount=0;  //Total Number of B Class seats in Plane
	   int count1=0;  //Number of E Class seats in row by row
	   int count2=0;  //Number of B Class seats in row by row
	   int i=0;
	   while(i!=flight.seatList.size()){
           cout<<flight.seatList[i].row<<":"<<flight.seatList[i].TypeOfClass<<":"<<flight.seatList[i].seats<<endl;
           if(flight.seatList[i].TypeOfClass=="E"){
           	    int j=0;	           //10 E AB
		        while(flight.seatList[i].seats[j]!='\0'){
		 //       	cout<<flight.seatList[i].seats<<endl;
		        	if(flight.seatList[i].seats[j]!='0'&&flight.seatList[i].seats[j]!='O'){
		        	   count1++;
		        	   Ecount++;
					}
		   	        j++;

		        }
		   }
		   else if(flight.seatList[i].TypeOfClass=="B"){
           	    int j=0;	           //10 E AB
		        while(flight.seatList[i].seats[j]!='\0'&&flight.seatList[i].seats[j]!='O'){
		   	        count2++;
		   	        j++;
		   	        Bcount++;
		        }
		   }
		   if(count1!=0||count2!=0){
		   	  cout<<flight.seatList[i].row<<" Has "<<count1<<" Number of seats in Class E"<<endl;
		      cout<<flight.seatList[i].row<<" Has "<<count2<<" Number of seats in Class B"<<endl;
		   }
	
		   count1=0;
		   count2=0;
		   i++;
     }
	 }
	 
}

int Flight::searchFlight(string data){
	string data1;
	int data2=0;
	data1=flight.FlightNum;
	if(data1==data){
        displayAvailableFlights();
		data2=1;
	}
	return data2;

}

//Search given number of seats available in given Flight
int Flight::searchNumberOfSeats(int data1,string data){
	string data2;
	int data3=0;
	data2=flight.FlightNum;
	if(data2==data){
		//
		//seats
	   int Ecount=0;  //Total Number of E Class seats in Plane
	   int Bcount=0;  //Total Number of B Class seats in Plane
	   int count1=0;  //Number of E Class seats in row by row
	   int count2=0;  //Number of B Class seats in row by row
	   int i=0;
	   while(i<flight.seatList.size()){
            cout<<flight.seatList[i].row<<":"<<flight.seatList[i].TypeOfClass<<":"<<flight.seatList[i].seats<<endl;
            if(flight.seatList[i].TypeOfClass=="E"){
           	    int j=0;	           //10 E AB
		        while(flight.seatList[i].seats[j]!='\0'&&flight.seatList[i].seats[j]!='O'){
		   	        count1++;
		   	        j++;
		   	        Ecount++;
		        }
		   }
		   else if(flight.seatList[i].TypeOfClass=="B"){
           	    int j=0;	           //10 E AB
		        while(flight.seatList[i].seats[j]!='\0'&&flight.seatList[i].seats[j]!='O'){
		   	        count2++;
		   	        j++;
		   	        Bcount++;
		        }
		   }
		   if(count1!=0||count2!=0){
		   	  cout<<flight.seatList[i].row<<" Has "<<count1<<" Number of seats in Class E"<<endl;
		      cout<<flight.seatList[i].row<<" Has "<<count2<<" Number of seats in Class B"<<endl;
		   }
		   count1=0;
		   count2=0;
		   i++;
       } 
       int TotalSeats=Ecount+Bcount;
       if(data1<TotalSeats){
       	  cout<<"Your request,Seats available in this Flight:"<<endl;
	   }
	   else{
	   	  cout<<"Your request,Seats not available in this Flight"<<endl;
	   }
    data3=1;   
	}
  return data3;	
}

//class seat Booking
int Flight::seatBooking(string FlightData,string rowData,string seatData){
	string data2;
	int data3=0;
	data2=flight.FlightNum;
	int i=0;
	if(data2==FlightData){
	   while(i<flight.seatList.size()){
            if(flight.seatList[i].row==rowData){
           	    int j=0;            //10 E AB
            //    cout<<"1"<<endl;
		        while(flight.seatList[i].seats[j]!='\0'){
		        //     cout<<"2"<<endl;
		        //     cout<<flight.seatList[i].seats[j]<<endl;
		   	         if(flight.seatList[i].seats[j]==seatData[0]){
		   	         	  flight.seatList[i].seats[j]='O';
		   	         	//  cout<<flight.seatList[i].seats[j]<<endl;
		   	         	  data3=1;
		   	       //  	  break;
						}
				j++;	 			
		        }
	//	    cout<<flight.seatList[i].seats[0]<<endl;    
		    break;    
		   }
		   i++;  
	}
   }
   return data3;
}

//class exit
void Flight::exit(ofstream &file){
	file<<flight.FlightNum<<endl;
	file<<flight.DateTime<<endl;
	file<<flight.DAirport<<endl;
	file<<flight.AAirport<<endl;
	int i=0;
	while(i<flight.seatList.size()){
		file<<flight.seatList[i].row;
		file<<" ";
		file<<flight.seatList[i].TypeOfClass;
		file<<" ";
		file<<flight.seatList[i].seats<<endl;
		i++;
	}
	
	
}

//get data from file
void GetData(){
//	cout<<"2"<<endl;
	string line,FlightNum,DateTime,DAirport,AAirport;
	ifstream myfile ("flights.txt");
//	cout<<"3"<<endl;
    int i=0;
	if (myfile.is_open())
	{	
		while ( myfile.good() )
		{
		//	cout<<"4"<<endl;
			getline (myfile,line);
			FlightNum=line;
			getline (myfile,line);
			DateTime=line;
			getline (myfile,line);
			DAirport=line;
			getline (myfile,line);
			AAirport=line;
            vector<seats> details;//detect previous data from txt file
			while(!line.empty()){
			   getline (myfile,line);

               string arr[4];
               int i = 0;
               stringstream ssin(line);
               while (ssin.good() && i < 4){
                   ssin >> arr[i];
                   ++i;
                }
            struct seats s;
            s.row=arr[0];
            s.TypeOfClass=arr[1];
            s.seats=arr[2];
			
//			cout<<s.row<<s.TypeOfClass<<s.seats<<endl;			
		    details.push_back(s);
			}
		//	cout<<"5"<<endl;
			Flight newPlane(FlightNum,DateTime,DAirport,AAirport,details);
			planes.push_back(newPlane);			
		}
	//	cout<<"6"<<endl;
		myfile.close();
		
	}
	else 
	{
		cout << "Unable to open file"; 
	}
}

//DisplaAvailableFlights Function without class
void DisplayAvailableFlights(vector<Flight>planes){
//	cout<<"1"<<endl;
	int i=0;
	while(i!=planes.size()){
	//	cout<<"2"<<endl;
		planes[i].displayAvailableFlights();
		cout<<"\n";
		i++;
	}

}

//search Flight
void SearchFlight(string data,vector<Flight>planes){
	int data1=0;
	int i=0;
	while(i!=planes.size()){
		data1=planes[i].searchFlight(data);
		if(data1==1){
			break;
		}
		i++;
	}

	if(data1==1){
		cout<<"Flight is here:"<<endl;
	}
	else if(data1==0){
		cout<<"Error,Flight is Not here:"<<endl;
	}
}

//see seat is available
void SeatAvailable(string data,int numberOfSeats,vector<Flight>planes){
	int data1=0;
	for(int i=0;i<planes.size();i++){
		data1=planes[i].searchNumberOfSeats(numberOfSeats,data);
		if(data1==1){
			break;
		}
	} 
}

//seat Booking
void SeatBooking(string FlightData,string rowData,string seatData,vector<Flight>&planes){
	 int data=0;
	 int i=0;
	 while(i<planes.size()){
	 	data=planes[i].seatBooking(FlightData,rowData,seatData);
	 	if(data==1){
	 		break;
		 }
		i++;
//	 cout<<"1"<<endl;	
	 }
//	 cout<<data<<endl;
	 if(data==0){
	 	cout<<"You seat is not available:"<<endl;
	 }
}

void Exit(vector<Flight>planes){
	 ofstream outFile;
	 outFile.open("data.txt");
	 int i=0;
	 while(i<planes.size()){
	 	 planes[i].exit(outFile);
	 	 i++;
	 }
     outFile.close();
}

int main(){
	GetData();
	int choice=0;
	while(choice!=6){
		cout<<"\n\n===============================================MENU===============================================\n\n";
		cout<<"1. Display available flights\n"<<endl;
		cout<<"2. View flight \n"<<endl;
		cout<<"3. Seat availability \n"<<endl;
		cout<<"4. Seat booking \n"<<endl;
		cout<<"5. Exit \n"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				DisplayAvailableFlights(planes);
				break;
			}
			case 2:{
				string FlightNum;
				cout<<"Enter the Flight Number"<<endl;
				cin>>FlightNum;
				SearchFlight(FlightNum,planes);
				break;
			}
			case 3:{
				string FlightNum;
				int numberOfSeats;
				cout<<"Enter the Flight Number"<<endl;
				cin>>FlightNum;
				cout<<"Enter the number of Seats"<<endl;
				cin>>numberOfSeats;
				SeatAvailable(FlightNum,numberOfSeats,planes);
				break;
			}
			case 4:{
				string FlightNum,Row,seat;
				cout<<"Enter the Flight Number"<<endl;
				cin>>FlightNum;
				cout<<"Enter the Row"<<endl;
				cin>>Row;
				cout<<"Enter the seat"<<endl;
				cin>>seat;
				SeatBooking(FlightNum,Row,seat,planes);
				break;
			}
			case 5:{
				Exit(planes);
				choice=6;
				break;
			}
		}
	}
	cout<<"Thank you for using this System:"<<endl;	
}
