#include<bits/stdc++.h>
#include<windows.h>
#include"cards_dealing.cpp"
using namespace std;
void player::receive()
{
    int card;
	for(int i=0;i<10;i++)
	{
		card=stock_pile.top();
		stock_pile.pop();
		hand[i]=card;
	}
}
void shuffle()
{
	int index, i, tmp;
	for(i=0;i<52;i++)
		poker[i]=i+1;	
	srand(time(NULL));
	for(i=0; i<52; i++)
	{
    	index=rand()%52;
	 	tmp=poker[i];
		poker[i]=poker[index];
		poker[index]=tmp;
	}
	while(!stock_pile.empty())
		stock_pile.pop();
	for(int i=0;i<52;i++)
		stock_pile.push(poker[i]);
	while(!discard_pile.empty())
		discard_pile.pop();
    pla1.start();
    pla2.start();
} 
void game_start()
{
	system("color 0e");
	system("cls");
	system("mode con cols=90 lines=30");
	for(int i=0;i<90;i+=3)
	{
		SetPosition(i,0);
		cout<<"*";
	}
	for(int i=0;i<30;i++)
	{
		SetPosition(0,i);
		cout<<"*";
	}
	for(int i=0;i<90;i+=3)
	{
		SetPosition(i,29);
		cout<<"*";
	}
	for(int i=0;i<30;i++)
	{
		SetPosition(89,i);
		cout<<"*";
	}
	SetPosition(0,29);
	string r;
	SetPosition(45,18);
	cout<<"请输入玩家1的名字 ：";
	cin>>r;
	pla1.set_id(r);
	SetPosition(45,20);
	cout<<"请输入玩家2的名字 ：";
	cin>>r;
	pla2.set_id(r);
	shuffle();
	pla1.receive();
	pla2.receive();
	remain=52;
	remain-=20;
	system("mode con cols=90 lines=30");
	for(int i=0;i<90;i+=3)
	{
		SetPosition(i,0);
		cout<<"*";
	}
	for(int i=0;i<30;i++)
	{
		SetPosition(0,i);
		cout<<"*";
	}
	for(int i=0;i<90;i+=3)
	{
		SetPosition(i,29);
		cout<<"*";
	}
	for(int i=0;i<30;i++)
	{
		SetPosition(89,i);
		cout<<"*";
	}
	q=0; 
	SetPosition(35,q+=2);
	cout<<"随机发牌"<<endl;
	SetPosition(0,29);
	Sleep(1000);
	pla1.sort_cards();
	pla2.sort_cards();
	SetPosition(18,q+=3);
	cout<<pla1.getid()<<" 的初始手牌 ：";
	Sleep(1000);
	pla1.show_cards();
	SetPosition(0,29);
	Sleep(1000);
	SetPosition(18,q+=2);
	cout<<pla2.getid()<<" 的初始手牌 ：";
	Sleep(1000);
	pla2.show_cards();
	SetPosition(0,29);
	Sleep(1000);
	int card;
	card=stock_pile.top();
	stock_pile.pop();
	remain--;
	discard_pile.push(card);
	judge_one(card,color,num);
	SetPosition(18,q+=2);
	cout<<"换牌柱的第一张牌 ：";
	show_one(color,num);
	cout<<endl;
	SetPosition(0,29);
	Sleep(1000);
	string c;
	SetPosition(18,q+=2);
	cout<<pla1.getid()<<" 是否要换牌柱的这张牌 ? Yes or No : ";
	cin>>c;
	while(c[0]!='Y'&&c[0]!='y'&&c[0]!='N'&&c[0]!='n')
	{
		SetPosition(18,q+=2);
		cout<<"请输入 yes 或者 no ：";
		cin>>c;
	}
	if(c[0]=='Y'||c[0]=='y')
	{
		pla1.insert(card);
		discard_pile.pop();
		pla1.sort_cards();
		in=card;
		SetPosition(18,q+=2);
		cout<<pla1.getid()<<"的当前手牌：";
		pla1.show_cards();
		SetPosition(0,29);
		Sleep(1000);
		pla1.discards();
		SetPosition(35,q+=4);
		Sleep(1000);
		cout<<" 游戏开始 ! "<<endl;
		SetPosition(0,29);
		rnd=-1;
		for(int i=1;i<=6;i++)
		{
			SetPosition(46,q);
			cout<<"( "<<6-i<<" )";
			SetPosition(0,29);
			Sleep(1500);
		}
		return;
	}
	else if(c[0]=='N'||c[0]=='n')
	{
		SetPosition(18,q+=2);
		cout<<pla2.getid()<<" 是否要换牌柱的这张牌 ? Yes or No : ";
		cin>>c;
		while(c[0]!='Y'&&c[0]!='y'&&c[0]!='N'&&c[0]!='n')
		{
			SetPosition(18,q+=2);
			cout<<"请输入 yes 或者 no : ";
			cin>>c;
		}
		if(c[0]=='Y'||c[0]=='y')
		{
			pla2.insert(card);
			discard_pile.pop();
			in=card;
			pla2.sort_cards();
			SetPosition(18,q+=2);
			cout<<pla2.getid()<<"的当前手牌：";
			pla2.show_cards();
			SetPosition(0,29);
			Sleep(1000);
			pla2.discards();
			Sleep(1000);
			SetPosition(35,q+=4);
			cout<<" 游戏开始 ! "<<endl;
			SetPosition(0,29);
			rnd=1;
			for(int i=1;i<=6;i++)
			{
				SetPosition(46,q);
				cout<<"( "<<6-i<<" )";
				SetPosition(0,29);
				Sleep(1500);
			}
			return;
		}
		else if(c[0]=='N'||c[0]=='n')
		{
			SetPosition(35,q+=4);
			cout<<" 游戏开始 ! "<<endl;
			SetPosition(0,29);
			rnd=-1;
			gm=1;
			for(int i=1;i<=6;i++)
			{
				SetPosition(46,q);
				cout<<"( "<<6-i<<" )";
				SetPosition(0,29);
				Sleep(1500);
			}
			return;
		}
	}
	return;
}
