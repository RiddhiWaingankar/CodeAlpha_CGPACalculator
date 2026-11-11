#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Course Class to store individual course data
class Course {
private:
    string courseName;
    double credits;
    double gradePoint;

public:
    Course(string name, double cr, double gp) {
        courseName = name;
        credits = cr;
        gradePoint = gp;
    }

    double getCredits() const { return credits; }
    double getGradePoint() const { return gradePoint; }
    string getCourseName() const { return courseName; }

    void displayCourse() const {
        cout << left << setw(20) << courseName 
             << setw(10) << credits 
             << setw(12) << gradePoint << endl;
    }
};

// Student Class using OOP to manage courses and CGPA calculation
class StudentCGPA {
private:
    vector<Course> courses;

public:
    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void calculateAndDisplayCGPA() const {
        if (courses.empty()) {
            cout << "No courses recorded." << endl;
            return;
        }

        double totalCredits = 0;
        double totalGradePoints = 0;

        cout << "\n========================================" << endl;
        cout << "          COURSE GRADE REPORT           " << endl;
        cout << "========================================" << endl;
        cout << left << setw(20) << "Course Name" 
             << setw(10) << "Credits" 
             << setw(12) << "Grade Pt" << endl;
        cout << "----------------------------------------" << endl;

        for (const auto& course : courses) {
            course.displayCourse();
            totalCredits += course.getCredits();
            totalGradePoints += (course.getCredits() * course.getGradePoint());
        }

        double cgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;

        cout << "----------------------------------------" << endl;
        cout << "Total Credits       : " << totalCredits << endl;
        cout << "Total Grade Points  : " << totalGradePoints << endl;
        cout << fixed << setprecision(2);
        cout << "Final CGPA / GPA    : " << cgpa << endl;
        cout << "========================================" << endl;
    }
};

int main() {
    int n;
    cout << "=== CodeAlpha C++ Task 1: CGPA Calculator ===" << endl;
    cout << "Enter the number of courses taken: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input for number of courses." << endl;
        return 1;
    }

    StudentCGPA student;

    for (int i = 0; i < n; ++i) {
        string name;
        double credits, gradePoint;

        cout << "\n--- Course " << (i + 1) << " ---" << endl;
        cout << "Enter course name: ";
        cin >> ws; // clear buffer
        getline(cin, name);
        cout << "Enter credit hours: ";
        cin >> credits;
        cout << "Enter grade points (e.g., on a 10-point scale): ";
        cin >> gradePoint;

        student.addCourse(Course(name, credits, gradePoint));
    }

    // Display final report
    student.calculateAndDisplayCGPA();

    return 0;
}