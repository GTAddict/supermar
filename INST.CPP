#include<iostream.h>

#include<conio.h>

#include<dir.h>

#include<stdio.h>

#include<process.h>

#include<fstream.h>

#include<shellapi.h>

#include<string.h>

/************************* DECLARING GLOBAL FILE OBJECTS ***********************************/

fstream memno;

fstream memdet;

fstream pro_no;

fstream problems;

fstream avail_dat;

fstream admin;

fstream checker;

/*********************** DECLARING GLOBAL FUNCTIONS ***************************************/

int install();

int uninstall();

/************************ MAIN STARTS HERE **************************/

int main()

{

start:

clrscr();

int ans;

gotoxy(24,1);

cout<<"SUPERMARKET INSTALLATION WIZARD";

gotoxy(1,3);

cout<<"Thank you for buying the SUPERMARKET product!";

gotoxy(1,5);

cout<<"What would you like to do?\n1.Install\n2.Uninstall\n3.Exit\n\nPlease select your option: ";

gotoxy(1,14);

cout<<"1. INSTALL\n\tSelect this option if you would like to install SUPERMARKET for the     first time.\n\n2.UNINSTALL\n\tThis will remove SUPERMARKET from your computer.\n\n3.EXIT\n\tThis will exit the installation wizard without making any changes.";

gotoxy(1,1);

gotoxy(27,10);

cin>>ans;

clrscr();

switch(ans)

{

 case 1:install();

        break;
 
 case 2:uninstall();
 
        break;
 
 case 3:_exit(0);
  
        break;
 
 default:cout<<"Sorry! Wrong option entered! Try again!";
 
         goto start;

}

return 0;

}
    
