#include <iostream> 
#include <string>
using namespace std;

/// <summary> 
/// add the variables we will use. We call the class �DateTime� because in it we will determine the date we need
/// </summary> 
class DateTime
{
private:
    int day;
    int month;
    int year;

public:

    /// <summary> 
    /// a method to set day of birth 
    /// </summary> 
    /// <param name="day"></param> 
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) // TO DO: february 28-29, april june 30 
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary> 
    /// a method to get day of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetDay() const
    {
        return day;
    }

    /// <summary> 
    /// a method to set month of birth 
    /// </summary> 
    /// <param name="month"></param> 
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary> 
    /// a method to get month of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetMonth() const
    {
        return month;
    }

    /// <summary> 
    /// a method to set year of birth 
    /// </summary> 
    /// <param name="year"></param> 
    void SetYear(int year)
    {
        this->year = year;
    }

    /// <summary> 
    /// a method to get year of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetYear() const
    {
        return year;
    }
    DateTime() {
        //cout << "DateTime c-tor without parameters\n";
        SetDay(23);
        SetMonth(3);
        SetYear(2005);
    }

    DateTime(int day, int month) {
        //cout << "DateTime c-tor with 2 parameters\n";
        SetDay(day);
        SetMonth(month);
        SetYear(2005);
    }

    DateTime(int day, int month, int year)
    {
        //cout << "DateTime main c-tor with 3 parameters\n";
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    DateTime(const DateTime& original)
    {
        //cout << "DateTime copy constructor\n";
        this->day = original.day;
        this->month = original.month;
        this->year = original.year;
    }

    ~DateTime() {
        //cout << "DateTime destructor\n";
    }


    /// <summary>
    /// display our date on the screen
    /// </summary>
    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
    string date_to_string()
    {
        string s;
        s += to_string(day);
        s += '.';
        s += to_string(month);
        s += '.';
        s += to_string(year);
        return s;
    }

    int& operator [] (unsigned int index)
    {
        if (index == 0)return day;
        if (index == 1)return month;
        if (index == 2)return year;
        throw"Incorrect index\n";
    }
};

// �������������� ��� cin >> date time
istream& operator >> (istream& cin, DateTime& s)
{
    int day;
    cout << "Enter the start day of study: ";
    cin >> day;
    s.SetDay(day);

    int month;
    cout << "Enter the start month of study: ";
    cin >> month;
    s.SetMonth(month);

    int year;
    cout << "Enter the start year of study: ";
    cin >> year;
    s.SetYear(year);

    return cin;
}

// �������������� ��� cout << date time
ostream& operator << (ostream& cout, const DateTime& s)
{
    cout << "Day of study start: " << s.GetDay() << "\n";
    cout << "Month of study start: " << s.GetMonth() << "\n";
    cout << "Year of study start: " << s.GetYear() << "\n";
    return cout;
}

////////////////////////////////////////////////////// 

/// <summary>
/// add the variables we will use. We call the class �Student� because in it we will describe student's personal information
/// </summary>
class Student
{
    static unsigned int count;

    string name;
    string surname;
    string father_name;
    string address;
    string phone_number;
    int home_task_average_rate;
    int age;
    DateTime birthday;
    DateTime study_start; // 25.10.1998 

    // TO DO:  

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    int* practice_rates = nullptr;
    int practice_rates_count = 0;

    int* exam_rates = nullptr;
    int exam_rates_count = 0;

public:
    static unsigned int GetCount()
    {
        return count;
    }

    Student()
    {
        count++;

        SetName("Minho");
        SetStudyStart({ 1, 9, 2022 });
    }

