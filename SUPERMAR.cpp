


/***************************************************************************************************************************************************************************
                       
 THIS PROGRAM ©2009 KRISHNA BHARADWAJ YERAGUDIPATI. ALL RIGHTS RESERVED. THIS COMPUTER PROGRAM IS PROTECTED BY COPYRIGHT LAW AND INTERNATIONAL TREATIES.

UNAUTHORIZED REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM, OR ANY PORTION OF IT, MAY RESULT IN SEVERE CIVIL AND CRIMINAL PENALTIES, AND WILL BE PROSECUTED

 TO THE MAXIMUM EXTENT POSSIBLE UNDER THE LAW. PRIOR PERMISSION MUST BE TAKEN FROM THE AUTHOR BEFORE USING ANY PART OF THIS PROGRAM. STRICTLY FOR PRIVATE

 USE ONLY. PLEASE NOTE THAT THIS IS FREEWARE AND CANNOT BE SOLD FOR EITHER PERSONAL OR PUBLIC GAIN. DONATIONS, HOWEVER, WILL BE GRATEFULLY ACCEPTED. -KBY

**************************************************************************************************************************************************************************/



#include<iostream.h>

#include<conio.h>

#include<process.h>

#include<stdio.h>

#include<iomanip.h>

#include<fstream.h>

#include<string.h>

/*         *********************  PRODUCT INFORMATION  ***********************       */

class {  public:                                    // THE MAIN CLASS, WHICH HOLDS ALL THE PRODUCT INFORMATION
                				  
         char prod[30];                             // THIS IS THE NAME OF THE ITEM
				  
         int avail;                                 // THIS IS THE AVAILABILITY OF THE ITEM

         int price;                                 // THIS IS THE PRICE  OF  THE ITEM

         int barcode;                               // THIS IS THE BARCODE OF THE ITEM

      }prod_data[297];
	  
char prodname[30][297];

prodname[30][297]=prod_data[297].prod[30];

fstream avail_dat;

/*     **************************  MEMBER INFORMATION  *****************      */
				 
class {	public: 
                                                             
        int age;                                         // AGE OF PERSON, REQUIRED FOR CHECKING IF GREATER THAN 18

        char name[31],sex,add[101];                      // NAME: HOLDS 100, MAX. 30 CHARS.,  ADD: ADDRESS; STORES MAX. 100 CHARS.

        long unsigned int PAN,phone;                     // PAN:LONG UNSIGNED AS IT HAS TO STORE LONG +VE NO., SAME FOR PHONE
				 
      }member[100];
	  
int member_no;                                           // KEEPS TRACK OF THE CURRENT MEMBER NUMBER 

fstream memno;

fstream memdet;

/*         **********************  PROBLEM DATA  *******************  */       

class { public:

        char prob[101];                            // DATABASE OF PROBLEMS
				  
	char proname[31];                          // DATABASE OF NAMES OF SUBMITTERS OF PROBLEMS
				  
       }pro_dat[100];

int k;                                             // COUNTS THE NUMBER OF PROBLEMS

fstream pro_no;

/*   ******************************* ALL THE FUNCTIONS USED ********************************************   */
 
 void availbly();

 void adstock();

 void checkout();

 void repprob();

 void checkprob();

 void addmem();

/*   ******************************************    MAIN STARTS HERE    *************************************************************  */
 
 int main()

