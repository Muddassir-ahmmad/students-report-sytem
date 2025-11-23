#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>


using namespace std;

struct Subject
{
    string sub;
    int marks;
};

struct student
{
    string name;
    vector<Subject> subjects;
};

char getGrade(float avg)
{
    if (avg >= 85)
        return 'A';
    if (avg >= 70)
        return 'B';
    if (avg >= 55)
        return 'C';
    if (avg >= 40)
        return 'D';
    return 'F';
}

void delstudent(student &s, const string &delname)
{
    if (s.name == delname)
    {
        s.name = "";
        s.subjects.clear();
        std::cout << "Student deleted successfully.\n";
    }
    else
    {
        std::cout << "Student not found.\n";
    }
}

void deleteSubject(student &s, const string &subdel)
{
    for (size_t i = 0; i < s.subjects.size(); ++i)
    {
        if (s.subjects[i].sub == subdel)
        {
            s.subjects.erase(s.subjects.begin() + i);
            std::cout << "Subject deleted successfully.\n";
            return;
        }
    }
    std::cout << "Subject not found.\n";
}

void deltemarks(student &s, const string subname, const int delmarks)
{
    for (size_t i = 0; i < s.subjects.size(); ++i)
    {
        if (s.subjects[i].sub == subname )
        {
            s.subjects[i].marks = 0;
            std::cout << "marks deleted successfully\n";
            return;
        }
    }
    std::cout << "marks not found\n";
}

void searchStudnt(student &s, string name)
{
    if (s.name == name)
    {
        cout << "Student found \n"
             << endl;
        cout << s.name;
        for (const auto &sub : s.subjects)
        {
            std::cout << sub.sub << " " << sub.marks << endl;
        }
    }
    std::cout << "student not found\n";
}

void searchSubject(student &s, const string &subname)
{
    for (const auto &sub : s.subjects)
    {
        if (sub.sub == subname)
        {
            std::cout << "Subject found: " << sub.sub << " with marks " << sub.marks << endl;
            return;
        }
    }
    std::cout << "Subject not found.\n";
}

void listStudents(const vector<student> &students)
{
    if(students.empty())
    {
        cout << "No students available.\n";
        return;
    }
    cout << "List of Students:\n";
    for (const auto &s : students)
    {
        cout << s.name << endl;
    }
}

void listAllsubjects(const vector<student> &students)
{
    if(students.empty())
    {
        cout << "No subjects available.\n";
        return;
    }
    set<string> allSubjects;
    for (const auto &s : students)
    {
        for (auto &su : s.subjects)
        {
            allSubjects.insert(su.sub);
        }
    }
    cout << "list of all subjects" << endl;
    for (const auto &all : allSubjects)
    {
        cout << all << endl;
    }
}

void Addsubject(student &s, const Subject &newSub)
{
    s.subjects.push_back(newSub);
    std::cout << "Subject added successfully.\n";
}

void updateStudentName(student &s, const string newname)
{
    if (s.name != newname)
    {
        s.name = newname;
        std::cout << "student name updated successfully\n";
    }
}

