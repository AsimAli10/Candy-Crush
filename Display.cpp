#include<iostream>
using namespace std;
#include"Shapes.cpp"
class display
{
public:
	shape pt;
	int arr[11][11]={0};
	int mouse;
	int a1,b1,a2,b2;
display()
{
	mouse=1;
	a1=0;
	b1=0;
	a2=0;
	b2=0;
}
int getrow(int x)
{
	return x/70;
}
int getcol(int y)
{
	return 11-(y/60);
}
int getmouse()
{
	return mouse;
}
void showScore()
{
	if(pt.mood==1)
	{
		pt.Score();
	}
	else 
	pt.TimeScore();	
}
int getScore()
{
	return pt.sc;
}
void showMoves()
{
pt.move();
}
int getMoves()
{
	return pt.moves;
}
void showLevel()
{
	pt.setLevel();
	pt.level();
}
int getLevel()
{
	return pt.lvl;
}
void ShowMood(int a)
{
	pt.setMood(a);
}
void dis()
{
	for(int a=1;a<11;a++)
	{
		for(int b=1;b<11;b++)
		{
			int k=arr[a][b];
			pt.set(a*70,b*70);
			if(k==0)
			{
				pt.square();
			}
			else if(k==1)
			{
				pt.circle();
			}
			else if(k==2)
			{
				pt.rec();
			}
			else if(k==3)
			{
				pt.trp();
			}
			else if(k==4)
			{
				pt.gem();
			}
			DrawLine( a*70-10 , b*70-10 ,  a*70+60 , b*70-10 , 10 , colors[MISTY_ROSE] );
			DrawLine( a*70-10 , b*70-10 ,  a*70-10 , b*70+60 , 10 , colors[MISTY_ROSE] );
			DrawLine( a*70-10 , b*70+60 ,  a*70+60 , b*70+60 , 10 , colors[MISTY_ROSE] );
			DrawLine( a*70+60 , b*70-10 ,  a*70+60 , b*70+60 , 10 , colors[MISTY_ROSE] );
		}
	}
	check();
}
void check()
{
	for(int a=1;a<11;a++)
	{
		for(int b=1;b<11;b++)
		{
			if(a+2<11)
			{
				if(arr[a][b]==arr[a+1][b])
				{
					if(arr[a+1][b]==arr[a+2][b])
					{
						cout<<"Found row of three at row "<<b<<" and cols "<<a<<" "<<a+1<<" "<<a+2<<"\n";
						for(int i=a;i<a+3;i++)
						{
							for(int j=b;j<10;j++)
							{
							arr[i][j]=arr[i][j+1];
							}
						}
						for(int i=a;i<a+3;i++)
						{
							for(int j=10;j>9;j--)
							{
								arr[i][j]=rand()%5;
							}
						}	
						dis();
						pt.sc+=10;
					}
				}
			}
		}
	}
	for(int a=1;a<11;a++)
	{
		for(int b=1;b<11;b++)
		{
			if(b+2<11)
			{
				if(arr[a][b]==arr[a][b+1])
				{
					if(arr[a][b+1]==arr[a][b+2])
					{
						cout<<"Found column of three at col "<<a<<" and rows "<<b<<" "<<b+1<<" "<<b+2<<"\n";
						for(int i=b;i<11;i++)
						{
							if(b+3<11)
							{
							arr[a][i]=arr[a][i+3];
							}
						}
						for(int k=10;k>7;k--)
						{
						arr[a][k]=rand()%5;
						}
						dis();
						pt.sc+=10;		
					}
				}
				
			}
		}
	}
	
}
bool ready(int a, int b, int c, int d)
{
	if(a<c)
	{
		if(arr[a+1][b]==arr[a+2][b]&&arr[a+2][b]==arr[a+3][b])
		{return true;}
		else if(arr[a+1][b]==arr[a+1][b-1]&&arr[a+1][b]==arr[a+1][b+1])
		{return true;}
		else if(arr[a+1][b]==arr[a+1][b+1]&&arr[a+1][b+1]==arr[a+1][b+2])
		{return true;}
		else if(arr[a+1][b]==arr[a+1][b-1]&&arr[a+1][b-1]==arr[a+1][b-2])
		{return true;}
		else if(arr[c-1][d]==arr[c-1][d-1]&&arr[c-1][d-1]==arr[c-1][d-2])
		{return true;}
		else if(arr[c-1][d]==arr[c-1][d+1]&&arr[c-1][d+1]==arr[c-1][d+2])
		{return true;}
		else if(arr[c-1][d]==arr[c-2][d]&&arr[c-2][d]==arr[c-3][d])
		{return true;}
		else if(arr[c-1][d]==arr[c-1][d-1]&&arr[c-1][d]==arr[c-1][d+1])
		{return true;}
	}
	else if(a>c)
	{
		if(arr[a-1][b]==arr[a-2][b]&&arr[a-2][b]==arr[a-3][b])
		{return true;}
		else if(arr[a-1][b]==arr[a-1][b-1]&&arr[a-1][b]==arr[a-1][b+1])
		{return true;}
		else if(arr[a-1][b]==arr[a-1][b+1]&&arr[a-1][b+1]==arr[a-1][b+2])
		{return true;}
		else if(arr[a-1][b]==arr[a-1][b-1]&&arr[a-1][b-1]==arr[a-1][b-2])
		{return true;}
		else if(arr[c+1][d]==arr[c+1][d-1]&&arr[c+1][d-1]==arr[c+1][d-2])
		{return true;}
		else if(arr[c+1][d]==arr[c+1][d+1]&&arr[c+1][d+1]==arr[c+1][d+2])
		{return true;}
		else if(arr[c+1][d]==arr[c+2][d]&&arr[c+2][d]==arr[c+3][d])
		{return true;}
		else if(arr[c+1][d]==arr[c+1][d-1]&&arr[c+1][d]==arr[c+1][d+1])
		{return true;}
	}
	else if(a==c&&b>d)
	{
		if(arr[a][b-1]==arr[a][b-2]&&arr[a][b-2]==arr[a][b-3])
		{return true;}
		else if(arr[a][b-1]==arr[a-1][b-1]&&arr[a][b-1]==arr[a+1][b-1])
		{return true;}
		else if(arr[a][b-1]==arr[a-1][b-1]&&arr[a-1][b-1]==arr[a-2][b-1])
		{return true;}
		else if(arr[a][b-1]==arr[a+1][b-1]&&arr[a+1][b-1]==arr[a+2][b-1])
		{return true;}
		else if(arr[c][d+1]==arr[c+1][d+1]&&arr[c+1][d+1]==arr[c+2][d+1])
		{return true;}
		else if(arr[c][d+1]==arr[c-1][d+1]&&arr[c-1][d+1]==arr[c-2][d+1])
		{return true;}
		else if(arr[c][d+1]==arr[c][d+2]&&arr[c][d+2]==arr[c][d+3])
		{return true;}
		else if(arr[c][d+1]==arr[c-1][d+1]&&arr[c][d+1]==arr[c+1][d+1])
		{return true;}
	}
	else if(a==c&&b<d)
	{
		if(arr[a][b+1]==arr[a][b+2]&&arr[a][b+2]==arr[a][b+3])
		{return true;}
		else if(arr[a][b+1]==arr[a-1][b+1]&&arr[a][b+1]==arr[a+1][b+1])
		{return true;}
		else if(arr[a][b+1]==arr[a-1][b+1]&&arr[a-1][b+1]==arr[a-2][b+1])
		{return true;}
		else if(arr[a][b+1]==arr[a+1][b+1]&&arr[a+1][b+1]==arr[a+2][b+1])
		{return true;}
		else if(arr[c][d-1]==arr[c+1][d-1]&&arr[c+1][d-1]==arr[c+2][d-1])
		{return true;}
		else if(arr[c][d-1]==arr[c-1][d-1]&&arr[c-1][d-1]==arr[c-2][d-1])
		{return true;}
		else if(arr[c][d-1]==arr[c][d-2]&&arr[c][d-2]==arr[c][d-3])
		{return true;}
		else if(arr[c][d-1]==arr[c-1][d-1]&&arr[c][d-1]==arr[c+1][d-1])
		{return true;}
	}
	else 
	return false;
	

}
void swap()
{
	int a=arr[b1][a1];
	arr[b1][a1]=arr[b2][a2];
	arr[b2][a2]=a;
	check();
	dis();
	if(pt.mood==2)
	{
	pt.moves-=1;
	}
}
int readyToSwap()
{
	if(b1==b2)
	{
		if(a1>a2)
		{
		return (a1-a2);
		}
		else if(a2>a1)
		{
		return a2-a1;
		}
	}
	else if (a1==a2)
	{
		if(b1>b2)
		{
		return (b1-b2);
		}
		else if(b2>b1)
		{
		return b2-b1;
		}
	}
	else 
	return 1-1;	
}
void setIntial()
{
	mouse=0;
	a1=0;
	b1=0;
	a2=0;
	b2=0;
}
void Hint()
{
	int i=0;
	for(int a=1;a<11;a++)
	{
		for(int b=1;b<11;b++)
		{
			if(b+2<11&&a-1>0&&a+1<11)
			{
				if(arr[a][b]==arr[a][b+1])
				{
					if(arr[a][b+1]==arr[a+1][b+2])
					{
					i=1;
					cout<<"Found Hint of three at col "<<a<<" and "<<a+1<<" and rows "<<b<<" "<<b+1<<" "<<b+2<<"\n";
					DrawSquare( (a*70) , (b*70) ,40,colors[BLACK]);
					DrawSquare( (a*70) , ((b+1)*70) ,40,colors[BLACK]);
					DrawSquare( ((a+1)*70) , ((b+2)*70) ,40,colors[BLACK]);
					dis();
					break;	
					}
					else if(arr[a][b+1]==arr[a-1][b+2])
					{
					i=1;
					cout<<"Found Hint of three at col "<<a<<" and "<<a-1<<" and rows "<<b<<" "<<b+1<<" "<<b+2<<"\n";
					DrawSquare( (a*70) , (b*70) ,40,colors[BLACK]);
					DrawSquare( (a*70) , ((b+1)*70) ,40,colors[BLACK]);
					DrawSquare( ((a+1)*70) , ((b+2)*70) ,40,colors[BLACK]);
					dis();
					break;
					}
				}
				
			}
		}
		if(i==1)
		{
		break;
		}
	}
}
~display()
{
}

};