{

 /*         *********
 
                INITIALIZATIONS ONLY
				
	     *********                                  */
 
 
 /********************************INITIALIZING AVAILABILITIES*********************************/

 avail_dat.open("C:\\Supermar\\Availability_details.dat", ios::binary|ios::in);

for (int pro=0; pro<297; pro++)                       // GET ALL THE AVAILABILITY DETAILS

 avail_dat.read((char *) & prod_data[pro], sizeof(prod_data));
 
avail_dat.close();

/**********GETTING MEMBERSHIP DETAILS AND INITIALIZATION************/

memno.open("C:\\Supermar\\Membership_count.dat", ios::in);   // FILE TO STORE THE MEMBERSHIP NUMBER

memno>>member_no;                                        // MEMNO RETRIEVES THE ACTUAL COUNT OF MEMBERS FROM THE FILE

memno.close();			                                 // CLOSES THE FILE

memdet.open("C:\\Supermar\\Membership_details.dat", ios::binary|ios::in);

for (int xo=0; xo<member_no; xo++)

 memdet.read((char*) & member[xo], sizeof(member)); // GET ALL THE MEMBERSHIP DATA FROM THE FILE
 
memdet.close();

/******************GETTING PROBLEM DATA AND INFO****************/

pro_no.open("C:\\Supermar\\Problem_count.dat", ios::in);

pro_no>>k;

pro_no.close();

/*************************************************** DATABASE OF ALL THE ITEMS IN SUPERMARKET *******************************************************/


prodname[][297]={"Asparagus","Beets","Broccoli/Cauliflower","Carrots","Celery","Corn","Cucumbers","Greens","Lettuce","Mushrooms","Onions","Peppers","Potatoes","Spinach","Sprouts","Squash","Tomatoes","Zucchini","Apples","Avocado","Bananas","Berris","Cherries","Grapes","Kiwis","Lemons/Limes","Melons","Oranges","Peaches","Pears","Plums","Applesauce","Baked Beans","Beans","Carrots","Corn","Mixed Fruit","Mixed Veggies","Olive","Pasta Sauce","Pickles","Refried Beans","Tuna","Canned Tomatoes","Soups","BBQ Sauce","Hot Sauce","Salsa","Soy Sauce","Steak Sauce","Syrup","Worcestershire Sauce","Bottled Water","Bullion Cubes","Cereal","Coffee","Gravy Honey","Jelly/Preservatives","Ketchup","Lemon/Lime Juice","Mac & Cheese","Mayonnaise","Mustard","Pancake/Waffle Mix","Pasta","Peanut Butter","Ramen","Soda Pop","Tea","Rice","Basil","Black Pepper","Cilantro","Cinnamon","Garlic","Oregano","Parsley","Red Pepper","Salt","Vanilla Extract","Apple Cider Vinegar","Balsamic Vinegar","Salad Dressing","Olive Oil","Vegetable Oil",

 "White Vinegar","Chip Dip","Eggs/Fake Eggs","Juice","Tofu","Tortillas","Butter","Half & half","Heavy Cream","Margarine","Milk","Sour Cream","Whipped Cream","Yogurt","Cheddar Cheese","Cottage Cheese","Cream Cheese","Feta Cheee","Mozzarella Cheese","Parmesan Cheese","Pepper Cheese","Provolone Cheese","Ricotta Cheese","Sandwich slices","Shredded Cheese","Swiss Cheese","Burittos","Desserts","Fish sticks","Ice cream","Juices","Pizzas","Popsicles","Fries / Tater Tots","Sorbet","TV dinners","Vegetables","Veggie Burgers","Bacon","Beef","Chicken","Ground Beef","Ground turkey","Ham","Hot Dogs","Lunchmeat","Pork","Sausage","Steak","Turkey","Catfish","Cocktail Sauce","Crab","Halibut","Oysters","Salmon","Shrimp","Tilapia","Tuna","Bagels","Buns","Cake","Cookies","Crackers","Croissants","Donuts","Fresh bread","Pastries","Pie","Pitas","Rolls","Sliced bread","Baking powder","Baking soda","Bread crumbs","Brown sugar","Cake decorations","Cake icing","Cake / Brownie mix","Chocolate chips","Cocoa","Flour","Oatmeal","Pie Shell",

 "Powdered sugar","Shortening","Sugar","Yeast","Candy","Cookies","Dried fruit","Granola Bars","Gum","Nuts","Popcorn","Potato Chips","Pudding","Pretzels","Tortilla Chips","Antiperspirant","Bath soap","Conditioner","Condoms","Cosmetics","Deodorant","Facial cleanser","Facial Tissue","Floss","Hair Gel/Spray","Hand Soap","Lip Balm","Moisturizing Lotion","Mouthwash","Q-Tips","Razors","Shampoo","Shaving Cream","Toilet Paper","Toothpaste","Allergy","Antidiarrheal","Aspirin","Antacid","Band-aids","Cold","Feminine products","Prescription","Sinus","Vitamins","Aluminum Foil","Coffee Filters","Dish Soap","Dishwasher Soap","Disposable Cups","Disposable Cutlery","Disposable Plates","Freezer Bags","Napkins","Non-stick Spray","Paper Towels","Plastic Wrap","Roasting Pan","Sandwich Bags","Sponges / Scrubber","Wax Paper","Air freshener","Bathroom Cleaner","Bleach","Dryer Sheets","Fabric Softener","Floor Cleaner","Garbage Bags","Glass Cleaner","Laundry Detergent","Mop Head","Spray Polish","Vacuum Bags","Automotive","Batteries",

 "Candles","CDRs","Charcoal","DVDRs","Fresh Flowers","Greeting Cards","Hardware","Insect Repellent","Insecticides","Light bulbs","Magazine/Newspapers","Random Impulse Buy","Sunscreen","Cat food","Cat litter","Cat treats","Dog food","Dog treats","Flea treatment","Pet shampoo","Baby food","Bottles / Cups","Diapers","Diaper lotion","Formula","Wipes","Envelopes","Glue","Notepads","Paper","Pens / Pencils","Scotch tape","Beer","Champagne","Club soda","Gin","Malt beverage","Red wine","Rum","Sake","Tonic","Whiskey","White Wine","Vodka","Burger Night","Chili Night","Pizza Night","Spaghetti Night","Taco Night","Take-out Deli Food"};

  /* TOTAL OF 297 (TWO HUNDRED AND NINETY SEVEN) PRODUCTS IN DATABASE. HUGE THANKS TO www.grocerylists.org FOR THE INVALUABLE LIST.*/
  
 /********************************************************** DATABASE OF ALL THE PRICES OF ITEMS *****************************************************/

 
 for (int m=0; m<297; m++)                                  // ****************** ONLY UNREALISTIC VALUES ***********************

  prod_data[m].price=((m+10)/10);                           // ****************** ONLY UNREALISTIC VALUES ***********************


/********************************************************* DATABASE OF ALL THE BARCODES **************************************************************/


for (int Z=0; Z<297; Z++)                                   // ASSIGNS BARCODES FROM 1000 TO 1296

 prod_data[Z].barcode=(1000+Z);



/********************************************************************************************************************************************************/

/*                                                   ! * ! * ! * ! * ! * ! * ! * ! * ! * ! * ! * ! * !

        
		** ** ** ** ** ACTUAL CODING OF THE MAIN STARTS HERE ** ** ** ** ** **
		
		
                                                       ! * ! * ! * ! * ! * ! * ! * ! * ! * ! * ! * ! * !                                                        */ 
 
 mainstart:					                                // WHEN ANY FUNCTION ENDS AND RETURNS, IT STARTS AGAIN HERE
 
 clrscr();                                                  // CLEARS THE SCREEN

 int ans;                                                   // FOR THE RESPONSE AND CONSEQUENT SWITCHING

 cout<<"\t\t\tWELCOME TO KRIHAN SUPERMARKET";

 cout<<"\n1.Check availability of goods...\n2.Check out...\n3.Add membership...\n4.Report problem...\n5.Add Stock...\n6.Check problems...\n7.Exit...\n8.About this program\n\n\tEnter option: "; // MAIN MENU

 cin>>ans;                                                  // FOR USER'S INPUT OF RESPONSE AND CONSEQUENT SWITCHING
                                                             
 switch(ans)

 {

  case 1:availbly();                                        // FOR CHECKING THE AVAILABILITY OF THE GOODS

	 break;

  case 2:checkout();                                        // FOR A CUSTOMER TO CHECK OUT AND THE BILL PROVIDED, ETC.

	 break;

  case 3:addmem();                                          // ADD A MEMBER FOR SPECIAL DISCOUNTS
  
	 break;

  case 4:repprob();                                         // FOR THE USER TO REPORT ANY SPECIFIC PROBLEMS, CUSTOMER COMPLAINTS, ETC.

	 break;

  case 5:adstock();                                         // FOR ADDING THE STOCK OF GOODS

	 break;

  case 6:checkprob();                                       // FOR THE OWNER / AUTHORIZED STAFF TO CHECK THE PROBLEM (WITH PASSWORD)

	 break;

  case 7:_exit(0);                                          // WILL CALL THE _EXIT FUNCTION AND WILL CLOSE

  default:cout<<"Wrong value entered! Please enter again!"; // IF NONE OF THE OPTIONS 1,2,3,4,5,6 ARE ENTERED

}

 goto mainstart;                                            // GOES TO THE BEGINNING, WHERE ALL THE OPTIONS ARE GIVEN AGAIN (MAIN MENU)

 return 0;
}

