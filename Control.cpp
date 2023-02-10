#include<iostream>
#include<cstring>
using namespace std;
#include"Menu.cpp"
class Control:public Menu
{
public:
display d;
shape *p=&d.pt;
int Mode=1,play,flag=10,hint;
string s;
Control()
{
	hint=0;
	play=0;
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			d.arr[i][j]=rand()%5;
		}
	}
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<1;j++)
		{
			d.arr[i][j]=10;
			d.arr[j][i]=10;
		}
	}
	cout<<"Please Enter your First Name: ";
	cin>>s;	
	flag=1;
	p->sc=0;
}
void setMenu(int a)
{
Menu::choice=a;
}
void setFlag(int a)
{
	flag=a;
}
int getFlag()
{
	return flag;
}
void MouseControl(int x, int y)
{
	if(play%2==0&&flag==2)
	{
		if(d.getmouse()%2==0)
		{
			d.a1=d.getcol(y);
			d.b1=d.getrow(x);
		}	
		else if(d.getmouse()%3==0)
		{
			d.a2=d.getcol(y);
			d.b2=d.getrow(x);
		}
		if (d.mouse>2)
		{
			if (d.readyToSwap()==1&&d.ready(d.b1,d.a1,d.b2,d.a2)==1)
			{
				d.swap();
				d.setIntial();
				d.dis();
			}
		}
		d.mouse++;
	}	
}
void load()
{
	if(p->moves>0)
	{
		d.dis();             
		d.check(); 
		d.showScore();
		d.showLevel();
		d.ShowMood(Mode);
		if(Mode==2)
		{
		d.showMoves();
		}
	}
	else if(p->moves<1)
	{
	flag=5;
	}
}
void Show_Menu()
{
	DrawRoundRect(220,760,420,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 230, 750, "Welcome To Candy Crush, "+s, colors[MISTY_ROSE]); 
	DrawRoundRect(340,610,160,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 600, "1. Play", colors[MISTY_ROSE]);
	DrawRoundRect(340,560,160,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 550, "2. Rules", colors[MISTY_ROSE]);
	DrawRoundRect(340,510,160,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 500, "3. Game Mode", colors[MISTY_ROSE]);
	DrawRoundRect(340,460,160,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 450, "4. High Score", colors[MISTY_ROSE]);
	DrawRoundRect(340,410,160,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 400, "5. Exit", colors[MISTY_ROSE]);
	DrawRoundRect(600,80,180,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 610, 70, "Programmed By:", colors[MISTY_ROSE]);
	DrawRoundRect(600,40,180,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 610, 30, "Asim Ali", colors[MISTY_ROSE]);
	DrawRoundRect(70,80,180,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 80, 70, "Instructor:", colors[MISTY_ROSE]);
	DrawRoundRect(70,40,180,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 80, 30, "Dr.Aleem", colors[MISTY_ROSE]);
	DrawRoundRect(220,260,420,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 270, 250, "Press Number You want to Go.", colors[MISTY_ROSE]); 
	DrawLine( 220 , 245 ,  220 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	DrawLine( 640 , 245 ,  640 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	
}
void end()
{
	DrawRoundRect(90,760,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 300, 750, "Thanks For Playing, "+s, colors[MISTY_ROSE]);
	if(Mode==1)
	{
	DrawRoundRect(340,610,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 600, "Mode: Normal", colors[MISTY_ROSE]);
	}
	else if(Mode==2)
	{
	DrawRoundRect(340,610,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 600, "Mode: Time-Trial", colors[MISTY_ROSE]);
	}
	DrawRoundRect(340,560,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 550, "Scores: "+to_string(p->sc), colors[MISTY_ROSE]);
	DrawRoundRect(340,510,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 500, "Level: "+to_string(d.getLevel()), colors[MISTY_ROSE]);
	DrawRoundRect(90,410,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 200, 400, "Press '5' to exit and 'B' to play Again.", colors[MISTY_ROSE]);
	DrawLine( 90 , 395 ,  90 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	DrawLine( 790 , 395 ,  790 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	Mode=1;
	p->sc=0;
	p->lvl=1;
	p->moves=20;
	p->target=100;
}
void TurnHint()
{
	d.Hint();
}
void KeyBoardControl(int key)
{
	if(key == '1')
	{
		flag=2;
		d.check();
		d.dis();
	}
	if(key == '2')
	{
		setMenu(2);
	}
	if(key == '3')
	{
		setMenu(3);
	}
	if(key == '4')
	{
		setMenu(4);
	}
	if(key == 'b'||key =='B')
	{
		setMenu(0);
		flag=1; 
	}
	if(key == 'N'||key =='n')
	{
		setMenu(0);
		Mode=1; 
	}
	if(key == 't'||key =='T')
	{
		setMenu(0);  
		Mode=2; 
	}
	if(key == 'p'||key =='P')
	{ 
		play++;
		if(play%2!=0)
		{
		flag=4;
		}
		else flag=2;
	}
	if(key == 'h'||key =='H')
	{
		hint++;	
		if(hint%2==1)
		{
		p->sc-=20;
		flag=3;
		}
		else 
		flag=2;
	
	}
	if(key == 'e'||key =='E')
	{ 
		flag=5;
	}
	if(key == '5')
	{
		int g=p->sc;
		Menu::H.setRun(g);
		Menu::H.file_reading();
		Menu::H.highscores();
		exit(1);
	}
}
~Control()
{
}
};
