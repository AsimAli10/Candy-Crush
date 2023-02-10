#include<iostream>

using namespace std;
class shape 
{
public:
	int x_axis,y_axis,sc,moves,lvl,mood,target;
	shape()
	{
	moves=20;
	lvl=1;	
	target=100;
	sc=0;
	}
	void set(int a, int b)
	{
	x_axis=a;
	y_axis=b;
	}
	void square()
	{
		DrawSquare( x_axis+10 , y_axis+10 ,20,colors[RED]);
	}
	void circle()
	{
		DrawCircle(x_axis+20,y_axis+20,10,colors[BLUE]);
	}
	void rec()
	{
		DrawSquare( x_axis+10 , y_axis+10 ,20,colors[WHITE]);
		DrawSquare( x_axis+13 , y_axis+13 ,13,colors[BLACK]);
	}
	void trp()
	{
		DrawTriangle( x_axis+5, y_axis+5 , x_axis+35, y_axis+5 , x_axis+20 , y_axis+35, colors[BROWN] ); 
	}
	void gem()
	{
		DrawCircle(x_axis+20,y_axis+20,13,colors[GREEN]);
		DrawCircle(x_axis+20,y_axis+20,8,colors[WHITE]);
	}
	void Score()
	{
		DrawString( 50, 800, "Score: "+to_string(sc), colors[MISTY_ROSE]);
		DrawString( 80, 20, "Score: ", colors[MISTY_ROSE]);
		DrawRoundRect(140,20,target,20,colors[BLACK],10);		
		DrawRoundRect(140,20,sc,20,colors[DARK_OLIVE_GREEN],10);
	}
	void TimeScore()
	{
		DrawString( 50, 800, "Score: "+to_string(sc), colors[MISTY_ROSE]);
		DrawString( 80, 20, "Score: ", colors[MISTY_ROSE]);
		DrawRoundRect(140,20,target,20,colors[BLACK],10);
		DrawRoundRect(140,20,(target/2)+sc,20,colors[DARK_OLIVE_GREEN],10);
	}
	void move()
	{
		DrawString( 700, 800, "Moves: "+to_string(moves), colors[MISTY_ROSE]);
		DrawString( 520, 20, "Moves: ", colors[MISTY_ROSE]);
		DrawRoundRect(600,20,100,20,colors[BLACK],10);
		DrawRoundRect(600,20,moves*5,20,colors[DARK_OLIVE_GREEN],10);
	}
	void level()
	{
		DrawString( 300, 800, "Level: "+to_string(lvl), colors[MISTY_ROSE]);
	}
	void setLevel()
	{
		if(sc>target)
		{
		lvl++;
		target+=50;
		sc=0;
		}
	}
	void setMood(int a)
	{
		mood=a;
		if(mood==1)
		{
		DrawString( 450, 800, "Mode: Normal", colors[MISTY_ROSE]);
		}
		if(mood==2)
		{
		DrawString( 450, 800, "Mode: Time-Trial", colors[MISTY_ROSE]);
		}
	}
	~shape()
	{
	}
};
