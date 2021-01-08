#include<bits/stdc++.h>
#include<windows.h>
#include"start_a_game.cpp"
using namespace std;
void player::ai_sort_cards()
{
	int ds1=0,ds2=0;
	sort(hand,hand+11);
	int x=0,y=0,z=0,w=0,cnt=0;
	init();
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
	sort(deadwoods,deadwoods+dw);
	dw-=m;
	calculate_deadwoods();
	ds1=dw_score;
	sort(hand,hand+11);
	x=0,y=0,z=0,w=0,cnt=0,m=0;
	init();
	int pp[11];
	for(int i=0;i<11;i++)
			pp[i]=hand[i];
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
	x=0;
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
	sort(deadwoods,deadwoods+dw);
	calculate_deadwoods();
	ds2=dw_score;
	if(ds1>=ds2)
	{
		sort(hand,hand+11);
		x=0,y=0,z=0,w=0,cnt=0;
		init();
		for(i=0;i<11;i++)
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
		m=0;
		sort(deadwoods,deadwoods+dw);
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
		sort(deadwoods,deadwoods+dw);
		dw-=m;
	}
	return;
}
void player::ai_discards()
{
	ai_sort_cards();
	Sleep(500);
	int card;
	card=get_deadwoods(dw-1);
	if(card==in)
		card=get_deadwoods(dw-2);
	cout<<"> Computer 选择弃牌 : ";
	judge_one(card,color,num);
	show_one(color,num);
	cout<<" <"<<endl;
	discard_pile.push(card);
	for(int i=0;i<11;i++)
		if(hand[i]==card)
		{
			hand[i]=0;
			break;
		}
	sort_cards();
	Sleep(2000);
	SetPosition(18,q+=2);
	cout<<"Computer 弃牌后的手牌 ：";
	show_cards();
}
void player::ai_game_start(int t)
{
	player t1;
	t1.copy_hand(get_hand());
	t1.insert(t);
	ai_sort_cards();
	t1.ai_sort_cards();
	calculate_deadwoods();
	t1.calculate_deadwoods();
	int pre_ds=dw_score;
	if(t1.getds()<=pre_ds)
	{
		insert(t);
		discard_pile.pop();
		rnd=1;
		SetPosition(18,q+=2);
		cout<<"> Computer 要这张牌 ！<"<<endl;
		SetPosition(18,q+=2);
		ai_discards();
		SetPosition(0,29);
		return;
	}
	if(t1.getds()>pre_ds)
	{
		int num1,num;
		char col,col1;
		judge_one(t1.get_deadwoods(0),col1,num1);
		judge_one(deadwoods[0],col,num);
		if(num1<=num)
		{
			insert(t);
			discard_pile.pop();
			rnd=1;
			SetPosition(18,q+=2);
			cout<<"> Computer 要这张牌 ！<"<<endl;
			SetPosition(18,q+=2);
			ai_discards();
			SetPosition(0,29);
			return;
		}
		if(num1>num)
		{
			rnd=-1;
			SetPosition(18,q+=2);
			cout<<"> Computer 不要这张牌 ！<"<<endl;
			SetPosition(0,29);
			gm=1;
			return;
		}
	}
	return;
}
