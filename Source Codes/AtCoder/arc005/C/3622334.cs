using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class ABC_088_D
{	
    static int row = 0;
    static int column = 0;

    static int ans = 0;
    static char[,] map;
    static bool[,,] passed; 
    static int sy = 0;
    static int sx = 0;
    static int gy = 0;
    static int gx = 0;
    
    static int[] dirX = new int[4] {-1,0,1,0};
    static int[] dirY = new int[4] {0,-1,0,1};
    static bool isGoal;
	public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        row = int.Parse(str[0]);
        column = int.Parse(str[1]);
      
        map = new char[row+2,column+2];
        passed = new bool[row+2, column+2,3];

        for(int i = 0 ; i < row+2 ; i++)
        {
            for(int j = 0 ; j < column+2 ; j++)
            {
                map[i,j] = '*';
            }
        }
        char[] c;
        for(int i = 1 ; i <= row ; i++)
        {
            c = Console.ReadLine().ToCharArray();
            for(int j = 1 ; j <= column ; j++)
            {
                if(c[j-1] == 's')
                {
                    sy = i;
                    sx = j;
                    map[i,j] = '.';
                }
                else if(c[j-1] == 'g')
                {
                    gy = i;
                    gx = j;
                    map[i,j] = '.';
                }
                else
                {
                map[i,j] = c[j-1];
                }
                    
            }
        }

        BFS(sy,sx);

        if(isGoal) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
    
   
     public static void BFS(int y , int x)
    {
        Queue<int> yPos = new Queue<int>();
        Queue<int> xPos = new Queue<int>();
        Queue<int> crush = new Queue<int>();

        yPos.Enqueue(y);
        xPos.Enqueue(x);
        crush.Enqueue(0);

        int nowY, nowX, c, yy, xx;
        while(yPos.Count > 0 && xPos.Count > 0)
        {
            nowY = yPos.Dequeue();
            nowX = xPos.Dequeue();
            c = crush.Dequeue();
           
            if(nowY == gy && nowX == gx)
            {    
                isGoal = true;
                break;
            }
            if(passed[nowY,nowX,c]) continue;
            passed[nowY,nowX,c] = true;
      
           
            
            
            for(int dir = 0 ; dir < dirX.Length ; dir++){
                yy = nowY+dirY[dir];
                xx = nowX+dirX[dir];
                
                if(map[yy,xx] == '#')
                {
                    if(c < 2){
                        yPos.Enqueue(yy);
                        xPos.Enqueue(xx);
                        crush.Enqueue(c+1);
                    }                
                } 
                else if(map[yy,xx] == '.')
                {
                        yPos.Enqueue(yy);
                        xPos.Enqueue(xx);
                        crush.Enqueue(c);
                }
            }
        }
    }

}