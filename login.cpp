#include<bits/stdc++.h>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include <string>
#include <vector>
using namespace std;
const char* month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
void login();
int Staffadd();
void Staff();
void Staffdisplay();
void Staffmodify();
void Staffremove();
void pursal();
void elec();
void travel();
void Expenses();
void total();
class texpense
{
    private:
        int ele,tra,sal,pur;
        double total;
    public:
        texpense(int a,int b,int c,int d)
        {
            ele=a;
            tra=b;
            sal=c;
            pur=d;
        }
        double caltotal()
        {
            total=ele+tra+sal+pur;
            return total;
        }
        void display()
        {
            cout <<"\t\t\t\t\t CURRENT SALARY AND PURCHASING EXPENSES\n";
            cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
            cout<<"\t\t\t     |   \tTYPE\t "<<"             EXPENSES(In rupees)\t"<<"  |"<<endl;
            cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<<setw(22)<<"ELECTRICITY"<<setw(22)<<ele<<endl;
            cout<<"\t\t\t";
            cout<<setw(22)<<"TRAVEL"<<setw(22)<<tra<<endl;
            cout<<"\t\t\t";
            cout<<setw(22)<<"PURCHASE"<<setw(22)<<pur<<endl;
            cout<<"\t\t\t";
            cout<<setw(22)<<"SALARY"<<setw(22)<<sal<<endl;
            cout<<"\t\t\t";
            cout<<setw(22)<<"TOTAL"<<setw(22)<<fixed<<setprecision(0)<<total<<endl;
        }
};
void del();
void add();
void modify();
void show();
void med();
//void login();
void select();
void cord();
void pord();
void ord();
void patient();
void patientmodify();
void patientremove();
void patientdisplay();
class Supplier {
    string name;
    string phone;

public:
    Supplier(const string &name) : name(name) {}
    Supplier(const string &name, const string &phoneNumber) : name(name), phone(phoneNumber) {}

    string getName() const { return name; }
    void setName(const string &newName) { name = newName; }

    string getPhoneNumber() const { return phone; }
    void setPhoneNumber(const string &newPhoneNumber)  { phone = newPhoneNumber; }
};
void supplieradd(vector<Supplier> &suppliers) {
    system("cls");
    string supplierName;
    cout << "Enter the name of the supplier: ";
    getline(cin, supplierName);

    bool exists = false;
    for (const auto &supplier : suppliers) {
        if (supplier.getName() == supplierName) {
            exists = true;
            break;
        }
    }
    if (!exists) {
        suppliers.push_back(Supplier(supplierName));
    } else {
        cout << "Supplier already exists." << endl;
    }
    system("pause");
}

