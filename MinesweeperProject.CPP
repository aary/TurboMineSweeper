//*************************************************************************
//                             MINESWEERPER                               *
//                       MADE BY - Aaryaman Sagar                         *
//*************************************************************************

#include<iostream>
//#include<conio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
/*void printarr(char arr[][9],int x,int y)
{
	int j,k;
	for(k=0;y<=y+8;y++,k++)
	{
		for(j=0;x<=x+8;x++,j++)
		{
			gotoxy(x,y);cout<<arr[k][j];
		}
		x = x-8;
	}
}*/

//***********************************************************************
//                         FUNCTION DECLERATIONS                        *
void rules();//                                                         *
void printbox();//				              	        *
void start();//						                *
int ten_exes(char arr[][9]);//				                *
void setmine(char arr[][9]);//				                *
void placeno(char arr[][9]);//				                *
void setspace(char arr[][9]);//				                *
void copy(char disp[][9],char field[][9],int x,int y);//                *
int checker(char displayarr[][9],char field[][9]);//	                *
//                                                                      *
//***********************************************************************

//FUNCTIONS

void rules()
{
	cout<<"THE OBJECT - Find the empty places while avoiding the mines.";
	cout<<endl<<"HOW TO PLAY - Uncover an empty box and keep playing. click on a mine and you\nlose.";
	cout<<"\nThe numbers indicate how many mines there are in the boxes around it.";
}
void printbox()
{
	cout<<"\n\t\t\t  0 1 2 3 4 5 6 7 8\n";
	cout<<"\t\t\t0|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t1|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t2|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t3|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t4|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t5|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t6|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t7|_|_|_|_|_|_|_|_|_|\n";
	cout<<"\t\t\t8|_|_|_|_|_|_|_|_|_|\n";
}
void start()
{
	cout<<"\t\t\t\t   Minesweeper\n\n";
	char ans;
	cout<<"Do you know  how to play the game (y/n)?";cin>>ans;
	if (ans=='y'){}
	else if (ans=='n')
	{rules();}
	else
	{cout<<"I'll assume you do";}
	printbox();
	cout<<"\nThis is your field of duty. You will have to \"click\" by typing in the\ncode of the box when asked for(y coordinate,x coordinate).";
	cout<<"\nPress any key to start.";
    char temp;
    cin >> temp;
	//clrscr();
}
int ten_exes(char arr[][9])
{
	int counter = 0;
	for (int i = 0;i<9;i++)
	{
		for (int j = 0;j<9; j++)
		{
			if (arr[i][j] == 'x')
			counter ++;
		}
	}
	if (counter == 10)
	{return 0;}
	else
	return 1;
}
void setmine(char arr[][9])
{
	int x,y;
	srand(time(NULL));
	while (ten_exes(arr))
	{
		y = (rand()+rand()*rand()+rand()*rand())%10;
		x = rand()%10;
		if (y<=8 && x<=8 && arr[y][x] != 'x')
		{
			arr[y][x]='x';
		}
	}
}
void placeno(char arr[][9])
{
	int x,y,xcor,ycor,flag,counter=0;
	for(x = 0; x<9 ;x++)
	{
		for(y = 0;y<=8;y++)
		{
			for(flag = 1;flag<=8;flag++)
			{
				ycor = y;
				xcor = x;
				if (flag == 1)
				{	ycor=ycor-1;
					if(((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					counter++;
					else
					continue;
				}
				else if (flag==2)
				{
					ycor=ycor-1;xcor=xcor+1;
					if(((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					counter++;
					else
					continue;
				}
				else if (flag == 3)
				{
					ycor = ycor;
					xcor=xcor+1;
					if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					{counter ++;}
					else
					continue;
				}
				else if (flag == 4)
				{
					ycor=ycor+1;
					xcor=xcor+1;
					if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					{counter ++;}
					else
					continue;
				}
				else if (flag == 5)
				{
					ycor = ycor+1;
					xcor = xcor;
					if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					{counter ++;}
					else
					continue;
				}
				else if (flag == 6)
				{
					ycor = ycor+1;
					xcor = xcor-1;
					if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					{counter ++;}
					else
					continue;
				}
				else if (flag == 7)
				{
					ycor  = ycor;
					xcor = xcor-1;
					if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					{counter ++;}
					else
					continue;
				}
				else if (flag == 8)
				{
					ycor = ycor-1;
					xcor = xcor-1;
					if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && arr[ycor][xcor]=='x')
					{
						counter ++;
					}
					else
					continue;
				}
			}
			if(arr[y][x]!='x')
			arr[y][x] = counter+48;
			counter = 0;
		}
	}
}
void setspace(char arr[][9])
{
	int x,y;
	for(y=0;y<=8;y++)
	{
		for(x=0;x<=8;x++)
		{
			arr[x][y] = ' ';
		}
	}
}
void copy(char disp[][9],char field[][9],int x,int y)
{
	int xcor,ycor;
	if ((field[y][x] != 'x' && field[y][x] != '0') && field[y][x] != ' ')
	{
		disp[y][x] = field[y][x];
		field[y][x] = ' ';
	}
	else if(field[y][x] == '0' /*|| field[y][x] == ' '*/)
	{
		if (field[y][x] == '0')
		{
			disp[y][x] = field[y][x];
			field[y][x] = ' ';
		
		for(int flag = 1;flag<=8;flag++)
		{
			ycor = y;
			xcor = x;
			if(flag == 1)
			{
				ycor = ycor-1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && field[ycor][xcor] == '0')
				{
					copy(disp,field,xcor,ycor);
				}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && (field[ycor][xcor]>48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 2)
			{
				ycor = ycor - 1;
				xcor = xcor + 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && (field[ycor][xcor] > 48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 3)
			{
				xcor = xcor + 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && (field[ycor][xcor] > 48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 4)
			{
				ycor = ycor + 1;
				xcor = xcor + 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && (field[ycor][xcor] > 48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 5)
			{
				ycor = ycor + 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && (field[ycor][xcor] > 48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 6)
			{
				ycor = ycor + 1;
				xcor = xcor - 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && (field[ycor][xcor] > 48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 7)
			{
				xcor = xcor - 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && (field[ycor][xcor] > 48 && field[ycor][xcor]<58))
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
			else if (flag == 8)
			{
				ycor = ycor - 1;
				xcor = xcor - 1;
				if (((ycor>=0 && xcor>=0) && (ycor<=8 &&xcor<=8)) && field[ycor][xcor] == '0')
				{copy(disp,field,xcor,ycor);}
				else if (((ycor>=0 && xcor>=0) && (ycor<=8 && xcor<=8)) && field[ycor][xcor]>48 && field[ycor][xcor]<58)
				{
					disp[ycor][xcor] = field[ycor][xcor];
					field[ycor][xcor] = ' ';
				}
			}
		}}
	}
}
int checker(char displayarr[][9],char field[][9])
{
	int counter = 0;
	for (int i = 0; i<=8; i++)
	{
		for(int j = 0; j<=8;j++)
		{
			if (displayarr[i][j] == ' ' || (displayarr[i][j] == '#' && field[i][j] == 'x'))
			counter++;
		}
	}
	if (counter == 10)
	return 0;
	else
	return 1;
}


//Program execution starts
int main()
{
	//clrscr();
	start();
	char field[9][9];
	setspace(field);
	setmine(field);
	placeno(field);
	char displayarr[9][9];
	setspace(displayarr);
	int x,y;
	for(;checker(displayarr,field);)
	{
		/*clrscr();
		gotoxy(25,6);cout<<"0 1 2 3 4 5 6 7 8";
		gotoxy(24,7);cout<<"0";
		gotoxy(24,8);cout<<"1";
		gotoxy(24,9);cout<<"2";
		gotoxy(24,10);cout<<"3";
		gotoxy(24,11);cout<<"4";
		gotoxy(24,12);cout<<"5";
		gotoxy(24,13);cout<<"6";
		gotoxy(24,14);cout<<"7";
		gotoxy(24,15);cout<<"8";*/
        cout << "  ";
        for (int i = 0; i < 9; i++) cout << i << ' '; cout << endl;
		for(int i = 0;i<=8;i++)
		{   cout << i << ' ';
			for(int j = 0;j<=8;j++)
			{
				//gotoxy(25+2*j,7+i);
				if (displayarr[i][j] == '0')
				cout<<"."<<" ";
				else
				cout<<displayarr[i][j]<<" ";
                //cout << displayarr[i][j] << ' ';
            }cout << endl;
		}
		cout<<endl;
		cout << "\n\t\t\tEnter 9 to flag.";
		cout<<"\n\t\t\tEnter x-coordinate ";cin>>x;
		if (x==9)
		{
			cout<<"\n\t\t\tThe next move will be flagged.";
			cout<<"\n\t\t\tEnter x-coordinate ";cin>>x;
			cout<<"\t\t\tEnter y-coordinate ";cin>>y;
			displayarr[y][x] = '#';
		}
		else
		{
			cout<<"\t\t\tEnter y-coordinate ";cin>>y;
			if(field[y][x] == 'x')
			{
				cout<<"\t\t\tThat was a mine. YOU LOSE.\n";
				break;
			}
			else if (field[y][x] == ' ')
			cout<<"That box has been revealed already.";
			else if (field[y][x] != 'x' && field[y][x] != ' ')
			{copy(displayarr,field,x,y);}
		}
	}
	if (checker(displayarr,field) == 0)
	cout<<"\n\n\t\t\tYOU WIN!!";
	
    
    return 0;
}