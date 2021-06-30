//PATIENT CONSULTANCY MANAGEMENT USING LIST
/*FUNCTIONS OF LIST USED :  push_back()
                            pop_front()
                            pop_back()
                            front(),back()
                            size()
                            empty()*/
#include <iostream>
#include <list>
#include <string.h>
#include <cstdlib>

using namespace std;

void display_fees(int, int, int);                        //displays the total expenses
void choice_appointment();                               //Books your appointment
int guided_dept(string, string, string, string, string); //Lets you select the doctor and department based on your symptoms
void fixed_appointment(string, string, int);             //To display your appointment details
class Patient;                                           //forward declaration of class
class Medical_details
{ //holds the medical records of all patients
public:
    string patient_name;
    string doctor_name;
    int fees;
    char timing[30];
    char dept[30];

public:
    void input_Details();   //holds patient's medical record
    void output_Details();  //output patient's medical record
    void output_Expenses(); //calculates expenses
};

void Medical_details::input_Details()
{
    cout << "\n-----------------------------------------\n"
         << endl;
    cout << "Please fill up the form to help us keep your records: " << endl;
    cout << "\n-----------------------------------------\n"
         << endl;
    cout << "Enter your name: " << endl;
    cin >> patient_name;
    cout << endl;
    cout << "Enter the doctor's name you selected to consult with:(DR) " << endl;
    cin >> doctor_name;
    cout << endl;
    cout << "Enter the department you will be visiting: " << endl;
    cin >> dept;
    cout << endl;
    cout << "Enter the timings of your appointment: " << endl;
    cin >> timing;
    cout << endl;
    cout << "Enter the visiting fees of your doctor: " << endl;
    cin >> fees;
}
void Medical_details::output_Details()
{
    cout << patient_name << "\t\t" << doctor_name << "\t\t\t" << dept << "\t\t\t" << timing << "\t\t" << fees << endl;
}
void Medical_details::output_Expenses()
{
    int ch, reg_fee = 500, med_fee, doc_fee, ch1;
    char n[30];
    cout << "Enter your name: ";
    cin >> n;
    cout << "Kindly choose the category of the medicine you require: " << endl;
    cout << "1.Cardiovascular Medicine" << endl;
    cout << "2.Gasterological Medicine" << endl;
    cout << "3.Gynaecological Medicine" << endl;
    cout << "4.Dermatological Medicine" << endl;
    cout << "5.Psychiatric Medicine" << endl;
    cin >> ch1;
    switch (ch1)
    {
    case 1:
        med_fee = 3000;
        doc_fee = 1050;
        cout << "Your name: \t" << n;
        display_fees(reg_fee, med_fee, doc_fee);
        break;

    case 2:
        med_fee = 2000;
        doc_fee = 1000;
        cout << "Your name: \t" << n;
        display_fees(reg_fee, med_fee, doc_fee);
        break;

    case 3:
        med_fee = 1500;
        doc_fee = 950;
        cout << "Your name: \t" << n;
        display_fees(reg_fee, med_fee, doc_fee);
        break;

    case 4:
        med_fee = 1100;
        doc_fee = 900;
        cout << "Your name: \t" << n;
        display_fees(reg_fee, med_fee, doc_fee);
        break;

    case 5:
        med_fee = 1500;
        doc_fee = 900;
        cout << "Your name: \t" << n;
        display_fees(reg_fee, med_fee, doc_fee);
        break;

    default:
        cout << "Wrong choice!";
    }
}
class Patient : public Medical_details
{ //stores the personal details of all patients
public:
    char name[30];
    char sex;
    int age;
    float weight;
    float height;
    char email[30];
    unsigned long long int contact;

public:
    // default constructor
    Patient()
    {
        strcpy(name, "N/A");
        sex = ' ';
        age = 0;
        weight = 0.0;
        height = 0.0;
        strcpy(email, "N/A");
        contact = 0;
    }
    // Parameterized constructor
    Patient(char *pName, char pSex, int pAge, float pWeight, float pHeight, char *pEmail, unsigned long long int pContact)
    {
        strcpy(name, pName);
        sex = pSex;
        age = pAge;
        weight = pWeight;
        height = pHeight;
        strcpy(email, pEmail);
        contact = pContact;
    }
    void getDetails();  //inputs personal information of all patients
    void showDetails(); //outputs all patient's personal information
};
void Patient::getDetails()
{
    cout << "\n-----------------------------------------\n"
         << endl;
    cout << "Please enter the personal details of the Patient" << endl;
    cout << "\n-----------------------------------------\n"
         << endl;
    cout << endl;
    cout << "Please enter the Name of the Patient:" << endl;
    cin >> name;
    //getline(cin, name);
    cout << endl;
    cout << "Please enter the Gender of the Patient:" << endl;
    cin >> sex;
    cout << endl;
    cout << "Please enter the Age of the Patient:" << endl;
    cin >> age;
    cout << endl;
    cout << "Please enter the Height of the Patient:(in cm)" << endl;
    cin >> height;
    cout << endl;
    cout << "Please enter the Weight of the Patient:(in kg)" << endl;
    cin >> weight;
    cout << endl;
    cout << "Please enter the Email of the Patient:" << endl;
    cin >> email;
    cout << endl;
    cout << "Please enter the Contact Number of the Patient: " << endl;
    cin >> contact;
    cout << endl;
}
void Patient::showDetails()
{
    cout << name << "\t" << sex << "\t" << age << "\t" << weight << "\t" << height << "\t" << email << "\t\t" << contact << "\t" << endl;
}

