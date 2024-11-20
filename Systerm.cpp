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
            cout<<"狼号码错误";
            return false;
        }
        else
        return true;
    }
    bool isSheepExit(int num)
    {
	    if(num>scount)
        {
            cout<<"羊号码错误";
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
        cout << "\n========生态模拟系统启动========" << endl;
	    cout<<"请先构建生态系统" << endl;
	
	
	    cout<<"请设置狼的数量以及羊的数量"<<endl;
	
	
	    int w1,s1;
	    cin>>w1>>s1;
	    wcount=w1;
	    scount=s1;
	
	    for(int i=1;i<=w1;i++){
		    cout<<"请设置狼的名称和年龄，勿重复"<<endl;
		    cout<<"输入名称"<<endl;
		    string name;cin>>name;
		
		    cout<<"输入年龄"<<endl;
		    int age;cin>>age;
		
		    cout<<"输入能量"<<endl;
		    int energy;cin>>energy;

		    w[i].setName(name);
		    w[i].setAge(age);
		    w[i].setEnergy(energy);

		    cout<<"输入X坐标"<<endl;
		    int x;cin>>x;
		    w[i].x=x;
		
		    cout<<"输入Y坐标"<<endl;
		    int y;cin>>y;
		    w[i].y=y;
		
		    area[x][y]="狼";
	    }
	
	    for(int i=1;i<=s1;i++){
		    cout<<"请设置羊的名称和颜色，勿重复"<<endl;
		    cout<<"输入名称"<<endl;
		
		    string name;cin>>name;
		    cout<<"输入颜色"<<endl;
		    string color;cin>>color;
		
		    s[i].setName(name);
		    s[i].setColor(color);
		
		    cout<<"输入X坐标"<<endl;
		    int x;cin>>x;
		    s[i].x=x;
		
		    cout<<"输入Y坐标"<<endl;
		    int y;cin>>y;
		    s[i].y=y;
		
		    area[x][y]="羊";
	    }
	
	
	
	    while (true) {
		    int choice;
		
		    cout << "\n========生态模拟系统菜单========" << endl;
		    cout << "1. 查阅生态系统生物数量" << endl;
	        cout << "2. 狼进食" << endl;		
	        cout << "3. 羊进食" << endl;		
	        cout << "4. 人工投喂狼" << endl;
	        cout << "5. 退出" << endl;
	        cout << "请选择操作: "<<endl;
		
		
	        cin >> choice;
	        cout<<"已选择功能"<<choice<<endl;
	        
	        switch (choice)
	        {
	        	
	        case 1:
	        {
	        	cout<<"狼数量为"<<wcount<<endl;
	        	cout<<"羊数量为"<<scount<<endl;
	        	break;
	        }

	        case 2:
	        {
	        	cout<<"选择狼号码"<<endl;
	        	int num1;cin>>num1;
	        	
	        	w[num1].energeWithDied(wcount,area);
	        	if(w[num1].isDied())
	        	{
	        		cout<<"狼已饿死，无法操作";
	        		break;
	        	}

	        	int min=10000;
	        	int maxweight=0;
	        	int k=0;

	        	for(int i=0;i<=7;i++)
	        	{
	        		for(int j=0;j<=7;j++)
	        		{
	        			if(area[i][j]=="羊")
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
	        	cout<<"选择羊号码"<<endl;
	        	int num3;cin>>num3;
	        	if(!s[num3].isDied())
	        	{
	        		s[num3].eat();
	        	}
	        	else 
	        	{
	        		cout<<"该羊已被吃掉";
	        	}
	        	break;
	        }

	        case 4:
	        {
	        	cout<<"选择狼号码"<<endl;
	        	int num1;cin>>num1;
	        
	        	w[num1].energeWithDied(wcount,area);
	        	if(w[num1].isDied())
	        	{
	        		cout<<"狼已饿死，无法操作";
	        		break;
	        	}

	        	while(true)
	        	{	
	        		cout<<"请输入投喂量,不超过5kg"<<endl;
	        		int add;cin>>add;

	        		if(add<=5)
	        		{
	        			w[num1].addEnergy(add);
	        			break;
	        		}
	        		else
	        		{
	        			cout<<"请重新选择投喂量"<<endl;
	        			continue;
	        		}
	        	}
	        	break;
	        }
	        case 5:
	        {
	        	cout << "谢谢使用生态模拟系统！" << endl;
	        	return 0;
	        }	
	        default:
	        {
	        	cout << "无效的选项，请重新选择！" << endl;
	        }
	        	
	        }
	        
	    }
	        
	    return 0;
    }
};