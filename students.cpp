#include<iostream>
#include<iomanip>

using namespace std;

int strength=0;
string junk;

struct Student{
    string name;
    float marks;
};

Student students[50];

int menu();

void end();

void addStudent();

void getMarks(int turtle);

void viewStudent();

int editMenu();

void edit();

void editName();

void editMarks();

void deleteStudent();

void search();

void average();

void topper();

void grade();

int main(){
    while(true){
        int choice = menu();
        switch(choice){
            case 1: addStudent();
                    break;
            case 2: viewStudent();
                    break;
            case 3: edit();
                    break;
            case 4: deleteStudent();
                    break;
            case 5: search();
                    break;
            case 6: average();
                    break;
            case 7: topper();
                    break;
            case 8: grade();
                    break;
            case 9: {
                cout<<"Information on grading system:\n" << "0-30 Grade: F\n" << "31-40 Grade: E\n" << "41-50 Grade: D\n" << "51-60 Grade: C\n" << "61-70 Grade: B\n" << "71-80 Grade: A\n" << "81-90 Grade: A+\n" << "91-100 Grade: S\n";
                end();
                break;
            }
            case 10: {
                cout << "Thank You for using our system!\n";
                cout << "Press enter to exit..." << endl;
                cin.ignore();
                getline(cin, junk);
                break;
            }
            default:cout << "Enter valid postion" << endl;
                    end();
        }
        if(choice==10)
            break;
    }
    
    return 0;
}

int menu(){
    int a;
    cout << "Student record management system\nMain Menu\n";
    cout << "1.Add Student\n";
    cout << "2.View all students\n";
    cout << "3.Edit student records\n";
    cout << "4.Delete a student record\n";
    cout << "5.Search by roll number\n";
    cout << "6.Calculate average marks\n";
    cout << "7.Find topper\n";
    cout << "8.Display Grade\n";
    cout << "9.Information on Grading System\n";
    cout << "10.Exit\n";
    cout << "Enter the numerical position of the option of your choice: \n";
    cin >> a;
    return a;
}

void end(){
    cout << "Press enter to continue..." << endl;
    cin.ignore();
    getline(cin, junk);
}

void addStudent(){
    cout << "Enter name of student: ";
    cin.ignore();
    getline(cin,students[strength].name);
    getMarks(strength);
    cout << "Student " << students[strength].name << " added with roll no " << strength + 1 << " and marks " << students[strength].marks << "." << endl;
    strength++;
    end();
}

void getMarks(int turtle){
    while(true){
        cout << "Enter marks of student(out of 100): ";
        cin >> students[turtle].marks;
        if(students[turtle].marks>100 || students[turtle].marks<0){
            cout << "Please enter marks in given range\n";
            continue;  
        }
        break;
    }
}

void viewStudent(){
    if(strength==0){
        cout << "Please add students to the record first!\n";
        end();
        return;
    }
    for(int i = 0;i<strength;i++){
        if(i == 0){
            cout << left << setw(10) << "Roll No." << setw(20) << "Name" << setw(5) << "Marks" << endl;
        }
        cout << left << setw(10) << i + 1 << setw(20) << students[i].name << setw(5) << students[i].marks << endl;
    }
    end();
}

int editMenu(){
    int a;
    cout << "Student record management system\nEdit Menu\n";
    cout << "1.Edit name of student\n";
    cout << "2.Edit marks of student\n";
    cout << "3.Return to main menu\n";
    cout << "Enter the numerical position of the option of your choice: \n";
    cin >> a;
    return a;
}

void edit(){
    while(true){
        if(strength==0){
            cout << "Please add students to the record first!\n";
            end();
            return;
        }
        int choice = editMenu();
        switch(choice){
            case 1: editName();
                    break;
            case 2: editMarks();
                    break;
            case 3: break;
            default:cout << "Enter valid postion" << endl;
                    end();
                    break;
        }
        if(choice==3)
            break;
    }
}

void editName(){
    int query;
    while(true){
        cout << "Please enter roll number of student: ";
        cin >> query;
        if(query>strength || query<1){
            cout << "Query exceeds current strength of students.\nPress enter to continue...\n";
            cin.ignore();
            getline(cin, junk);
            continue;
        }
        break;
    }
    cout << "Enter new name of student: ";
    cin.ignore();
    getline(cin, students[query-1].name);
    cout << "Edit successful.\n";
    end();
}

