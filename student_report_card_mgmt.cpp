#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

class student
{
    int rollno;
    char name[50];
    int SE_marks, CN_marks, AT_marks, COA_marks, OS_marks;
    double per;
    char grade;
    void calculate(); // function to calculate grade
public:
    void getdata();        // function to accept data from user
    void showdata() const; // function to show data on screen
    void show_tabular() const;
    int retrollno() const;
}; // class ends here

void student::calculate()
{
    per = (SE_marks + CN_marks + AT_marks + COA_marks + OS_marks) / 5.0;
    if (per >= 80)
        grade = 'A';
    else if (per >= 70)
        grade = 'B';
    else if (per >= 50)
        grade = 'C';
    else
        grade = 'F';
}

void student::getdata()
{
    system("color 0c");
    cout << "\t\t\t============================================================" << endl;
    cout << "\n\t\t\t\tEnter The roll number of student :";
    cin >> rollno;
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (name == name)
        {
            cout << "\n\t\t\t\tRoll No is already Enterd!!!!!" << endl;
            exit(0);
        }
    }
    inFile.close();

    cout << "\n\t\t\t\tEnter The Name of student : ";
    cin.ignore();
    cin.getline(name, 50);

    cout << "\n\t\t\t\tEnter The marks in Software engineering out of 100 : ";
    cin >> SE_marks;
    if (SE_marks >= 100)
    {
        cout << "\n\t\t\t\tInvalid Marks!!!!" << endl;
        exit(0);
    }

    cout << "\n\t\t\t\tEnter The marks in Computer Network out of 100     : ";
    cin >> CN_marks;
    if (CN_marks >= 100)
    {
        cout << "\n\t\t\t\tInvalid Marks!!!!" << endl;
        exit(0);
    }
    cout << "\n\t\t\t\tEnter The marks in Automata theory out of 100      : ";
    cin >> AT_marks;
    if (AT_marks >= 100)
    {
        cout << "\n\t\t\t\tInvalid Marks!!!!" << endl;
        exit(0);
    }
    cout << "\n\t\t\t\tEnter The marks in COA out of 100                  : ";
    cin >> COA_marks;
    if (COA_marks >= 100)
    {
        cout << "\n\t\t\t\tInvalid Marks!!!!" << endl;
        exit(0);
    }
    cout << "\n\t\t\t\tEnter The marks in Operating system out of 100     : ";
    cin >> OS_marks;
    if (OS_marks >= 100)
    {
        cout << "\n\t\t\t\tInvalid Marks!!!!" << endl;
        exit(0);
    }
    cout << "\t\t\t============================================================" << endl;
    calculate();
}

void student::showdata() const
{
    system("color 0d");
    cout << "\t\t\t===========================================================" << endl;
    cout << "\n\t\t\t\tRoll number of student        : " << rollno;
    cout << "\n\t\t\t\tName of student               : " << name;
    cout << "\n\t\t\t\tMarks in Software engineering : " << SE_marks;
    cout << "\n\t\t\t\tMarks in Computer Network     : " << CN_marks;
    cout << "\n\t\t\t\tMarks in Automata theory      : " << AT_marks;
    cout << "\n\t\t\t\tMarks in COA                  : " << COA_marks;
    cout << "\n\t\t\t\tMarks in Operating system     : " << OS_marks;
    cout << "\n\t\t\t\tPercentage of student is      : " << per;
    cout << "\n\t\t\t\tGrade of student is           : " << grade << endl;
    cout << "\t\t\t===========================================================" << endl;
}

void student::show_tabular() const
{
    cout << rollno << setw(4) << " " << name << setw(10) << SE_marks << setw(8) << CN_marks << setw(8) << AT_marks << setw(8)
         << COA_marks << setw(8) << OS_marks << setw(8) << per << setw(8) << grade << endl;
}

int student::retrollno() const
{
    return rollno;
}

void write_student(); // write the record in binary file
void display_all();   // read all records from binary file

void dis_speci(int); // accept rollno and read record from binary file

void modify_student(int); // accept rollno and update record of binary file
void delete_student(int); // accept rollno and delete selected records from binary file
void class_result();      // display all records in tabular format from binary file
void result();            // display result menu
void intro();             // display welcome screen
void entry_menu();        // display entry menu on screen

