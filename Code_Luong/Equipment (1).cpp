#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
class Equipment{
protected:
    string name;
    int value;
    string element;
public:
    virtual void Input(){
        fflush(stdin);
        cout<<"nhap vao ten trang bi: ";
        getline(cin,name);
        cout<<"nhap vao gia: ";
        cin>>value;
        fflush(stdin);
        cout<<"nhap vao nguyen to: ";
        getline(cin,element);
    }
    virtual void Output(){
        cout<<"Ten Trang Bi: "<<name<<endl;
        cout<<"Gia Cua Trang Bi: "<<value<<"$"<<endl;
        cout<<"Nguyen To Cua Trang bi: "<<element<<endl;
    }
    int get_value(){
    	return value;
	}
	string get_element(){
		return element;
	}
	string get_name(){
		return name;
	}
    Equipment(){
    }
    ~Equipment(){
    }
};
class Weapon : public Equipment {
    private:
        float power;
        string rarity;
    public:
        void Input(){
            Equipment::Input();
            cout<<"nhap vao chi so suc manh: ";
            cin>>power;
            fflush(stdin);
            cout<<"nhap vao do hiem cua vu khi: ";
            getline(cin,rarity);
        }
        void Output(){
            Equipment::Output();
            cout<<"Chi So Suc Manh Cua Vu Khi: "<<power<<endl;
            cout<<"Do Hiem: "<<rarity<<endl;
        }
        Weapon(){
        }
        ~Weapon(){
        }
};

class Armor : public Equipment {
    private:
        float special_defend;
        float physical_defend;
    public:
        void Input(){
            Equipment::Input();
            cout<<"nhap vao chi so khang phep: ";
            cin>>special_defend;
            cout<<"nhap vao chi so khang vat ly: ";
            cin>>physical_defend;
        }
        void Output(){
            Equipment::Output();
            cout<<"Chi So Khang Phep: "<<special_defend<<endl;
            cout<<"Chi so Khang Vat Ly : "<<physical_defend<<endl;
        }
        Armor(){
        }
        ~Armor(){
        }
};
