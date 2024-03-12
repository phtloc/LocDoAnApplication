#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
class Character{
	protected:
		string name;
		float strength;
		float health;
		vector<Equipment*> inventory;
	public:
		virtual void Input(){
			fflush(stdin);
			cout<<"Nhap ten nhan vat:";
			getline(cin,name);
			cout<<"Nhap vao chi so suc manh:";
			cin>>strength;
			cout<<"Nhap vao luong mau:";
			cin>>health;
		}
		virtual void Output(){
			cout<<"Ten nhan vat:"<<name<<endl;
			cout<<"Suc manh:"<<strength<<endl;
			cout<<"Mau:"<<health<<endl;
			cout<<"Trang bi ban dang co"<<endl;
			if(inventory.size()==0){
				cout<<"Chua co trang bi"<<endl;
			}
			else{
			cout<<"DANH SACH TRANG BI MA NHAN VAT DANG SO HUU"<<endl;	
			for(int i=0;i<inventory.size();i++){
				inventory[i]->Output();
			}
			}
		}
		void addEquipment(Equipment* equipment) {
        	inventory.push_back(equipment);
    	}
    	void get_equipment(string new_name,int &count){
    		for(int i=0;i<inventory.size();i++){
        		if(0==stricmp( inventory[i]->get_name().c_str(), new_name.c_str()))
        		{
            		Output();
            		count++;
        		}
			}
		}
    	string get_name(){
		return name;
		}
		float get_strength(){
			return strength;
		}
		float get_health(){
			return health;
		}
		Character(){
		}
		~Character(){
		}
};
class Warrior :public Character{
	private:
		float shield;
	public:
		void Input(){
			Character::Input();
			cout<<"Nhap vao luong giap:";
			cin>>shield;
		}
		void Output(){
			Character::Output();
			cout<<"Giap cua nhan vat:"<<shield<<endl;
		}
		Warrior(){
		}
		~Warrior(){
		}
};
class Mage :public Character{
	private:
		float special_damage;
	public:
		void Input(){
			Character::Input();
			cout<<"Nhap vao sat thuong phep:";
			cin>>special_damage;
		}
		void Output(){
			Character::Output();
			cout<<"Sat thuong phep cua nhan vat:"<<special_damage<<endl;
		}
	Mage(){
	}
	~Mage(){
	}
};
class Archers :public Character{
	private:
		float physical_damage;
	public:
		void Input(){
			Character::Input();
			cout<<"Nhap vao sat thuong vat ly:";
			cin>>physical_damage;
		}
		void Output(){
			Character::Output();
			cout<<"Sat thuong vat ly cua nhan vat:"<<physical_damage<<endl;
		}
		Archers(){
		}
		~Archers(){
		}
};
