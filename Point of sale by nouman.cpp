// User name is 7
// Passowrd is 1
#include <iostream> //for input output functions ..
#include <fstream>  // for file handling ..
#include <string>   // for string constant...
#include <iomanip>  // for setw() function....

using namespace std;

class mainclass{
public:

//MAIN MENU........
void mainfun()
{
	
	/* 
	Main Menu of my project..
	lets go....
	*/ 
cout<<"~~~~~~~~~~~~~~~~~~~~~Welcome to Point of sale~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
cout<<setw(45)<<"*****Main Menu*****\n\n";      
cout<<setw(45)<<" 1 -  Manage Items  \n\n";
cout<<setw(49)<<" 2 -  Manage Customers  \n\n";
cout<<setw(46)<<" 3 -  Make New Sale  \n\n";
cout<<setw(45)<<" 4 -  Make Payment  \n\n";
cout<<setw(46)<<" 5 -  Print Reports  \n\n";
cout<<setw(37)<<" 6 -  Exit  \n\n";
cout<<setw(50)<<"Enter a number from 1 and 6 = "; // in main class cursur is stop for input...
 }


};
//ITEM CLASS MENU.......
class itemclass{
/*
Item class is used for maintaining the item
of products of market.... 
*/
public:
	void itemfun(){
	cout<<"\n\n1- Add new Item  \n\n";  
	cout<<"2- Update Item details  \n\n";
	cout<<"3- Find Items  \n\n";
	cout<<"4- Remove Existing Item  \n\n";
	cout<<"5- Back to Main Menu  \n\n";
	cout<<"Enter a number from 1 and 5 = "; // Again cursur is stop for user input ...



}
//NEW ITEM MEMBER FUNCTION OF ITEM CLASS....
void newitem()
{
long price,qun,id;
string name,date;
ifstream fin("itemid.txt");
int value=0;

if(!fin)
{
fin.close();
ofstream fout("itemid.txt");
fout<<0;
fout.close();
fin.open("itemid.txt");
}
fin>>value;
fin.close();
ofstream fout("itemid.txt");

fout<<value+1;
fout.close();

id = value+1;

 	cout<<"\nNew item id is = ";
    cout<<id;
    cout<<"\nEnter date in the formate of dd/month/year = ";
    cin>>date;
   	cout<<"\nEnter new item name = ";
    cin>>name;
    cout<<"\nEnter new item price = ";
    cin>>price;
    cout<<"\nEnter new item quantity = ";
    cin>>qun;

    cout<<"\nDo you want to save the information on the file press Y/N "; //system ask for saving data on file...
char press;
	cin>>press;
    switch(press){         //if you press y it means yes and data is saved on file....
    case 'y':
{
		
        ofstream fout;
        fout.open("Item.txt",ios::app ); //file is open in append mode its mean info is modify...
        fout<<"\n\n*********Details of Existed items********** ";
        fout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	fout<<"   1\tHP system\t20000\t300 ";
    	fout<<"\n2-ID \tName\t\tPrice\tQuantity \n\n";
    	fout<<"   2\tDell system\t25000\t250 ";
		fout<<"\n3-ID \tName\t\tPrice\tQuantity \n\n";
    	fout<<"   3\tLenovo system\t30000\t240 ";
		fout<<"\n4-ID \tName\t\tPrice\tQuantity \n\n";
    	fout<<"   4\tAcer system\t35000\t400 ";
		fout<<"\n\n********Details of New items************";
		fout<<"\n\nToday date is  \n"<<date;
		fout<<"\n\n1-ID \tName\t\tPrice\tQuantity \n\n";
		fout<<"   "<<id<<"\t"<<name<<"\t\t"<<price<<"\t"<<qun  ;
        cout<<"\n\n\nYour information is saved successfully\n\n ";
    break;
    }
    default :{
        cout<<"\n\a\a\a Alert your information is not saved ....\n\n";  //in default if you enter n than system produce alert beep... 
    }
    }


};

//UPDATE ITEM MEMBER FUNCTION OD ITEM CLASS.......
void updateitem()
{
    	int id;
    	cout<<"\nEnter id of item from 1 to 4 = ";  //user enter one to four id number...
    	cin>>id;
    /*
    i use switch case because it is simple
    to code as compare to if else..
    */
    	switch(id){//first switch..
    	case 1:
    	cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	cout<<"   1\tHP system\t20000\t300 ";
    	break;
    	case 2:
    	cout<<"\n2-ID \tName\t\tPrice\tQuantity \n\n";
    	cout<<"   2\tDell system\t25000\t250 ";
    	break;
    	case 3:
    	cout<<"\n3-ID \tName\t\tPrice\tQuantity \n\n";
    	cout<<"   3\tLenovo system\t30000\t240 ";
    	break;
   		 case 4:
   		 cout<<"\n4-ID \tName\t\tPrice\tQuantity \n\n";
    	cout<<"   4\tAcer system\t35000\t400 ";
    	break;
    	default:
    	cout<<"\nItem of that id is not exist";
    	}//first switch close...
    	
    	cout<<"\n\nDO you want to modify press Y/N = ";  //system ask for modification ...
    	char press;
    	cin>>press;
    	string date;
    	int price,qun;
    	switch(press){//2nd switch
    	case 'y':
    	cout<<"\nEnter the details  item which you want to modify... ";
    	cout<<"\n\nEnter date = ";
    	cin>>date;
    	cout<<"\nEnter id = ";
    	cin>>id;
    	cout<<"\nEnter price = ";
    	cin>>price;
    	cout<<"\nEnter quntity = ";
    	cin>>qun;
    	cout<<"\n\nModification succesfully thanks ....\n\n"; //system show a massage of succesfully modification.... 
    	break;
    	default:
        cout<<"\n\n\a\a\aLeave out.... \n";
        }//2nd switch close..
        
        cout<<"\n\nDo you want to save information on file Y/N= "; //Here system ask for save information on file .... 
        char push;
        cin>>push;
        switch(push)
        {//complete file handling...
        case 'y' :{
        ofstream fout;
        fout.open("Item.txt ",ios::app);
        fout<<"\n\n********Modifying items Details************";
        switch(id){
    	case 1:
    	fout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	fout<<"   "<<id<<"\tHP system\t"<<price<<"\t"<<qun;
    	break;
    	case 2:
    	fout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	fout<<"   "<<id<<"\tDell system\t"<<price<<"\t"<<qun;
    	break;
    	case 3:
        fout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	fout<<"   "<<id<<"\tlenovo system\t"<<price<<"\t"<<qun;
    	break;
   		case 4:
   		fout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	fout<<"   "<<id<<"\tAcer system\t"<<price<<"\t"<<qun;
    	break;
    	default:
    	cout<<"\nItem of that id is not exist";
    	}
			if(id==1){
			
			cout<<"\n\nDetails of item After modification  ";
			cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	    cout<<"   "<<id<<"\tHP system\t"<<price<<"\t"<<qun;
    		}
		else if(id==2)
		{
			cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	cout<<"   "<<id<<"\tDell system\t"<<price<<"\t"<<qun;
		}
		
		else if(id==3)
		{
			cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n"; 
			cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	cout<<"   "<<id<<"\tLenovo system\t"<<price<<"\t"<<qun;
		}
		
		else if(id==4)
		{
					cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n"; 
			cout<<"\n1-ID \tName\t\tPrice\tQuantity \n\n";    
    	cout<<"   "<<id<<"\tAcer system\t"<<price<<"\t"<<qun;
		}
		}
        default :
        {

        cout<<"\n\n\a\a\a Alert information is not saved ";
         }
        }

}


//FIND ITEM MEMBER FUNCTION OF ITEM CLASS..........
void finditem()
{
    long id,price,qun;
    string name;
    /*
    Systen ask to enter details of item
    which he /she want to find ..
    */
		cout<<"\n\nEnter information to find item...  ";
		cout<<"\n\nEnter id = ";
		cin>>id;
		cout<<"\n\nEnter name of item = ";
		cin>>name;
		cout<<"\n\nEnter price of item = ";
		cin>>price;
		cout<<"\n\nEnter quantity = ";
		cin>>qun;
//After gating info system check for item ...
if(id==1 && name == "hp" && price ==20000 && qun==300)
{
   		cout<<"\n\nItem is finded";

    	cout<<"\n1-ID \tName\t\tPrice\tQuantity \n";

    	cout<<"   1\tHP system\t20000\t300 ";}
else if(id==2 && name == "dell" && price == 25000 && qun == 250)
   {
       cout<<"\n\nItem is finded";

       cout<<"\n2-ID \tName\t\tPrice\tQuantity \n";

       cout<<"   2\tDell system\t25000\t250 ";}
else if(id == 3 && name=="lenovo" && price == 30000 && qun == 240)
    {
        cout<<"\n\nItem is finded";

        cout<<"\n3-ID \tName\t\tPrice\tQuantity \n";

        cout<<"   3\tLenovo system\t30000\t240 ";}
else if(id == 4 && name=="acer" && price == 35000 && qun == 400)
    {
        cout<<"\n\nItem is finded";

        cout<<"\n4-ID \tName\t\tPrice\tQuantity \n";

        cout<<"   4\tAcer system\t35000\t400 ";}
else {													//if system not find item than it show all item ....

        cout<<"\n\n\a\a\aPlease enter correct information "; 

        cout<<"\n\n1-ID \tName\t\tPrice\tQuantity \n";

        cout<<"   1\tHP system\t20000\t300 ";

        cout<<"\n\n   2\tDell system\t25000\t250 ";

        cout<<"\n\n   3\tLenovo system\t30000\t240 ";

        cout<<"\n\n   4\tAcer system\t35000\t400 ";

    }
}


//REMOVE ITEM MEMBER FUNCTION OF ITEM CLASS..........
void removeitem()
{
    int id,con;
		cout<<"\n\nEnter the id of item Which you want to remove = "; //system ask for enter id of item which he wants to remove ...
		cin>>id;
		cout<<"\n\nConfirm id = ";  //And than confirm id ....
		cin>>con;
if(id==1 && con == 1)
{
    cout<<"\n\nItem is removed successfully ";   //Massage of removing Successfully....
    cout<<"\nDetails of item after removing ";  //And than show information after removing item ....

        cout<<"\n1-ID \tName\t\tPrice\tQuantity ";

        cout<<"\n\n   2\tDell system\t25000\t250 ";

        cout<<"\n\n   3\tLenovo system\t30000\t240 ";

        cout<<"\n\n   4\tAcer system\t35000\t400 ";

}
else if(id == 2 && con == 2)
{
    cout<<"\n\nItem is removed successfully ";  //Massage of removing Successfully....
    cout<<"\nDetails of item after removig ";  //And than show information after removing item ....

        cout<<"\n1-ID \tName\t\tPrice\tQuantity ";

        cout<<"\n\n   1\tHP system\t20000\t300 ";

        cout<<"\n\n   3\tLenovo system\t30000\t240 ";

        cout<<"\n\n   4\tAcer system\t35000\t400 ";

}
else if(id == 3 && con == 3)
{
    cout<<"\n\nItem is removed successfully ";  //Massage of removing Successfully...
    cout<<"\nDetails of item after removig ";  //And than show information after removing item ....

        cout<<"\n1-ID \tName\t\tPrice\tQuantity ";

        cout<<"\n\n   1\tHP system\t20000\t300 ";

        cout<<"\n\n   2\tDell system\t25000\t250 ";

        cout<<"\n\n   4\tAcer system\t35000\t400 ";

}
else if(id == 4 && con == 4)
{
    cout<<"\n\nItem is removed successfully ";  //Massage of removing Successfully...
    cout<<"\nDetails of item after removig ";  //And than show information after removing item ....

        cout<<"\n1-ID \tName\t\tPrice\tQuantity \n";

        cout<<"\n\n   1 \tHP system\t20000\t300 ";

        cout<<"\n\n   2\tDell system\t25000\t250 ";

        cout<<"\n\n   3\tLenovo system\t30000\t240 ";


}//closing of else if statements
} //closing of remove function ...

};  //And at the end closing of item class....