/*********************************************    MAIN ENDS HERE    *****************************************************************************/















 /********************************************    CHECK AVAILABILITY STARTS HERE    *******************************************************************/
 
 void availbly()


 {

   availstart:                                                              // IF USER WANTS TO CHECK GOODS AGAIN

   clrscr();

   cout<<"\t\t\tCHECK AVAILABILITY OF GOODS!\n\n";
                                                                            
   int barnew;                                                              // BARCODE TO BE INPUT TO COMPARE WITH PRE-DEFINED ONES

   cout<<"Please input the barcode of the item you want to check...\n";

   cin>>barnew;                                                             // INPUTTING THE NEW BARCODE

   int flag=300;                                                            // FLAG WILL NOT CHANGE IF NO PRODUCT EXISTS, SO INITIALIZE IT TO 300

   char ans;                                                                // FOR ASKING WHETHER USER WANTS TO CHECK ANOTHER PRODUCT OR NOT

   for (int i=0; i<297; i++)                                                 // LOOP WHERE THE ITEM IS FOUND

    {

    if (barnew==prod_data[i].barcode)                                        // CONDITION FOR OLD BARCODE==BARNEW

     flag=i;                                                                // FLAG TAKES THE POSTION OF PRODUCT

    break;

    }

  if (flag==300)                                                            // 300 AS NO PRODUCT IS FOUND AND FLAG IS NOT CHANGED

   cout<<"\n\tSorry! No such product found!\n\t";
    
  else                                                                      // SOME VALUE BETWEEN 1000 AND 1297

   cout<<"The availability of "<<prod_data[flag].prod<<" is "<<prod_data[flag].avail<<"\n";

  wrong:                                                                    // IF THE USER INPUTS WRONG CHOICE (NEITHER Y NOR y NOR N NOR n)

  cout<<"\n\tWould you like to check other products(Y/N)?";                 

  cin>>ans;                                                                 // USER INPUT TO CHECK MORE ITEMS

  if (ans=='y' || ans=='Y')

   goto availstart;                                                         // GOES TO THE START, WHERE BARCODE IS ASKED (BARNEW)

  else

  if (ans=='n' || ans=='N')

   return;

  else                                                                      // IF THE USER INPUTS WRONG CHOICE (NEITHER Y NOR y NOR N NOR n)

   cout<<"\n\tWrong choice entered! Please try again\n\t!";

  goto wrong;

  }