int main()
{
    system("cls");
    system("color 0a");
    char ch;
    cout.setf(ios::fixed | ios::showpoint);
    cout << setprecision(2); // program outputs decimal number to two decimal places
    intro();
    do
    {
        system("cls");
        system("color 0a");
        cout << "\t\t\t====================================================================" << endl;
        Sleep(300);
        cout << "\n\n\t\t\t\t\tMAIN MENU";
        Sleep(300);
        cout << "\n\n\t\t\t\t\t01. ENTRY/EDIT MENU";
        Sleep(300);
        cout << "\n\n\t\t\t\t\t02. RESULT MENU";
        Sleep(300);
        cout << "\n\n\t\t\t\t\t03. EXIT\n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t====================================================================" << endl;
        Sleep(300);
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        Sleep(300);
        cin >> ch;
        switch (ch)
        {
        case '1':
            entry_menu();
            break;
        case '2':
            result();
            break;
        case '3':
            break;
        default:
            cout << "\a";
        }
    } while (ch != '3');
    return 0;
}

void write_student()
{
    student st;
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
    outFile.close();
    cout << "\n\nStudent record Has Been Created ";
    cin.ignore();
    cin.get();
}

void display_all()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.showdata();
        // cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void dis_speci(int n)
{

    student st;
    system("color 0f");
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.retrollno() == n)
        {
            st.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nrecord not exist";
    cin.ignore();
    cin.get();
}

void modify_student(int n)
{
    system("color 0b");
    bool found = false;
    student st;
    fstream File;
    File.open("student.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {

        File.read(reinterpret_cast<char *>(&st), sizeof(student));
        if (st.retrollno() == n)
        {
            st.showdata();
            cout << "\n\nPlease Enter The New Details of student" << endl;
            st.getdata();
            int pos = (-1) * static_cast<int>(sizeof(st));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&st), sizeof(student));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void delete_student(int n)
{
    student st;
    system("color 0e");
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.retrollno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}

void class_result()
{
    student st;
    system("color 0e");
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    cout << "======================================================================\n";
    // cout << "R.No        Name          Se    CN    At    Coa    Os    %age    Grade" << endl;
    cout << "R.NO " << setw(4) << " NAME " << setw(20) << " Se " << setw(8) << "Cn" << setw(8) << "Coa" << setw(8) << " Os " << setw(8) << "At" << setw(8) << " %age " << setw(8) << " Grade " << setw(8) << endl;
    cout << "======================================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}

void result()
{
    char ch;
    int rno;
    system("cls");
    cout << "\t\t\t============================================================" << endl;
    cout << "\n\t\t\t\tRESULT MENU";
    cout << "\n\n\t\t\t\t1. Class Result";
    cout << "\n\n\t\t\t\t2. Student Report Card";
    cout << "\n\n\t\t\t\t3. Back to Main Menu" << endl;
    cout << "\t\t\t============================================================" << endl;
    cout << "\n\n\n\tEnter Choice (1/2/3)? ";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case '1':
        class_result();
        break;
    case '2':
        cout << "\n\n\tEnter Roll Number Of Student : ";
        cin >> rno;
        dis_speci(rno);
        break;
    case '3':
        break;
    default:
        cout << "\a";
    }
}

void intro()
{

    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t * * *   ****  *       ****   ***    ***    ****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * *  *      *      *      *   *  * * *  *        " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * *  *****  *      *      *   *  * * *  *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * *  *      *      *      *   *  * * *  *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  ***    ****  *****   ****   ***   * * *   ****     " << endl;
    Sleep(300);
    cout << endl;
    cout << "\t\t\t\t================================================" << endl;
    Sleep(500);
    cout << "\t\t\t\tTHIS IS STUDENT REPORT CARD MANEGEMENT SYSTEM" << endl;
    Sleep(500);
    cout << "\t\t\t\t================================================" << endl;
    Sleep(500);
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void entry_menu()
{
    char ch;
    int num;
    system("cls");
    Sleep(300);
    system("color 09");
    cout << "\t\t\t=============================================================" << endl;
    Sleep(300);
    cout << "\n\n\t\t\t\tENTRY MENU";
    Sleep(300);
    cout << "\n\n\t\t\t\t1.CREATE STUDENT RECORD";
    Sleep(300);
    cout << "\n\n\t\t\t\t2.DISPLAY ALL STUDENTS RECORDS";
    Sleep(300);
    cout << "\n\n\t\t\t\t3.SEARCH STUDENT RECORD ";
    Sleep(300);
    cout << "\n\n\t\t\t\t4.MODIFY STUDENT RECORD";
    Sleep(300);
    cout << "\n\n\t\t\t\t5.DELETE STUDENT RECORD";
    Sleep(300);
    cout << "\n\n\t\t\t\t6.BACK TO MAIN MENU\n"
         << endl;
    Sleep(300);
    cout << "\t\t\t=============================================================" << endl;
    Sleep(300);
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    Sleep(300);
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case '1':
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        system("color 0f");
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        dis_speci(num);
        break;
    case '4':
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        modify_student(num);
        break;
    case '5':
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        delete_student(num);
        break;
    case '6':
        break;
    default:
        cout << "\a";
        entry_menu();
    }
}
