/* Product demo project using file handling **/

/**** header file inclusion ***/
#include<iostream>/* cin>>,cout<<,.getline()*/
#include<fstream>/* ifstream,ofstream,fstream,open()/close()/read()/write()*/
#include<stdlib.h>/* system("cls"),system("pause")*/
#include<process.h>/* exit(0)===> exit --0(exit with success)*/
#include<stdio.h>
using namespace std;/* include namespace std */

/********Product class definition**/
class Product{
	/**member data of class **/
	int pno;
	char name[20];
	float price;
   public:
   	/* member function of class **/
   	void input(); //create write
   	void show(); //read all
   	void search();//search specific
   	void update(); //update
   	void Delete(); //delete
};


/*************input Data **********/
void Product::input()
   	{
   		
	   	ofstream fout("product.dat",ios::app);
		cout<<"Enter product no:";
		cin>>pno;
		cout<<"\nEnter product name:";                        
		cin.ignore(); 
		cin.getline(name,20);
		cout<<"Enter product price:";
		cin>>price;   
	    //*fileobject.write((char)&Object,sizeof(object)); 
		   //this=&p
		   fout.write((char*)this,sizeof(*this));
		  // fout.write((char*)&p,sizeof(p));
		   fout.close();
		   }

/*************show Data **********/	   
	void Product::show()
	{
		system("cls");
	ifstream fin("product.dat",ios::in);
	//this=&p
	while(fin.read((char*)this,sizeof(*this)))
	{
	
		cout<<"\nDetail of Product:\n";
		cout<<"\nProduct num=>"<<pno;
		cout<<"\nProduct Name=>"<<name;
		cout<<"\nProduct price=>"<<price;
		cout<<endl;
		system("pause");
		}
    fin.close();
	}

/*************search Data **********/
void Product:: search()
{
	int sno;
	bool rst=false;
	system("cls");
	ifstream fin("product.dat",ios::in);
	//this=&p
	cout<<"\nEnter Product number:";
	cin>>sno; //103
	
	//Arrays---search---->c file search----C++ search
	//C++ file
	while(fin.read((char*)this,sizeof(*this)))
	{
	    if(sno==pno)
	    {
		
			cout<<"\nDetail of Product:\n";
			cout<<"\nProduct num=>"<<pno;
			cout<<"\nProduct Name=>"<<name;
			cout<<"\nProduct price=>"<<price;
			cout<<endl;
			rst=true;
			break;
		}
		
		}
		
	if(rst==false)
		cout<<"No Record found";
    fin.close();
}
/*************update Data **********/
void Product::update()
{
	int sno;
	
	bool rst=false;
	system("cls");
	ifstream fin("product.dat",ios::in);
    ofstream fout("temp.dat",ios::out);
	
	//this=&p
	cout<<"\nEnter Product number:";
	cin>>sno; //103
	
	//Arrays---search---->c file search----C++ search
	//C++ file
	while(fin.read((char*)this,sizeof(*this)))
	{
	    if(sno==pno)
	    {
		
			cout<<"\nDetail of new Product:\n";
			cout<<"Enter pno:";
			cin>>pno;
			cout<<"Enter name:";
			cin.ignore();
			cin.getline(name,20);
			cout<<"Enter price:";
			cin>>price;
			fout.write((char*)this,sizeof(*this));
			rst=true;
			
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		}
		
		}
		
	if(rst==false)
		cout<<"No Record found";
		
	
    fin.close();
	fout.close();
	remove("product.dat");
	rename("temp.dat","product.dat");
}
/*************delete Data **********/
void Product::Delete(){
	
	int sno;
	
	bool rst=false;
	system("cls");
	ifstream fin("product.dat",ios::in);
    ofstream fout("temp.dat",ios::out);
	
	//this=&p
	cout<<"\nEnter Product number:";
	cin>>sno; //103
	
	//Arrays---search---->c file search----C++ search
	//C++ file
	while(fin.read((char*)this,sizeof(*this)))
	{
	    if(sno!=pno)
	    {
		    fout.write((char*)this,sizeof(*this));
			rst=true;
			
		}
		
		}
		
	if(rst==false)
		cout<<"No Record found";
		
	
    fin.close();
	fout.close();
	remove("product.dat");
	rename("temp.dat","product.dat");
}

int main()
{
	int ich;
	Product p;
	while(1)
	{
		system("cls");
		cout<<"\n1.input";
		cout<<"\n2.show";
		cout<<"\n3.search";
		cout<<"\n4.edit";
		cout<<"\n5.delete";
		cout<<"\n6.Exit";
		cout<<"\nEnter your choice:";
		cin>>ich;
		//selection
		switch(ich)
		{
			case 1:
			     p.input();
			break;
			case 2:
				 p.show();
			break;
			case 3:
				p.search();
			break;
			case 4:
				p.update();
			break;
			case 5:
				p.Delete();
			break;
			case 6:
				exit(0); //process.h	
			default:
				cout<<"\nwrong choice";
		}//swit over heere
		cout<<endl;
		system("pause");
		
	}//looping
	
	
	
	return 0;
}
