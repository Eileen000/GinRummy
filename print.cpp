#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
void SetBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}
void SetPosition(int x,int y)
{
    HANDLE winHandle;//���
    COORD pos = {x,y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù��λ�� 
    SetConsoleCursorPosition(winHandle,pos); 
}
void setinit()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
	FOREGROUND_RED|
	FOREGROUND_GREEN|
	FOREGROUND_INTENSITY); 
}
int print()
{
	system("color 0e");
	string s[7],m[7],n[7];
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
    s[0]="      G G G";  
    s[1]="    G";              
    s[2]="  G";                 
    s[3]=" G";                  
    s[4]="  G    G G G";       
    s[5]="   G       G";        
    s[6]="     G G G G";       
    m[0]="IIIIIIII";    
    m[1]="   II";      
    m[2]="   II";       
    m[3]="   II";       
    m[4]="   II";       
    m[5]="   II";       
    m[6]="IIIIIIII";
	n[0]="N N       N";
    n[1]="N  N      N";
    n[2]="N   N     N";
    n[3]="N    N    N";
    n[4]="N     N   N";
    n[5]="N      N  N";
    n[6]="N       N N"; 
	for(int i=0;i<7;i++)
    {
    	Sleep(100);
    	SetPosition(2,(i+1));
    	cout<<s[i];
	}	
	for(int i=0;i<7;i++)
	{
		Sleep(100);
    	SetPosition(37,(i+1));
    	cout<<m[i];
	}
	for(int i=0;i<7;i++)
	{
		Sleep(100);
    	SetPosition(72,(i+1));
    	cout<<n[i];
	} 
	string a[8],b[8],c[8],d[8],e[8];
	a[0]=" R  R R R R";      
	a[1]=" R        R";
	a[2]=" R        R";
	a[3]=" R  R R R R";
	a[4]=" R  R";
	a[5]=" R    R";
	a[6]=" R      R";
	a[7]=" R        R";
	b[0]="UU        UU";
	b[1]="UU        UU";
	b[2]="UU        UU";
	b[3]="UU        UU";
	b[4]="UU        UU";
	b[5]="UU        UU";
	b[6]=" UU      UU";
	b[7]="   UU  UU";
	c[0]="MM             MM";
	c[1]="M M           M M";
	c[2]="M  M         M  M";
	c[3]="M   M       M   M";
	c[4]="M    M     M    M";
	c[5]="M     M   M     M";
	c[6]="M      M M      M";
	c[7]="M               M";
	d[0]="MM             MM";
	d[1]="M M           M M";
	d[2]="M  M         M  M";
	d[3]="M   M       M   M";
	d[4]="M    M     M    M";
	d[5]="M     M   M     M";
	d[6]="M      M M      M";
	d[7]="M               M";
	e[0]="YY        YY";
	e[1]=" YY      YY";
	e[2]="  YY    YY";
	e[3]="   YY  YY";
	e[4]="     YY";
	e[5]="     YY";
	e[6]="     YY";
	e[7]="     YY";
	for(int i=0;i<8;i++)
	{
		Sleep(100);
		SetPosition(2,10+i);
		cout<<a[i];
	}
	for(int i=0;i<8;i++)
	{
		Sleep(100);
		SetPosition(17,10+i);
		cout<<b[i];
	}
	for(int i=0;i<8;i++)
	{
		Sleep(100);
		SetPosition(32,10+i);
		cout<<c[i];
	}
	for(int i=0;i<8;i++)
	{
		Sleep(100);
		SetPosition(52,10+i);
		cout<<d[i];
	}
	for(int i=0;i<8;i++)
	{
		Sleep(100);
		SetPosition(72,10+i);
		cout<<e[i];
	}
	SetPosition(35,19);
	cout<<"�ϡ��¼�ѡ�񣬻س���ȷ��"<<endl;
	SetPosition(40, 22);
    SetBackColor();
    std::cout << "��Ҷ�ս" ;
    setinit();
    SetPosition(40, 24);
    std::cout << "�˻���ս" ;
    SetPosition(40, 26);
    std::cout << "�˳���Ϸ" ;
	SetPosition(0,29);    
    int ch;
    int key = 1;
    bool flag = false;
    while((ch=getch()))
    {
    	if(ch==-32)
			ch=getch();
        switch(ch)
        {
        case 72:
            if (key > 1)
            {
                switch (key)
                {
                case 2:
                    SetPosition(40, 22);
                    SetBackColor();
                    std::cout << "��Ҷ�ս" ;
					setinit();
                    SetPosition(40, 24);
                    std::cout << "�˻���ս" ;

                    --key;
                    break;
                case 3:
                    SetPosition(40, 24);
                    SetBackColor();
                    std::cout << "�˻���ս" ;
					setinit();
                    SetPosition(40, 26);
                    std::cout << "�˳���Ϸ" ;

                    --key;
                    break;
                }
            }
        SetPosition(0,29);
        break;
        case 80:
            if (key < 3)
            {
                switch (key)
                {
                case 1:
                    SetPosition(40, 24);
                    SetBackColor();
                    std::cout << "�˻���ս" ;
                    setinit();
                    SetPosition(40, 22);
                    std::cout << "��Ҷ�ս" ;

                    ++key;
                    break;
                case 2:
                    SetPosition(40, 26);
                    SetBackColor();
                    std::cout << "�˳���Ϸ" ;
                    setinit();
                    SetPosition(40, 24);
                    std::cout << "�˻���ս" ;

                    ++key;
                    break;
                }
            }
            SetPosition(0,29);
            break;
        case 13:
            flag = true;
            break;
        default:
            break;
    	}
        if (flag) 
			break;
	}	
	switch (key)
    {
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return -1;
    default:
        break;
    }
}
void saygoodbye()
{
	system("cls");
	SetPosition(5,4);
	cout<<"�ǳ���л�����ĵ������� ��С� ͬѧ��Ƶ� Gin Rummy ��";
	SetPosition(5,6);
	cout<<"���������������������Ʒ��ɶȵ���Ҫָ�꣡";
	SetPosition(5,8);
	cout<<"������ڴ˴���Ϸ֮�õ����鼫��, �벻Ҫ��ϧ���ı���͹���Ŷ ~";
	SetPosition(5,10);
	cout<<"������ڱ���Ϸ�����������, ���������ǻ۵�ͷ�Ժ������˫�۷�����һЩ�޷����̵� bug,";
	SetPosition(5,12);
	cout<<"����һ��Ҫ��֪������Ŷ �����߿���ץס����һ�л����������Լ��Ĳ��� ~";
	SetPosition(5,14);
	cout<<"��������ϵ�绰 : 18362992812 ,��ӭ���� ��ʤ�м� ";
	SetPosition(28,18);
	cout<<"������Ե, �����ٻᡣлл ��";
	for(int i=0;i<8;i++)
		cout<<endl;
}
