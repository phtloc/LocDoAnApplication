#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
void Menu(vector<Character *> dsnv,vector<Equipment *> dstb){
	int luachon;
	while(true){
		system ("cls");
		cout<<"=======SU LUA CHON========"<<endl;
		cout<<"1.Nhap vao nhan vat:"<<endl;
		cout<<"2.Nhap vao trang bi:"<<endl;
		cout<<"3.Danh sach nhan vat:"<<endl;
		cout<<"4.Danh sach trang bi:"<<endl;
		cout<<"5.Them trang bi cho nhan vat"<<endl;
		cout<<"6.Xoa nhan vat"<<endl;
		cout<<"7.Xoa trang bi"<<endl;
		cout<<"8.Sap xep nhan vat theo luong mau"<<endl;
		cout<<"9.Tim kiem trang bi"<<endl;
		cout<<"10.Tim kiem nhan vat so huu trang bi do"<<endl;
		cout<<"0.Thoat"<<endl;
		cout<<"======NHAP LUA CHON======  ";
		cin>>luachon;
		if(luachon==1){
			int luachon_nv;
			cout<<"=====LOP NHAN VAT====="<<endl;
			do{
				cout<<"1. Warrior"<<endl;
				cout<<"2. Mage"<<endl;
				cout<<"3. Archers"<<endl;
				cout<<"Nhap lua chon:";
				cin>>luachon_nv;
			}while(luachon_nv!=1&luachon_nv!=2&&luachon_nv!=3);
			if(luachon_nv==1){
				Character *nv= new Warrior();
				nv ->Input();
				dsnv.push_back(nv);
			}else if(luachon_nv==2){
				Character *nv= new Mage();
				nv ->Input();
				dsnv.push_back(nv);
			}else if(luachon_nv==3){
				Character *nv= new Archers();
				nv ->Input();
				dsnv.push_back(nv);
			}
			system("pause");
		}else if(luachon==2){
			int luachon_tb;
			cout<<"=====TRANG BI====="<<endl;
			do{
				cout<<"1. Weapon"<<endl;
				cout<<"2. Armor"<<endl;
				cout<<"Nhap lua chon:";
				cin>>luachon_tb;
			}while(luachon_tb!=1&&luachon_tb!=2);
			if(luachon_tb==1){
				Equipment *tb= new Weapon();
				tb ->Input();
				dstb.push_back(tb);
			}else if(luachon_tb==2){
				Equipment *tb= new Armor();
				tb ->Input();
				dstb.push_back(tb);
			}
			system("pause");
		}else if(luachon==3){
			cout<<"==========DANH SACH NHAN VAT=========="<<endl;
			for(int i=0;i<dsnv.size();i++){
				dsnv[i]->Output();
				cout<<"\n";
			}
			system("pause");
		}else if(luachon==4){
			cout<<"==========DANH SACH TRANG BI=========="<<endl;
			for(int i=0;i<dstb.size();i++){
				dstb[i]->Output();
				cout<<"\n";
			}
			system("pause");
		}else if(luachon==5){
		cout<<"Nhan vat dang co"<<endl;
			for(int i=0;i<dsnv.size();i++){
				cout<<dsnv[i]->get_name()<<endl;
			}
			string new_name;
			fflush(stdin);
			cout<<"Nhap ten nhan vat muon them trang bi:";
			getline(cin,new_name);
			int count=0;
			int dem=0;
			for(int i=0;i<dsnv.size();i++)
    		{
        		if(0==stricmp( dsnv[i]->get_name().c_str(), new_name.c_str()))
        		{
        			cout<<"Trang bi dang co"<<endl;
        			for(int k=0;k<dstb.size();k++){
						cout<<dstb[k]->get_name()<<endl;
					}
            		string new_weapon;
					fflush(stdin);
					cout<<"Nhap ten trang bi ban muon them:";
					getline(cin,new_weapon);
					for(int j=0;j<dstb.size();j++)
    				{
        				if(0==stricmp( dstb[j]->get_name().c_str(), new_weapon.c_str()))
        				{
            				dsnv[i]->addEquipment(dstb[j]);
            				cout<<"Nhan vat da duoc them trang bi"<<endl;
            				count=-dsnv.size()-10;
            				dem=-dstb.size()-10;
        				}
        				dem++;
    				}
        			if(dem==0||dem==dstb.size()){
						cout<<"Trang bi khong ton tai"<<endl;
						count=-dsnv.size()-10;
					}  				
        		}
				count++;
    		}
    		if(count==0||count==dsnv.size()){
    			cout<<"Nhan vat khong ton tai"<<endl;
			}
    		system("pause");
		}else if(luachon==6){
			int vt;
			cout<<"Nhap vao vi tri nhan vat muon xoa:";
			cin>>vt;
			dsnv.erase(dsnv.begin()+vt-1);
			cout<<"nhan vat ay da duoc xoa"<<endl;
			cout<<"==========DANH SACH NHAN VAT=========="<<endl;
			for(int i=0;i<dsnv.size();i++){
				dsnv[i]->Output();
				cout<<"\n";
			}
			system("pause");
		}else if(luachon==7){
			int vt;
			cout<<"Nhap vao vi tri trang bi muon xoa:";
			cin>>vt;
			dstb.erase(dstb.begin()+vt-1);
			cout<<"trang bi da duoc xoa"<<endl;
			cout<<"==========DANH SACH TRANG BI=========="<<endl;
			for(int i=0;i<dstb.size();i++){
				dstb[i]->Output();
				cout<<"\n";
			}
			system("pause");
		}else if(luachon==8){
			Character *temp;
			cout<<"Danh sach nhan vat da duoc sap xep"<<endl;
			for(int i=0;i<dsnv.size();i++){
				for(int j=i+1;j<dsnv.size();j++){
					if(dsnv[i]->get_health()>dsnv[j]->get_health()){
						temp=dsnv[i];
						dsnv[i]=dsnv[j];
						dsnv[j]=temp;
					}
				}
			}
			cout<<"==========DANH SACH NHAN VAT THEO MAU=========="<<endl;
			for(int i=0;i<dsnv.size();i++){
				dsnv[i]->Output();
				cout<<"\n";
			}
			system("pause");
		}else if(luachon==9){
			string new_name;
			fflush(stdin);
			cout<<"Nhap ten trang bi ban muon tim:";
			getline(cin,new_name);
			for(int i=0;i<dstb.size();i++)
    		{
        		if(0==stricmp( dstb[i]->get_name().c_str(), new_name.c_str()))
        		{
            		dstb[i]->Output();
        		}
    		}
    		system("pause");
		}else if(luachon==10){
			string new_weapon;
			fflush(stdin);
			cout<<"Nhap ten trang bi ban muon tim:";
			getline(cin,new_weapon);
			int dem=0;
			int count=0;
			for(int j=0;j<dstb.size();j++){
				if(0==stricmp( dstb[j]->get_name().c_str(), new_weapon.c_str()))
        		{
        			dem++;
        		}
        	}
        	if(dem==0){
        		cout<<"Trang bi khong ton tai"<<endl;
        		count=10;
			}
        	if(dem!=0){
        		cout<<"=======DANH SACH NHAN VAT SO HUU TRANG BI DO======="<<endl;
			}
			for(int i=0;i<dsnv.size();i++){
				dsnv[i]->get_equipment(new_weapon,count);
			}
			if(count==0){
				cout<<"Khong co nhan vat nao so huu trang bi ban dang tim kiem"<<endl;
			}
			system("pause");
		}else{
				break;
			}
		}
}
int main(){
	vector <Character *> dsnv;
	vector <Equipment *> dstb;
	Menu(dsnv,dstb);
	dsnv.clear();
	dstb.clear();
}
