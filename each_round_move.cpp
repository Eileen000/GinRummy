#include<bits/stdc++.h>
#include"ai_start.cpp"
using namespace std;
void player::eat()
{
	in=discard_pile.top();
	discard_pile.pop();
	insert(in);
	sort_cards();
	SetPosition(18,q+=2);
	cout<<id<<" �ĵ�ǰ���� ��";
	show_cards();
}
void player::take()
{
	in=stock_pile.top();
	stock_pile.pop();
	remain--;
	insert(in);
	in=0;
	sort_cards();
	SetPosition(18,q+=2);
	cout<<id<<" �ĵ�ǰ���� ��";
	show_cards();
}
void player::result()
{
	SetPosition(18,q+=2);
	cout<<id<<" �÷� ��"<<score<<"  ";
	cout<<",  ��ľ�� ��"<<dw_score;
	continueflag=0;
}
void player::gin(player&pre)
{
	if(dw==1)
	{
		discards();
		int num;
		char color;
		judge_one(dis,color,num);
		SetPosition(18,q+=2);
		cout<<id<<" Gin , ���� ";
		show_one(color,num);
	}
	SetPosition(18,q++);
	cout<<id;
	show_cards();
	SetPosition(18,q++);
	cout<<pre.getid();
	pre.show_cards();
	calculate_deadwoods();
	pre.calculate_deadwoods();
	score=25+pre.getds();
	SetPosition(18,q+=2);
	result();
	pre.result();
	SetPosition(18,q+=2);
	cout<<id<<" ʤ ��";
	continueflag=0;
	Sleep(5000);
}
void player::lay_off(string r)
{
	int temp[22],index=1;
	sort_cards();
	cout<<endl;
	SetPosition(18,q+=2);
	cout<<id<<" : ��ѡ�����һ����ľ������� ";
	cout<<r<<" �ĳ�����"<<endl;
	Sleep(2000);
	SetPosition(18,q+=2);
	cout<<"��������� : ";
	show_cards();
	Sleep(1500);
	SetPosition(18,q+=2);
	cout<<"���������� -1 "<<endl;
	while(index!=-1)
	{
		char buff[80];
		SetPosition(18,q+=2);
		cout<<"�����㽫Ҫ���ߵ��Ƶı�� (0 - 10) : ";
		cin>>index;
		while(!cin.good())
		{
			cin.clear();
			cin.getline(buff,80);
			SetPosition(18,q+=2);
			cout<<"����������Ŷ (0 - 10) : ";
			cin>>index;
		}
		while((index<0||index>10)&&index!=-1)
		{
			SetPosition(18,q+=2);
			cout<<"���������ַ�Χ 0-10 ��";
			cin>>index;
			cout<<endl;
		}
		if(index!=-1)
			hand[index]=0;
	}
}
void player::ai_lay_off()  //now==com,pre==pla
{
	player temp;
	temp.copy_hand(hand);
	int i,j;
	for(i=0;i<dw;i++)
	{
		temp.insert(deadwoods[i]);
		temp.sort_cards();
		if(temp.get_dw_sum()!=pla.get_dw_sum())
			break;
		for(j=0;j<11;j++)
			if(temp.get_deadwoods(j)!=pla.get_deadwoods(j))
				break;
		if(j<11)
			continue;
		deadwoods[i]=100;
	}
	SetPosition(18,q+=2);
	cout<<"> "<<id<<" ������� <";
	SetPosition(18,q+=2);
	show_cards();
	SetPosition(0,39);
	Sleep(1000);
}
void player::knock(player&pre)
{
	calculate_deadwoods();
	pre.calculate_deadwoods();
	if(getds()>=10)
	{
		SetPosition(18,q+=2);
		cout<<"���� Knock ! ";
		sort(hand,hand+11);
		if(hand[0]!=0)
		{
			discards();
			string r;
			SetPosition(18,q+=2);
			cout<<id<<"(Gin/Knock/Pass):";
			cin>>r;
			while(r[0]!='P'&&r[0]!='p'&&r[0]!='G'
		     	 &&r[0]!='g'&&r[0]!='K'&&r[0]!='k')//
			{
				SetPosition(18,q+=2);
				cout<<"�Ƿ����� ! ������ gin, knock �� pass :";
				cin>>r;
			}
			if(r[0]=='G'||r[0]=='g')
			{
				if(dw>1)
				{
					SetPosition(18,q+=2);
					cout<<"��ҵ�ǰ�޷� Gin ! ������ pass ���� knock :  ";
					cin>>r;
				}
				else
				gin(pre);
			}
			if(r[0]=='K'||r[0]=='k')
				knock(pre);
			}
		return;
	}
	if(moshi==1)
		pre.lay_off(id);
	else if(moshi==0)
		com.ai_lay_off();
	pre.sort_cards();
	calculate_deadwoods();
	pre.calculate_deadwoods();
	if(dw_score<pre.getds())
	{
		score=(pre.getds()-dw_score);
		SetPosition(18,q+=2);
		result();
		pre.result();
		SetPosition(18,q+=2);
		cout<<id<<" * ʤ �� *"<<endl;
		Sleep(5000);
	}
	else if(dw_score>=pre.getds())
	{
		pre.set_score(10+dw_score-pre.getds());
		SetPosition(18,q+=2);
		result();
		pre.result();
		SetPosition(18,q+=2);
		cout<<pre.getid()<<" * ʤ �� *"<<endl;
		Sleep(5000);
	}
	return;
}
void player::each_round(player&pre)
{
	system("color 0e");
	system("cls");
	system("mode con cols=90 lines=40");
	for(int i=0;i<90;i+=3)
	{
		SetPosition(i,0);
		cout<<"#";
	}
	for(int i=0;i<40;i++)
	{
		SetPosition(0,i);
		cout<<"*";
	}
	for(int i=0;i<90;i+=3)
	{
		SetPosition(i,39);
		cout<<"#";
	}
	for(int i=0;i<40;i++)
	{
		SetPosition(89,i);
		cout<<"*";
	}
	q=0;
	SetPosition(3,q+=2);
	cout<<"��ǰ��� : "<<id<<endl;
	if(gm==0)
	{
		dis=discard_pile.top();
		SetPosition(3,q+=2);
		cout<<pre.getid()<<" ���� ";
		judge_one(dis,color,num);
		Sleep(300);
		show_one(color,num);
	}
	gm=0;
	Sleep(300);
	SetPosition(3,q+=2);
	cout<<"������ ";
	Sleep(300);
	show_one(color,num);
	Sleep(500);
	cout<<"    ʣ�� ";
	Sleep(300);
	cout<<remain;
	cout<<" ����"<<endl;
	SetPosition(0,39);
	zuhe="1";
	q=8;
	sort_cards();
	Sleep(500);
	SetPosition(18,q+=2);
	cout<<id<<" �ĵ�ǰ���� ��";
	show_cards();
	SetPosition(0,39);
	sort_cards();
	Sleep(1000);
	string r;
	SetPosition(18,q+=2);
	cout<<id<<"(Eat/Take):";
	cin>>r;
	while(r[0]!='E'&&r[0]!='e'&&r[0]!='T'&&r[0]!='t')
	{
		SetPosition(18,q+=2);
		cout<<"�Ƿ�����, ������ eat ���� take ��";
		cin>>r;
	}
	if(r[0]=='E'||r[0]=='e')
		eat();
	if(r[0]=='T'||r[0]=='t')
		take();
	SetPosition(18,q+=1);
	cout<<" --------------------------------------------------";
	SetPosition(18,q+=1);
	cout<<"| ��ѡ�����Ʒ�ʽ ��ͬ������(1) or ������ͬ����(0) |";
	SetPosition(18,q+=1);
	cout<<"| ������ϴ��� ��";
	cin>>zuhe;
	while(zuhe!="0"&&zuhe!="1")
	{
		SetPosition(18,q+=1);
		cout<<"�Ƿ����� ! ������ 0 �� 1 ��";
		cin>>zuhe;
	}
	SetPosition(18,q+=1);
	cout<<"---------------------------------------------------"<<endl;
	SetPosition(0,39);
	sort_cards();
	Sleep(1000);
	SetPosition(18,q+=1);
	if(zuhe=="1")
		cout<<"��ͬ�����ȣ�";
	else
		cout<<"��������ͬ���ȣ�";
	show_cards();
	SetPosition(0,39);
	Sleep(1000);
	SetPosition(18,q+=2);
	cout<<id<<"(Discard/Gin/Knock):";
	cin>>r;
	while(r[0]!='G'&&r[0]!='g'&&r[0]!='D'&&r[0]!='d'&&r[0]!='K'&&r[0]!='k')
	{
		SetPosition(18,q+=2);
		cout<<"�Ƿ����� ! ������ discard, gin ���� knock ��";
		cin>>r;
	}
	if(r[0]=='G'||r[0]=='g')
	{
		if(dw>1)
		{
			SetPosition(18,q+=2);
			cout<<" ��ҵ�ǰ�޷� Gin ! ������ discard ���� knock : ";
			cin>>r;
		}
		else
			gin(pre);
	}
	if(r[0]=='D'||r[0]=='d')
	{
		discards();
		string f;
		SetPosition(18,q+=2);
		cout<<id<<"(Gin/Knock/Pass):";
		cin>>f;
		while(f[0]!='P'&&f[0]!='p'&&f[0]!='G'
		      &&f[0]!='g'&&f[0]!='K'&&f[0]!='k')//
		{
			SetPosition(18,q+=2);
			cout<<"�Ƿ����� ! ������ pass, gin �� knock :";
			cin>>f;
		}
		if(f[0]=='G'||f[0]=='g')
		{
			if(dw>1)
			{
				SetPosition(18,q+=2);
				cout<<"��ҵ�ǰ�޷� Gin ! ������ pass ���� knock :  ";
				cin>>f;
			}
			else
				gin(pre);
		}
		if(f[0]=='K'||f[0]=='k')
				knock(pre);
	}
	if(r[0]=='K'||r[0]=='k')
		knock(pre);
	SetPosition(0,39);
	Sleep(1000);
	if(continueflag&&remain)
	{
		SetPosition(28,q+=4);
		cout<<"* ��һ���� "<<pre.getid()<<" ����Ŷ *";
	}
	SetPosition(0,39);
	Sleep(2000);
	return;
}
void ask()
{
	SetPosition(18,q+=2);
	cout<<"�Ƿ�����һ�֣������� Yes or No:";
	string c;
	cin>>c;
	while(c[0]!='y'&&c[0]!='Y'&&c[0]!='N'&&c[0]!='n')
	{
		SetPosition(18,q+=2);
		cout<<"�Ƿ����� ! ������ yes �� No : ";
		cin>>c;
	}
	if(c[0]=='Y'||c[0]=='y')
	{
		pla1.set_last(pla1.getds());
		pla2.set_last(pla2.getds());
		continueflag=1;
	}
	else if(c[0]=='N'||c[0]=='n')
	{
		pla1.set_last(0);
		pla1.set_last(0);
		pla1.idclear();
		pla2.idclear();
		continueflag=0;
	}
}
void liuju()
{
	pla1.calculate_deadwoods();
	pla2.calculate_deadwoods();
	cout<<pla1.getid()<<" ��ľ��Ϊ ��"<<pla1.getds()<<endl;
	SetPosition(18,q+=2);
	cout<<pla2.getid()<<" ��ľ��Ϊ ��"<<pla2.getds()<<endl;
	SetPosition(18,q+=2);
	cout<<"���֣�˫������Ϊ0 "<<endl;
	ask();
	return;
}
