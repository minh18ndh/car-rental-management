#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <chrono>
#include <thread>
#include <dos.h>
#include <iomanip> 
#include <algorithm>
#include <cmath>
#include <cstring>
#include <windows.h>

using namespace std;

struct sedanInfo {
  int ID[3] = {1, 2, 3};
  string company[3] = {"Mercedes", "BMW", "Audi"};
  string model[3] = {"S450 4Matic", "735i Pure Excellence", "A8L"};
  int seats[3] = {5, 5, 5};
  int drivingRange[3] = {500, 480, 490};   //in miles
  string transmission[3] = {"Automatic", "Automatic", "Automatic"};
  bool airConditioning[3] = {true, true, true};   //true for Yes, false for No
  int rentPricePerDay[3] = {270, 250, 230};   //in dollars
} sedan;

struct suvInfo {
  int ID[3] = {1, 2, 3};
  string company[3] = {"Range Rover", "Mercedes-Maybach", "BMW"};
  string model[3] = {"Sport Autobiography 3.0", "GLS 600 4Matic", "X5 xDrive40i M Sport"};
  int seats[3] = {7, 7, 7};
  int drivingRange[3] = {700, 650, 550};
  string transmission[3] = {"Automatic", "Automatic", "Automatic"};
  bool airConditioning[3] = {true, true, true};
  int rentPricePerDay[3] = {450, 600, 350};
} suv;

struct minivanInfo {
  int ID[3] = {1, 2, 3};
  string company[3] = {"Mercedes-Benz", "Lexus", "BMW"};
  string model[3] = {"V 250 AMG", "LM350", "2 Series Gran Tourer"};
  int seats[3] = {7, 4, 5};
  int drivingRange[3] = {550, 700, 600};
  string transmission[3] = {"Automatic", "Automatic", "Automatic"};
  bool airConditioning[3] = {true, true, true};
  int rentPricePerDay[3] = {230, 320, 180};
} mini;

//-----------------------------------------------------------------------------------------------------------------------------------//

class Car 
{
public:
  string carCategory;
  int carModel_ID;
  string carModel;
  int seats;
  int drivingRange;
  string transmission;   //"Manual" or "Automatic"
  bool airConditioning;
  int rentPricePerDay;
};

//-----------------------------------------------------------------------------------------------------------------------------------//

class Customer  //customer class
{
	public:
	string customerName;
  string phoneNumber;
  char checkoutData;
  int rentDays = 0;
  int rentalFee = 0;  //additional int vatiables defined
  bool isValidPhoneNumber(const string& phoneNumber) 
  {
    return phoneNumber.size() == 10 && phoneNumber[0] == '0';
  };
  bool isValidDays() 
  {
    return rentDays > 0 && rentDays < 366;
  };
};

//-----------------------------------------------------------------------------------------------------------------------------------//

class Menu : public Car, public Customer  //inherit from class Car and Customer
{
  public:

  void gotoxy(int x, int y) 
  {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }
  
//-----------------------------------------------------------------------------------------------------------------------------------//

