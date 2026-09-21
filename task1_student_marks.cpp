#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int STUDENTS = 6;
const int SUBJECTS = 4;

int main() {
    string subjectNames[SUBJECTS] = {"English", "Mathematics", "Programming", "AI"};
    int marks[STUDENTS][SUBJECTS] = {{78, 85, 92, 88},{65, 70, 74, 68},{90, 95, 89, 93},{55, 62, 58, 60},{82, 79, 85, 91},{73, 88, 80, 76}};
    int total[STUDENTS] = {0};
    double average[STUDENTS] = {0};
    cout << "MARKS TABLE=\n";
    cout << left << setw(10) << "Student";
    for (int j = 0; j < SUBJECTS; j++)
        cout << setw(14) << subjectNames[j];
    cout << "\n" << string(10 + 14 * SUBJECTS, '-') << "\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << left << setw(10) << ("S" + to_string(i + 1));
        for (int j = 0; j < SUBJECTS; j++)
            cout << setw(14) << marks[i][j];
        cout << "\n";
    }
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < SUBJECTS; j++)
            total[i] += marks[i][j];
        average[i] = static_cast<double>(total[i]) / SUBJECTS;
    }
    cout << "\nTOTAL & AVERAGE\n";
    cout << left << setw(10) << "Student" << setw(10) << "Total" << "Average\n";
    cout << string(30, '-') << "\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < STUDENTS; i++) {
        cout << left << setw(10) << ("S" + to_string(i + 1))
             << setw(10) << total[i]
             << average[i] << "\n";
    }
    cout << "\n HIGHEST MARKS PER SUBJECT\n";
    for (int j = 0; j < SUBJECTS; j++) {
        int highest = marks[0][j];
        int topStudent = 0;
        for (int i = 1; i < STUDENTS; i++) {
            if (marks[i][j] > highest) {
                highest = marks[i][j];
                topStudent = i;
            }
        }
        cout << left << setw(14) << subjectNames[j]
             << ": " << highest << " (Student S" << topStudent + 1 << ")\n";
    }
    int bestIndex = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (total[i] > total[bestIndex])
            bestIndex = i;
    }
    cout << "\n TOP STUDENT \n";
    cout << "Student S" << bestIndex + 1 << " has the highest total: "
         << total[bestIndex] << " (Average: " << average[bestIndex] << ")\n";
    return 0;
}
