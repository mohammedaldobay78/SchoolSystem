#include <iostream>
#include <vector>
using namespace std;

struct stStudent
{
  string Name = "";
  int ID = 0;
  float Grade = 0.0;
};

struct stSchoolInfo
{
  int SchoolID;
  string SchoolName;
  string SchoolLevel;
  int CountOfStudent;
  vector<stStudent> students;
};

//==================================================================
// Student System
stStudent ReadStudentInfo()
{
  stStudent TempStudent;

  cout << "Student Name: ";
  cin.ignore();
  getline(cin, TempStudent.Name);
  cout << "Student ID: ";
  cin >> TempStudent.ID;
  cout << "Student Grade: ";
  cin >> TempStudent.Grade;

  return TempStudent;
}

void PrintStudent(stStudent &Student)
{
  cout << "Name  : " << Student.Name << endl;
  cout << "ID    : " << Student.ID << endl;
  cout << "Grade :" << Student.Grade << endl;
}


void PrintAllStudents(vector <stStudent>& vStudents)
{
  cout << "(All Students)\n\n";
  for (stStudent& Student : vStudents)
  {
    cout << "===========================\n";
    PrintStudent(Student);
    cout << "===========================\n";
    cout << endl;
  }
}

//--------------------
void AddStudent(vector <stStudent> &vStudents)
{
	char agree;
  int i = 1;
  do
  {
    cout << "===========================\n";
    cout << "student " << i << " info" << endl;
    cout << "===========================\n";
    vStudents.push_back(ReadStudentInfo());
    cout << "===========================\n";
    i++;

    cout << "\nDo You Wnat to Add more (y/n):" << endl;
    cin >> agree;
  } while (agree == 'y' || agree == 'Y');

}

// ------------------
void PrintStudentInfo(vector <stStudent> &vStudents)
{
  int FindID;
  cout << "===========================\n";
  cout << "Enter Student ID: ";
  cin >> FindID;

  for (stStudent& Student : vStudents)
  {
    if (Student.ID == FindID)
    {
      cout << "\n===========================\n";
      PrintStudent(Student);
      cout << "===========================\n";
    }
    else
    {
      cout << "NOT Found" << endl;
    }
  }
  
}


//--------------------
vector <stStudent> StudentSystem()
{
  vector<stStudent> vStudents;
  bool RunApp = true;

  while (RunApp)
  {
    cout << "\n\n===========================\n";
    cout << "[1] Add Student" << endl;
    cout << "[2] Print Student Info" << endl;
    cout << "[3] Show Students" << endl;
    cout << "[4] Exit" << endl;
    cout << "===========================\n";

    int choice;
    cout << "\n Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      AddStudent(vStudents);
      break;

    case 2:
      PrintStudentInfo(vStudents);
      break;

    case 3:
      PrintAllStudents(vStudents);
      break;

    default:
      cout << "\nOUT" << endl;
      RunApp = false;
      break;
    }
  }

  return vStudents;
}

//====================================================================================
// School System
stSchoolInfo ReadSchoolInfo(){
  stSchoolInfo TempSchool;

  cout << "School ID: " << endl;
  cin >> TempSchool.SchoolID;
  cout << "School Name: " << endl;
  cin.ignore();
  getline(cin, TempSchool.SchoolName);

  cout << "School Level: " <<endl;
  cin >> TempSchool.SchoolLevel;

  cout << "Count Students: " << endl;
  cin >> TempSchool.CountOfStudent;

  return TempSchool;
}

vector<stSchoolInfo> AddSchool(){
  vector<stSchoolInfo> vctSchoolInfo;
  char agree;
  do
  {
    stSchoolInfo SchoolInfo = ReadSchoolInfo();
    vctSchoolInfo.push_back(SchoolInfo);

    cout << "Do You Want Add More (y/n): ";
    cin >> agree;

  } while (agree == 'y' || agree == 'Y');

  return vctSchoolInfo;
}

void PrintSchoolInfo(stSchoolInfo info){
  cout << "\n===========================\n";
  cout << "School ID    : " << info.SchoolID << endl;
  cout << "School Name  : " << info.SchoolName << endl;
  cout << "School Level :" << info.SchoolLevel << endl;
  cout << "Count If Student :" << info.CountOfStudent << endl;
  cout << "===========================\n";
}


void SearchSchoolInfo(vector<stSchoolInfo> &vctSchoolInfo){

  int FindID;
  cout << "===========================\n";
  cout << "Enter School ID: ";
  cin >> FindID;

  for (stSchoolInfo& info : vctSchoolInfo)
  {
    if (info.SchoolID == FindID)
    {
      PrintSchoolInfo(info);
    }
    else
    {
      cout << "NOT Found" << endl;
    }
    
  }
}


void PrintAllSchoolsInfo(vector<stSchoolInfo> &vctSchoolInfo){
  int i = 1;
  for (stSchoolInfo &info : vctSchoolInfo)
  {
    cout<< "=====================" <<endl;
    cout << "School " << i << endl;
    cout<< "=====================" <<endl;
    PrintSchoolInfo(info);
    cout << "=====================" << endl;

    i++;
  }
}

void AddStudentToShcool(vector<stSchoolInfo> &vctSchoolInfo){
  vector<stStudent> vStudents = StudentSystem();
  int FindID;
  cout << "===========================\n";
  cout << "Enter School ID: ";
  cin >> FindID;

  for (stSchoolInfo& info : vctSchoolInfo)
  {
    if (info.SchoolID == FindID)
    {
      info.students = vStudents;
    }
    else
    {
      cout << "NOT Found" << endl;
    }
    
  }
  
}

void SchoolSystem()
{
  vector<stSchoolInfo> vctSchoolInfo;

  bool RunApp = true;

  while (RunApp)
  {
    cout << "\n\n===========================\n";
    cout << "[1] Add School" << endl;
    cout << "[2] Search School Info" << endl;
    cout << "[3] Show All Schools" << endl;
    cout << "[4] Add Student to school" << endl;
    cout << "[5] Exit" << endl;
    cout << "===========================\n";

    int choice;
    cout << "\n Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      vctSchoolInfo = AddSchool();
      break;

    case 2:
      SearchSchoolInfo(vctSchoolInfo);
      break;

    case 3:
      PrintAllSchoolsInfo(vctSchoolInfo);
      break;
    
    case 4:
      AddStudentToShcool(vctSchoolInfo);

    default:
      cout << "\nOUT" << endl;
      RunApp = false;
      break;
    }
  }
}

int main()
{
  //--------------------
  SchoolSystem();

  return 0;
}