/***********************************************    CHECK AVAILABILITY ENDS HERE    *******************************************************************/















 /******************************************************* CHECK OUT STARTS HERE **********************************************************************/

void checkout()

{

clrscr();                                                                      // CLEARS THE SCREEN

int barnew,toprice=0;                                                          // BARNEW: THE VALUE INPUT TO BE COMPARED WITH EXISTING BARCODES, TOPRICE: TOTAL PRICE AT THE END OF BILL

int cash;                                                                      // AMOUNT OF CASH CUSTOMER  ACTUALLY GIVES THE CASHIER

cout<<"\t\t\t\tCHECK OUT...\n\n\nPress any key to continue...";

getch();

table:

clrscr();

gotoxy(1,1);
cout<<"Bar code";
gotoxy(23,1);
cout<<"Item";
gotoxy(42,1);
cout<<"Price";
gotoxy(63,1);
cout<<"Availability\n";

for (int li=0; li<80; li++)

 cout<<"-";

for (int is=0; is<25; is++)

 {

  gotoxy(12,is);
  cout<<"|";
  gotoxy(33,is);
  cout<<"|";
  gotoxy(53,is);
  cout<<"|";
 }

int lineno=3;                                                                       // COUNTS THE LINE NUMBER FOR gotoxy()

start:                                                                             // IF MORE ITEMS ARE PRESENT

if (lineno==25)

 goto table;

gotoxy(1,lineno);

cin>>barnew;                                                                       // INPUT OF BARNEW AS DESCRIBED ABOVE

int flag=300;                                                                      // IF FLAG REMAINS 0; NO SUCH PRODUCT EXISTS

if (barnew==0)                                                                     // IF BARNEW=0 THEN USER DOES NOT WANT ANY MORE PRODUCTS

 goto end;                                                                         // WHERE THE BILL IS PRINTED

else                                                                              // HERE ITEM IS COMPARED, PRICES, ETC. ARE FOUND

{

 for (int i=0; i<297; i++)

  {

   if (barnew==prod_data[i].barcode)

    flag=i;

  }

 if (flag==300)

  {

     gotoxy(13,lineno);
     cout<<"Invalid Barcode";
     gotoxy(42,lineno);
     cout<<"---";
     gotoxy(64,lineno);
     cout<<"---";
     lineno++;

     goto start;                                                                     // WHERE THE USER ENTERS BARNEW AGAIN

   }

prod_data[flag].avail--;                                                           // DECREASING THE AVAILABILITY

gotoxy(13,lineno);
cout<<prod_data[flag].prod;
gotoxy(42,lineno);
cout<<prod_data[flag].price;
gotoxy(64,lineno);
cout<<prod_data[flag].avail;
lineno++;
                                                     
toprice+=prod_data[flag].price;                                                              // ADDING THE PRICE OF THIS ITEM TO TOTAL PRICE

goto start;                                                                        // WHERE BARNEW IS ENTERED AGAIN

}
 

end:                                                                               // BILL IS PRINTED

int newmem;

memstrt:

clrscr();

char memans;

cout<<"Are you a member, so that you may avail discount?\n";

cin>>memans;

if (memans=='Y' || memans=='y')

{

 cout<<"Enter your membership no:";

 cin>>newmem;
 
 if (newmem<1 || newmem>member_no)
  
   {
    
	 cout<<"Sorry! That membership number does not exist! Please try again!";
	 
	 getch();
	 
	 goto memstrt;
	 
   }
   
  else
  
  {

    int newPAN;
  
    cout<<"Please enter your PAN number for verification...\n";
  
    cin>>newPAN;
  
    clrscr();
  
    if (newPAN==member[newmem].PAN)
   
    {
	
	 toprice-=((1/10)*toprice);
	 
	 cout<<"Congratulations! You have successfully availed a 10% discount on the total price!";
	 
	 getch();

    }

    else

    if (memans!='N' || memans!='n')

    {
  
     cout<<"Sorry! Invalid choice! Try again!";
 
     goto memstrt;
   
    }

  }

}
   
clrscr();
   
cout<<"THE TOTAL PRICE IS";
 
gotoxy(50,1);
 
cout<<toprice<<endl;

cout<<"CASH RENDERED";
 
gotoxy(50,2);

cin>>cash;

cout<<"\n\nBALANCE TO BE GIVEN";

gotoxy(50,4);

cout<<(cash-toprice);

getch();

avail_dat.open("C:\\Supermar\\Availability_Details.dat", ios::binary|ios::out|ios::app|ios::noreplace);

for (int xyz=0; xyz<297; xyz++)                       // GET ALL THE AVAILABILITY DETAILS

 avail_dat.write((char *) & prod_data[xyz], sizeof(prod_data));

avail_dat.close();

clrscr();

gotoxy(18,13);

cout<<"THANK YOU FOR SHOPPING. PLEASE VISIT AGAIN!";

getch();

clrscr();

}






 /***********************************************   ADD A MEMBER STARTS HERE ***************************************************************************/
 

 void addmem()

 {

  clrscr();
  
  if (member_no==100)
   
   {
   
    cout<<"\n\tSorry! You are too late! You have missed out on the promotional opportunity! 100 members are over!";
	
	return;
	
   }

 cout<<"\t\tOPEN A NEW MEMBERSHIP ACCOUNT...\n\n\tIn each of the following details, if a limit is present, it is specified. If you cross the limit, the rest of your input will be truncated!\n\n\tPress any key to start the registration process.";
 
 getch();

 cout<<"\nPlease enter your name(max. 30 characters): ";

 gets(member[member_no].name);

 cout<<"\nPlease enter your age: ";

 cin>>member[member_no].age;

 if (member[member_no].age<18)                                      // CONDITION TO CHECK WHETHER CUSTOMER IS A MAJOR OR NOT

  {

   cout<<"Sorry, you are a Minor. We do not accept Minors.";    

   getch();

   return;                                                          // GOES BACK TO MAIN MENU i.e. mainstart

  }

 cout<<"\nPlease enter your sex(M/F): ";

 cin>>member[member_no].sex;

 if (member[member_no].sex=='m' || member[member_no].sex=='M' || member[member_no].sex=='f' || member[member_no].sex=='F')// CONDITION TO CHECK INTEGRITY OF GENDER

  {

   cout<<"\nPlease enter your PAN card number: ";

   cin>>member[member_no].PAN;                                            // INPUT OF PAN CARD NUMBER

   cout<<"\nPlease enter your address, you may type any characters you please except for ~. So please type your address line by line, followed by the \" ~ \" and the return   button to complete it. Please start here(max.100 characters):\n";

   cin.getline(member[member_no].add,100,'~');                  // GETS ADDRESS OF MEMBER, IN WHICH ANY SYMBOL CAN BE TYPED, '~' SHOULD BE TYPED TO END

   cout<<"\nPlease enter your phone number: ";                  

   cin>>member[member_no].phone;                                // INPUT OF TELEPHONE NUMBER

   cout<<"\nSaving files to disk. The speed may vary depending on your hardware and system settings...";
   
   ofstream memdet ("Membership_details.dat", ios::binary|ios::app|ios::noreplace);

   memdet.write((char*) & member[member_no], sizeof(member));   

   memdet.close();
   
   clrscr();                                                    // CLEARS THE SCREEN

   cout<<"Thank you for registering. Your Registration number is ";

   cout<<++member_no;                                           // INCREMENT THE MEMBERS AND PROVIDES MEMBER NUMBER, SINCE ARRAY INDEX BEGINS FROM 0, FIRST PERSON GETS "1".

   memno.open("C:\\Supermar\\Membership_count.dat", ios::out|ios::trunc);
   
   memno<<member_no;
   
   cout<<"\n\n\tPlease make sure to remember all these details for future reference!";

   getch();
   
   return;                                                      // RETURNS TO MAIN MENU.

  } 
  
  else                                                          // IF GENDERLESS

  { 

    cout<<"Please enter a valid Gender.";

    getch();

    return;

  }

 }


  /***********************************************   ADD A MEMBER ENDS HERE ***************************************************************************/


  


  /***********************************************    ADD STOCK STARTS HERE    ************************************************************************/

  void adstock()

  {

   qstart:                                                           // IF USER WANTS TO ADD PRODUCTS AGAIN

   clrscr();

   int barnew;                                                              // BARCODE TO BE INPUT TO COMPARE WITH PRE-DEFINED ONES

   cout<<"ADD STOCK.....\n\n\n\n";
   
   cout<<"Please input the barcode of the item you want to check...\n";

   cin>>barnew;                                                             // INPUTTING THE NEW BARCODE

   int flag=300;                                                            // FLAG WILL NOT CHANGE IF NO PRODUCT EXISTS, SO INITIALIZE IT TO 300

   for (int i=0; i<297; i++)                                                 // LOOP WHERE THE ITEM IS FOUND

    {

    if (barnew==prod_data[i].barcode)                                        // CONDITION FOR OLD BARCODE==BARNEW

     flag=i;                                                                 // FLAG TAKES THE POSTION OF PRODUCT

    break;

    }

  if (flag==300)                                                            // 300 AS NO PRODUCT IS FOUND AND FLAG IS NOT CHANGED

   cout<<"\n\tSorry! No such product found!\n\t";
    
  else                                                                      // SOME VALUE BETWEEN 1000 AND 1297

   {
   
    cout<<"Please input the quantity of the goods you are adding:\n";

   int q;                                                                   // QUANTITY OF THE ITEM

   cin>>q;                                                                  // INPUT OF QUANTITY

   prod_data[i].avail+=q;                                                   // ADDING THE AVAILABILITY
   
   cout<<"\n\tSuccessfully added!";
   
   }

   char qans;                                                               // ASKING WHETHER USER WANTS TO ADD MORE PRODUCTS

   wrans:                                                                   // IF USER INPUTS WRONG ANSWER

   cout<<"\n\tDo you want to add more goods(Y/N)?";

   cin>>qans;                                                               // TO SEE USER'S OPINION
   
   avail_dat.open("C:\\Supermar\\Availability_details.dat", ios::binary|ios::trunc|ios::out);

   for (int xyz=0; xyz<297; xyz++)                       // GET ALL THE AVAILABILITY DETAILS

    avail_dat.write((char *) & prod_data[xyz], sizeof(prod_data));

  if (qans=='y' || qans=='Y')                                              // IF USER WANTS TO INPUT MORE GOODS

    goto qstart;                                                            //WHERE BARNEW IS AKSED

   else                                                                     

   if (qans=='n' || qans=='N')						    // IF USER WANTS TO GO BACK

    return;                                                                 // TO MAIN MENU

   else                                                                     // IF QANS IS WRONG, I.E. QANS IS NOT Y, y, N, OR n

    cout<<"You have entered a wrong option. Please try again...";

   goto wrans;                                                              // WHERE QUESTION WILL BE ASKED AGAIN

  }

 /***********************************************    ADD STOCK ENDS HERE    ************************************************************************/








 /*******************************************   REPORT PROBLEMS STARTS HERE   ***************************************************************************/
 
 void repprob()

 {

  clrscr();

  cout<<"\t\t\tREPORT A PROBLEM...";
  
  if (k==100)
  
   {
   
    cout<<"We're really sorry. There is no more space to report any more problems!\nPlease contact yout administrator...\n";
   
    getch();
   
    return;
	
   }
   
  cout<<"\n\nPlease enter your name:\n";

  gets(pro_dat[k].proname);

  cout<<"Please enter your problem(max. 100 characters) and press ~ to finish:\n";

  cin.getline(pro_dat[k].prob,100,'~');                                                        // INPUT OF PROBLEM, MAX. 100 CHAR.S, ENDS WITH '~'

  ofstream probout ("C:\\Supermar\\Problem_data.dat", ios::app|ios::binary|ios::noreplace);
  
   probout.write((char *) & pro_dat[k], sizeof(pro_dat));
  
  k++;                                                                                         // INCREMENTING THE NO. OF PROBLEMS

  clrscr();

  cout<<"Thanks for taking your time to report the problem.\n\tPress any key to continue...";

  getch();
  
  return;                                                                                      // GOES BACK TO MAIN MENU

 }

