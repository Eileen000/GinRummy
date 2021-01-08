#include<bits/stdc++.h>
#include"each_round_move.cpp"
using namespace std;
void player::ai_take_or_eat(int t,int e)
{
	ai_sort_cards();
	calculate_deadwoods();
	//int pre_ds=dw_score;
	int maxn,a,b;
	judge_one(deadwoods[dw-1],color,maxn);
	judge_one(t,color,a);
	judge_one(e,color,b);
	if(maxn<a&&maxn<b)
	{
		if(a<=b)
		{
			insert(t);
			stock_pile.pop();
			remain--;
			cout<<"> Computer 选择 take ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer take后的手牌 ：";
			show_cards();
			return;
		}
		else
		{
			insert(e);
			discard_pile.pop();
			in=e;
			cout<<"> Computer 选择 eat ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer eat后的手牌 ：";
			show_cards();
			return;
		}
	}
	else if(maxn>a&&maxn<=b)
	{
		insert(t);
		stock_pile.pop();
		remain--;
		cout<<"> Computer 选择 take ! <"<<endl;
		ai_sort_cards();
		Sleep(3000);
		SetPosition(18,q+=2);
		cout<<"Computer take后的手牌 ：";
		show_cards();
		return;
	}
	else if(maxn>b&&maxn<=a)
	{
		insert(e);
		discard_pile.pop();
		in=e;
		cout<<"> Computer 选择 eat ! <"<<endl;
		ai_sort_cards();
		Sleep(3000);
		SetPosition(18,q+=2);
		cout<<"Computer eat后的手牌 ：";
		show_cards();
		return;
	}
	else if(maxn>=a&&maxn>=b)
	{
		if(a>=b)
		{
			insert(t);
			stock_pile.pop();
			remain--;
			cout<<"> Computer 选择 take ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer take后的手牌 ：";
			show_cards();
			return;
		}
		else
		{
			insert(e);
			discard_pile.pop();
			in=e;
			cout<<"> Computer 选择 eat ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer eat后的手牌 ：";
			show_cards();
			return;
		}
	}
	/*player t1,t2;
	t1.copy_hand(hand);
	t2.copy_hand(hand);
	t1.insert(t);
	t2.insert(e);
	if(e==100000)
	{
		t1.ai_sort_cards();
		insert(t);
		stock_pile.pop();
		remain--;
		cout<<"> Computer 选择 take ! <"<<endl;
		ai_sort_cards();
		Sleep(3000);
		SetPosition(18,q+=2);
		cout<<"Computer take后的手牌 ：";
		show_cards();
		return;
	}
	t1.ai_sort_cards();
	t2.ai_sort_cards();
	t1.calculate_deadwoods();
	t2.calculate_deadwoods();
	if(t1.getds()<pre_ds&&t2.getds()<pre_ds)
	{
		if(t1.getds()<=t2.getds())
		{
			insert(t);
			stock_pile.pop();
			remain--;
			cout<<"> Computer 选择 take ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer take后的手牌 ：";
			show_cards();
			return;
		}
		else if(t1.getds()>t2.getds())
		{
			insert(e);
			discard_pile.pop();
			in=e;
			cout<<"> Computer 选择 eat ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer eat后的手牌 ：";
			show_cards();
			return;
		}
	}
	if((t1.getds()<pre_ds&&t2.getds()==pre_ds)||(t1.getds()<pre_ds&&getds()>pre_ds)||(t1.getds()==pre_ds&&t2.getds()==pre_ds)||(t1.getds()==pre_ds&&t2.getds()>pre_ds))
	{
		insert(t);
		stock_pile.pop();
		remain--;
		cout<<"> Computer 选择 take ! <"<<endl;
		ai_sort_cards();
		Sleep(3000);
		SetPosition(18,q+=2);
		cout<<"Computer take后的手牌 ：";
		show_cards();
		return;
	}
	if((t2.getds()==pre_ds&&t1.getds()>pre_ds)||(t2.getds()<pre_ds&&t1.getds()==pre_ds)||(t2.getds()<pre_ds&&t1.getds()>pre_ds))
	{
		insert(e);
		in=e;
		discard_pile.pop();
		cout<<"> Computer 选择 eat ! <"<<endl;
		ai_sort_cards();
		Sleep(3000);
		SetPosition(18,q+=2);
		cout<<"Computer eat后的手牌 ：";
		show_cards();
		return;
	}
	if(t1.getds()>pre_ds&&t2.getds()>pre_ds)
	{
		int num1,num2,num;
		char col,col1,col2;
		judge_one(t1.get_deadwoods(0),col1,num1);
		judge_one(t2.get_deadwoods(0),col2,num2);
		judge_one(deadwoods[0],col,num);
		if((num1<num&&num2<num)||(num1>num&&num2>num))
		{
			if(num1<=num2)
			{
				insert(t);
				stock_pile.pop();
				remain--;
				cout<<"> Computer 选择 take ! <"<<endl;
				ai_sort_cards();
				Sleep(3000);
				SetPosition(18,q+=2);
				cout<<"Computer take后的手牌 ：";
				show_cards();
				return;
			}
			else
			{
				insert(e);
				in=e;
				discard_pile.pop();
				cout<<"> Computer 选择 eat ! <"<<endl;
				ai_sort_cards();
				Sleep(3000);
				SetPosition(18,q+=2);
				cout<<"Computer eat后的手牌 ：";
				show_cards();
				return;
			}
		}
		if(num1>num&&num2<=num)
		{
			insert(e);
			in=e;
			discard_pile.pop();
			cout<<"> Computer 选择 eat ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer eat后的手牌 ：";
			show_cards();
			return;
		}
		if(num1<=num&&num2>=num)
		{
			insert(t);
			stock_pile.pop();
			remain--;
			cout<<"> Computer 选择 take ! <"<<endl;
			ai_sort_cards();
			Sleep(3000);
			SetPosition(18,q+=2);
			cout<<"Computer take后的手牌 ：";
			show_cards();
			return;
		}
	}*/
	return;
}
void player::ai_gin()
{
	if(dw==1)
		ai_discards();
	result();
	pla.result();
	cout<<"Computer 胜利 ！"<<endl;
	return;
}
void ai_each_round()
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
	cout<<"当前玩家 : "<<com.getid()<<endl;
	if(gm==0)
	{
		dis=discard_pile.top();
		SetPosition(3,q+=2);
		cout<<pla.getid()<<" 弃牌 ";
		judge_one(dis,color,num);
		Sleep(500);
		show_one(color,num);
	}
	gm=0;
	Sleep(300);
	SetPosition(3,q+=2);
	cout<<"换牌柱 ";
	Sleep(300);
	show_one(color,num);
	Sleep(500);
	cout<<"    剩余 ";
	Sleep(300);
	cout<<remain;
	Sleep(300);
	cout<<" 张"<<endl;
	q=8;
	com.ai_sort_cards();
	SetPosition(0,39);
	Sleep(500);
	SetPosition(18,q+=2);
	cout<<com.getid()<<" 的当前手牌 ：";
	com.show_cards();
	SetPosition(0,39);
	int t=stock_pile.top(),e;
	if(!discard_pile.empty())
		e=discard_pile.top();
	else
		e=100000;
	Sleep(2000);
	SetPosition(18,q+=2);
	com.ai_take_or_eat(t,e);
	SetPosition(0,39);
	com.calculate_deadwoods();
	pla.calculate_deadwoods();
	if(com.get_dw_sum()<=1)
	{
		SetPosition(35,q+=2);
		cout<<"Computer Gin !"<<endl;
		SetPosition(0,39);
		com.ai_gin();
		Sleep(5000);
		return;
	}
	else if(com.getds()<=10&&pla.getds()>com.getds())
	{
		SetPosition(35,q+=2);
		cout<<"Computer Knock !"<<endl;
		pla.lay_off(com.getid());
		com.calculate_deadwoods();
		pla.calculate_deadwoods();
		if(com.getds()<pla.getds())
			com.set_score(pla.getds()-com.getds());
		else
			pla.set_score(10+(com.getds()-pla.getds()));
		com.result();
		pla.result();
		Sleep(5000);
		return;
	}
	Sleep(2000);
	SetPosition(18,q+=2);
	com.ai_discards();
	SetPosition(0,39);
	com.calculate_deadwoods();
	pla.calculate_deadwoods();
	if(com.get_dw_sum()<=1)
	{
		SetPosition(35,q+=2);
		cout<<"Computer Gin !"<<endl;
		SetPosition(0,39);
		com.ai_gin();
		return;
	}
	else if(com.getds()<=10&&pla.getds()>com.getds())
	{
		SetPosition(35,q+=2);
		cout<<"Computer Knock !"<<endl;
		pla.lay_off(com.getid());
		com.calculate_deadwoods();
		pla.calculate_deadwoods();
		if(com.getds()<=pla.getds())
			pla.set_score(10+(com.getds()-pla.getds()));
		else
			com.set_score(pla.getds()-com.getds());
		com.result();
		pla.result();
		if(com.getds()>=pla.getds())
		{
			cout<<pla.getid()<<" 胜 利 "<<endl; 
		}
		else
		{
			cout<<com.getid()<<" 胜 利 "<<endl;
		}
		Sleep(5000);
		return;
	}
	Sleep(1000);
	SetPosition(28,q+=4);
	cout<<"* 下一轮由 "<<pla.getid()<<" 操作哦 *";
	for(int i=1;i<=10;i++)
	{
		SetPosition(sizeof(pla.getid())+20+28,q);
		cout<<"( "<<10-i<<" )";
		SetPosition(0,39);
		Sleep(1500);
	}
	return;
}