  void openLink(const std::wstring& url) 
  {
    ShellExecuteW(NULL, L"open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
  }

//-----------------------------------------------------------------------------------------------------------------------------------//

  Menu() {};

  void customerDataMenu()
  {
    cout << "Please provide following information " <<endl; 
    do 
    {
      cout << "Number of days you wish to rent the car (enter 1 to 365): ";
      cin >> rentDays;
      if (!isValidDays())
      {
        cout << " " <<endl;
        cout << "Invalid number of days. Please try again!" <<endl;
        cout << "----------------------------------------------------------------------------------------------" <<endl;
        cout << "" <<endl;
        cin.clear();
        cin.ignore();
      }
    }
    while (!isValidDays());

    cout << "Please Enter your Name: ";
    cin >> customerName;
    do
    {
      cout << " " <<endl;
      cout << "Please Enter your phone number (start with 0, 10 digits): ";
      cin >> phoneNumber;
      cout <<endl;
      if (!isValidPhoneNumber(phoneNumber))
      {
        cout << "Invalid phone number. Please try again!" <<endl;
        cout << "----------------------------------------------------------------------------------------------" <<endl;
        cout << "" <<endl;
        cin.clear();
        cin.ignore();
      }
    }
    while (!isValidPhoneNumber(phoneNumber));
  }

//-----------------------------------------------------------------------------------------------------------------------------------//

  void homeMenu()
    {
      do
      {
        cout << "" <<endl;
        cout << "" <<endl;

        ifstream in("welcome.txt");
        if (!in) 
        {
          cout << "Cannot open input file.\n";
        }
        char str[1000];
        while (in) 
        {
            in.getline(str, 1000);
            if (in) cout << str << endl;
        }
        
        cout << "\t\t\t\tPlease select a category" <<endl; 
        cout << "\t\t\t\tEnter '1' for Sedan." <<endl;
        cout << "\t\t\t\tEnter '2' for SUV." <<endl;
        cout << "\t\t\t\tEnter '3' for Minivan." <<endl;
        cout << "\t\t\t\tEnter '4' for a Special surprise." <<endl;
        cout <<endl;
        cout << "\t\t\t\tChoose a category from the above options: ";
        cin >> carCategory;
        cout <<endl;
        cout << "--------------------------------------------------------------------------" <<endl;

        if (carCategory == "1")
        {
          system("CLS");

          cout << " " <<endl;
          cout << " " <<endl;
          Sleep(500);
          sedanMenu();
        }

        if (carCategory == "2")
        {
          system("CLS");

          cout << " " <<endl;
          Sleep(500);
          suvMenu();
        }

        if (carCategory == "3")
        {
          system("CLS");

          cout << " " <<endl;
          Sleep(500);
          minivanMenu();
        }  

        if (carCategory == "4")
        {
          system("CLS");

          wstring url = L"https://www.youtube.com/watch?v=dQw4w9WgXcQ";
          openLink(url);
          Sleep(3000);
          homeMenu();
        }  

        if (carCategory != "1" && carCategory != "2" &&  carCategory != "3" && carCategory != "4")
        {    
            cin.clear();
            cin.ignore();
            system("CLS");
            cout << "Invalid category. Please try again!" <<endl;
        }
      }
      while (carCategory != "1" && carCategory != "2" &&  carCategory != "3" && carCategory != "4");
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

  void sedanMenu()
  {
    do 
    {
      cout << "" <<endl;
      cout << "" <<endl;

      ifstream in("welcome.txt");
      if (!in) 
      {
        cout << "Cannot open input file.\n";
      }
      char str[1000];
      while (in) 
      {
          in.getline(str, 1000);
          if (in) cout << str << endl;
      }
      cout << "You have chosen Sedan" <<endl;
      cout << "" <<endl;

      for (int i = 0; i < 3; i++) 
      {
        cout << i+1 << ". " << sedan.company[i] << " " << sedan.model[i] <<endl;
        cout << "     Number of Seats: " << sedan.seats[i] << endl;
        cout << "     Driving Range: Approximately " << sedan.drivingRange[i] << " miles" << endl;
        cout << "     Transmission: " << sedan.transmission[i] << endl;
        cout << "     Air Conditioning: " << (sedan.airConditioning[i] ? "Yes" : "No") << endl;
        cout << "     Rent Price per Day: $" << sedan.rentPricePerDay[i] << endl;
        cout << endl;
      }
      cout << "----------------------------------------------------------------------------------------------" <<endl;
    
      cout << "Please select a sedan" <<endl; 
      cout << "" <<endl;
      for (int i = 0; i < 3; i++) 
      {
        cout << "Enter '" << i+1 << "' for " << sedan.company[i] << " " << sedan.model[i] <<endl;
      }
      cout <<endl;
      cout << "Choose a sedan from the above options: ";
      cin >> carModel_ID;
      cout << "----------------------------------------------------------------------------------------------" <<endl;
      if (to_string(carModel_ID) != "1" && to_string(carModel_ID) != "2" &&  to_string(carModel_ID) != "3")
        {    
          cout << "" <<endl;
          cin.clear();
          cin.ignore();
          system("CLS");
          cout << "Invalid Sedan. Please try again!" <<endl;
        }
    }
    while (to_string(carModel_ID) != "1" && to_string(carModel_ID) != "2" &&  to_string(carModel_ID) != "3"); 

    carModel = sedan.company[carModel_ID-1] + " " + sedan.model[carModel_ID-1];
    cout <<endl;
    cout << "----------------------------------------------------------------------------------------------" <<endl;

    customerDataMenu();
  };

//-----------------------------------------------------------------------------------------------------------------------------------//

  void suvMenu()
  {
    do 
    {
      cout << "" <<endl;
      cout << "" <<endl;

      ifstream in("welcome.txt");
      if (!in) 
      {
        cout << "Cannot open input file.\n";
      }
      char str[1000];
      while (in) 
      {
          in.getline(str, 1000);
          if (in) cout << str << endl;
      }
      cout << "You have chosen SUV" <<endl;
      cout << "" <<endl;

      for (int i = 0; i < 3; i++) 
      {
        cout << i+1 << ". " << suv.company[i] << " " << suv.model[i] <<endl;
        cout << "     Number of Seats: " << suv.seats[i] << endl;
        cout << "     Driving Range: Approximately " << suv.drivingRange[i] << " miles" << endl;
        cout << "     Transmission: " << suv.transmission[i] << endl;
        cout << "     Air Conditioning: " << (suv.airConditioning[i] ? "Yes" : "No") << endl;
        cout << "     Rent Price per Day: $" << suv.rentPricePerDay[i] << endl;
        cout << endl;
      }
      cout << "----------------------------------------------------------------------------------------------" <<endl;

      cout << "Please select an SUV" <<endl; 
      for (int i = 0; i < 3; i++) 
      {
        cout << "Enter '" << i+1 << "' for " << suv.company[i] << " " << suv.model[i] <<endl;
      }
      cout <<endl;
      cout << "Choose an SUV from the above options: ";
      cin >> carModel_ID;
      cout << "----------------------------------------------------------------------------------------------" <<endl;
      if (to_string(carModel_ID) != "1" && to_string(carModel_ID) != "2" &&  to_string(carModel_ID) != "3")
          {    
            cout << "" <<endl;
            cin.clear();
            cin.ignore();
            system("CLS");
            cout << "Invalid SUV. Please try again!" <<endl;
          }
    }
    while (to_string(carModel_ID) != "1" && to_string(carModel_ID) != "2" &&  to_string(carModel_ID) != "3"); 

    carModel = suv.company[carModel_ID-1] + " " + suv.model[carModel_ID-1];
    cout <<endl;
    cout << "----------------------------------------------------------------------------------------------" <<endl;

    customerDataMenu();
  };

//-----------------------------------------------------------------------------------------------------------------------------------//

  void minivanMenu()
  {
    do 
    {
    cout << "" <<endl;
    cout << "" <<endl;

    ifstream in("welcome.txt");
    if (!in) 
    {
      cout << "Cannot open input file.\n";
    }
    char str[1000];
    while (in) 
    {
        in.getline(str, 1000);
        if (in) cout << str << endl;
    }
    cout << "You have chosen Minivan" <<endl;
    cout << "" <<endl;

    for (int i = 0; i < 3; i++) 
    {
      cout << i+1 << ". " << mini.company[i] << " " << mini.model[i] <<endl;
      cout << "     Number of Seats: " << mini.seats[i] << endl;
      cout << "     Driving Range: Approximately " << mini.drivingRange[i] << " miles" << endl;
      cout << "     Transmission: " << mini.transmission[i] << endl;
      cout << "     Air Conditioning: " << (mini.airConditioning[i] ? "Yes" : "No") << endl;
      cout << "     Rent Price per Day: $" << mini.rentPricePerDay[i] << endl;
      cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------" <<endl;
    
    cout << "Please select a minivan" <<endl; 
    for (int i = 0; i < 3; i++) 
    {
      cout << "Enter '" << i+1 << "' for " << mini.company[i] << " " << mini.model[i] <<endl;
    }
    cout <<endl;
    cout << "Choose a minivan from the above options: ";
    cin >> carModel_ID;
    cout << "----------------------------------------------------------------------------------------------" <<endl;
    if (to_string(carModel_ID) != "1" && to_string(carModel_ID) != "2" &&  to_string(carModel_ID) != "3")
        {    
          cout << "" <<endl;
          cin.clear();
          cin.ignore();
          system("CLS");
          cout << "Invalid Minivan. Please try again!" <<endl;
        }
    }
    while (to_string(carModel_ID) != "1" && to_string(carModel_ID) != "2" &&  to_string(carModel_ID) != "3"); 

    carModel = mini.company[carModel_ID-1] + " " + mini.model[carModel_ID-1];
    cout <<endl;
    cout << "----------------------------------------------------------------------------------------------" <<endl;

    customerDataMenu();
  };

//-----------------------------------------------------------------------------------------------------------------------------------//

  void rentCalculation()
  {
		Sleep(1000);
		cout << "Calculating rent, please wait......" <<endl;
    Sleep(2000);
    system("CLS");
		
		if (carCategory == "1")
        rentalFee = rentDays * sedan.rentPricePerDay[carModel_ID - 1];
    if (carCategory == "2")
        rentalFee = rentDays * suv.rentPricePerDay[carModel_ID - 1];
    if (carCategory == "3")
        rentalFee = rentDays * mini.rentPricePerDay[carModel_ID - 1];
  };

//-----------------------------------------------------------------------------------------------------------------------------------//

  void showInvoice()
  {
    Sleep(1000);
    cout << " " <<endl;
    cout << " Generating invoice......" <<endl;
    Sleep(2000);
    system("CLS");
    cout << "\n\t\t                           MPM Car Rental - Customer Invoice                  " <<endl;
    Sleep(200);
    cout << "\t\t	 --------------------------------------------------------------------------" <<endl;
    Sleep(200);
    cout << "\t\t	| Invoice No. :"<<"------------------|" << setw(40) << "#Cqalw457565485" << " |" <<endl;
    Sleep(200);
    cout << "\t\t	| Customer Name:"<<"-----------------|" << setw(40) << customerName << " |" <<endl;
    Sleep(200);
    cout << "\t\t	| Phone Number:"<<"------------------|" << setw(40) << phoneNumber << " |" <<endl;
    Sleep(200);
    cout << "\t\t	| Car Model :"<<"--------------------|" << setw(40) << carModel << " |" <<endl;
    Sleep(200);
    cout << "\t\t	| Number of days :"<<"---------------|" << setw(40) << rentDays << " |" <<endl;
    Sleep(200);
    cout << "\t\t	| Rent fee :"<<"---------------------|" << setw(38) << rentalFee << " $ |" <<endl;
    Sleep(200);
    cout << "\t\t	| Insurance (10%) :"<<"--------------|" << setw(38) << 0.1 * rentalFee << " $ |" <<endl;
    Sleep(200);
    cout << "\t\t	| Tax and fee (8%) :"<<"-------------|" << setw(38) << 0.08 * 1.1 * rentalFee << " $ |" <<endl;
    Sleep(200);
    cout << "\t\t	 --------------------------------------------------------------------------" <<endl;
    Sleep(200);
    cout << "\t\t	| Total Rental Amount is :"<<"-------|" << setw(38) << 1.188 * rentalFee << " $ |" <<endl;
    Sleep(200);
    cout << "\t\t	 --------------------------------------------------------------------------" <<endl;
    Sleep(200);
    cout << " " <<endl;
    cout << "\t\t	   //////////////////////////////////////////////////////////" <<endl;
    cout << "\t\t	  // You are advised to pay up the amount before due date //" <<endl;
    cout << "\t\t	 //       Otherwise penelty fee will be applied          //" <<endl;
    cout << "\t\t        //////////////////////////////////////////////////////////" <<endl;

    Sleep(2000);
    ifstream inD("thankyou.txt");
    if (!inD) 
    {
      cout << "Cannot open input file.\n";
    }
    char str[200];
    while (inD) 
    {
        inD.getline(str, 200);  
        if (inD) cout << str << endl;
    }
    Sleep(1000);

    system("PAUSE");
    system("CLS");
  };

//-----------------------------------------------------------------------------------------------------------------------------------//

  void donutMenu()
  {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    system("CLS");
    const int durationInSeconds = 8;
    auto startTime = std::chrono::high_resolution_clock::now();

    cout << "" <<endl;
    cout << "" <<endl;

    ifstream in("donut.txt");
    if (!in) 
    {
      cout << "Cannot open input file.\n";
    }
    char str[1000];
    while (in) 
    {
        in.getline(str, 1000);
        if (in) cout << str << endl;
    }

    for (;;) 
    {
      memset(b, 32, 1760);
      memset(z, 0, 7040);
      for (j = 0; j < 6.28; j += 0.07) 
      {
        for (i = 0; i < 6.28; i += 0.02) 
        {
          float c = sin(i);
          float d = cos(j);
          float e = sin(A);
          float f = sin(j);
          float g = cos(A);
          float h = d + 2;
          float D = 1 / (c * h * e + f * g + 5);
          float l = cos(i);
          float m = cos(B);
          float n = sin(B);
          float t = c * h * g - f * e;
          int x = 40 + 30 * D * (l * h * m - t * n);
          int y = 12 + 15 * D * (l * h * n + t * m);
          int o = x + 80 * y;
          int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
          if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) 
          {
            z[o] = D;
            b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
          }
        }
      }
      gotoxy(0, 0);  //Move cursor to the top-left corner of the screen
      for (k = 0; k < 1761; k++) 
      {
        cout << (k % 80 ? b[k] : '\n');  //Print the character
        A += 0.00004;
        B += 0.00002;
      }
      Sleep(3);
      //Check elapsed time
      auto currentTime = std::chrono::high_resolution_clock::now();
      auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
      //Break the loop if the specified duration is reached
      if (elapsedTime >= durationInSeconds) 
      {
          break;
      }
    }
    Sleep(1000);
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "   No more donut!" <<endl;
    Sleep(3000);
    system("CLS");
    homeMenu();
  };
};

//-----------------------------------------------------------------------------------------------------------------------------------//

class Welcome  //welcome class
{
	public:
	void welcomeMes()
	{
    cout << "" <<endl;
    cout << "" <<endl;

    ifstream in("welcome.txt");
    if (!in) 
    {
      cout << "Cannot open input file.\n";
    }
    char str[1000];
    while (in) 
    {
        in.getline(str, 1000);
        if (in) cout << str << endl;
    }

    Sleep(100);
    cout << "\nStarting the program please wait....." <<endl;
    Sleep(1000);
    cout << "\nloading up files....." <<endl;
    Sleep(1000);
    
    system("CLS");
  }
};

//-----------------------------------------------------------------------------------------------------------------------------------//

int main()
{
  Welcome welcome; 
  welcome.welcomeMes(); 
  Menu menu;
  menu.homeMenu();
  menu.rentCalculation();
  menu.showInvoice();
  Sleep(2000);
  menu.donutMenu();

  return 0;
}