    Student(const Student& original)
    {
        count++;

        this->name = original.name;
        this->surname = original.surname;
        this->birthday = original.birthday;
        this->study_start = original.study_start;

        this->hometask_rates_count = original.hometask_rates_count;

        this->hometask_rates = new int[this->hometask_rates_count];
        for (int i = 0; i < this->hometask_rates_count; i++)
        {
            this->hometask_rates[i] = original.hometask_rates[i];
        }

        this->practice_rates_count = original.practice_rates_count;

        this->practice_rates = new int[this->practice_rates_count];
        for (int i = 0; i < this->practice_rates_count; i++)
        {
            this->practice_rates[i] = original.practice_rates[i];
        }

        this->exam_rates_count = original.exam_rates_count;

        this->exam_rates = new int[this->exam_rates_count];
        for (int i = 0; i < this->exam_rates_count; i++)
        {
            this->exam_rates[i] = original.exam_rates[i];
        }
    }

    Student(string value)
    {
        name = value;
    }
    /*Student() :Student("Minho", "lee", "Minsung", {25, 10, 1998}, "Seoul", "0325112014", {1, 9, 2022}) {}

    Student(string name, string surname, string father_name, string address, string phone_number) :Student("Minho", "Lee", "Minsung", { 25, 10, 1998 }, "Seoul", "0325112014", { 1, 9, 2022 }) {}

    Student(string name, string surname, string father_name, DateTime birthday, string address, string phone_number, DateTime study_start)
    {
        SetName(name);
        SetSurname(surname);
        SetFatherName(father_name);
        SetBirthday(birthday);
        SetAddress(address);
        SetPhoneNumber(phone_number);
        SetStudyStart(study_start);
    }*/

    /// <summary> 
    ///  Defines a destructor for the class "Student." This destructor checks for allocated memory for the "hometask_rates" array and removes it if there is, preventing a memory leak
    /// </summary> 
    ~Student()
    {
        count--;

        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }
    }

    /// <summary> 
    /// a method to set the name 
    /// </summary> 
    /// <param name="name"></param> 
    void SetName(string name)
    {
        this->name = name;
    }

    /// <summary> 
    /// a method to get the name 
    /// </summary> 
    /// <returns></returns> 
    string GetName() const
    {
        return name;
    }

