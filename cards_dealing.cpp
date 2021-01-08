#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void show_one(char color,int num)
{
	cout<<color;
	if(num>1&&num<10)
		cout<<num;
	else
	{
		if(num==1)
			cout<<"A";
		else if(num==10)
			cout<<"T";
		else if(num==11)
			cout<<"J";
		else if(num==12)
			cout<<"Q";
		else if(num==13)
			cout<<"K";
	}
	return;
}
void judge_one(int one,char&color,int&num)
{
	if(!(one%4))
	{
		color=4;
		num=one/4;
		return;
	}
	else if(!((one+1)%4))
		color=5;
	else if(!((one+2)%4))
		color=3;
	else
		color=6;
	num=one/4+1;
	return;
}
class player{
	int hand[11],s[11],h[11],c[11],d[11];
	int melds[11],deadwoods[11];
	int score,dw_score;
	int dw;
	int last;
	string id;
	public:
		player & operator=(const player & f);
		void each_color(int a[], int&n, int color);
		void init();
		void sort_cards();
		void show_cards();
		void discards();
		void calculate_deadwoods();
		void start();
		void set_id(string s);
		void receive();
		string getid();
		void insert(int n);
		void eat();
		void take();
		void knock(player&pre);
		int getds();
		void gin(player&pre);
		void lay_off(string r);
		void ai_sort_cards();
		void ai_lay_off();
		void ai_discards();
		void ai_game_start(int t);
		int get_dw_sum();
		int get_deadwoods(int n);
		void result();
		void set_last(int n);
		void idclear();
		void each_round(player&pre);
		int* get_hand();
		void copy_hand(const int* pre);
		void ai_take_or_eat(int t,int e);
		void ai_gin();
		void set_score(int n);
};
int flag=1;
int remain=52;
int position[12];
int dis;
int in,out;
string winner;
int num,continueflag=0;
char color;
string zuhe="1";
int rnd=1;
int gm=0;
int q=2;
int moshi;
stack<int> stock_pile,discard_pile;
int poker[52];
player pla1,pla2;
player com,pla;
void player::set_score(int n)
{
	score=n;
}
int* player::get_hand()
{
	int *p=hand;
	return p;
}
void player::copy_hand(const int* pre)
{
	for(int i=0;i<11;i++)
		hand[i]=pre[i];
}
void player::idclear()
{
    id.clear();
}
void player::set_last(int n)
{
    last=n;
}
int player::get_deadwoods(int n)
{
    return deadwoods[n];
}
int player::get_dw_sum()
{
    return dw;
}
int player::getds()
{
    return dw_score;
}
void player::insert(int n)
{
    sort(hand,hand+11);
    hand[0]=n;
}
string player::getid()
{
    return id;
}
void player::set_id(string s)
{
    id=s;
}
void player::start()
{
    memset(hand,0,sizeof(hand));
    score=0;
	dw_score=0;
}
void player::each_color(int a[], int&n, int color)
{
	sort(a,a+n);
	int cnt=0,k=n;
	if(n<3)
	{
		for(int i=0;i<n;i++)
		{
			int x=a[i]*4-(4-color);
			a[i]=0;
			k--;
			deadwoods[dw++]=x;
	    }
	    return;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if(i==0&&(a[i]+1)!=a[i+1])
			{
				int x=a[i]*4-(4-color);
				deadwoods[dw++]=x;
				a[i]=0;
				k--;
				continue;
			}
			else if((a[i]+1)==a[i+1])
			{
			    cnt++;
			    continue;
			}
			else if((a[i]+1)!=a[i+1]&&cnt>=2)
			{
				cnt=0;
				continue;
			}
			else if((a[i]+1)!=a[i+1]&&cnt<2)
			{
				for(int j=i-cnt;j<=i;j++)
				{
					int x=a[j]*4-(4-color);
					deadwoods[dw++]=x;
					k--;
					a[j]=0;
				}
				cnt=0;
				continue;
			}
		}
		if(cnt==1)
		for(int i=n-2;i<n;i++)
		{
			int x=a[i]*4-(4-color);
			deadwoods[dw++]=x;
			k--;
			a[i]=0;
		}
		if(cnt==0)
		{
			int x=a[n-1]*4-(4-color);
			deadwoods[dw++]=x;
			k--;
			a[n-1]=0;
		}
	}
	sort(a,a+n);
	n=k;
	return ;
}
void player::init()
{
	memset(s,0,sizeof(s));
	memset(h,0,sizeof(h));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(melds,0,sizeof(melds));
	for(int i=0;i<11;i++)
		deadwoods[i]=100;
	dw=0;
	dw_score=0;
	score=0;
}
void player::sort_cards()
{
	if(zuhe=="1")
	{
		sort(hand,hand+11);
		init();
		int x=0,y=0,z=0,w=0,cnt=0;
		for(int i=0;i<11;i++)
		{
			int num;
			char color;
			if(hand[i]==0)
				continue;
			judge_one(hand[i],color,num);
			if(color==6)
				s[x++]=num;
			if(color==3)
				h[y++]=num;
			if(color==5)
				c[z++]=num;
			if(color==4)
				d[w++]=num;
		}
		each_color(s,x,1);
		each_color(h,y,2);
		each_color(c,z,3);
		each_color(d,w,4);
		int m=0;
		sort(deadwoods,deadwoods+dw);
		int num[11],i,j;
		char color[11];
		if(dw>0)
			judge_one(deadwoods[0],color[0],num[0]);
		for(i=1;i<dw;i++)
		{
			judge_one(deadwoods[i],color[i],num[i]);
			if(num[i]==num[i-1])
				cnt++;
			else
			{
				if(cnt>=2)
					for(j=i-cnt-1;j<i;j++)
					{
						melds[m++]=deadwoods[j];
						deadwoods[j]=100;
					}
				cnt=0;
			}
		}
		if(cnt>=2)
		for(j=i-cnt-1;j<i;j++)
		{
			melds[m++]=deadwoods[j];
			deadwoods[j]=100;
		}
		sort(deadwoods,deadwoods+11);
		dw-=m;
	}
	else if(zuhe=="0")
	{
		sort(hand,hand+11);
		int x=0,y=0,z=0,w=0,cnt=0,m=0;
		init();
		int pp[11],i,j;
		for(int i=0;i<11;i++)
 			pp[i]=hand[i];
		char color[11];
		int num[11];
		if(pp[0])
			judge_one(pp[0],color[0],num[0]);
		else
			num[0]=0;
		for(i=1;i<11;i++)
		{
			judge_one(pp[i],color[i],num[i]);
			if(num[i]==num[i-1])
				cnt++;
			else
			{
				if(cnt>=2)
					for(j=i-cnt-1;j<i;j++)
					{
						melds[m++]=pp[j];
						pp[j]=0;
					}
				cnt=0;
			}
		}
		if(cnt>=2)
		for(j=i-cnt-1;j<i;j++)
		{
			melds[m++]=pp[j];
			pp[j]=0;
		}
		for(int i=0;i<11;i++)
		{
			int num;
			char color;
			if(pp[i]==0)
				continue;
			judge_one(pp[i],color,num);
			if(color==6)
				s[x++]=num;
			if(color==3)
				h[y++]=num;
			if(color==5)
				c[z++]=num;
			if(color==4)
				d[w++]=num;
		}
		each_color(s,x,1);
		each_color(h,y,2);
		each_color(c,z,3);
		each_color(d,w,4);
		sort(deadwoods,deadwoods+11);
	}
	return;
}
void player::show_cards()
{
	char color=6;
	int i,num,cnt=0,tmp=0;
	for(i=0;i<11;i++)
		if(s[i])
		{
			tmp++;
			position[cnt++]=s[i]*4-3;
			Sleep(100);
			if(i>2&&s[i]>(s[i-1]+1))
				cout<<" ";
			show_one(color,s[i]);
		}
	if(tmp)
	{
		cout<<"  ";
		tmp=0;
	}
	color=3;
	for(i=0;i<11;i++)
		if(h[i])
		{
			tmp++;
			position[cnt++]=h[i]*4-2;
			Sleep(100);
			if(i>2&&h[i]>(h[i-1]+1))
				cout<<" ";
			show_one(color,h[i]);
		}
	if(tmp)
	{
		cout<<"  ";
		tmp=0;
	}
	color=5;
	for(i=0;i<11;i++)
		if(c[i])
		{
			tmp++;
			position[cnt++]=c[i]*4-1;
			Sleep(100);
			if(i>2&&c[i]>(c[i-1]+1))
				cout<<" ";
			show_one(color,c[i]);
		}
	if(tmp)
	{
		cout<<"  ";
		tmp=0;
	}
	color=4;
	for(i=0;i<11;i++)
		if(d[i])
		{
			tmp++;
			position[cnt++]=d[i]*4;
			Sleep(100);
			if(i>2&&d[i]>(d[i-1]+1))
				cout<<" ";
			show_one(color,d[i]);
		}
	if(tmp)
	{
		cout<<"  ";
		tmp=0;
	}
	int temp=0;
	for(i=0;i<11;i++)
	if(melds[i])
	{
		tmp++;
		judge_one(melds[i],color,num);
		if(num!=temp&&temp)
			cout<<"  ";
		position[cnt++]=melds[i];
		Sleep(100);
		show_one(color,num);
		temp=num;
	}
	if(tmp)
	{
		cout<<"  ";
		tmp=0;
	}
	for(i=0;i<dw;i++)
	{
		tmp++;
		judge_one(deadwoods[i],color,num);
		position[cnt++]=deadwoods[i];
		Sleep(100);
		show_one(color,num);
	}
	cout<<endl;
	cout<<endl;
}
void player::discards()
{
	SetPosition(18,q+=2);
	cout<<id<<" 请选择一张弃牌编号 (0 - 10) :";
	int one;
	char buff[80];
	cin>>out;
	while(!cin.good())
	{
		cin.clear();
		cin.getline(buff,80);
		SetPosition(18,q+=2);
		cout<<"请输入数字哦 (0 - 10) : ";
		cin>>out;
	}
	while(out<0||out>10)
	{
		SetPosition(18,q+=2);
		cout<<"请输入范围 0-10 : ";
		cin>>out;
		one=position[out];
	}
	one=position[out];
	while(one==in)
	{
		SetPosition(18,q+=2);
		cout<<"不能丢弃本回合 eat 的牌 , 请再次输入 ：";
		cin>>out;
		while(out<0||out>10)
		{
			SetPosition(18,q+=2);
			cout<<"请输入数字范围 0-10 : ";
			cin>>out;
			one=position[out];
		}
		one=position[out];
	}
	for(int i=0;i<11;i++)
		if(hand[i]==one)
			hand[i]=0;
	discard_pile.push(one);
	sort_cards();
	SetPosition(18,q+=2);
	cout<<id<<" 的当前手牌 ：";
	show_cards();
}
void player::calculate_deadwoods()
{
	int num;
	char color;
	dw_score=0;
	for(int i=0;i<11;i++)
	{
		if(deadwoods[i]>52)
			continue;
		judge_one(deadwoods[i],color,num);
		if(num<10)
			dw_score+=num;
		else
			dw_score+=10;
	}
	dw_score+=last;
	return;
}
