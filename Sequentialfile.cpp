#include<iostream>
#include<fstream>
using namespace std;

class Student{
    int roll_no;
    char name[30];
    char division[5];
    char address[30];
    public:
      void accept();
      void display();
      int rollno(){
          return roll_no;
      }
};

void Student::accept(){
    cout<<"\n Enter roll no:";
    cin>>roll_no;
    cout<<"\n enter name:";
    cin>>name;
    cout<<"\n Enter division:";
    cin>>division;
    cout<<"\n Enter address:";
    cin>>address;
    cout<<"\n";
}

void Student::display(){
    cout<<"\n"<<roll_no<<"\t"<<name<<"\t"<<division<<"\t"<<address;
}

void create(){
    Student s;
    int i,n;
    
    ofstream out("Student.txt");
    cout<<"\n How many records do you want to enter:";
    cin>>n;
    
    for(i=0;i<n;i++){
        s.accept();
        out.write((char *) & s,sizeof(s));
    }
    out.close();
}

void search(){
    Student s;
    int n,flag=0;
    ifstream in ("Student.txt");
    cout<<"\n Enter roll no to search:";
    cin>>n;
    while(in.read((char *) & s,sizeof(s))){
        if(s.rollno()==n){
            flag=1;
            cout<<"\n Record found......";
            cout<<"\n Rollno    Name   Division   Address";
            s.display();
            break;
        }
    }
    if(flag==0){
        cout<<"\n Record no found....";
    }
    in.close();
    
    
}

void display(){
    Student s;
    ifstream in("Student.txt");
    while(in.read((char *) & s,sizeof(s))){
        s.display();
    }
    in.close();
}

void add_record(){
    Student s;
    ofstream out("Student.txt",ios::app);
    s.accept();
    out.write((char *) & s,sizeof(s));
    out.close();
    cout<<"\n Record successfully addedd.......";
}

void delete_record(){
    int n,flag=0;
    Student s;
    cout<<"\n Enter roll no to be deleted:";
    cin>>n;
    ifstream in("Student.txt");
    ofstream out("temp.txt");
    while(in.read((char *) & s,sizeof(s))){
        if(s.rollno()!=n){
            out.write((char *)& s,sizeof(s));
        }
        
        else{
            flag=1;
            cout<<"\n Record successfully deleted....";
        }
    }
    if(flag==0){
        cout<<"\n Record not found......";
    }
    in.close();
    out.close();
    remove("Student.txt");
    rename("temp.txt","Student.txt");
}

int main(){
    int ch;
    do{
        cout<<"\n Menu:";
        cout<<"\n 1.Create database";
        cout<<"\n 2.Search database";
        cout<<"\n 3.Display database";
        cout<<"\n 4.Add Record";
        cout<<"\n 5.Delete Record";
        cout<<"\n 6.Exit";
         
        cout<<"\n Enter your choice:";
        cin>>ch;
        
        switch(ch){
            case 1:
            cout<<"\n";
              create();
              break;
            
            case 2:
              cout<<"\n";
              search();
              break;
              
            case 3:
              cout<<"\n";
              cout<<"\n Rollno   Name   Division    Address";
              display();
              break;
              
            case 4:
              cout<<"\n ";
              add_record();
              break;
              
            case 5:
              cout<<"\n";
              delete_record();
              break;
              
            case 6:
              cout<<"\n successfully Exited.....";
              break;
        }
        
    }while(ch!=6);
    return 0;
}