int main()
{ //main function starts
    list<Patient> lst;
    list<Patient>::iterator it;
    list<Medical_details> mst;
    list<Medical_details>::iterator its;
    Medical_details m1, temp1;
    Patient p1, temp;
    int choice, flag;
    while (1)
    {
        cout << "\n-----------------------------------------\n"
             << endl;
        cout << "Patient Consultancy Management System" << endl;
        cout << "\n-----------------------------------------\n"
             << endl;
        cout << "1.Enter a new Patient's details." << endl;
        cout << "2.To book an appointment." << endl;
        cout << "3.Delete Patient's record from the front." << endl;
        cout << "4.Delete Patient's record from the back." << endl;
        cout << "5.View all Expenses." << endl;
        cout << "6.View all Patient's records." << endl;
        cout << "7.View the total number of patients in the hospital" << endl;
        cout << "8.Evacuate the entire hospital" << endl;
        cout << "9.Leave the Hospital." << endl;
        cout << "\nEnter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p1.getDetails();
            lst.push_back(p1);
            break;
        case 2:
            choice_appointment();
            m1.input_Details();
            mst.push_back(m1);
            break;
        //deleting from front
        case 3:
            if (lst.empty()) //checks if the list is empty or not
            {
                cout << "Currently there are no patient records to display";
                break;
            }
            int c;
            cout << "Press 1 to delete Patient's Personal Record:" << endl
                 << "Press 2 to delete Patient's Medical Records: " << endl;
            cin >> c;
            if (c == 1)
            {
                cout << endl;
                cout << "The personal details of the patient before deleting are: " << endl;
                cout << endl;
                cout << "Name"
                     << "\t"
                     << "Sex"
                     << "\t"
                     << "Age"
                     << "\t"
                     << "Weight"
                     << "\t"
                     << "Height"
                     << "\t"
                     << "Email"
                     << "\t\t"
                     << "Contact no" << endl;
                for (it = lst.begin(); it != lst.end(); ++it)
                    it->showDetails();

                cout << "\t" << endl;
                temp = lst.front();
                lst.pop_front(); //deletes one record

                cout << "The personal details of the patient after deleting are: " << endl;
                cout << endl;
                cout << "Name"
                     << "\t"
                     << "Sex"
                     << "\t"
                     << "Age"
                     << "\t"
                     << "Weight"
                     << "\t"
                     << "Height"
                     << "\t"
                     << "Email"
                     << "\t\t"
                     << "Contact no" << endl;
                for (it = lst.begin(); it != lst.end(); ++it)
                    it->showDetails();

                cout << "\t" << endl;
            }
            else //deleting medical record
            {
                cout << endl;

                cout << "The medical details of the patients before deleting are: " << endl;
                cout << endl;
                cout << "Patient's Name"
                     << "\t"
                     << "Consulting Doctor"
                     << "\t"
                     << "Visiting Department"
                     << "\t\t"
                     << "Appointment Timings"
                     << "\t\t"
                     << "Fee" << endl;
                for (its = mst.begin(); its != mst.end(); ++its)
                    its->output_Details();

                cout << "\t" << endl;
                temp1 = mst.front();
                mst.pop_front();
                cout << endl;
                cout << "The medical details of the patients after deleting are: " << endl;
                cout << endl;
                cout << "Patient's Name"
                     << "\t"
                     << "Consulting Doctor"
                     << "\t"
                     << "Visiting Department"
                     << "\t\t"
                     << "Appointment Timings"
                     << "\t\t"
                     << "Fee" << endl;
                for (its = mst.begin(); its != mst.end(); ++its)
                    its->output_Details();

                cout << "\t" << endl;
            }
            cout << "THANK YOU!" << endl;
            break;
        //deleting from back
        case 4:
            if (lst.empty())
            {
                cout << "Currently there are no patient records to display";
                break;
            }
            int choice1;
            cout << "Press 1 to delete Patient's Personal Record:" << endl
                 << "Press 2 to delete Patient's Medical Records: " << endl;
            cin >> choice1;
            if (choice1 == 1)
            {
                cout << endl;
                cout << "The personal details of the patients before deleting are: " << endl;
                cout << endl;
                cout << "Name"
                     << "\t"
                     << "Sex"
                     << "\t"
                     << "Age"
                     << "\t"
                     << "Weight"
                     << "\t"
                     << "Height"
                     << "\t"
                     << "Email"
                     << "\t\t\t"
                     << "Contact no" << endl;
                for (it = lst.begin(); it != lst.end(); ++it)
                    it->showDetails();

                cout << "\t" << endl;
                temp = lst.back();
                lst.pop_back();

                cout << "The personal details of the patients after deleting are: " << endl;
                cout << endl;
                cout << "Name"
                     << "\t"
                     << "Sex"
                     << "\t"
                     << "Age"
                     << "\t"
                     << "Weight"
                     << "\t"
                     << "Height"
                     << "\t"
                     << "Email"
                     << "\t\t\t"
                     << "Contact no" << endl;
                for (it = lst.begin(); it != lst.end(); ++it)
                    it->showDetails();

                cout << "\t" << endl;
            }
            else
            {
                cout << endl;
                cout << "The medical details of the patients before deleting are: " << endl;
                cout << endl;
                cout << "Patient's'Name"
                     << "\t\t"
                     << "Consulting Doctor"
                     << "\t\t"
                     << "Visiting Department"
                     << "\t\t"
                     << "Appointment Timings"
                     << "\t\t"
                     << "Fees" << endl;
                for (its = mst.begin(); its != mst.end(); ++its)
                    its->output_Details();

                cout << "\t" << endl;
                temp1 = mst.back();
                mst.pop_back();

                cout << endl;
                cout << "The medical details of the patients after deleting are: " << endl;
                cout << endl;
                cout << "Patient's Name"
                     << "\t\t"
                     << "Consulting Doctor"
                     << "\t\t"
                     << "Visiting Department"
                     << "\t\t"
                     << "Appointment Timings"
                     << "\t\t"
                     << "Fees" << endl;
                for (its = mst.begin(); its != mst.end(); ++its)
                    its->output_Details();

                cout << "\t" << endl;
            }
            cout << "THANK YOU!" << endl;
            break;
        case 5:
            temp1.output_Expenses();
            break;
        //view details
        case 6:
            if (lst.empty())
            {
                cout << "Currently there are no patient records to display";
                break;
            }
            int c1;
            cout << endl;
            cout << "Press 1 to view all Patient's Personal Record:" << endl
                 << "Press 2 to view all Patient's Medical Records: " << endl;
            cin >> c1;
            if (c1 == 1)
            {
                cout << endl;
                cout << "The personal details of the patient are: " << endl;
                cout << endl;
                cout << "Name"
                     << "\t"
                     << "Sex"
                     << "\t"
                     << "Age"
                     << "\t"
                     << "Weight"
                     << "\t"
                     << "Height"
                     << "\t"
                     << "Email"
                     << "\t\t\t\t"
                     << "Contact Number" << endl;
                for (it = lst.begin(); it != lst.end(); ++it)
                    it->showDetails();

                cout << "\t" << endl;
                cout << "THANK YOU!" << endl;
            }
            else
            {
                cout << endl;
                cout << "The medical details of the patient are: " << endl;
                cout << endl;
                cout << "Patient's Name"
                     << "\t"
                     << "Consulting Doctor"
                     << "\t"
                     << "Visiting Department"
                     << "\t\t"
                     << "Appointment Timings"
                     << "\t\t"
                     << "Fees" << endl;
                for (its = mst.begin(); its != mst.end(); ++its)
                    its->output_Details();

                cout << "\t" << endl;

                cout << "THANK YOU!" << endl;
            }

            break;
        case 7:
            cout << "The total number of patients currently in the hospital are:\t" << lst.size();
            break;
        case 8:
            cout << "A corona patient has been detected !!! The hospital will be closed and everybody will be safely evacuated !!" << endl;
            cout << "We apologize for the inconvience caused !! All patient's records are deleted !! " << endl;
            lst.clear();
            mst.clear();
            break;

        case 9:
            cout << "Thank You For Visiting !";
            exit(0);
            break;
        default:
            cout << "Wrong Choice!" << endl;
        }
    }
    return 0;
}
void display_fees(int rf, int mf, int df)
{
    cout << endl;
    cout << "Your total bill summary is as follows:" << endl;
    cout << "Registration Fee: \t\t" << rf << endl;
    cout << "Visiting Doctor Fee: \t\t" << df << endl;
    cout << "Medicinal Fee: \t\t\t" << mf << endl;
    cout << "Total: \t\t\t\t" << rf + df + mf << endl;
    cout << "THANK YOU!";
}
void choice_appointment()
{
    int ch1, ch2, f;
    string d, doc1, doc2, t1, t2;
    cout << "\n-----------------------------------------\n"
         << endl;
    cout << "Welcome to the Appointment Centre" << endl;
    cout << "\n-----------------------------------------\n"
         << endl;
    cout << endl;
    cout << "Please select the symptoms you may be suffering from: " << endl;
    cout << endl;
    cout << "1.Chest Pain, Chest discomfort, Shortness of breath, Pain in the neck, Jaw, Throat, Upper Abdomen or Back." << endl;
    cout << endl;
    cout << "2.Abdominal pain and discomfort, Constipation and Diarrhoea, Nausea, Vomiting." << endl;
    cout << endl;
    cout << "3.Burning sensation during urination, Pain or pressure in pelvis, Sores or lumps in the genital area." << endl;
    cout << endl;
    cout << "4.Skin, Hair, Nails, and Adjacent Mucous Membranes Disorders. " << endl;
    cout << endl;
    cout << "5.Emotional and Mental Illness (Physical, Emotional, Behavioural)." << endl;
    cout << "\nEnter your choice: ";
    cin >> ch1;
    switch (ch1)
    {
    case 1:
        d = "CARDIOLOGY";
        doc1 = "Dr. A.S.BAWA ";
        doc2 = "Dr. A.J.KASHYAP ";
        t1 = "11AM-12:30PM";
        t2 = "10AM-11:30PM";
        f = 1050;
        ch2 = guided_dept(d, doc1, doc2, t1, t2);
        switch (ch2)
        {
        case 1:
            fixed_appointment(doc1, t1, f);
            break;

        case 2:
            fixed_appointment(doc2, t2, f);
            break;
        default:
            cout << "Wrong choice";
        }
        break;
    case 2:
        d = "GASTERNOLOGY";
        doc1 = "Dr A.GUPTA";
        doc2 = "Dr A.P.SEHGAL";
        t1 = "02:00PM-03:30PM";
        t2 = "04:00PM-05:30PM";
        f = 1000;
        ch2 = guided_dept(d, doc1, doc2, t1, t2);
        switch (ch2)
        {
        case 1:
            fixed_appointment(doc1, t1, f);
            break;

        case 2:
            fixed_appointment(doc2, t2, f);
            break;
        default:
            cout << "Wrong choice";
        }
        break;
    case 3:
        d = "GYNAECOLOGY";
        doc1 = "Dr. BEDI ";
        doc2 = "Dr A.B.SINGHAL";
        t1 = "11AM-12:30PM";
        t2 = "10AM-11:30PM";
        f = 1500;
        ch2 = guided_dept(d, doc1, doc2, t1, t2);
        switch (ch2)
        {
        case 1:
            fixed_appointment(doc1, t1, f);
            break;

        case 2:
            fixed_appointment(doc2, t2, f);
            break;
        default:
            cout << "Wrong choice";
        }
        break;
    case 4:
        d = "DERMATOLOGY";
        doc1 = "Dr LIPIKA ";
        doc2 = "Dr M.MISHRA";
        t1 = "06:00PM-07:30PM";
        t2 = "10:00AM-12:00PM";
        f = 1200;
        ch2 = guided_dept(d, doc1, doc2, t1, t2);
        switch (ch2)
        {
        case 1:
            fixed_appointment(doc1, t1, f);
            break;

        case 2:
            fixed_appointment(doc2, t2, f);
            break;
        default:
            cout << "Wrong choice";
        }
        break;
    case 5:
        d = "PSYCHIATRY";
        doc1 = "Dr P.B.DUTTA";
        doc2 = "Dr M.MIGLANI";
        t1 = "11AM-12:30PM";
        t2 = "01:00PM-02:30PM";
        f = 1800;
        ch2 = guided_dept(d, doc1, doc2, t1, t2);
        switch (ch2)
        {
        case 1:
            fixed_appointment(doc1, t1, f);
            break;

        case 2:
            fixed_appointment(doc2, t2, f);
            break;
        default:
            cout << "Wrong choice";
        }
        break;
    default:
        cout << "Wrong choice";
    }
}

int guided_dept(string d, string n1, string n2, string t1, string t2)
{
    int ch2;
    cout << "YOU ARE GUIDED TO OUR " << d << " DEPARTMENT" << endl;
    cout << endl;
    cout << "Here is a list of the avaliable doctors with their timings. Kindly select one according to your need." << endl;
    cout << endl;
    cout << "SERIAL NO"
         << "\t"
         << "NAME"
         << "\t"
         << "\t"
         << "APPOINTMENT TIME" << endl;
    cout << "1."
         << "\t" << n1 << "\t"
         << "\t" << t1 << endl;
    cout << "2."
         << "\t" << n2 << "\t" << t2 << endl;
    cout << endl;
    cout << "Enter the Doctor you wish to consult: " << endl;
    cin >> ch2;
    return ch2;
}

void fixed_appointment(string n, string t, int f)
{
    cout << "YOUR APPOINTMENT WITH " << n << " IS FIXED AT TIME " << t << endl;
    cout << endl;
    cout << "YOUR APPOINTMENT FEE IS RS " << f << endl;
    cout << endl;
    cout << "THANK YOU!" << endl;
}