/**********************************************   REPORT PROBLEMS ENDS HERE   ***************************************************************************/








/************************************************* CHECK PROBLEMS STARTS HERE **************************************************************************/

void checkprob()

{

 clrscr();

 class { public:

        char admname[20];

        char admpass[15];
		
	  }userpass[5];
	  
 int check;
 
 fstream checker;

 checker.open("C:\\Supermar\\User_Checker.dat", ios::in);
 
 checker>>check;

 checker.close();
 
 if (check==10283495)
 
  {
  
   cout<<"You have been locked out. You cannot enter. Please contact your administrator...";
   
   return;
   
  }
 
 cout<<"\t\t\t\tFOR AUTHORIZED PERSONNEL ONLY...";

 for (int z=0; z<3; z++)                                     // GIVES 3 CHANCES TO THE USER

  { 

   clrscr();
   
   char tempname[20];
   
   char tempass[15];
   
   cout<<"\nEnter username, "<<(3-z)<<" chance(s) left:\n";

   gets(tempname);
   
   cout<<"\nEnter password:\n";
   
   gets(tempass);
   
   for (int map=0; map<5; map++)
    
	if (strcmpi(tempname, userpass[map].admname)
	
	 if (strcmpi(tempass, userpass[map].admpass)
	 
	  goto correct;
	  
   cout<<"Invalid Username or Password! Try again!";
   
   getch();
   
  }
   
checker.open("C:\\Supermar\\User_Checker.dat", ios::out|ios::trunc);

checker<<"10283495";

checker.close();
 
 cout<<"You have been locked out. You cannot enter. Please contact your administrator...";// IF ANSWER IS WRONG

 getch();

 return;

 correct:                                                    // IF ANSWER IS CORRECT

 checker.close();

 cout<<"There are "<<k<<" problems...\n\n\t\t";              // INFORMING USER OF PROBLEMS

 ifstream probin ("C:\\Supermar\\Problem_data.dat", ios::binary);
 
 for (int mil=0; mil<k; mil++)
 
 probin.read((char *) & pro_dat[mil], sizeof(pro_dat));
 
 for (int g=0; g<k; g++)                                   // LOOP FOR THE NUMBER OF PROBLEMS

  {

   cout<<"Problem "<<(g+1)<<":\nName: "<<pro_dat[g].proname<<"\nProblem: ";

   puts(pro_dat[g].prob);                                   // OUTPUTS THE STRING

   cout<<"\nPress any key to view next problem...\n";

   getch();

  }

return;                                                     // RETURNS TO MAIN MENU

}

/**************************************************** CHECK PROBLEMS ENDS HERE **************************************************************************/


/*********----------------------------------------_______________-END OF PROGRAM-_______________-----------------------------------------------**********/