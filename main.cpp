/*
Assignment-2
Name: KHALED MAHMUD SUJON 
Matric number: A20EC4082
lecturer : Dr Bander Ali 
focus : linked list apply and operation 

*/

#include<iostream>
using namespace std;

class Student{
    public:
        string name;
        int metric_ID;
        string course_name;
        float total_mark;
        Student* next;

        Student(){
            name="";
            metric_ID=0;
            course_name="";
            total_mark=0.0;
            next=NULL;
        }
        Student(string n, int ID, string cn,float tm){
            name=n;
            ID=metric_ID;
            course_name=cn;
            total_mark=tm;
        }
};
//linked list 
class LinkedList{
    public:
        Student* head;
        LinkedList(){
            head=NULL;
        }
        LinkedList(Student* s){
            head=s;
        }
        // checking function
        Student* checkNode(int ID){
            Student* temp=NULL;

            Student* ptr=head;
            while(ptr!=NULL){
                if(ptr->metric_ID==ID){
                    temp=ptr;
                }
                ptr=ptr->next;
            }
            return temp;
        }

        //search operation for student
        void searchStudent(int ID){
            Student* temp=checkNode(ID);
            if(temp==NULL){
                cout<<"NO student found!"<<endl;
            }
            else{
                cout<<"Student Name: "<<temp->name<<endl;
                    cout<<"Metric ID: "<<temp->metric_ID<<endl;
                    cout<<"Course Enrolled: "<<temp->course_name<<endl;
                    cout<<"Total mark: "<<temp->total_mark<<endl;
                    cout<<endl;
            }
        }

        //Insert operation for  student
        void insertStudent(Student* s){
            if(checkNode(s->metric_ID)!=NULL){
                cout<<"Student with metric ID: "<<s->metric_ID<<" exist"<<endl;
            }
            else{
                if(head==NULL){
                    head=s;
                    cout<<"<----- Student added ----->"<<endl;
                }
                else{
                    Student *ptr=head;
                    while(ptr->next!=NULL){
                        ptr=ptr->next;
                    }
                    ptr->next=s; //insert student
                    cout<<"<----- Student added ----->"<<endl;
                }
            }
        }

        //Delete operatation for  student
        void deleteStudent(int ID){
            if(head==NULL){
                cout<<"There is no student record"<<endl;
            }
            else{
                //first node delete
                if(head->metric_ID==ID){
                    head=head->next;
                    cout<<"<----- Student deleted ----->"<<endl;                
                }
                else{
                    Student *temp=NULL;
                    Student* prevptr=head;
                    Student* currentptr=head->next;

                    while(currentptr!=NULL){
                        if(currentptr->metric_ID==ID){
                            temp=currentptr;
                            currentptr=NULL;
                        }
                        else{
                            prevptr=prevptr->next;
                            currentptr=currentptr->next;
                        }
                    }//end of while loop
                    if(temp!=NULL){
                        prevptr->next=temp->next;
                        cout<<"<----- Student deleted ----->"<<endl;
                    }
                    else{
                        cout<<"Student does not Exist with metric ID: "<<ID<<endl;
                    }
                }
            }
        }

        //print all student record  
        void printRecord(){
            if(head==NULL){
                cout<<"Student record empty"<<endl;
            }
            else{
                int i=0;
                Student *temp=head;
                cout<<"The Student Record: "<<endl;
                while(temp!=NULL){
                    ++i;
                    cout<<"|| Record "<<i<<" ||"<<endl;
                    cout<<"Student Name: "<<temp->name<<endl;
                    cout<<"Metric ID: "<<temp->metric_ID<<endl;
                    cout<<"Course Enrolled: "<<temp->course_name<<endl;
                    cout<<"Total mark: "<<temp->total_mark<<endl;
                    cout<<endl;
                    temp=temp->next;
                }
            }
        }

};

// main function 
int main(){
    LinkedList l1;
    int option;
    string name,course;
    int ID,k;
    float total_mark;

    do{
        cout<<"##########WELCOME##########"<<endl;
        cout<<endl<<"What operation do you want to perform? select option number. enter 0 to exit"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Search Student"<<endl;
        cout<<"3. Delete Student"<<endl;
        cout<<"4. Print all Student"<<endl;
        cout<<"5. clear screen"<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>option;
        cin.ignore();
        cout<<endl;

        Student* s1=new Student();//dynamic memory allocation

        switch(option){
            case 0: break;
            case 1:
                cout<<"Enter the details of Student"<<endl;
                cout<<"Name: ";
                getline(cin,name);
                cout<<"Metric ID: ";
                cin>>ID;
                cin.ignore();
                cout<<"Course enrolled: ";
                getline(cin,course);
                cout<<"Total mark: ";
                cin>>total_mark;

                s1->name=name;
                s1->course_name=course;
                s1->metric_ID=ID;
                s1->total_mark=total_mark;

                l1.insertStudent(s1);

                break;
            
            case 2: 
                cout<<"Enter Student metric ID: ";
                cin>>k;
                l1.searchStudent(k);

                break;
            
            case 3: 
                cout<<"Delete operation"<<endl;
                cout<<"Enter Student metric ID: ";
                cin>>k;
                l1.deleteStudent(k);

                break;
            
            case 4: 
                l1.printRecord();
                break;
            case 5:system("cls");
            default:
                cout<<"Enter proper Option Number"<<endl;
        }//end of switch
    }while(option!=0);

    return 0;
}