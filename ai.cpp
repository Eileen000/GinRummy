#include<bits/stdc++.h>
#include"ai_each_round.cpp"
using namespace std;

void ai()
{
	system("color 0e");
	while(continueflag)
	{
		ai_start();
		while(remain&&continueflag)
		{
			if(rnd==1)
				pla.each_round(com);
			else if(rnd==-1) 
				ai_each_round();
			system("cls");
			rnd*=-1;
		}
		if(!continueflag)
			ask();
		if(remain<=0)
		{
			liuju();
			ask();
		}
	}
}