//CUSTOMER CLASS .....
class customerclass{
public:
void customerfun(){       //This is the menu function of customer class ... 
cout<<"\n\n 1 -  Add new Customer \n\n";
cout<<" 2 -  Update Customer details \n\n";
cout<<" 3 -  Find Customer \n\n";
cout<<" 4 -  Remove Existing Customer \n\n";
cout<<" 5 -  Back to Main Menu \n\n";
cout<<"Enter a number from 1 and 5 = ";


    }

//ADD CUSTOMER MEMBER FUNCTION OF CUSTOMER CLASS.....
void addcustomer()
{
	string id,phone,name,address,email,date;
	long   salelimit;
	cout<<"\n\nEnter the following information ";  //system ask user to enter details of costumer ...
	cout<<"\n\nEnter date = ";
	cin>>date;
	cout<<"Enter Id = ";
	cin>>id;
	cout<<"\n\nEnter your name = ";
	cin>>name;
	cout<<"\n\nEnter your address = ";
	cin>>address;
	cout<<"\n\nEnter your Email = ";
	cin>>email;
	cout<<"\n\nEnter your phone no = ";
	cin>>phone;
	cout<<"\n\nEnter your sale limit = ";
	cin>>salelimit;
	cout<<"\n\nDo you want to save the following inforamtion Y/N = "; //System ask user to save data on file .

char press;
cin>>press;  //if press is y than  its mean yes
if(press=='y'){
ofstream fout;
fout.open("customer.txt" ,ios ::app);     //saving data on file ...
fout<<"\n\n**************New customer***************";
fout<<"\n\nToday date is = "<<date;
fout<<"\n\nID\tname\tAddress\t\tEmail\t\tPhone no\t\tSale limit ";
fout<<"\n\n"<<id<<"\t"<<name<<"\t"<<address<<"\t"<<email<<"\t"<<phone<<"\t\t"<<salelimit;

cout<<"\n\nyour information is successfully saved...";
}
else{
    cout<<"\a\a\a\a Alert your information is not saved ..."; //otherwise Alert is show ...

}

}

//UPDATE CUSTOMER MEMBER FUNCTION OF CUSTOMER CLASS.....
void updatecustomer()
{
    int id;
cout<<"\n\nEnter details of customer  "; 
cout<<"\n\nEnter customer id = ";	//system ask for enter id of customer for modification....
cin>>id;
if(id==1){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";  //customer one..
}
else if(id==2){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";			//customer two..	
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
}
else if(id==3){
     cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";           //customer three..
    cout<<"\n\n3\t3\tWaqar\tIslamabad\twaqar121@gmail.com\t0312-9375704";

    }
else if(id==4)
{
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";           //customer four..
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}
else {
    cout<<"\n\nCustomer not found ";
}
cout<<"\n\nDo you want to modify customer details Y/N";     //system ask for modification ....
char press;
cin>>press;
if(press=='y')
 {

    cout<<"\n\nEnter details of customer to update information  ";
    string phone,name,address,email,date;

    cout<<"\n\nEnter the following information ";       //And than enter modify values ....
    cout<<"\n\nEnter date = ";
    cin>>date;
    cout<<"\n\nEnter your name = ";
    cin>>name;
    cout<<"\n\nEnter your address = ";
    cin>>address;
    cout<<"\n\nEnter your Email = ";
    cin>>email;
    cout<<"\n\nEnter your phone no = ";
    cin>>phone;
        cout<<"\n\nDo you want to save information on file Y/N = "; //Ask for saving data on file ...
char push;
cin>>push;
if(push=='y')
{
    ofstream fout; 
    fout.open("customer.txt",ios::app);         //saving data on file ....
 	switch(id)
 	{
	 case 1:
	 	fout<<"**********Upadate customer***********";
	 	 fout<<"\n\nID\tname\tAddress\t\tEmail\t\tPhone no ";
    	 fout<<"\n\n\t1"<<name<<"\t"<<address<<"\t"<<email<<"\t"<<phone;
    	 cout<<"\n\ninformation is saved ....";
	 break;
	  case 2:
	    fout<<"**********Upadate customer***********";
		 fout<<"\n\nID\tname\tAddress\t\tEmail\t\tPhone no ";
    	 fout<<"\n\n\t2"<<name<<"\t"<<address<<"\t"<<email<<"\t"<<phone;
    	 cout<<"\n\ninformation is saved ....";
		  break;
    	  case 3:
    	  	fout<<"**********Upadate customer***********";
		  fout<<"\n\nID\tname\tAddress\t\tEmail\t\tPhone no ";
    	 fout<<"\n\n\t3"<<name<<"\t"<<address<<"\t"<<email<<"\t"<<phone;
    	  cout<<"\n\ninformation is saved ....";
		 break;
		  case 4:
		  	fout<<"**********Upadate customer***********";
		  fout<<"\n\nID\tname\tAddress\t\tEmail\t\tPhone no ";
    	 fout<<"\n\n\t4"<<name<<"\t"<<address<<"\t"<<email<<"\t"<<phone;
	  cout<<"\n\ninformation is saved ....";
	 break;
	 
	 
	 }

}
else {
    cout<<"\n\a\a\aAlert information is not saved on file....";   //Alert on not saving information...
}

}
    else
{

   cout<<"\a\aOk customer details is not update ";  
}


}


//FIND CUSTOMER MEMBER FUNCTION OF CUSTOMER CLASS.....
void findcustomer()
{
//System ask user to enter customer id ,name ,email ,phone to find it....
cout<<"\n\nPlease specify atleast one of the following to find the customer.";
cout<<"\n\n1-Customer ID:";
cout<<"\n\n2-Name:";
cout<<"\n\n3-Email:";
cout<<"\n\n4-Phone:";
string name,email,phone;
int id;
cout<<"\n\npress 1 to 4 key "; //choose one....
int key;
cin>>key;
if(key==1) //if user press 1 then...
{

    cout<<"\n\nEnter customer ID = "; //system ask to enter id....
    cin>>id;
    if(id==1){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
}
else if(id==2){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
}
else if(id==3){
     cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n3\t3\tWaqar\tIslamabad\twaqar121@gmail.com\t0312-9375704";

    }
else if(id==4)
{
        cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}
else {
    cout<<"\n\n\a\a\aCustomer not found.... "; //if id is not match then this condition is apply...
}
}

else if(key==2)//if user press 2 then...
{
   cout<<"Enter customer Name = ";//system ask to enter name....

   cin>>name;
           if(name=="Nouman"){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
}
else if(name=="Arslan"){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
}
else if(name=="Waqar"){
     cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n3\t3\tWaqar\tIslamabad\twaqar121@gmail.com\t0312-9375704";

    }
else if(name=="shahid")
{
        cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}
else {
    cout<<"\n\n\a\a\aCustomer not found... ";//if Name is not match then this condition is apply...
}


}
else if(key==3)//if user enter 3 then
{


    cout<<"Enter Email of Customer = ";//system ask user to enter customer email....

   cin>>email;
           if(email=="nomibaloch775@gmail.com"){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
}
else if(email=="arslan745@gmail.com"){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
}
else if(email=="waqar121@gmail.com"){
     cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n3\t3\tWaqar\tIslamabad\twaqar121@gmail.com\t0312-9375704";

    }
else if(email=="shahid141@gmail.com")
{
        cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}
else {
    cout<<"\n\n\a\a\aCustomer not found.... ";//if email is not match then this condition is apply...
}




}
else if(key==4)//if user press 4 then...
{

     cout<<"Enter phone no of customer = "; //system ask user to enter phone no...

   cin>>phone;
           if(phone=="0302-9572806"){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
}
else if(phone=="0344-9774816"){
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
}
else if(phone=="0312-9375704"){
     cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n3\t3\tWaqar\tIslamabad\twaqar121@gmail.com\t0312-9375704";

    }
else if(phone=="0314-1542755")
{
        cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}
else {
    cout<<"\n\n\a\a\aCustomer not found ";//if Number is not match then this condition is apply...
}



}
else {
    cout<<"\a\a\a\n\nAlert please enter valid entry ... "; //else system generate error.......
}


}//end of function...........