void editMarks(){
    int query;
    while(true){
        cout << "Please enter roll number of student: ";
        cin >> query;
        if(query>strength || query<1){
            cout << "Query exceeds current strength of students.\nPress enter to continue...\n";
            cin.ignore();
            getline(cin, junk);
            continue;
        }
        break;
    }
    while(true){
        cout << "Enter new marks of student(out of 100): ";
        cin >> students[query-1].marks;
        if(students[query-1].marks>100 || students[query-1].marks<0){
            cout << "Please enter marks in given range\nPress enter to continue...\n";
            cin.ignore();
            getline(cin, junk);
            continue;
        }
        cout << "Edit successful.\n";
        break;
    }
    end();
}

void deleteStudent(){
    if(strength==0){
        cout << "Please add students to the record first!\n";
        end();
        return;
    }
    int query;
    while(true){
        cout << "Please enter roll number of student: ";
        cin >> query;
        if(query>strength || query<1){
            cout << "Query exceeds current strength of students.\nPress enter to continue...\n";
            cin.ignore();
            getline(cin, junk);
            continue;
        }
        break;
    }
    cout << "Student " << students[query-1].name << " has been removed from records.\n";
    students[query-1].name;
    strength--;
    end();
}

void search(){
    if(strength==0){
        cout << "Please add students to the record first!\n";
        end();
        return;
    }
    int query;
    while(true){
        cout << "Please enter roll number of student: ";
        cin >> query;
        if(query>strength || query<1){
            cout << "Query exceeds current strength of students.\nPress enter to continue...\n";
            cin.ignore();
            getline(cin, junk);
            continue;
        }
        break;
    }
    cout << "Name: " << students[query-1].name << "\nMarks: " << students[query-1].marks << endl;
    end();
}

void average(){
    if(strength==0){
            cout << "Please add students to the record first!\n";
            end();
            return;
        }
    float totalMarks{0}, averageMarks{0};
    for(int i =0;i<strength;i++){
        totalMarks += students[i].marks;
        if(i==strength-1){
            averageMarks = totalMarks/strength;
            break;
        }
    }
    cout << "The average marks of student are: " << averageMarks << endl;
    end();
}

void topper(){
    if(strength==0){
        cout << "Please add students to the record first!\n";
        end();
        return;
    }
    float highestMarks=-1;
    int i,topperRoll;
    for(i=0;i<strength;i++){
        if(highestMarks<students[i].marks){
            highestMarks = students[i].marks;
            topperRoll = i;
        }
    }
    cout << "The topper is " << students[topperRoll].name << " with " << students[topperRoll].marks <<  " marks." << endl;
    end();
}

void grade(){
    if(strength==0){
        cout << "Please add students to the record first!\n";
        end();
        return;
    }
    int query;
    while(true){
        cout << "Enter roll no of student: ";
        cin >> query;
        if(query>strength || query<1){
            cout << "Query exceeds current strength of students.\nPress enter to continue...\n";
            cin.ignore();
            getline(cin, junk);
            continue;
        }
        break;
    }
    if(students[query-1].marks>=0 && students[query-1].marks<=30){
        cout << students[query-1].name << "'s grade is F." << endl;
    } else if(students[query-1].marks>30 && students[query-1].marks<=40){
        cout << students[query-1].name << "'s grade is E." << endl;
    } else if(students[query-1].marks>40 && students[query-1].marks<=50){
        cout << students[query-1].name << "'s grade is D." << endl;
    } else if(students[query-1].marks>50 && students[query-1].marks<=60){
        cout << students[query-1].name << "'s grade is C." << endl;
    } else if(students[query-1].marks>60 && students[query-1].marks<=70){
        cout << students[query-1].name << "'s grade is B." << endl;
    } else if(students[query-1].marks>70 && students[query-1].marks<=80){
        cout << students[query-1].name << "'s grade is A." << endl;
    } else if(students[query-1].marks>80 && students[query-1].marks<=90){
        cout << students[query-1].name << "'s grade is A+." << endl;
    } else if(students[query-1].marks>90 && students[query-1].marks<=100){
        cout << students[query-1].name << "'s grade is S." << endl;
    }

    end();
}