int install()
{

 // ATTENTION!!!!!    COPY THE MAIN EXECUTABLE TO C:\\  !!!!!!!!!!!!!!!!!!!!!!

instart:

cout<<"We're sorry, the SUPERMARKET program will be installed in your C:\\ drive by default. We will make the option more flexible next time...";

cout<<"\nPress any key to start...";

mkdir ("C:\\Supermar");

clrscr();

cout<<"Creating files...\n";

cout<<"Creating membership files...1 of 2...\n";

memno.open ("C:\\Supermar\\Membership_count.dat", ios::out);          // FILE CREATION: MEMBERSHIP NUMBER. THIS FILE KEEPS TRACK OF THE NUMBER OF MEMBERS.

 memno<<"0";                                                      //  THE NUMBER OF MEMBERS IS ZERO

if (memno)

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";

memno.close();                                                    // CLOSES THE FILE. WILL BE OPENED ONLY WHEN NECESSARY

cout<<"Creating membersip files...2 of 2...\n";

memdet.open ("C:\\Supermar\\Membership_details.dat", ios::binary|ios::out);// FILE CREATION: MEMBERSHIP DETAILS. THIS FILE KEEPS TRACK OF THE MEMBER DETAILS.

memdet.close();                                                   // CLOSES THE FILE. WILL BE OPENED ONLY WHEN NECESSARY

if (memdet)

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";

cout<<"Creating problem files...1 of 2...\n";

pro_no.open ("C:\\Supermar\\Problem_count.dat", ios::out);          // FILE CREATION: PROBLEM NUMBER. THIS FILE KEEPS TRACK OF THE NUMBER OF PROBLEMS.

 pro_no<<"0";                                                      //  THE NUMBER OF PROBLEMS IS ZERO

if (pro_no)

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";
 
pro_no.close();                                                    // CLOSES THE FILE. WILL BE OPENED ONLY WHEN NECESSARY

cout<<"Creating problem files...2 of 2\n";

problems.open ("C:\\Supermar\\Problem_data.dat", ios::binary|ios::out);     // FILE CREATION: KEEPS TRACK OF ALL THE PROBLEMS

if (problems)

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";

problems.close();                                                 // CLOSES THE FILE. WILL BE OPENED ONLY WHEN NECESSARY

cout<<"Creating availability file...\n";

class {  public:                                    // THE MAIN CLASS, WHICH HOLDS ALL THE PRODUCT INFORMATION
                				  
         char prod[30];                             // THIS IS THE NAME OF THE ITEM
				  
		 int avail;                                 // THIS IS THE AVAILABILITY OF THE ITEM

         int price;                                 // THIS IS THE PRICE  OF  THE ITEM

         int barcode;                               // THIS IS THE BARCODE OF THE ITEM

      }prod_data[297];

avail_dat.open ("C:\\Supermar\\Availability_details.dat", ios::binary|ios::out);

for(int a=0; a<297; a++)                                             // INITIALIZES THE AVAILABILITY OF THE GOODS TO 100 EACH.

 prod_data[a].avail=100;
  
if (avail_dat)
 
 cout<<"Done.\n";
 
else
 
 cout<<"ERROR!\n";
 
avail_dat.close();                                               // CLOSES THE FILE. WILL BE OPENED ONLY WHEN NECESSARY
 
cout<<"Creating User Checker File...\n";

checker.open("C:\\Supermar\\User_Checker.dat", ios::out);                  // FILE CREATION: CHECKS WHETHER ANYONE HAS TRIED TO HACK INTO THE PROBLEM DATABASE AND LOCKS IT

if (checker)

 cout<<"Done";
 
else

 cout<<"ERROR!";
 
 clrscr();
 
if !((memno) || (memdet) || (pro_no) || (problems) || (avail_det) || (checker))
 
{
 
 char insans;
 
 cout<<"It looks like the Installation encountered problems. Would you like to try to install again?";
 
 cin>>insans;
 
 if (insans=='Y' || insans=='y')
 
  goto instart;
  
 else
 
  {
  
   cout<<"Program will quit now!";
   
   _exit();
   
  }
  
}
  
char open;
  
class { public:

        char admname[20];

        char admpass[15];
		
	  }userpass[5];
  
cout<<"You need to create a user name and password to have administrative priveleges.\nYou can create a maximum of 5 accounts.\nPLEASE NOTE THAT YOU CANNOT CREATE ACCOUNTS AT A LATER STAGE!\nPress any key to continue...";

getch();

clrscr();
  
for (int no=0; no<5; no++)
  
 {
  
  char temp[15];

  clrscr();
  
  cout<<"Account number "<<(no+1)<<"\nPlease choose a user name (max. 20 chars.):\n";
 
  gets(userpass[no].admname);
  
  pass:
  
  cout<<"\nEnter password (max. 15 chars.):\n";
  
  gets(userpass[no].admpass);
  
  cout<<"\nRe-enter password:\n";
  
  gets(temp);
  
  int comp=strcmpi(userpass[no].admpass, temp);
  
  if (!comp)
  
  {
  
   cout<<"Passwords do not match. Try again.\n";
   
   goto pass;
   
  }
  
  cout<<"Account successfully created! Type 'Y' to create more accounts or any other key to continue...";
  
  char passans;
  
  cin>>passans;
  
  if (passans!='Y' || passans!='y')
  
   break;
   
 }

admin.open("C:\\Supermar\\Admin_data.dat", ios::binary);

for (int j=0; j<no; j++);
 
 admin.write((char *) & userpass[j], sizeof(userpass));
 
if (!admin)

 {
 
  cout<<"An error has occured. Please install the program again.";
  
  getch();
  
  _exit(0);
  
 }
 
admin.close();
 
char exec;

cout<<"Congratulations! You may begin using your SUPERMARKET program now!\n\n";
  
cout<<"\tWould you like to launch the SUPERMARKET program now?\n\nPress Y or y to launch the program and quit this wizard or any other key to simply quit...";
  
cin>>exec;
  
if (exec=='Y' || exec== 'y')
  
  ShellExecute(0,"open","C:\\Supermar\\Supermar.exe","","",1);
  
_exit(0);
  
}
 
 
 
 
 
 
 int uninstall()
 
 {
 

  //////*************  ATTENTION!!!!  DELETE THE MAIN EXECUTABLE!!!!!!!    ***************////////////////


  uninstart:
  
  clrscr();
  
  char ans;
  
  cout<<"This will uninstall SUPERMARKET from your computer. Are you sure?(Y/N)";
  
  if (ans=='N' || ans=='n')
   
    _exit(0);
	
   else 
   
   if (!(ans=='Y' || ans=='y'))
   
   {
   
    cout<<"Wrong response! Try again!";
	
	goto uninstart;
	
   }
   
clrscr();
   
cout<<"Uninstalling your product...\n";
   
cout<<"Deleting files...\n";

cout<<"Deleting membership files...1 of 2...\n";

memno.close();

remove ("C:\\Supermar\\Membership_count.dat");

if !(remove ("C:\\Supermar\\Membership_count.dat"))

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";

cout<<"Deleting membersip files...2 of 2...\n";

memdet.close();

remove ("C:\\Supermar\\Membership_details.dat");

if !((remove ("C:\\Supermar\\Membership_details.dat"))

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";

cout<<"Deleting problem files...1 of 2...\n";

pro_no.close(); 

remove ("C:\\Supermar\\Problem_count.dat");

if !(remove ("C:\\Supermar\\Problem_count.dat"))

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";
 
cout<<"Deleting problem files...2 of 2\n";

problems.close();                                            

remove ("C:\\Supermar\\Problem_data.dat");

if !((remove ("C:\\Supermar\\Problem_data.dat"))

 cout<<"Done.\n";

else

 cout<<"ERROR!\n";

cout<<"Deleting availability file...\n";

avail_dat.close();

remove ("C:\\Supermar\\Availability_details.dat");

if !(remove ("C:\\Supermar\\Availability_details.dat"))

 cout<<"Done.\n"
 
else
 
 cout<<"ERROR!\n";
 
cout<<"Deleting User Accounts...\n";

admin.close();

remove ("C:\\Supermar\\Admin_data.dat");

if !(remove("C:\\Supermar\\Admin_data.dat"))

 cout<<"Done.\n";
 
else

 cout<<"ERROR!\n";

cout<<"Deleting User Checker...\n";

admin.close();

remove ("C:\\Supermar\\User_Checker.dat");

if !(remove("C:\\Supermar\\User_Checker.dat"))

 cout<<"Done.\n";
 
else

 cout<<"ERROR!\n";

clrscr();
 
if ((remove ("C:\\Supermar\\Membership_count.dat")) || (remove ("C:\\Supermar\\Membership_details.dat")) || (remove ("C:\\Supermar\\Problem_count.dat")) || (remove ("C:\\Supermar\\Availability_details.dat")) || (remove ("C:\\Supermar\\Problem_data.dat")) || (remove ("C:\\Supermar\\Admin_data.dat")) || (remove ("C:\\Supermar\\User_Checker.dat")))
 
 {
 
 char uninsfail;
 
 cout<<"It looks like the Uninstallation encountered problems. Would you like to try to uninstall again?";
 
 cin>>uninsfail;
 
 if (uninsfail=='Y' || uninsfail=='y')
 
  goto uninstart;
  
 else
 
  {
  
   cout<<"Program will quit now!";
   
   _exit(0);
   
  }
  
 }
  
  cout<<"Congratulations! Your Supermarket program has successfully been uninstalled! Unfortunately, the files in use were not deleted. \nPress any key to close this window and delete the files manually...";
  
  getch();
  
  ShellExecute(0,"open","C:\\Windows\\Supermar","","",1);
  
  _exit(0);     
  
 }
   
    