 //REMOVE CUSTOMER MEMBER FUNCTION OF CUSTOMER CLASS.....
void removecustomer()
{
int id,con;
cout<<"\n\nPlease enter the id of customer to remove = ";//system ask user to enter id of customer to remove....
cin>>id;
cout<<"\n\nconfirm id = "; //confirmetion....
cin>>con;

if(id==1 && con == 1)// cheacking condition 
{

    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
    cout<<"\n\n3\t3\tWaqar\tIslamabad  waqar121@gmail.com\t0312-9375704";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}
else if(id==2 && con ==2) //cheacking conditon...
{


    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
    cout<<"\n\n3\t3\tWaqar\tIslamabad  waqar121@gmail.com\t0312-9375704";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";
}

else if(id==3 && con == 3)//cheacking conditon.....
{


    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755";


}
 else if(id==4 && con == 4)//cheacking condition....
 {


    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816";
   cout<<"\n\n3\t3\tWaqar\tIslamabad  waqar121@gmail.com\t0312-9375704";
 }
 else
{

    cout<<"\a\a\a\n\n Sorry customer not found ...";//if conditon is not apply than system generate error....

}
}//End of function.....


};//End of class
class saleclass // sale class...
{   
public:     
void salefun(){       //main menu fuction of sale class..
cout<<"\n\n 1 - Make new sale \n\n";
cout<<" 2 - Main menu \n\n";
cout<<"Enter a number from 1 and 2 = "; //system ask user for choice ...
}

void makenewsale()  //if choice is one then this fuction is called...
{
long i, id,itemid,qun,sub;
string date;
do{                 //i use do while loop for this funtion because it repeat 4 time...

//Enter Details...
cout<<"\n\nEnter date = ";
cin>>date;
cout<<"\n\nEnter customer id = ";
cin>>id;
cout<<"\n\nPlease add for this sale ";
cout<<"\n\nEnter item id = ";
cin>>itemid;


if(itemid == 1 )
{

//if user enter 1 item id then this interface is open....
    cout<<"\n\nItem is finded";

    cout<<"\n\nItem id is "<<itemid;

    cout<<"\n\n1-ID \tName\t\tPrice ";

    cout<<"\n\n   1\tHP system\t20000 ";

    cout<<"\n\nEnter quantity of item = ";

    cin>>qun;

    sub=20000*qun;  //for total price multiply quantity with the price of item....

    cout<<"\n\nSub price of item is = "<<sub;
}
else if(itemid == 2) 
{
//if user enter 2  item id then this interface is open...


       cout<<"\n\nItem is finded";

       cout<<"\n\nItem id is "<<itemid;

       cout<<"\n\n2-ID \tName\t\tPrice ";

       cout<<"\n\n   2\tDell system\t25000 ";

       cout<<"\n\nEnter quantity of item = ";

       cin>>qun;

       sub=25000*qun;// Agiain multiply quantity with price of item...

       cout<<"\nSub price of item is = "<<sub;

       }
else if(itemid == 3 )
{
//if user enter 3  item id then this interface is open...

        cout<<"\n\nItem is finded";

        cout<<"\n\nItem id is "<<itemid;

        cout<<"\n\n3-ID \tName\t\tPrice ";

        cout<<"\n\n   3\tLenovo system\t30000 ";

        cout<<"\n\nEnter quantity of item = ";
        
        cin>>qun;

        sub=30000*qun;        // Agiain multiply quantity with price of item...

        cout<<"\nSub price of item is = "<<sub;
        }
else if(itemid == 4 )
{
	//if user enter 4  item id then this interface is open...


        cout<<"\n\nItem is finded";

        cout<<"\n\nItem id is "<<itemid;

        cout<<"\n\n4-ID \tName\t\tPrice ";

        cout<<"\n\n   4\tAcer system\t35000 ";

        cout<<"\n\nEnter quantity of item = ";

        cin>>qun;

        sub=35000*qun;// Agiain multiply quantity with price of item...

        cout<<"\nSub price of item is = "<<sub;
        }
        
        
else {
    cout<<"\n\n\a\a\a\a\aWrong entry Item is not founded ....";//Alert item not found...
}
cout<<"\nDo you want to make new sale or end sale Y/N ";
/*user ask for make new sale or end sale...
if press y than do while loop is again start for top
and again same process..
*/
char key;  

cin>>key;

if(key=='y')
{

}
else
{
	
    break;//else break the loop and go down ...
}
}while(i<=4);

/*In lower all conditions system cheacked customer id and itme id
and show report
*/
if(id==1 && itemid == 1){

cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Nouman\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Hp system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==1 && itemid==2){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Nouman\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Dell system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==1 && itemid==3){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Nouman\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Lenovo system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==1 && itemid==4){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Nouman\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Acer system"<<"\t\t"<<qun<<"\t\t"<<sub;

}

else if(id==2 && itemid == 1){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Arslan\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Hp system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==2 && itemid==2){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Arslan\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Dell system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==2 && itemid==3){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Arslan\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Lenovo system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==2 && itemid==4){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Arslan\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Acer system"<<"\t\t"<<qun<<"\t\t"<<sub;

}

else if(id==3 && itemid == 1){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Waqar\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Hp system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==3 && itemid==2){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Waqar\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Dell system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==3 && itemid==3){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Waqar\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Lenovo system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==3 && itemid==4){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Waqar\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Acer system"<<"\t\t"<<qun<<"\t\t"<<sub;

}


else if(id==4 && itemid == 1){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Shahid\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Hp system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==4 && itemid==2){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Shahid\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Dell system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==4 && itemid==3){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Shahid\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Lenovo system"<<"\t\t"<<qun<<"\t\t"<<sub;

}
else if(id==4 && itemid==4){
cout<<"\nsale id is =  "<<itemid<<"\t\t\t\t"<<"customer id is = "<<id<<"\n\n";
cout<<"Today date is = "<<date<<"\t\t\t"<<"customer name is = "<<"Shahid\n\n";
cout<<"Item id is \tItem name\t"<<"item qunatity\t"<<"item price \n\n";
cout<<itemid<<"\t\t"<<"Acer system"<<"\t\t"<<qun<<"\t\t"<<sub;

}









}//End of fuction...







};//End of sale class
class paymentclass{
public:
void paymentfun()
{
    long total,itemid,customerid,qun,amount,paid;
cout<<"\n\nEnter following information = ";
cout<<"\n\nEnter item id = ";//system ask to enter item id..
cin>>itemid;
cout<<"\n\nEnter customer id = ";//ask to enter customer id...
cin>>customerid;
cout<<"\n\nEnter quantity = ";//and quatity of item...
cin>>qun;

/* in Below all condition system match and show customer id
item id and multiply price with qunatity and show the total 
amount and also remaining amount
*/
if(customerid == 1 && itemid==1)
 {

    cout<<"\n\nCustomer name is Nouman ";
    total=qun*20000;
	cout<<"\n\nTotal amount = " <<total;
    cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 1 && itemid==2)
 {

    cout<<"\n\nCustomer name is Nouman ";
    total=qun*25000;
	cout<<"\n\nTotal amount = " <<total;
    cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}


else if(customerid == 1 && itemid==3)
 {

    cout<<"\n\nCustomer name is Nouman ";
    total=qun*30000;
	cout<<"\n\nTotal amount = " <<total;
    cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 1 && itemid==4)
 {

    cout<<"\n\nCustomer name is Nouman ";
    total=qun*35000;
	cout<<"\n\nTotal amount = " <<total;
    cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\nRemaining amount is = "<<amount;
}

else if(customerid == 2 && itemid==1)
 {

    cout<<"\n\nCustomer name is Arslan ";
    total=qun*20000;
	cout<<"\n\nTotal amount = " <<total;
    cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}


else if(customerid == 2 && itemid==2)
 {

    cout<<"\n\nCustomer name is Arslan ";
 	total=qun*25000;
	cout<<"\n\nTotal amount = " <<total;
    cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}


else if(customerid == 2 && itemid==3)
 {

    cout<<"\n\nCustomer name is Arslan ";
    total=qun*30000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}



else if(customerid == 2 && itemid==4)
 {

    cout<<"\n\nCustomer name is Arslan ";
    total=qun*35000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 3 && itemid==1)
 {

    cout<<"\n\nCustomer name is Waqar ";
     total=qun*20000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 3 && itemid==2)
 {

    cout<<"\n\nCustomer name is Waqar ";
    total=qun*25000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 3 && itemid==3)
 {

    cout<<"\n\nCustomer name is Waqar ";
    total=qun*30000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}




else if(customerid == 3 && itemid==4)
 {

    cout<<"\n\nCustomer name is Waqar ";
    total=qun*35000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}


else if(customerid == 4 && itemid==1)
 {

    cout<<"\n\nCustomer name is Shahid ";
    total=qun*20000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}


else if(customerid == 4 && itemid==2)
 {

    cout<<"\n\nCustomer name is Shahid ";
    total=qun*25000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 4 && itemid==3)
 {

    cout<<"\n\nCustomer name is Shahid ";
    total=qun*30000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\nAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
}

else if(customerid == 4 && itemid==4)
 {

    cout<<"\n\nCustomer name is Shahid ";
    total=qun*35000;
	cout<<"\n\nTotal amount = " <<total;
 	cout<<"\n\bAmount to be paid = ";
    cin>>paid;
    amount=total-paid;
    cout<<"\n\nRemaining amount is = "<<amount;
    cout<<endl;
}





}//End of payment  function...



};

