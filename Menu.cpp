#include<iostream>
using namespace std;
#include"Display.cpp"
#include"HighScore.cpp"
class Menu
{
public:
	int choice;
	HighScor H;
	Menu()
	{
	choice=0;
	}
	virtual void Show_Menu()
	{
	DrawString( 400, 700, "1. Play", colors[MISTY_ROSE]);
	DrawString( 400, 600, "2. Help", colors[MISTY_ROSE]);
	DrawString( 400, 500, "3. High Score", colors[MISTY_ROSE]);
	DrawString( 400, 400, "4. Game Mode", colors[MISTY_ROSE]);
	DrawString( 400, 300, "5. Exit", colors[MISTY_ROSE]);
	}
	void Rules()
	{
	DrawRoundRect(90,760,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 270, 750, "Some Rules To Play Game", colors[MISTY_ROSE]);
	DrawRoundRect(90,660,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 650, "1. Click first gem and then second to swap.", colors[MISTY_ROSE]);
	DrawRoundRect(90,610,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 600, "2. Try to make such matches that can result in more matches.", colors[MISTY_ROSE]);
	DrawRoundRect(90,560,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 550, "3. Press 'P' for Pause/Play.", colors[MISTY_ROSE]);
	DrawRoundRect(90,510,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 500, "4. There are limited swaps in Time-Trial Mode.", colors[MISTY_ROSE]);
	DrawRoundRect(90,460,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 450, "5. Every level has increased target to achieve.", colors[MISTY_ROSE]);
	DrawRoundRect(90,410,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 400, "6. Every swap scores 10 points.", colors[MISTY_ROSE]);
	DrawRoundRect(90,360,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 350, "7. Press 'H' for hint and Then Again Press 'H' to Play Loss= -20 pts", colors[MISTY_ROSE]);
	DrawRoundRect(90,310,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 100, 300, "8. If you want to end game during play, Press 'E' .", colors[MISTY_ROSE]);	
	DrawRoundRect(90,210,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 270, 200, " Press 'B' to go Back.", colors[MISTY_ROSE]);
	DrawLine( 90 , 195 ,  90 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	DrawLine( 790 , 195 ,  790 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	}
	void Mood()
	{
	DrawRoundRect(90,760,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 300, 750, "Modes   of   Game", colors[MISTY_ROSE]);
	DrawRoundRect(340,610,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 600, "Time Trial ", colors[MISTY_ROSE]);
	DrawRoundRect(340,560,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 550, "Normal", colors[MISTY_ROSE]);
	DrawRoundRect(90,460,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 200, 450, "Press 'T' for Time-Trial & 'N' for Normal", colors[MISTY_ROSE]);
	DrawLine( 90 , 445 ,  90 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	DrawLine( 790 , 445 ,  790 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	}
	void HighScore()
	{
	H.file_reading();
	}
	~Menu()
	{
	
	}
};
