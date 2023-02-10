#include<iostream>
#include <fstream>
using namespace std;
class HighScor
{
public:
	int scores[4];
	fstream outfile,userfile;
	int highrun;
	void setRun(int a)
	{
		highrun=a;
	}
	int file_reading()
	{
		fstream userfile;
		userfile.open("Highscore.txt",ios::in);
		for(int i=0; i<4; i++)
		{
		userfile>>scores[i];
		}
	DrawRoundRect(90,760,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 300, 750, "High Scores", colors[MISTY_ROSE]);
	DrawRoundRect(340,660,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 650, "1. "+to_string(scores[0]), colors[MISTY_ROSE]);
	DrawRoundRect(340,610,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 600, "2. "+to_string(scores[1]), colors[MISTY_ROSE]);
	DrawRoundRect(340,560,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 550, "3. "+to_string(scores[2]), colors[MISTY_ROSE]);
	DrawRoundRect(340,510,200,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 500, "4. "+to_string(scores[3]), colors[MISTY_ROSE]);
	DrawRoundRect(90,410,700,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 200, 400, "Press 'B' to go Back", colors[MISTY_ROSE]);
	DrawLine( 90 , 395 ,  90 , 775 , 10 , colors[DARK_OLIVE_GREEN] );
	DrawLine( 790 , 395 ,  790 , 775 , 10 , colors[DARK_OLIVE_GREEN] );	
	userfile.close();
	}
	int highscores()
	{
		int larger;
		outfile.open("Highscore.txt",ios::out);
		for(int i=0;i<4;i++)
		{
			for(int j=i;j<4;j++)
				{
				if(scores[i]<highrun)
				{
		        		larger=scores[i];
		        		scores[i]=highrun;
		        		highrun=larger;
				}
			}
		}
		for(int i=0;i<4;i++)
		{
			for(int j=i+1;j<4;j++)
			{
				if(scores[i]<scores[j])
				{
					larger=scores[i];
					scores[i]=scores[j];
					scores[j]=larger;
				}
	   		}
			outfile<<scores[i]<<endl;
		}
		outfile.close();
		return 0;
	}
};