void UpdateSubName(student &s, const string &oldname, const string &newname)
{
    for (auto &sub : s.subjects)
    {
        if (sub.sub == oldname)
        {
            sub.sub = newname;
            std::cout << "Subject name updated successfully.\n";
            return;
        }
    }
    std::cout << "Subject not found.\n";
}
void UpdateSubMark(student &s, const int &oldmark, const int &newmark)
{
    for (auto &sub : s.subjects)
    {
        if (sub.marks == oldmark)
        {
            sub.marks = newmark;
            std::cout << "New marks updated succefully updated successfully.\n";
            return;
        }
    }
    std::cout << "Subject not found to Update marks.\n";
}
int main()
{
    int  choice;
    string sname;
    vector<student> students;

    cout << "what you want do";
    cout << "1, add student\n";
    cout << "2, checkgrade\n";
    cout << "3, search student\n";
    cout << "4, search by subjects\n";
    cout << "5, lsit all students\n";
    cout << "6, lsit all subjects\n";
    cout << "7, add new subject\n";
    cout << "8, update student\n";
    cout << "9, update subject name\n";
    cout << "10,update subjec mark\n";
    cout << "11, delete subject\n";
    cout << "12, delete marks\n";
    cout << "13, delete student\n";
    cout << "14, Exit\n";




    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
             int n;
            cout << "Enter number of students to add: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                student s;
                cout << "Enter name of student " << (i + 1) << ": ";
                cin >> s.name;

                int subcount;
                cout << "Enter number of subjects for " << s.name << ": ";
                cin >> subcount;

                for (int j = 0; j < subcount; ++j) {
                    Subject subj;
                    cout << "  Enter subject name: ";
                    cin >> subj.sub;
                    cout << "  Enter marks for " << subj.sub << ": ";
                    cin >> subj.marks;
                    s.subjects.push_back(subj);
                }
                students.push_back(s);
            }
            break;
        
        case 2:
            cout << "\n\n--- Students Report Card ---\n";
            for (auto &s : students)
            {
                std::cout << "\nStudent Name: " << s.name << endl;

                if (s.subjects.empty())
                {
                    std::cout << "  No subjects available.\n";
                    continue;
                }

                int total = 0;
                for (Subject &su : s.subjects)
                {
                    std::cout << "  " << su.sub << " marks: " << su.marks << endl;
                    total += su.marks;
                }

                float avg = static_cast<float>(total) / s.subjects.size();
                std::cout << "  Average: " << avg << endl;
                std::cout << "  Grade: " << getGrade(avg) << endl;
            }

            break;
        case 3:
            cout << "Enter the student name to search";
            cin >> sname;
            for (auto &s : students)
            {
                searchStudnt(s, sname);
            }
            std::cout << "student not found";
            break;
        case 4:
            cout << "search Subject\n";
            cout << "Enter the subject name to search: ";
            cin >> sname;
            for (auto &s : students)
            {
                searchSubject(s, sname);
            }
            break;

        case 5:
                cout << "LIST ALL STUDENTS\n";
                listStudents(students);
                break;
        case 6:
                cout << "list all the subjects\n";
                listAllsubjects(students);
                break;

        case 7:
                cout << "add new subjects\n";
                cout << "Enter the student name to add subject: ";
                cin >> sname;
                for (auto &s : students)
                    {
                        if (s.name == sname)
                            {
                                Subject newsub;
                                cout << "enter the subject name: ";
                                cin >> newsub.sub;
                                cout << "enter the marks: ";
                                cin >> newsub.marks;
                                Addsubject(s, newsub);
                                break;
                            };
                    }
                cout << "student not found\n";
                break;

        case 8:{
                cout << "update student name\n";
                cout << "Enter the student name to update student name: ";
                cin >> sname;
                bool found3 = false;
                for (auto &s : students)
                {
                    if (sname == s.name)
                    {
                        string newname;
                        cout << "Enter the new student name: ";
                        cin >> newname;
                        updateStudentName(s, newname);
                        found3 = true;
                        break;
                    }
                }
                if (!found3)
                {
                    cout << "student not found\n";
                }
                break;
            }

        case 9:
        {
                cout << "update subject name\n";

                string oldname, newname;
                cout << "Enter the student name to update subject name: ";
                cout << endl;
                cin >> sname;
                cout << "Enter the old subject name: ";
                cout << endl;
                cin >> oldname;
                cout << "Enter the new subject name: ";
                cout << endl;
                cin >> newname;
                bool found2 = false;
                for (auto &s : students)
                {
                    if (sname == s.name)
                        UpdateSubName(s, oldname, newname);
                    found2 = true;
                    break;
                }
                if (!found2)
                {
                    cout << "the students doet exits\n"
                         << endl;
                }
                break;
            }

        case 10:
        {
                cout << "Update the marks\n";
                int oldmarks, newmarks;
                cout << "Enter the student name to update subject marks: ";
                cout << endl;
                cin >> sname;
                cout << "Enter the old marks : ";
                cout << endl;
                cin >> oldmarks;
                cout << "Enter the new subject name: ";
                cout << endl;
                cin >> newmarks;
                bool found4 = false;
                for (auto &s : students)
                {
                    if (sname == s.name){
                     UpdateSubMark(s, oldmarks, newmarks);
                    found4 = true;}
                    break;
                }
                if (!found4)
                {
                    cout << "the students doet exits\n"
                         << endl;
                }
                break;
            }

        case  11:
        {
                cout<<"deleteSubject\n";
                cout<<"Enter the student name to delete subject from: ";
                cin>>sname;
                cout<<"Enter the subject name to delete: ";
                string subdel;
                cin>>subdel;
                for(auto &s:students){
                    if(s.name==sname){
                        deleteSubject(s,subdel);
                        break;
                    }

                }cout<<"student not found\n";
                break;
            }
            
        case 12:
        {
                cout<<"deltemarss\n";
                cout<<"Enter the student name to delete marks from: ";
                cin>>sname;
                cout<<"Enter the subject name to delete marks: ";
                string subnamemarks;
                int delmarks;
                cin>>subnamemarks;
                cout<<"Enter the marks to delete: ";
                cin>>delmarks;
                for(auto &s:students){
                    if(s.name==sname){
                        deltemarks(s,subnamemarks,delmarks);
                        break;
                    }
                }cout<<"student not found\n";
                break;
            }
        case  13:
                cout<<"delete student\n";
                cout<<"Enter the student name to delete student : ";
                cin>>sname;
                for(auto &s:students){
                    delstudent(s,sname);
                    break;
                }cout<<"student not found\n";
                break;
            
        case 14:
                exit(0);
                break;
            default:
                cout<< "invalid choice\n";
                break;
            
        }

       
        return 0;
    }
}