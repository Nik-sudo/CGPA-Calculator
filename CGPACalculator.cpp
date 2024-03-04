#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Course {
    private:
        string name;
        float grade;
        int termTaken;
        int yearTaken;
    public:
        Course(string n, float x, int y, int z) {
            name = n;
            grade = x;
            termTaken = y;
            yearTaken = z;
        }
        string getName() {
            return name;
        }
        float getGrade() {
            return grade;
        }
        int getTerm() {
            return termTaken;
        }
        int getYear() {
            return yearTaken;
        }

};

void add_courses(vector<Course> &courses);
void list_courses(vector<Course> &courses);
void calculateCGPA(vector<Course> &courses);

int main() {
    system("cls");
    int input;
    vector<Course> courses;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                              CGPA Calculator                             "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                   1. Add Courses"<<endl;
    cout<<"                   2. List Courses"<<endl;
    cout<<"                   3. Calculate CGPA (Cummulative Grade Point Average)"<<endl;
    cout<<"                   4. Exit Application"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    
    sub:
    cout<<"Enter input: ";
    cin>>input;

    switch(input) {
        case 1:
            add_courses(courses);
            break;
        case 2:
            list_courses(courses);
            break;
        case 3:
            calculateCGPA(courses);
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            cout<<"Please Choose a Number From the List!\n"<<endl;
            goto sub;
            break;
    }

    return 0;
}

void add_courses(vector<Course> &courses) {
    system("cls");
    string name;
    float grade;
    int termTaken;
    int yearTaken;

    cout<<"-------------- Add courses -----------------\n"<<endl;
    cout<<"Enter the Name of the Course: ";
    cin>>name;
    cout<<"Enter the Grade you received for that Course (%): ";
    cin>>grade;
    cout<<"Enter the Term you took the Course: ";
    cin>>termTaken;
    cout<<"Enter the Year you took the Course: ";
    cin>>yearTaken;
    Course enteredCourse(name, grade, termTaken, yearTaken);
    courses.push_back(enteredCourse);
    cout<<"\n\nCourse Entered Successfully!\n"<<endl;

    sub:
    int input;
    cout<<"1. Add Another Course"<<endl;
    cout<<"2. Main Menu\n"<<endl;
    cout<<"Enter Input: ";
    cin>>input;

    switch(input) {
        case 1:
            add_courses(courses);
            break;
        case 2:
            main();
            break;
        default:
            cout<<"Please Choose a Number From the List!\n"<<endl;
            goto sub;
            break;
    }

}

void list_courses(vector<Course> &courses) {
    system("cls");
    cout<<"-------------- List courses -----------------\n"<<endl;
    if(courses.size() == 0) {
        cout<<"No Courses have been Added!\n"<<endl;
        cout << "Press Enter to Go Back to Main Menu";
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        main();
        return;
    }

}

void calculateCGPA(vector<Course> &courses) {
    system("cls");
    cout<<"-------------- CGPA Calculating -----------------\n\n"<<endl;
    cout << "Press Enter to Go Back to Main Menu";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    main();
    return;
}