void addPhone(vector<Supplier> &suppliers) {
    system("cls");
    string supplierName,phone;
    cout << "Enter the name of the supplier: ";
    getline(cin, supplierName);
    cout << "Enter the phone number of the supplier: ";
    getline(cin, phone);


    bool found = false;
    for (auto &supplier : suppliers) {
        if (supplier.getName() == supplierName) {
            supplier.setPhoneNumber(phone);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Supplier not found." << endl;
    }
    system("pause");
}

void displaySuppliers(const vector<Supplier> &suppliers) {
    system("cls");
    cout << setw(20) << left << "Supplier Name" <<  setw(10) << "Phone Number" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (const auto &supplier : suppliers) {
        cout << setw(20) << left << supplier.getName()<<  setw(10) <<supplier.getPhoneNumber() << endl;
    }
    system("pause");
}

void saveToFile(const vector<Supplier> &suppliers, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &supplier : suppliers) {
            file << "Supplier Name: " << supplier.getName() << endl;
            file << "Phone Number: " << supplier.getPhoneNumber() << endl;
            file << endl;
        }
        file.close();
        cout << "Data saved to " << filename << " successfully." << endl;
    } else {
        cout << "Unable to open file " << filename << " for writing." << endl;
    }
}
void loadFromFile(vector<Supplier> &suppliers, const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        string name, phoneNumber;
        bool isName = false;
        while (getline(file, line)) {
            if (line.find("Supplier Name: ") != string::npos) {
                name = line.substr(15);
                isName = true;
            } else if (line.find("Phone Number: ") != string::npos) {
                phoneNumber = line.substr(14);
                suppliers.push_back(Supplier(name, phoneNumber));
                isName = false;
            }
        }
        file.close();
        cout << "Data loaded from " << filename << " successfully." << endl;
    } else {
        cout << "Unable to open file " << filename << " for reading." << endl;
    }
}
void options() {
    vector<Supplier> suppliers;
    loadFromFile(suppliers, "suppliers_data.txt");
    int choice;
    do {
        ppk:
        system("cls");
        cout << "\n\t\t\t\t\t\tMenu:\n";
        cout << "\t\t\t\t\t\t1. Add supplier name\n";
        cout << "\t\t\t\t\t\t2. Add supplier phone number\n";
        cout << "\t\t\t\t\t\t3. Display suppliers\n";
        cout << "\t\t\t\t\t\t4. Save suppliers to file\n";
        cout << "\t\t\t\t\t\t5. Back to main menu\n";
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        fflush(stdin);
        if(cin.fail()) {
            cin.clear();
            cout << endl<<"ERROR!!!! NO STRING TYPE OPTION CAN BE TAKEN ENTER ONLY INT VALUE B/W 1 TO 5"<<endl;
            system("pause");
            system("cls");
            goto ppk;
            return ;
        }
        cin.ignore();
        switch (choice) {
            case 1:
                supplieradd(suppliers);
                break;
            case 2:
                addPhone(suppliers);
                break;
            case 3:
                displaySuppliers(suppliers);
                break;
            case 4:
                saveToFile(suppliers, "suppliers_data.txt");
                break;
            case 5:
                select();
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);
}
void cord(){
    ncap:
    string oa;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t  1-SHOW LIST :"<<endl;
    cout<<"\t\t\t\t\t\t  2-GO BACK :"<<endl<<endl;
    cout<<"\t\t\t\t\t\t  Enter Choice - ";
    cin>>oa;
    cout<<endl<<endl;
    if(oa=="1"){
        fstream file2;
        file2.open("orders\\completed\\list.txt",ios::in);
        cout<<"      -------------------------------------------------------------------------------------------"<<endl;
        cout<<"     |   \tMed Number\t "<<"      Quantity\t\t"<<"   Total Price\t"<<"     Pending Date        |"<<endl;
        cout<<"      -------------------------------------------------------------------------------------------"<<endl;
        while(file2.good()){
            string x;
            getline(file2,x);
            if((x.length())==0){
                continue;
            }
            else{
                ifstream file;
                file.open("orders\\completed\\"+x+".txt");
                while(file.good()){
                    string y;
                    getline(file,y);
                    cout<<setw(22)<<y;
                }
                file.close();
            }
            cout<<endl;
        }
        file2.close();
        cout<<endl<<endl;
        system("pause");
        system("cls");
        goto ncap;
    }
    else if(oa=="2"){
        system("cls");
        ord();
    }
    else{
        system("cls");
        cout<<"\t\t\t\t\tWrong Input......Try Again....."<<endl;
        goto ncap;
    }
}
void mod(){
    xback:
    int m=0;
    string mm1;
    string nn1;
    string l;
    cout<<"\t\t\t\t\tEnter Medicine number - ";
    cin>>nn1;
    ifstream pfile;
    pfile.open("orders\\pending\\list.txt");
    while(pfile.good()){
        getline(pfile,l);
        if(l==nn1){
            m=m+1;
        }
        else{
            continue;
        }
    }
    pfile.close();
    if(m==1){
        lback:
        cout<<"\t\t\t\t\t\t1-Change details : "<<endl;
        cout<<"\t\t\t\t\t\t2-Order Completed :"<<endl<<endl;
        cout<<"\t\t\t\t\t\tEnter choice - ";
        cin>>mm1;
        if(mm1=="1"){
            ofstream lfile;
            lfile.open("orders\\pending\\"+nn1+".txt");
            string a,b;
            int bb;
            cout<<"\t\t\t\t\tEnter Quantity - ";
            cin>>bb;
            cout<<"\t\t\t\t\tEnter Order deadline - ";
            cin>>a;
            ifstream file2;
            file2.open("medicine\\"+nn1+".txt");
            while(file2.good()){
                getline(file2,b);
            }
            int pop=stoi(b);
            int prc = pop*bb;
            string bb1=to_string(bb);
            string prc1=to_string(prc);
            lfile<<nn1<<endl<<bb1<<endl<<prc1<<endl<<a;
            cout<<"\t\t\t\t\tMODIFIED SUCCESFULLY........"<<endl<<endl;
            system("timeout 6");
            system("cls");
            lfile.close();
            file2.close();
            //func to get back to order menu
        }
        else if(mm1=="2"){
            fstream ofile;
            ofile.open("orders\\completed\\list.txt",ios::app);
            ofile<<nn1<<endl;
            string op = "move orders\\pending\\"+nn1+".txt";
            string op2=" orders\\completed";
            string op3 = op +op2;
            system(op3.c_str());
            system("cls");
            cout<<endl<<endl<<"\t\t\t\t\tSure, Moving it to completed list....."<<endl;
            ifstream ifile;
            ifile.open("orders\\pending\\list.txt");
            ofstream ifile2;
            ifile2.open("orders\\pending\\list1.txt");
            while(ifile.good()){
                string lk;
                getline(ifile,lk);
                if(lk==nn1){
                    continue;
                }
                else{
                    ifile2<<lk<<endl;
                }
            }
            ofile.close();
            ifile.close();
            ifile2.close();
            string jj="del orders\\pending\\list.txt";
            system(jj.c_str());
            string kp="rename orders\\pending\\list1.txt list.txt";
            system(kp.c_str());
            system("timeout 6");
            system("cls");
            //func to get back to order menu
        }
        else{
            system("cls");
            cout<<"\t\t\t\t\tWrong choice......Try again...."<<endl<<endl;
            goto lback;
        }
    }
    else{
        system("cls");
        cout<<endl<<endl<<"\t\t\t\t\tMedicine dont exists..... Try Again....."<<endl<<endl;
        goto xback;
    }
}
void pord(){
    backy:
    string nn;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t1 - ADD ORDER :"<<endl;
    cout<<"\t\t\t\t\t\t2 - MODIFY ORDER :"<<endl;
    //cout<<"\t\t\t\t\t\t3 - DELETE ORDER :"<<endl;
    cout<<"\t\t\t\t\t\t3 - SHOW LIST :"<<endl;
    cout<<"\t\t\t\t\t\t4 - GO BACK :"<<endl;
    cout<<"\t\t\t\t\t\tEnter your choice number - ";
    cin>>nn;
    if(nn=="1"){
        pback:
        string g;int m=0;string gg;
        cout<<"Enter medicine number - ";
        cin>>g;
        ifstream pfile;
        pfile.open("medicine\\list.txt");
        while(pfile.good()){
            string l;
            getline(pfile,l);
            if(l==g){
                m=m+1;
            }
            else{
                continue;
            }
        }
        pfile.close();
        if(m==1){
            int k;
            cout<<"Enter Quantity - ";
            cin>>k;
            cout<<"Enter Order deadline - ";
            cin>>gg;
            string pp;
            fstream file1;
            ifstream file2;
            file1.open("orders\\pending\\list.txt",ios::app);
            file2.open("medicine\\"+g+".txt");
            while(file2.good()){
                getline(file2,pp);
            }
            int pop=stoi(pp);
            int prc = pop*k;
            string k1=to_string(k);
            string prc1=to_string(prc);
            ofstream file3;
            file3.open("orders\\pending\\"+g+".txt");
            file3<<g<<endl<<k1<<endl<<prc1<<endl;
            file3<<gg;
            fflush(stdin);
            file1<<g<<endl;
            fflush(stdin);
            cout<<"Added Succesfully......"<<endl<<endl;
            file1.close();
            file2.close();
            system("timeout 6");
            system("cls");
            file3.close();
            goto backy;
        }
        else{
            system("cls");
            cout<<endl<<endl<<"\t\t\t\t\tMedicine dont exists..... Try Again....."<<endl<<endl;
            goto pback;
        }
    }
    else if(nn=="2"){
        mod();
    }
    else if(nn=="3"){
        system("cls");
        fstream file2;
        file2.open("orders\\pending\\list.txt",ios::in);
        cout<<endl<<endl;
        cout<<"      -------------------------------------------------------------------------------------------"<<endl;
        cout<<"     |   \tMed Number\t "<<"      Quantity\t\t"<<"   Total Price\t"<<"     Pending Date        |"<<endl;
        cout<<"      -------------------------------------------------------------------------------------------"<<endl;
        while(file2.good()){
            string x;
            getline(file2,x);
            if((x.length())==0){
                continue;
            }
            else{
                ifstream file;
                file.open("orders\\pending\\"+x+".txt");
                while(file.good()){
                    string y;
                    getline(file,y);
                    cout<<setw(22)<<y;
                }
                file.close();
                cout<<endl;
            }
        }
        cout<<endl<<endl;
        file2.close();
        system("pause");
        system("cls");
        goto backy;
    }
    else if(nn=="4"){
        system("cls");
        ord();
    }
    else{
        system("cls");
        cout<<endl<<endl<<"\t\t\t\t\t\tInvalid choice.....Try Again...."<<endl<<endl;
        goto backy;
    }
}
void ord(){
    system("cls");
    backx:
    string n;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t1 - PENDING ORDERS :"<<endl;
    cout<<"\t\t\t\t\t\t2 - COMPLETED ORDERS :"<<endl;
    cout<<"\t\t\t\t\t\t3 - GO BACK :"<<endl;
    cout<<"\t\t\t\t\t\tEnter your choice number - ";
    cin>>n;
    if(n=="1"){
        system("cls");
        pord();
    }
    else if(n=="2"){
        system("cls");
        cord();
    }
    else if(n=="3"){
        select();
    }
    else{
        system("cls");
        cout<<endl<<endl<<"\t\t\t\t\t\tWrong Choice..... Try again..."<<endl<<endl;
        goto backx;
    }
}
void total()
{
        system("cls");
        int tsum=0;
        int esum=0;
        int ssum=0;
        int psum=0;
        ifstream fin1;
        fin1.open("Expenses\\Travel.txt");
        for(int i=0;i<12;i++){
            string a;
            getline(fin1,a);
            int b=stoi(a);
            tsum+=b;
        }
        fin1.close();
        ifstream fin2;
        fin2.open("Expenses\\Electricity.txt");
        for(int i=0;i<12;i++){
            string a;
            getline(fin2,a);
            int b=stoi(a);
            esum+=b;
        }
        fin2.close();
        ifstream file2;
        file2.open("orders\\pending\\list.txt");
        while(file2.good()){
            string x;
            getline(file2,x);
            if((x.length())==0){
                continue;
            }
            else{
                ifstream file;
                string y;
                file.open("orders\\pending\\"+x+".txt");
                for(int i=0;i<3;i++){getline(file,y);}
                int b=stoi(y);
                psum+=b;
                file.close();
            }
        }
        file2.close();
        ifstream file1;
        file1.open("Staff details\\list.txt");
        while(file1.good()){
            string a;
            getline(file1,a);
            if((a.length())==0){
                continue;
            }
            else{
                ifstream file3;
                string d;
                file3.open("Staff details\\"+a+".txt");
                for(int i=0;i<5;i++){getline(file3,d);}
                int b=stoi(d);
                ssum+=b;
                file3.close();
            }
        }
        file1.close();
        texpense exp(esum,tsum,ssum,psum);
        exp.caltotal();
        exp.display();
        system("pause");
        Expenses();
}
void pursal()
{
        system("cls");
        ifstream file2;
        file2.open("orders\\pending\\list.txt");
        int pursum=0;
        while(file2.good()){
            string x;
            getline(file2,x);
            if((x.length())==0){
                continue;
            }
            else{
                ifstream file;
                string y;
                file.open("orders\\pending\\"+x+".txt");
                for(int i=0;i<3;i++){getline(file,y);}
                int b=stoi(y);
                pursum+=b;
                file.close();
            }
        }
        file2.close();
        ifstream file1;
        file1.open("Staff details\\list.txt");
        int salsum=0;
        while(file1.good()){
            string a;
            getline(file1,a);
            if((a.length())==0){
                continue;
            }
            else{
                ifstream file3;
                string d;
                file3.open("Staff details\\"+a+".txt");
                for(int i=0;i<5;i++){getline(file3,d);}
                int b=stoi(d);
                salsum+=b;
                file3.close();
            }
        }
        file1.close();
        cout <<"\t\t\t\t\t CURRENT SALARY AND PURCHASING EXPENSES\n";
    cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
    cout<<"\t\t\t     |   \tTYPE\t "<<"             EXPENSES(In rupees)\t"<<"  |"<<endl;
    cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
    cout<<"\t\t\t";
        cout<<setw(22)<<"PURCHASE"<<setw(22)<<pursum<<endl;
        cout<<"\t\t\t";
        cout<<setw(22)<<"SALARY"<<setw(22)<<salsum<<endl;
        system("pause");
        Expenses();
}
void elec()
{
    system("cls");
    ifstream fin;
    fin.open("Expenses\\Electricity.txt");
    system("cls");
    int i=0;
    cout <<"\t\t\t\t\t ELECTRICITY BILL FOR YEAR 2024\n";
    cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
    cout<<"\t\t\t     |   \tMONTH\t "<<"             BILL(In rupees)\t\t"<<"  |"<<endl;
    cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
    for(i=0;i<12;i++){
        string x;
        getline(fin,x);
        cout<<"\t\t\t";
        cout<<setw(22)<<month[i]<<setw(22)<<x<<endl;
    }
    fin.close();
    fflush(stdin);
    Start:
    cout<<"Do you want to know the total electricity expenses(y/n):";
    string y;
    cin>>y;
    if(y=="y"||y=="Y")
    {
        int sum=0;
        ifstream fin1;
        fin1.open("Expenses\\Electricity.txt");
        for(i=0;i<12;i++){
            string a;
            getline(fin1,a);
            int b=stoi(a);
            sum+=b;
        }
        cout<<"\n\t\t TOTAL ELECTRICITY EXPENSES="<<sum<<endl;
        fin1.close();
        system("pause");
        Expenses();
    }
    else if(y=="n"||y=="N"){
        system("timeout 6");
        Expenses();
    }
    else{
        cout<<"\t\t\t WRONG INPUT!!!\n";
        system("timeout 6");
        goto Start;
    }
}
void travel()
{
    system("cls");
    ifstream fin;
    fin.open("Expenses\\Travel.txt");
    system("cls");
    int i=0;
    cout <<"\t\t\t\t\t TRAVEL EXPENSE FOR YEAR 2024\n";
    cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
    cout<<"\t\t\t     |   \tMONTH\t "<<"             TRAVEL EXPENSE\t\t"<<"  |"<<endl;
    cout<<"\t\t\t      ------------------------------------------------------------"<<endl;
    for(i=0;i<12;i++){
        string x;
        getline(fin,x);
        cout<<"\t\t\t";
        cout<<setw(22)<<month[i]<<setw(22)<<x<<endl;
    }
    fin.close();
    fflush(stdin);
    Start:
    cout<<"Do you want to know the total travel expenses(y/n):";
    string y;
    cin>>y;
    if(y=="y"||y=="Y")
    {
        int sum=0;
        ifstream fin1;
        fin1.open("Expenses\\Travel.txt");
        for(i=0;i<12;i++){
            string a;
            getline(fin1,a);
            int b=stoi(a);
            sum+=b;
        }
        cout<<"\n\t\t TOTAL TRAVEL EXPENSES="<<sum<<endl;
        fin1.close();
        system("pause");
        Expenses();
    }
    else if(y=="n"||y=="N"){
        system("timeout 6");
        Expenses();
    }
    else{
        cout<<"\t\t\t WRONG INPUT!!!\n";
        system("timeout 6");
        goto Start;
    }
}
void Expenses()
{
    system("cls");
    int choice ;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t\t1-DISPLAY ELECTIRICITY BILLS"<<endl;
    cout <<"\t\t\t\t\t\t2-DISPLAY TRAVEL EXPENSES"<<endl;
    cout <<"\t\t\t\t\t\t3-DISPLAY CURRENT PURCHASING AND SALARY EXPENSES"<<endl;
    cout <<"\t\t\t\t\t\t4-DISPLAY TOTAL EXPENSES"<<endl;
    cout <<"\t\t\t\t\t\t5-BACK TO MAIN MENU"<<endl;
    cout<<"\t\t\t\t\t\tENTER YOUR CHOICE- ";
    cin>>choice;
    if (std::cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! ";
            return ;
        }
    switch(choice){
        case 1:
            elec();
            break;
        case 2:
            travel();
            break;
        case 3:
            pursal();
            break;
        case 4:
            total();
            break;
        case 5:
            select();
            break;
        default:
            cout<<"WRONG INPUT!!\n";
            system("pause");
            Expenses();
    }
}
void del(){
    back2:
    string n;int l=0;
    cout<<endl<<"\t\t\t\t\t\tEnter Medicine number you want to delete - ";
    cin>>n;
    ifstream file("medicine\\list.txt");
    while(file.good()){
        string j;
        getline(file,j);
        if(j==n){
            l=l+1;
        }
        else{
            continue;
        }
    }
    file.close();
    if(l==1){
        back1:
        char t;
        cout<<endl<<"\t\t\t\t\t\tAre you sure you want to delete it(y or n) -";
        fflush(stdout);
        cin>>t;
        fflush(stdin);
        if(t=='y'){
            string f=("del medicine\\"+n+".txt");
            system(f.c_str());
            ofstream file1;
            file1.open("medicine\\list1.txt");
            ifstream f2;
            f2.open("medicine\\list.txt");
            while(f2.good()){
                string ss;
                getline(f2,ss);
                if(ss==n){
                    continue;
                }
                else{
                    file1<<ss<<endl;
                }
            }
            f2.close();
            file1.close();
            system("del medicine\\list.txt");
            system("rename medicine\\list1.txt list.txt" );
            // system("pause");
            system("cls");
            cout<<"\t\t\t\t\t\tDeleted succesfully....."<<endl<<endl;
            cout<<"\t\t\t\t\t\tUpdated list......"<<endl<<endl<<endl;
            show();
            system("pause");
        }
        else if(t=='n'){
            system("cls");
            cout<<endl<<endl<<endl;
            cout<<endl<<"\t\t\t\t\t\tSure, not deleting the provided medicine......."<<endl<<endl;
            system("timeout 6");
            system("cls");
            med();
        }
        else{
            system("cls");
            cout<<endl<<"\t\t\t\t\t\tWrong input try again....."<<endl<<endl;
            goto back1;
        }
    }
    else{
        system("cls");
        cout<<endl<<"\t\t\t\t\t\tFile dont exist try again....."<<endl<<endl;
        goto back2;
    }
}
void modify(){

    system("cls");
    uuk:
    string x;
    string name,exp,price;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\tEnter Medicine number you want to modify - ";
    cin>>x;
    string n;int l=0;
    ifstream file("medicine\\list.txt");
    while(file.good()){
        string j;
        getline(file,j);
        if(j==x){
            l=l+1;
        }
        else{
            continue;
        }
    }
    if(l==1){
        cout<<endl<<endl;
        ofstream file;
        file.open("medicine\\"+x+".txt");
        cout<<endl<<"\t\t\t\t\t\tEnter Medicine name - ";
        cin>>name;
        cout<<endl<<"\t\t\t\t\t\tEnter expiry date - ";
        cin>>exp;
        cout<<endl<<"\t\t\t\t\t\tENTER PRICE - ";
        cin>>price;
        cout<<endl<<endl<<"\t\t\t\t\t\t.....SUCCESFULLY MODIFIED....."<<endl<<endl;
        file<<x<<endl<<name<<endl<<exp<<endl<<price;
        file.close();
        system("pause");
        med();
    }
    else{
        system("cls");
        cout<<endl<<endl<<"\t\t\t\t\tMedicine dont exist try again...."<<endl<<endl;
        goto uuk;
    }
    /*cout<<endl<<endl;
    ofstream file;
    file.open("medicine\\"+x+".txt");
    cout<<endl<<"\t\t\t\t\t\tEnter Medicine name - ";
    cin>>name;
    cout<<endl<<"\t\t\t\t\t\tEnter expiry date - ";
    cin>>exp;
    cout<<endl<<"\t\t\t\t\t\tENTER PRICE - ";
    cin>>price;
    cout<<endl<<endl<<"\t\t\t\t\t\t.....SUCCESFULLY MODIFIED....."<<endl<<endl;
    file<<x<<endl<<name<<endl<<exp<<endl<<price;
    file.close();
    system("pause");
    med();*/
}
void show(){
    system("cls");
    fstream file2;
    file2.open("medicine\\list.txt",ios::in);
    file2.seekg(2);
    cout<<"      -------------------------------------------------------------------------------------------"<<endl;
    cout<<"     |   \tMed Number\t "<<"      Name\t\t"<<"   Expiry\t\t"<<"    Price        |"<<endl;
    cout<<"      -------------------------------------------------------------------------------------------"<<endl;
    while(file2.good()){
        string x;
        getline(file2,x);
        if((x.length())==0){
            continue;
        }
        else{
            ifstream file;
            file.open("medicine\\"+x+".txt");
            while(file.good()){
                string y;
                getline(file,y);
                cout<<setw(22)<<y;
            }
            file.close();//check
        }
        cout<<endl;
    }
    file2.close();
    system("pause");
    med();
}
void add(){
    int n;
    cout<<"\t\t\t\t\t\tHow many medicines you want to add - ";
    cin>>n;
    system("cls");
    cout<<endl;
    fstream file2;
    file2.open("medicine\\list.txt",ios::app);
    for(int i=0;i<n;i++){
        string no;
        string name;
        string exp;
        int price;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<endl<<"\t\t\t\t\t\tEnter Medicine Number - ";
        cin>>no;
        ofstream file;
        file.open("medicine\\"+no+".txt",ios::out);
        file2<<no<<endl;
        cout<<endl<<"\t\t\t\t\t\tEnter Medicine name - ";
        cin>>name;
        cout<<endl<<"\t\t\t\t\t\tEnter expiry date - ";
        cin>>exp;
        cout<<endl<<"\t\t\t\t\t\tENTER PRICE - ";
        cin>>price;
        cout<<endl<<endl<<"\t\t\t\t\t\t.....SUCCESFULLY ADDED....."<<endl<<endl;
        system("timeout 6");
        file<<no<<endl<<name<<endl<<exp<<endl<<price;
        system("cls");
        file.close();
    }
    file2.close();
    system("pause");
    med();
}
void med(){
    system("cls");
    string x;
    bac:
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t1 - ADD MEDICINE :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t2 - SHOW LIST :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t3 - MODIFY LIST :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t4 - DELETE MEDICINE :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t5 - GO BACK :"<<endl<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\tEnter your choice number - ";
    fflush(stdout);
    cin>>x;
    fflush(stdin);
    if(x=="1"){
        add();
    }
    else if(x=="2"){
        show();
    }
    else if(x=="3"){
        modify();
    }
    else if(x=="4"){
        del();
    }
    else if(x=="5"){
        select();
    }
    else{
        system("cls");
        cout<<endl<<"\t\t\t\t\t\tINVALID CHOICE TRY AGAIN"<<endl;
        goto bac;
    }
}
int Staffadd(){
    fflush(stdin);
    string ename, epos;
    long long int esal, eid;
    int eage;
    system("cls");
    cout << "NAME- ";
    fflush(stdin);
    getline(cin, ename);
    cout << "AGE- ";
    cin >> eage;
    if (std::cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! ";
            return 0;
        }
    else{
    if(eage<18||eage>60){
        cout <<"AGE CANNOT BE LESS THAN 18 OR MORE THAN 60!! \n";
        system("pause");
        fflush(stdin);
        Staff();
    }
    cout << "POSITION- ";
    fflush(stdin);
    getline(cin, epos);
    cout << "SALARY- ";
    cin >> esal;
    if (std::cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! ";
            return 0;
        }
    if(esal<1500){
        cout <<"SALARY CANNOT BE LESS THAN 1500!! \n";
        system("pause");
        Staffadd();
    }
    cout << "ID- ";
    cin >> eid;
    if (std::cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! ";
            return 0;
        }
    string id=to_string(eid);
    ifstream file2;
    file2.open("Staff details/list.txt");
    int count = 0;
    string f;
    while(file2.good()){
        getline(file2,f);
        if(f==id){
            count++;
            break;
        }
    }
    file2.close();
    if (count==1){
        cout<<"Employee ID already exists !!\n";
        system ("pause");
        Staff();
    }
    ofstream fout;
    fout.open("Staff details/" + to_string(eid) + ".txt", ios::app | ios::out);
    if (!fout.is_open()) {
        cout << "Error in file opening ";
    }
    else {
        fout << ename << "\n" << eid << "\n" << eage << "\n" << epos << "\n" << esal << "\n";
        cout << "Details entered successfully!!\n";
        fout.close();
    }
    ofstream fout1;
    fout1.open("Staff details/list.txt",ios::app);
    fout1<<eid<<endl;
    fout1.close();
    system ("pause");
    Staff();}
}
void Staffdisplay(){
    system("cls");
    fstream file2;
    file2.open("Staff details\\list.txt",ios::in);
    file2.seekg(2);
    cout<<"      --------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"     |   \tName\t "<<"             Staff ID\t\t"<<"       AGE\t\t"<<"POSITION\t\t"<<"  SALARY          |"<<endl;
    cout<<"      --------------------------------------------------------------------------------------------------------------------"<<endl;
    while(file2.good()){
        string x;
        getline(file2,x);
        if((x.length())==0){
            continue;
        }
        else{
            ifstream file;
            file.open("Staff details/"+x+".txt");
            while(file.good()){
                string y;
                getline(file,y);
                cout<<setw(22)<<y;
            }
        }
        cout<<endl;
    }
    system("pause");
    Staff();
}
void Staffmodify(){
    system("cls");
    int eid;
    cout<<"Enter the Employee ID you want to Modify-";
    cin>>eid;
    if (std::cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! ";
            return ;
        }
    string id=to_string(eid);
    ifstream file2;
    file2.open("Staff details/list.txt");
    int count = 0;
    string f;
    while(file2.good()){
        getline(file2,f);
        if(f==id){
            count++;
            break;
        }
    }
    file2.close();
    if (count==0){
        cout<<"Employee Not found !!\n";
        system ("pause");
        Staff();
    }
    ifstream fin;
    fin.open("Staff details/"+to_string(eid)+".txt");
    cout<<"      --------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"     |   \tName\t "<<"             Staff ID\t\t"<<"       AGE\t\t"<<"POSITION\t\t"<<"  SALARY          |"<<endl;
    cout<<"      --------------------------------------------------------------------------------------------------------------------"<<endl;
    while(fin.good()){
            string y;
            getline(fin,y);
            cout<<setw(22)<<y;
        }
        fin.close();
        char c;
        Stepback:
        cout<<"\nAre you sure you want to Modify Details!!(Y/N)";
        cin>>c;

        if(c=='Y'||c=='y'){
            string eid1=to_string(eid)+".txt";
            string del = "Staff details/" + eid1;
            remove (del.c_str());
            ifstream finList("Staff details/list.txt");
        ofstream foutList("Staff details/list1.txt");
        if (!finList || !foutList) {
            cout << "Error updating employee list." << endl;
            return;
        }
        string idToRemove = to_string(eid);
        string id;
        while (getline(finList, id)) {
            if (id != idToRemove) {
                foutList << id << endl;
            }
        }
        finList.close();
        foutList.close();
        ifstream finList1("Staff details/list1.txt");
        ofstream foutList1("Staff details/list.txt");
        if (!finList1 || !foutList1) {
            cout << "Error updating employee list." << endl;
            return;
        }
        string idToRemove1 = to_string(eid);
        string id1;
        while (getline(finList1, id1)) {
            if (id1!= idToRemove1) {
                foutList1 << id1 << endl;
            }
        }
        finList1.close();
        foutList1.close();

        string path = "Staff details/list1.txt";
        if (remove(path.c_str()) != 0) {
            cout << "Error deleting list file: "  << endl;
            return;
        }
        system("pause");
            Staffadd();
        }
        else if(c=='N'||c=='n'){
            system("pause");
            Staff();
        }
        else{
            cout<<"WRONG INPUT!!\n";
            system("pause");
            goto Stepback;
        }
}
void Staffremove() {
    int eid;
    cout << "Enter the Employee ID you want to remove: ";
    cin >> eid;
    if (std::cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! ";
            return ;
        }
    string filename = "Staff details/" + to_string(eid) + ".txt";
    ifstream fin(filename);
    if (!fin) {
        cout << "Employee with ID " << eid << " not found." << endl;
        system("timeout 6");
        Staff();
    }

    cout << "Employee details:" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|   \tName\t             Staff ID\t\t       AGE\t\tPOSITION\t\t  SALARY          |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    string line;
    while (getline(fin, line)) {
        cout << setw(22) << line ;
    }
    cout<<endl;
    fin.close();
    char confirm;
    cout << "Are you sure you want to remove the employee? (Y/N): ";
    cin >> confirm;
    if (confirm == 'Y' || confirm == 'y') {
        if (remove(filename.c_str()) != 0) {
            cout << "Error deleting file: "  << endl;
            return;
        }

        ifstream finList("Staff details/list.txt");
        ofstream foutList("Staff details/list1.txt");
        if (!finList || !foutList) {
            cout << "Error updating employee list." << endl;
            return;
        }
        string idToRemove = to_string(eid);
        string id;
        while (getline(finList, id)) {
            if (id != idToRemove) {
                foutList << id << endl;
            }
        }
        finList.close();
        foutList.close();
        ifstream finList1("Staff details/list1.txt");
        ofstream foutList1("Staff details/list.txt");
        if (!finList1 || !foutList1) {
            cout << "Error updating employee list." << endl;
            return;
        }
        string idToRemove1 = to_string(eid);
        string id1;
        while (getline(finList1, id1)) {
            if (id1!= idToRemove1) {
                foutList1 << id1 << endl;
            }
        }
        finList1.close();
        foutList1.close();

        string path = "Staff details/list1.txt";
        if (remove(path.c_str()) != 0) {
            cerr << "Error deleting list file: " << strerror(errno) << endl;
            return;
        }

        cout << "Employee removed successfully." << endl;
        system("pause");
        Staff();
    }
    else{
        cout << "Removal canceled." << endl;
        system("pause");
        system("cls");
        Staff();
    }
}
void Staff(){
    system("cls");
    int choice ;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t\t1-ADD STAFF MEMBER"<<endl;
    cout <<"\t\t\t\t\t\t2-DISPLAY STAFF MEMBERS"<<endl;
    cout <<"\t\t\t\t\t\t3-MODIFY STAFF MEMBER"<<endl;
    cout <<"\t\t\t\t\t\t4-REMOVE STAFF MEMBER"<<endl;
    cout <<"\t\t\t\t\t\t5-BACK TO MAIN MENU"<<endl;
    cout<<"\t\t\t\t\t\tENTER YOUR CHOICE- ";
    cin>>choice;
    if (std::cin.fail()) {
            cin.clear();
            cout << "Invalid input! ";
            return ;
        }
    switch(choice){
        case 1:
        Staffadd();
        break;
        case 2:
        Staffdisplay();
        break;
        case 3:
        Staffmodify();
        break;
        case 4:
        Staffremove();
        break;
        case 5:
        select();
        break;
        default:
        cout<<"WRONG INPUT!!\n";
        system("pause");
        Staff();
    }
}
void patientmodify() {
    system("cls");
    int id;
    cout << "Enter the patient ID you want to Modify: ";
    cin >> id;
    if(cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! NO STRING TYPE ID CAN BE TAKEN ENTER ONLY INT VALUE\n";
            system("pause");
            return ;
    }
    cin.ignore();
    ifstream f("Patient\\" + to_string(id) + ".txt");
    if (!f.is_open()) {
        cout << "Patient with ID " << id << " not found." << endl;
        system("pause");
        patient();
        return;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|Name\t\t\t ID\t\tAGE   DISEASE\t\t\t\t   |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    string name, age, disease;
    getline(f, name);
    f >> id;
    f.ignore();
    getline(f, age);
    getline(f, disease);
    f.close();
    cout  << setw(20) << left << name << "\t" << setw(10) << id << "\t"
        << setw(5) << age << "\t" << setw(20) << disease  << endl;
    char c;
    cout << "Are you sure you want to Modify Details? (Y/N): ";
    cin >> c;
    if (c == 'Y' || c == 'y') {
        ofstream fout("Patient\\" + to_string(id) + ".txt");
        if (!fout.is_open()) {
            cout << "Error in file opening.";
            system("pause");
            return;
        }
        cout << "Enter new details: \n";
        cout << "NAME: ";
        cin.ignore();
        getline(cin, name);
        cout << "AGE: ";
        getline(cin, age);
        cout << "DISEASE: ";
        getline(cin, disease);
        fout << name << "\n" << id << "\n" << age << "\n" << disease << "\n";
        fout.close();
        cout << "Details modified successfully." << endl;
        system("pause");
        patient();
    }
    else if (c == 'N' || c == 'n') {
        system("pause");
        patient();
    }
    else {
        cout << "WRONG INPUT!!" << endl;
        system("pause");
        patientmodify();
    }
}
void patientRemove(){
    system("cls");
    int id;
    cout << "Enter the patient ID you want to remove: ";
    cin >> id;
    if(cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! NO STRING TYPE ID CAN BE TAKEN ENTER ONLY INT VALUE\n";
            system("pause");
            return ;
    }
    cin.ignore();
    ifstream fin("Patient\\" + to_string(id) + ".txt");
    if (!fin.is_open()) {
        cout << "Patient with ID " << id << " not found." << endl;
        system("pause");
        patient();
        return;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|Name\t\t\t ID\t\tAGE   DISEASE\t\t\t\t   |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    string name, age, disease;
    getline(fin, name);
    fin >> id;
    fin.ignore();
    getline(fin, age);
    getline(fin, disease);
    cout << "| " << setw(20) << left << name << "\t" << setw(10) << id << "\t"
         << setw(5) << age << "\t" << setw(20) << disease << " |" << endl;
    fin.close();
    char c;
    cout << "Are you sure you want to remove the patient? (Y/N): ";
    cin >> c;
    cin.ignore();
    if (c == 'Y' || c == 'y') {
        string eid1 = to_string(id) + ".txt";
        string del = "Patient\\" + eid1;
        remove(del.c_str());
        cout << "Patient Removed successfully!" << endl;
        ifstream finList("patient\\list.txt");
        ofstream foutList("patient\\list1.txt");
        if (!finList || !foutList) {
            cerr << "Error updating employee list." << endl;
            return;
        }
        string idToRemove = to_string(id);
        string id;
        while (getline(finList, id)) {
            if (id != idToRemove) {
                foutList << id << endl;
            }
        }
        finList.close();
        foutList.close();
        ifstream finList1("patient\\list1.txt");
        ofstream foutList1("patient\\list.txt");
        if (!finList1 || !foutList1) {
            cerr << "Error updating employee list." << endl;
            return;
        }
        string id1;
        while (getline(finList1, id1)) {
            if (id1!= idToRemove) {
                foutList1 << id1 << endl;
            }
        }
        finList1.close();
        foutList1.close();

        string path = "patient\\list1.txt";
        if (remove(path.c_str()) != 0) {
            cerr << "Error deleting list file: " << strerror(errno) << endl;
            return;
        }
        system("pause");
        patient();
    }
    else if (c == 'N' || c == 'n') {
        system("pause");
        patient();
    }
    else {
        cout << "WRONG INPUT!!" << endl;
        system("pause");
        patientRemove();
    }
    system("pause");
}
void patientdisplay() {
    ifstream listFile("patient\\list.txt");
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|Name\t\t\t ID\t\tAGE   DISEASE\t\t\t\t   |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    if (listFile.is_open()) {
        string patientID;
        while (getline(listFile, patientID)) {
            ifstream patientFile("patient\\" + patientID + ".txt");
            if (patientFile.is_open()) {
                string name, age, disease;
                getline(patientFile, name);
                getline(patientFile, patientID);
                getline(patientFile, age);
                getline(patientFile, disease);
                cout  << setw(20) << left << name << "\t" << setw(10) << patientID << "\t"
                     << setw(5) << age << "\t" << setw(20) << disease  << endl;
                patientFile.close();
            }
        }
        listFile.close();
    } else {
        cout << "Error: Unable to open list file." << endl;
    }
    system("pause");
    patient();
}
int addpatient() {
    system("cls");
    string ename, epos;
    int eage, eid;
    cout << "NAME: ";
    cin.ignore();
    getline(cin, ename);
    cout << "AGE: ";
    cin >> eage;
    if(cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! NO STRING TYPE AGE CAN BE TAKEN. ENTER ONLY INT VALUE\n";
            system("pause");
            return 0;
    }
    cout << "DISEASE: ";
    cin.ignore();
    getline(cin, epos);
    cout << "ID: ";
    cin >> eid;
    if(cin.fail()) {
            cin.clear();
            cout << "ERROR!!!! NO STRING TYPE ID CAN BE TAKEN. ENTER ONLY INT VALUE\n";
            system("pause");
            return 0;
    }

    cin.ignore();
    ifstream checkFile("patient\\" + to_string(eid) + ".txt");
    if (checkFile) {
        cout << "A patient with ID " << eid << " already exists. Please choose a different ID." << endl;
        checkFile.close();
        system("pause");
        addpatient();
        return 0;
    }
    ofstream f("patient\\" + to_string(eid) + ".txt");
    if (!f.is_open()) {
        cout << "Error in file opening ";
        system("pause");
        return 0;
    }
    f << ename << "\n" << eid << "\n" << eage << "\n" << epos << "\n";
    cout << "Details entered successfully!!\n";
    f.close();
    ofstream fi1("patient/list.txt", ios::app);
    if (!fi1.is_open()) {
        cout << "Error in file opening ";
        system("pause");
        return 0;
    }
    fi1 << eid << endl;
    fi1.close();
    system("pause");
    patient();
}
void patient(){
    //ool:
    system("cls");
    int c;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t\t1-Add Patient Name"<<endl;
    cout <<"\t\t\t\t\t\t2-Display Patient Details"<<endl;
    cout <<"\t\t\t\t\t\t3-Modify Patient Details"<<endl;
    cout <<"\t\t\t\t\t\t4-Remove Patient"<<endl;
    cout <<"\t\t\t\t\t\t5-Previous Menu"<<endl;
    cout<<"\t\t\t\t\t\tEnter your Choice- ";
    fflush(stdout);
    cin>>c;
    fflush(stdin);
    switch(c){
        case 1:
        system("cls");
        addpatient();
        break;
        case 2:
        system("cls");
        patientdisplay();
        break;
        case 3:
        patientmodify();
        break;
        case 4:
        patientRemove();
        break;
        case 5:
        select();
        break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            fflush(stdout);
            system("pause");
            //goto ool;
            patient();
    }
}
void login(){
    system("title Pharmacy Management System");
        system("@echo off");
        system("cls");
        system("color 70");
        cout<<"\t\t\t\t\t\t"<<" ---------------------------"<<endl;
        cout<<"\t\t\t\t\t\t"<<"|                           |"<<endl;
        cout<<"\t\t\t\t\t\t"<<"|    PHARMACY MANAGEMENT    |"<<endl;
        cout<<"\t\t\t\t\t\t"<<"|          SYSTEM           |"<<endl;
        cout<<"\t\t\t\t\t\t"<<"|                           |"<<endl;
        cout<<"\t\t\t\t\t\t"<<" ---------------------------"<<endl;
        cout<<"\t\t\t\t"<<"    WELCOME TO THE INTERFACE OF PHARMACY MANAGEMENT SYSTEM"<<endl<<endl<<endl<<endl<<endl;
        stepback:
        string user;
        cout<<"\t\t\t\t\t\t"<<"Username :";
        cin>>user;
        fflush(stdin);
        cout<<"\t\t\t\t\t\t"<<"Password :";
        char password[20];
        int i = 0;
        char ch;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {
                if (i > 0) {
                    cout << "\b \b";
                    i--;
                }
            } else {
                password[i++] = ch;
                cout << '*';
            }
        }

        password[i] = '\0';
        int x=0;
        char pass[6] = {'a','b','c','d','e','f'};
        int n = sizeof(pass);
        for(int i=0;i<n;i++){
            if(password[i]==pass[i]){
                x++;
            }
            else{
                system("cls");
                cout<<endl<<endl<<endl;
                cout<<endl<<"\t\t\t\t\t\t"<<"WRONG PASSWORD TRY AGAIN"<<endl;
                cout<<endl<<endl<<endl;
                goto stepback;
            }
        }
        if(x==n){
            cout<<endl<<endl<<endl;
            cout<<endl<<"\t\t\t\t\t\t"<<"LOGIN SUCCESSFULL"<<endl;
            cout<<endl<<endl<<endl;
            system("pause");
            select();
        }
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
}
void select(){
    system("cls");
    string x;
    bac:
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t1 - MEDICINE :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t2 - STAFF DETAILS :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t3 - ORDERS :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t4 - EXPENSES :"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t5 - SUPPLIER DETAILS:"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t6 - PAITENT DETAILS:"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\t7 - LOG OUT:"<<endl;
    fflush(stdout);
    cout<<"\t\t\t\t\t\tEnter your choice number - ";
    fflush(stdout);
    cin>>x;
    fflush(stdin);
    if(x=="1"){
        med();
    }
    else if(x=="2"){
        Staff();
    }
    else if(x=="3"){
        ord();
    }
    else if(x=="4"){
        Expenses();
    }
    else if(x=="5"){
        options();
    }
    else if(x=="6"){
        patient();
    }
    else if(x=="7"){
        cout<<"EXITING THE PROGRAM....\n";
        fflush(stdin);
        system("timeout 6 ");
        return;
    }
    else{
        system("cls");
        cout<<endl<<"\t\t\t\t\t\tINVALID CHOICE TRY AGAIN"<<endl;
        goto bac;
    }
}
int main(){
    system("title PHARMACY MANAGEMENT");
    login();
}
