#include<bits/stdc++.h>
#include"ai_dealing.cpp"
using namespace std;
void ai_start()
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
	shuffle();
	int card;
	string r;
	SetPosition(45,20);
	cout<<"����������֣�";
	cin>>r;
	pla.set_id(r);
	com.set_id("Computer");
	com.receive();
	pla.receive();
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
	cout<<"�������"<<endl;
	SetPosition(0,29);
	Sleep(1000);
	pla.sort_cards();
	com.sort_cards();
	SetPosition(18,q+=3);
	cout<<pla.getid()<<" �ĳ�ʼ���� ��";
	Sleep(1000);
	pla.show_cards();
	SetPosition(0,29);
	Sleep(1000);
	SetPosition(18,q+=2);
	cout<<"Computer �ĳ�ʼ���� ��";
	Sleep(1000);
	com.show_cards();
	SetPosition(0,29);
	Sleep(1000);
	card=stock_pile.top();
	stock_pile.pop();
	remain--;
	discard_pile.push(card);
	judge_one(card,color,num);
	SetPosition(18,q+=2);
	cout<<"�������ĵ�һ���� ��";
	show_one(color,num);
	cout<<endl;
	SetPosition(0,29);
	Sleep(1000);
	string c;
	SetPosition(18,q+=2);
	cout<<pla.getid()<<" �Ƿ�Ҫ�������������� ? Yes or No  :  ";
	cin>>c;
	while(c[0]!='Y'&&c[0]!='y'&&c[0]!='N'&&c[0]!='n')
	{
		SetPosition(18,q+=2);
		cout<<"�Ƿ����� ! ������ yes �� no ��";
		cin>>c;
	}
	if(c[0]=='Y'||c[0]=='y')
	{
		pla.insert(card);
		discard_pile.pop();
		in=card;
		pla.sort_cards();
		SetPosition(18,q+=2);
		cout<<pla.getid()<<"�ĵ�ǰ���ƣ�";
		pla.show_cards();
		SetPosition(0,29);
		Sleep(1000);
		pla.discards();
		Sleep(1000);
		SetPosition(35,q+=4);
		cout<<" ��Ϸ��ʼ ! "<<endl;
		SetPosition(0,29);
		rnd=-1;
		for(int i=1;i<=10;i++)
		{
			SetPosition(46,q);
			cout<<"( "<<10-i<<" )";
			SetPosition(0,29);
			Sleep(1500);
		}
		return;
	}
	else
	{
		com.ai_game_start(card);
		SetPosition(35,q+=4);
		cout<<" ��Ϸ��ʼ ! "<<endl;
		SetPosition(0,29);
		for(int i=1;i<=10;i++)
		{
			SetPosition(46,q);
			cout<<"( "<<10-i<<" )";
			SetPosition(0,29);
			Sleep(1500);
		}
		return;
	}
	return;
}