public:

    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

    /// <summary>
    /// a method to get birthday
    /// </summary>
    /// <returns></returns>
    DateTime GetBirthday() const
    {
        return birthday;
    }
    /// <summary>
    /// a method to set the date of study start
    /// </summary>
    /// <param name="study_start"></param>
    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }
    /// <summary>
    /// a method to get the date of study start
    /// </summary>
    /// <returns></returns>
    DateTime GetStudyStart() const
    {
        return study_start;
    }

    /// <summary>
    /// � method that allows you to change a student's last name
    /// </summary>
    /// <param name="surname">some new value for student surname</param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// a method to get the surname
    /// </summary>
    /// <returns></returns>
    string GetSurname() const
    {
        return surname;
    }

    /// <summary>
    ///  � method that allows you to change a student's father name
    /// </summary>
    /// <param name="father_name"></param>
    void SetFatherName(string father_name) {
        this->father_name = father_name;
    }

    /// <summary>
    /// a method to get the father name
    /// </summary>
    /// <returns></returns>
    string GetFatherName() const {
        return father_name;
    }

    /// <summary>
    /// � method that allows you to change a student's address
    /// </summary>
    /// <param name="address"></param>
    void SetAddress(string address) {
        this->address = address;
    }

    /// <summary>
    /// a method to get the adress
    /// </summary>
    /// <returns></returns>
    string GetAddress() const {
        return address;
    }

    /// <summary>
    /// � method that allows you to change a student's phone number
    /// </summary>
    /// <param name="phone_number"></param>
    void SetPhoneNumber(string phone_number) {
        this->phone_number = phone_number;
    }

    /// <summary>
    /// a method to get the phone number
    /// </summary>
    /// <returns></returns>
    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    int GetAge() const
    {
        return age;
    }
    /// <summary>
    /// This method involves adding a grade to the student's homework grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++)
                temp[i] = hometask_rates[i];
            temp[hometask_rates_count] = rate;
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }
    /// <summary>
    /// shows grades for the student's hometask
    /// </summary>
    void PrintHometaskRates() const
    {
        cout << "Hometasks rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i] << ", ";
        }
        cout << "\n";
    }
    /// <summary>
    /// returns the hometask grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetHometaskRateByIndex(unsigned int index) const //to get the grade by index, but without returning a pointer to the original data array, we need to add the "const" keyword to this method
    {
        if (index >= hometask_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return hometask_rates[index];
    }
    /// <summary>
    /// a method to get the hometasks grade count
    /// </summary>
    /// <returns></returns>
    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
    }

    int GetHometaskAverageRate() const
    {
        return home_task_average_rate;
    }

    /// <summary>
    /// This method involves adding a grade to the student's practice grade list, and the grade should be between 1 and 12 points
    /// </summary>
    /// <param name="rate"></param>
    void AddPracticeRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (practice_rates_count == 0)
        {
            practice_rates = new int[1];
            practice_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[practice_rates_count + 1];

            for (int i = 0; i < practice_rates_count; i++)
            {
                temp[i] = practice_rates[i];
            }
            temp[practice_rates_count] = rate;

            delete[] practice_rates;

            practice_rates = temp;
        }

        practice_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's practice
    /// </summary>
    void PrintPracticeRates() const
    {
        cout << "Practice rates: ";
        for (int i = 0; i < practice_rates_count; i++)
        {
            cout << practice_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the practice grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetPracticeRateByIndex(unsigned int index) const //to get the grade by index, but without returning a pointer to the original data array, we need to add the "const" keyword to this method
    {
        if (index >= practice_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return practice_rates[index];
    }

    /// <summary>
    ///  a method to get the practice grade count
    /// </summary>
    /// <returns></returns>
    int GetPracticeRatesCount() const
    {
        return practice_rates_count;
    }

    /// <summary>
    /// This method involves adding a grade to the student's exam rate list, and the grade should be between 1 and 12 points
    /// </summary>
    /// <param name="rate"></param>
    void AddExamRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (exam_rates_count == 0)
        {
            exam_rates = new int[1];
            exam_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[exam_rates_count + 1];

            for (int i = 0; i < exam_rates_count; i++)
            {
                temp[i] = exam_rates[i];
            }
            temp[exam_rates_count] = rate;

            delete[] exam_rates;

            exam_rates = temp;
        }

        exam_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's exams
    /// </summary>
    void PrintExamRates() const
    {
        cout << "Exam rates: ";
        for (int i = 0; i < exam_rates_count; i++)
        {
            cout << exam_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the exam grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetExamRateByIndex(unsigned int index) const //to get the grade by index, but without returning a pointer to the original data array, we need to add the "const" keyword to this method
    {
        if (index >= exam_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return exam_rates[index];
    }

    /// <summary>
    ///  a method to get the exam grade count
    /// </summary>
    /// <returns></returns>
    int GetExamRatesCount() const
    {
        return exam_rates_count;
    }

    int GetAverageHometaskRate()const
    {
        int average = 0;
        for (int i = 0; i < hometask_rates_count; i++)
            average += hometask_rates[i];
        average = average / hometask_rates_count;
        return average;
    }

    /// <summary>
    /// print's student's whole information, but without grades
    /// </summary>
    void ShowStudent() const
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        //cout << "Birthday: " << birthday << endl;
        cout << "Father Name: " << father_name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_number << endl;
        //cout << "Study Start: " << study_start << endl;
    }

    Student& operator=(const Student& original)
    {
        if (this == &original)
            return *this;
        name = original.name;
        surname = original.surname;
        birthday = original.birthday;
        study_start = original.study_start;

        if (hometask_rates != nullptr)
            delete[] hometask_rates;

        if (exam_rates != nullptr)
            delete[]exam_rates;

        if (practice_rates != nullptr)
            delete[]practice_rates;

        hometask_rates_count = original.hometask_rates_count;
        exam_rates_count = original.exam_rates_count;
        practice_rates_count = original.practice_rates_count;

        if (hometask_rates_count > 0)
        {
            hometask_rates = new int[hometask_rates_count];
            for (int i = 0; i < hometask_rates_count; i++)
                hometask_rates[i] = original.hometask_rates[i];
        }

        if (exam_rates_count > 0)
        {
            exam_rates = new int[exam_rates_count];
            for (int i = 0; i < exam_rates_count; i++)
                exam_rates[i] = original.exam_rates[i];
        }

        if (practice_rates_count > 0)
        {
            practice_rates = new int[practice_rates_count];
            for (int i = 0; i < practice_rates_count; i++)
                practice_rates[i] = original.practice_rates[i];
        }

        return *this;
    }

};

bool operator==(const Student& left, const Student& right)
{
    return left.GetAverageHometaskRate() == right.GetAverageHometaskRate();
}

bool operator!=(const Student& left, const Student& right)
{
    return left.GetAverageHometaskRate() != right.GetAverageHometaskRate();
}

bool operator>(const Student& left, const Student& right)
{
    return left.GetAverageHometaskRate() > right.GetAverageHometaskRate();
}

bool operator<(const Student& left, const Student& right)
{
    return left.GetAverageHometaskRate() < right.GetAverageHometaskRate();
}

// �������������� ��� cin >> student
istream& operator >> (istream& cin, Student& s)
{
    string name; // �������� ��������� ��i���
    cout << "Enter student's name: ";
    cin >> name;
    s.SetName(name);

    string surname; // �� ���� �������� ��������� ��i���
    cout << "Enter student's surname: ";
    cin >> surname;
    s.SetSurname(surname);

    string father_name; 
    cout << "Enter student's father name: ";
    cin >> father_name;
    s.SetFatherName(father_name);

    string address;
    cout << "Enter student's address: ";
    cin >> address;
    s.SetAddress(address);

    DateTime birthday;

    cout << "Enter the student's day of birth (1-31): ";
    int day;
    cin >> day; // 23
    birthday.SetDay(day);

    cout << "Enter the student's month of birth (1-12): ";
    int month;
    cin >> month; // 3
    birthday.SetMonth(month);

    cout << "Enter the student's year of birth: ";
    int year;
    cin >> year; // 2005
    birthday.SetYear(year);

    s.SetBirthday(birthday);

    return cin;
}

// �������������� ��� cout << student
ostream& operator << (ostream& cout, const Student& s)
{
    cout << "Student name: " << s.GetName() << "\n";
    cout << "Student surname: " << s.GetSurname() << "\n";
    return cout;
}

unsigned int Student::count = 0;

class Group
{
    Student* group;
    Student** students = nullptr;
    int students_count = 0;
    int group_size;
    string group_name;
    int course_number;
    string specialization;
    int home_task_average_rate;
    void SetGroupSize(int group_size)
    {
        this->group_size = group_size;
    }

public:
    /*friend istream& operator>>(istream& cin, Group& s);
    friend ostream& operator<<(ostream& cout, Group& s);*/
    Group() : Group(0) {}
    /*Group()
    {
        SetGroupName(group_name);
        SetSpecializationGroup(specialization);
        SetCourseNumber(2);
    }*/

    Group(int group_size)
    {
        this->group_size = group_size;
        SetCourseNumber(2);
        SetGroupName(group_name);
        SetSpecializationGroup(specialization);
        group = new Student[group_size];
    }

    Group(int group_size, int course_number, string group_name, string specialization)
    {
        this->group_size = group_size;
        this->course_number = course_number;
        this->group_name = group_name;
        this->specialization = specialization;
        group = new Student[group_size];
    }

    Group(const Group& original)
    {
        //this->home_task_average_rate = original.home_task_average_rate;
        this->course_number = original.course_number;
        this->specialization = original.specialization;
        this->group_name = original.group_name;
        this->students_count = original.students_count;

        this->students = new Student * [this->students_count];
        for (int i = 0; i < this->students_count; i++)
        {
            this->students[i] = original.students[i];
        }
    }

    /*~Group()
    {
        if (students != nullptr)
        {
            for (int i = 0; i < students_count; i++)
            {
                delete students[i];
            }
            delete[] students;
        }
    }*/

    Group& operator=(const Group& original)
    {
        if (this == &original)
        {
            return *this;
        }

        if (group != nullptr)
            delete[] group;

        group_size = original.group_size;
        course_number = original.course_number;
        group_name = original.group_name;
        specialization = original.specialization;

        group = new Student[group_size];
        for (int i = 0; i < this->group_size; i++)
            group[i] = original.group[i];

        return *this;
    }

    void printGroup()
    {
        cout << "Group name: " << group_name << endl;
        cout << "Specialization: " << specialization << endl;
        int f;
        Student temp;
        for (int i = 1; i < group_size; i++)
        {
            f = 0;
            for (int r = 0; r < group_size - i; r++)
            {
                if (group[r].GetSurname() > group[r + 1].GetSurname())
                {
                    temp = group[r];
                    group[r] = group[r + 1];
                    group[r + 1] = temp;
                    f = 1;
                }
            }
            if (f == 0)
            {
                break;
            }
        }
        for (int i = 0; i < group_size; i++)
        {
            cout << i + 1 << ' ' << group[i].GetSurname() << ' ' << group[i].GetName();
            cout << endl;
        }
    }

    int getGroupSize() const
    {
        return group_size;
    }

    void SetCourseNumber(int course_number)
    {
        if (course_number > 0)
        {
            this->course_number = course_number;
        }
        else
        {
            cout << "Incorrect value!" << endl;
            throw "ERROR!\n";
        }
    }

    int GetCourseNumber() const
    {
        return course_number;
    }

    void SetSpecializationGroup(string specialization)
    {
        if (specialization != " ")
        {
            this->specialization = specialization;
        }
        else
        {
            cout << "Incorrect value!" << endl;
            throw "ERROR!\n";
        }
    }

    string GetSpecializationGroup() const
    {
        return specialization;
    }

    void SetGroupName(string group_name)
    {
        if (group_name != " ")
        {
            this->group_name = group_name;
        }
        else
        {
            cout << "Incorrect value!" << endl;
            throw "ERROR!\n";
        }
    }

    string GetGroupName() const
    {
        return group_name;
    }

    void SetStudentsCount(int students_count)
    {
        if (students_count > 0)
        {
            this->students_count = students_count;
        }
        else
        {
            cout << "Incorrect value!" << endl;
            throw "ERROR!\n";
        }
    }

    int StudentsCount() const
    {
        return students_count;
    }

    void AddStudent(const Student& new_student)
    {
        Student** temp = new Student * [students_count + 1];
        for (int i = 0; i < students_count; i++)
        {
            temp[i] = new Student(*students[i]);
        }

        temp[students_count] = new Student(new_student);
        delete[] students;
        students = temp;
        students_count++;
    }

    Student GetStudentByIndex(unsigned int index) const
    {
        if (index < students_count)
        {
            return *students[index];
        }
        else
        {
            cout << "Index out of bounds when accessing student array." << endl;
            throw "ERROR!";
        }
    }
   
    void RemoveStudentWithMinHomeworkAverage()
    {
        if (students_count == 0)
        {
            cout << "Group is empty. Cannot remove a student." << endl;
            return;
        }

        int lowestIndex = 0;
        double lowestAverage = students[0]->GetHometaskAverageRate(); // 7) ������ ��� �������� ����� ������ �� ������ ������� :)

        for (int i = 1; i < students_count; i++)
        {
            double currentAverage = students[i]->GetHometaskAverageRate();
            if (currentAverage < lowestAverage)
            {
                lowestAverage = currentAverage;
                lowestIndex = i;
            }
        }

        for (int i = lowestIndex; i < students_count - 1; i++)
        {
            students[i] = students[i + 1];
        }
        students_count--;

        //cout << "Removed student with the lowest homework average." << endl;
    }

    void GroupMerger(Group& another_group)
    {
        for (int i = 0; i < another_group.StudentsCount(); i++)
        {
            this->AddStudent(another_group.GetStudentByIndex(i));
        }

        int k = another_group.StudentsCount();
        for (int i = 0; i < k; i++)
        {
            another_group.RemoveStudentWithMinHomeworkAverage();
        }
    }

    void TransferStudent(Group& other, int index)
    {
        if (index >= 0 && index < students_count)
        {
            other.AddStudent(*students[index]);
            for (int i = index; i < students_count - 1; i++)
            {
                students[i] = students[i + 1];
            }
            students_count--;
        }
    }

    operator string()
    {
        string file;
        file += "Group name: \n";
        file += group_name;

        file += "Specialization: \n";
        file += specialization;

        for (int i = 0; i < group_size; i++)
        {
            file += "Student's number: \n";
            file += to_string(i + 1);

            file += "Name: \n";
            file += group[i].GetName();

            file += group[i].GetSurname();
            file += "Study start: \n";
            file += group[i].GetStudyStart().date_to_string();
        }
        return file;
    }

};

bool operator == (const Group& left, const Group& right)
{
    return left.getGroupSize() == right.getGroupSize();
}

bool operator != (const Group& left, const Group& right)
{
    return left.getGroupSize() != right.getGroupSize();
}

// �������������� ��� cin >> group
istream& operator >> (istream& cin, Group& s)
{
    string group_name; // �������� ��������� ��i���
    cout << "Enter the group name: ";
    cin >> group_name;
    s.SetGroupName(group_name);

    int course_number; // �� ���� �������� ��������� ��i���
    cout << "Enter the course number: ";
    cin >> course_number;
    s.SetCourseNumber(course_number);

    string specialization;
    cout << "Enter the group's specialization: ";
    cin >> specialization;
    s.SetSpecializationGroup(specialization);

    int students_count;
    cout << "Enter the number of students: ";
    cin >> students_count;
    s.SetStudentsCount(students_count);

    s.group = new Student[s.group_size];

    return cin;
}

// �������������� ��� cout << group
ostream& operator << (ostream& cout, const Group& s)
{
    cout << "Group name: " << s.GetGroupName() << "\n";
    cout << "Course number: " << s.GetCourseNumber() << "\n";

    /*for (int i = 0; i < s.group_size; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << s.group[i].GetName() << endl;
        cout << "Surname: " << s.group[i].GetSurname() << endl;
        cout << "Birthday: ";
        s.group[i].GetBirthday().Print();
        cout << "Study start date: ";
        s.group[i].GetStudyStart().Print();
    }*/

    return cout;
}

class Fraction
{
    int numerator; // ���������
    int denominator; // �����������

public:
    Fraction();
    Fraction(int numerator, int denominator);
    
    Fraction(int value)
    {
        numerator = value;
        denominator = 1;
    }

    double GetDecimal() const;
    void Print() const;
    void PrintDecimal() const;

    static Fraction Sum(const Fraction& left, const Fraction& right);
    bool GreaterThan(const Fraction& another) const;
    bool Equals(const Fraction& another) const;
    bool LessThan(const Fraction& another) const;

    int GetNumerator() const;
    int GetDenominator() const;
    void SetNumerator(int numerator);
    void SetDenominator(int denominator);
};

int main()
{
    setlocale(0, "UKR");

    string name = "Minho";
    Student st = name;
    Group a;

    a.AddStudent(st);
    string b = a;
    cout << b;

    Student s;
    cin >> s;
    cout << s;

    s.AddHometaskRate(10);
    s.AddHometaskRate(12);
    s.AddHometaskRate(9);
    s.AddHometaskRate(8);
    s.PrintHometaskRates();

    s.AddPracticeRate(7);
    s.AddPracticeRate(10);
    s.AddPracticeRate(9);
    s.AddPracticeRate(11);
    s.PrintPracticeRates();

    s.AddExamRate(12);
    s.AddExamRate(10);
    s.AddExamRate(11);
    s.AddExamRate(9);
    s.PrintExamRates();

    s.ShowStudent();
    cout << s.GetHometasksRatesCount() << "\n";
    cout << s.GetPracticeRatesCount() << "\n";
    cout << s.GetExamRatesCount() << "\n";
}