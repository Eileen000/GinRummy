#include<bits/stdc++.h>
#include<windows.h>
#include"print.cpp"
#include"ai.cpp"
using namespace std;
int main()
{
	system("color 0e");
	moshi=print();	
	Sleep(1000);
	system("cls");
	continueflag=1;
	if(moshi==0)
		ai();
	while(moshi==1&&continueflag)
	{
		game_start();
		while(remain&&continueflag) 
		{
			if(rnd==1)
				pla1.each_round(pla2);
			else if(rnd==-1) 
				pla2.each_round(pla1);
			rnd*=-1;
		}
		if(continueflag==0)
			ask();
		if(remain<=0)
			liuju();	
	}
	if(moshi==-1||continueflag==0||remain<=0)
		saygoodbye();
	return 0;
}