//Print class is use to print report.........
class printreport{
public:
	
void printfun()
{
	//system ask user to for his choice ..........
cout<<"\n\n 1 -  Stock in Hand \n\n";//when use enter 1 than control move to stock function
cout<<" 2 -  Customer Balance \n\n";//when use enter 2 than control move to balance function
cout<<" 3 -  Sales Report (by date) \n\n";//when use enter 3 than control move to report function
}

void stock()
{


int id;
//system ask user to enter id of item.......
cout<<"\n\nEnter item id = ";
cin>>id;
switch(id)//switch case search item linked with the id.........
{
	
case 1 ://if item id is 1.....
        cout<<"\n\n1-ID \tName\t\tPrice\tQuantity \n\n";

        cout<<"   1\tHP system\t20000\t300 \n\n";
        break;

case 2 ://if item id is 2.....
        cout<<"\n\n1-ID \tName\t\tPrice\tQuantity \n\n";

        cout<<"   2\tDell system\t25000\t250 \n\n";
        break;
case 3 ://if item id is 3.....
        cout<<"\n\n1-ID \tName\t\tPrice\tQuantity \n\n";

        cout<<"   3\tLenovo system\t30000\t240 \n\n";
        break;
case 4 ://if item id is 4.....
        cout<<"\n\n1-ID \tName\t\tPrice\tQuantity \n\n";

        cout<<"   4\tAcer system\t35000\t400 \n\n";
        break;
default :
cout<<"\a\a\a\n\nEnter valid id....\a\a\a";//system generate error when id is not matched....
break;
}

}//end of fuction...............

//balance function check the balance of customer....
void balance()
{
     int cusid;
    cout<<"\n\nEnter customer id = ";//system ask to enter id of customer........
    cin>>cusid;
    if(cusid==1)//if id is 1...
	{
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no\tBalance ";
    cout<<"\n\n1\t1\tNouman\tBhalwal\tnomibaloch775@gmail.com\t0302-9572806\t10000Rs";
}
else if(cusid==2)//if id is 2...
{
    cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no\tBalance";
    cout<<"\n\n2\t2\tArslan\tLahore\tarslan745@gmail.com\t0344-9774816\t9000Rs";
}
else if(cusid==3)//if id is 3...
{
     cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no\tBalance ";
    cout<<"\n\n3\t3\tWaqar\tIslamabad\twaqar121@gmail.com\t0312-9375704\t8000Rs";

    }
else if(cusid==4)//if id is 4.....
{
        cout<<"\n\nSr.no \tID\tname\tAddress\t\tEmail\t\tPhone no\tBalance ";
    cout<<"\n\n4\t4\tshahid\tJhelum\tshahid141@gmail.com\t0314-1542755\t5000Rs";
}
else {
    cout<<"\n\n\a\aCustomer not found ";//system generate error when customer id is not  match........
}


}//end of function





//report function is use to print report on the screen.......
void report()
{

 string from,to;
 string hp;
cout<<"\n\nDate from = ";//system ask to enter date from..
cin>>from;
cout<<"\n\nDate to = ";//till....
cin>>to;
cout<<from<<"\t"<<to;
cout<<"\n\nItem id\tItem name\tQuantity\t Amount \n\n";

cout<<"   1\tHP system\t5\t\t100000 ";

cout<<"\n\n   2\tDell system\t10\t\t2500000";

cout<<"\n\n   3\tLenovo system\t4\t\t120000 ";

cout<<"\n\n   4\tAcer system\t2\t\t70000";

cout<<"\n\n\t\t\tTotal sale is =4400000";


}//end of report function ........



};//end of report class...

