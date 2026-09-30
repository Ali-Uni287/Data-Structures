#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Course {
    string code;
    string name;
    int credits;
    Course* next;
};

Course* createCourse(const string& code, const string& name, int credits) {
    Course* c = new Course;
    c->code = code;
    c->name = name;
    c->credits = credits;
    c->next = nullptr;
    return c;
}

Course* findCourse(Course* head, const string& code) {
    while (head != nullptr && head->code != code)
        head = head->next;
    return head;
}

void addAtBeginning(Course*& head, const string& code, const string& name, int credits) {
    if (findCourse(head, code) != nullptr) {
        cout << "Course " << code << " already exists in this list.\n";
        return;
    }
    Course* c = createCourse(code, name, credits);
    c->next = head;
    head = c;
    cout << "Course " << code << " added at the beginning.\n";
}

void addAtEnd(Course*& head, const string& code, const string& name, int credits) {
    if (findCourse(head, code) != nullptr) {
        cout << "Course " << code << " already exists in this list.\n";
        return;
    }
    Course* c = createCourse(code, name, credits);
    if (head == nullptr) {
        head = c;
    } else {
        Course* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = c;
    }
    cout << "Course " << code << " added at the end.\n";
}

void searchCourse(Course* head, const string& code) {
    Course* c = findCourse(head, code);
    if (c == nullptr) {
        cout << "Course " << code << " not found.\n";
        return;
    }
    cout << "Code: " << c->code << " | Name: " << c->name << " | Credit Hours: " << c->credits << "\n";
}

void deleteCourse(Course*& head, const string& code) {
    if (head == nullptr) {
        cout << "Course " << code << " not found.\n";
        return;
    }
    Course* del = nullptr;
    if (head->code == code) {
        del = head;
        head = head->next;
    } else {
        Course* cur = head;
        while (cur->next != nullptr && cur->next->code != code)
            cur = cur->next;
        if (cur->next == nullptr) {
            cout << "Course " << code << " not found.\n";
            return;
        }
        del = cur->next;
        cur->next = del->next;
    }
    cout << "Course " << del->code << " deleted.\n";
    delete del;
}

int countCourses(Course* head) {
    int count = 0;
    for (; head != nullptr; head = head->next)
        count++;
    return count;
}

void displayCourses(Course* head, const string& heading) {
    cout << "\n" << heading << "\n";
    if (head == nullptr) {
        cout << "No courses in this list.\n";
        return;
    }
    for (Course* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->code;
        if (cur->next != nullptr)
            cout << " -> ";
    }
    cout << "\n";
    for (Course* cur = head; cur != nullptr; cur = cur->next)
        cout << "  " << cur->code << " | " << cur->name << " | " << cur->credits << " credit hours\n";
    cout << "Total courses: " << countCourses(head) << "\n";
}

void concatenate(Course*& first, Course*& second) {
    if (second == nullptr) {
        cout << "The other list is empty, nothing to concatenate.\n";
        return;
    }
    if (first == nullptr) {
        first = second;
    } else {
        Course* cur = first;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = second;
    }
    second = nullptr;
}

void freeList(Course*& head) {
    while (head != nullptr) {
        Course* temp = head;
        head = head->next;
        delete temp;
    }
}

int readInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

string readLine(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

Course*& pickList(Course*& morning, Course*& evening, string& label) {
    int which;
    do {
        which = readInt("Select list (1 = Morning, 2 = Evening): ");
    } while (which != 1 && which != 2);
    label = (which == 1) ? "Morning Courses:" : "Evening Courses:";
    return (which == 1) ? morning : evening;
}

int main() {
    Course* morning = nullptr;
    Course* evening = nullptr;
    int choice;

    do {
        cout << "\n===== University Department Course Management =====\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Concatenate Another Course List\n";
        cout << "8. Exit\n";
        choice = readInt("Enter your choice: ");

        string label;
        switch (choice) {
            case 1:
            case 2: {
                Course*& list = pickList(morning, evening, label);
                string code = readLine("Course Code: ");
                string name = readLine("Course Name: ");
                int credits = readInt("Credit Hours: ");
                if (choice == 1)
                    addAtBeginning(list, code, name, credits);
                else
                    addAtEnd(list, code, name, credits);
                break;
            }
            case 3: {
                Course*& list = pickList(morning, evening, label);
                searchCourse(list, readLine("Enter Course Code: "));
                break;
            }
            case 4: {
                Course*& list = pickList(morning, evening, label);
                deleteCourse(list, readLine("Enter Course Code: "));
                break;
            }
            case 5: {
                displayCourses(morning, "Morning Courses:");
                displayCourses(evening, "Evening Courses:");
                break;
            }
            case 6: {
                Course*& list = pickList(morning, evening, label);
                cout << "Total courses: " << countCourses(list) << "\n";
                break;
            }
            case 7: {
                int which;
                do {
                    which = readInt("Append which list onto the other? (1 = Evening onto Morning, 2 = Morning onto Evening): ");
                } while (which != 1 && which != 2);
                if (which == 1) {
                    concatenate(morning, evening);
                    displayCourses(morning, "Combined Course List:");
                } else {
                    concatenate(evening, morning);
                    displayCourses(evening, "Combined Course List:");
                }
                break;
            }
            case 8:
                cout << "Goodbye.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 8);

    freeList(morning);
    freeList(evening);
    return 0;
}
