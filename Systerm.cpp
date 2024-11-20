#include<bits/stdc++.h>
using namespace std;
#include"Wolve.cpp"
class Systerm
{
public:
	int wcount;
	int scount;
    Systerm(){}
    bool isWloveExit(int num)
    {
	    if(num>wcount)
        {
            cout<<"�Ǻ������";
            return false;
        }
        else
        return true;
    }
    bool isSheepExit(int num)
    {
	    if(num>scount)
        {
            cout<<"��������";
            return false;
        }
        else
        return true;
    }

   	Wolve w[15];
	Sheep s[15];
    string area[8][8];
    int search(int m,int n) 
    {
	    int k=1;
	    for(int i=1;i<=scount;i++)
	    {
		    if(s[i].x==m&&s[i].y==n)
		    {
			    k=i;
		    }	
	    }
	    return k;
    }

    int startSysterm()
    {
        cout << "\n========��̬ģ��ϵͳ����========" << endl;
	    cout<<"���ȹ�����̬ϵͳ" << endl;
	
	
	    cout<<"�������ǵ������Լ��������"<<endl;
	
	
	    int w1,s1;
	    cin>>w1>>s1;
	    wcount=w1;
	    scount=s1;
	
	    for(int i=1;i<=w1;i++){
		    cout<<"�������ǵ����ƺ����䣬���ظ�"<<endl;
		    cout<<"��������"<<endl;
		    string name;cin>>name;
		
		    cout<<"��������"<<endl;
		    int age;cin>>age;
		
		    cout<<"��������"<<endl;
		    int energy;cin>>energy;

		    w[i].setName(name);
		    w[i].setAge(age);
		    w[i].setEnergy(energy);

		    cout<<"����X����"<<endl;
		    int x;cin>>x;
		    w[i].x=x;
		
		    cout<<"����Y����"<<endl;
		    int y;cin>>y;
		    w[i].y=y;
		
		    area[x][y]="��";
	    }
	
	    for(int i=1;i<=s1;i++){
		    cout<<"������������ƺ���ɫ�����ظ�"<<endl;
		    cout<<"��������"<<endl;
		
		    string name;cin>>name;
		    cout<<"������ɫ"<<endl;
		    string color;cin>>color;
		
		    s[i].setName(name);
		    s[i].setColor(color);
		
		    cout<<"����X����"<<endl;
		    int x;cin>>x;
		    s[i].x=x;
		
		    cout<<"����Y����"<<endl;
		    int y;cin>>y;
		    s[i].y=y;
		
		    area[x][y]="��";
	    }
	
	
	
	    while (true) {
		    int choice;
		
		    cout << "\n========��̬ģ��ϵͳ�˵�========" << endl;
		    cout << "1. ������̬ϵͳ��������" << endl;
	        cout << "2. �ǽ�ʳ" << endl;		
	        cout << "3. ���ʳ" << endl;		
	        cout << "4. �˹�Ͷι��" << endl;
	        cout << "5. �˳�" << endl;
	        cout << "��ѡ�����: "<<endl;
		
		
	        cin >> choice;
	        cout<<"��ѡ����"<<choice<<endl;
	        
	        switch (choice)
	        {
	        	
	        case 1:
	        {
	        	cout<<"������Ϊ"<<wcount<<endl;
	        	cout<<"������Ϊ"<<scount<<endl;
	        	break;
	        }

	        case 2:
	        {
	        	cout<<"ѡ���Ǻ���"<<endl;
	        	int num1;cin>>num1;
	        	
	        	w[num1].energeWithDied(wcount,area);
	        	if(w[num1].isDied())
	        	{
	        		cout<<"���Ѷ������޷�����";
	        		break;
	        	}

	        	int min=10000;
	        	int maxweight=0;
	        	int k=0;

	        	for(int i=0;i<=7;i++)
	        	{
	        		for(int j=0;j<=7;j++)
	        		{
	        			if(area[i][j]=="��")
	        			{
	        				int xx=abs(i-w[num1].x);
	        				int yy=abs(j-w[num1].y);
	        			    int len=pow(xx,2)+pow(yy,2);
	        				
	        				if(len<min)
	        				{
	        					
	        					k=search(i,j);
	        					
	        					maxweight=s[k].getWeight();
	        					min=len;
	        				}
	        				else if(len==min)
	        				{
	        					int q=search(i,j);
	        					if(s[q].getWeight()>maxweight)
	        					{
	        						k=q;
	        						maxweight=s[q].getWeight();
	        					}
	        				} 
	        			}	
	        		}	
	        	}
	        		
	        	min=(int)sqrt(min);
	        	w[num1].eat(s[k],min);
	        	
	        	scount-=1;
	        	area[s[k].x][s[k].y]={0};

	        	break;
	        }

	        case 3:
	        {	
	        	cout<<"ѡ�������"<<endl;
	        	int num3;cin>>num3;
	        	if(!s[num3].isDied())
	        	{
	        		s[num3].eat();
	        	}
	        	else 
	        	{
	        		cout<<"�����ѱ��Ե�";
	        	}
	        	break;
	        }

	        case 4:
	        {
	        	cout<<"ѡ���Ǻ���"<<endl;
	        	int num1;cin>>num1;
	        
	        	w[num1].energeWithDied(wcount,area);
	        	if(w[num1].isDied())
	        	{
	        		cout<<"���Ѷ������޷�����";
	        		break;
	        	}

	        	while(true)
	        	{	
	        		cout<<"������Ͷι��,������5kg"<<endl;
	        		int add;cin>>add;

	        		if(add<=5)
	        		{
	        			w[num1].addEnergy(add);
	        			break;
	        		}
	        		else
	        		{
	        			cout<<"������ѡ��Ͷι��"<<endl;
	        			continue;
	        		}
	        	}
	        	break;
	        }
	        case 5:
	        {
	        	cout << "ллʹ����̬ģ��ϵͳ��" << endl;
	        	return 0;
	        }	
	        default:
	        {
	        	cout << "��Ч��ѡ�������ѡ��" << endl;
	        }
	        	
	        }
	        
	    }
	        
	    return 0;
    }
};