int main()
{
int code;
string name;
cout<<"Enter user name = ";
cin>>name;
cout<<"\n\nEnter password = ";
cin>>code;
if(name == "1" && code == 7)
{

mainclass mainobj;
mainmenu:
mainobj.mainfun();
int num;
cin>>num;
switch(num){
case 1 :

    itemclass itemobj;
    itemfun:
    itemobj.itemfun();
    int a;
    cin>>a;
    if(a==1)
	{
	itemobj.newitem();
	goto itemfun;
    }
	else if(a==2)
    {
	itemobj.updateitem();
    goto itemfun;
    }
	else if(a==3)
    {
	itemobj.finditem();
    goto itemfun;
	}
	else if(a==4)
    {
	itemobj.removeitem();
    goto itemfun;
	}
	else if(a==5) goto mainmenu;
      
    else
    cout<<"\n\nPlease Enter vaild number\a\a\a\a\a\a\a ";
      break;
case 2 :


    customerclass customerobj;
    customermenu:
    customerobj.customerfun();
    int b;
    cin>>b;
    if(b==1)
    {
	customerobj.addcustomer();
	goto customermenu;
	}
    else if(b==2)
    {
	customerobj.updatecustomer();
    goto customermenu;
	}
	else if(b==3)
    {
	customerobj.findcustomer();
    goto customermenu;
	}
	else if(b==4)
 	{  
 	customerobj.removecustomer();
    goto customermenu;
	}
	else if(b==5) goto mainmenu;
        
    else
        cout<<"\n\nPlease Enter vaild number\a\a\a\a\a\a\a\a\a\a ";
    break;


case 3 :

    saleclass saleobj;
    saleobj.salefun();
    int c;
    cin>>c;
    if(c==1)
        saleobj.makenewsale();

    else if(c==2) goto mainmenu;
    
    else
        cout<<"\n\nPlease Enter valid number \a\a\a\a\a\a\a\a\a\a ";

    break;

case 4 :



    paymentclass paymentobj;
    paymentobj.paymentfun();
    goto mainmenu;
    break;
case 5 :



    printreport printobj;
    printobj.printfun();
    int d;
    cin>>d;
    if(d==1)
        printobj.stock();
    else if(d==2)
        printobj.balance();
    else if(d==3)
        printobj.report();
        
    else


        cout<<"\n\n\a\a\a\a\aAlert please enter valid number ";
        break;

default :
    cout<<"\n\nEnter valid choice\a\a\a\a\a\a";
}

}
else 
{

cout<<"\n\n\a\a\a\a Sorry Error ";
}
}
