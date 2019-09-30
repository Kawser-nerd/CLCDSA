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
    static bool[,] passed; 
    static bool isGoal;
    static int max = 0;
	public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        row = int.Parse(str[0]);
        column = int.Parse(str[1]);
      
        map = new char[row+2,column+2];
        passed = new bool[row+2, column+2];

        for(int i = 0 ; i < row+2 ; i++)
        {
            for(int j = 0 ; j < column+2 ; j++)
            {
                map[i,j] = '#';
            }
        }
        char[] c;
        for(int i = 1 ; i <= row ; i++)
        {
            c = Console.ReadLine().ToCharArray();
            for(int j = 1 ; j <= column ; j++)
            {
                map[i,j] = c[j-1];
                if(c[j-1]=='.')
                {
                    max++;
                }
            }
        }
        BFS(1,1);
        if(isGoal) Console.WriteLine(ans);
        else Console.WriteLine("-1");
    }
    
   
     public static void BFS(int y , int x)
    {
        Queue<int> yPos = new Queue<int>();
        Queue<int> xPos = new Queue<int>();
        Queue<int> cnt = new Queue<int>();

        yPos.Enqueue(y);
        xPos.Enqueue(x);
        cnt.Enqueue(1);

        int nowY, nowX, nowCnt;
        while(yPos.Count > 0 && xPos.Count > 0)
        {
            nowY = yPos.Dequeue();
            nowX = xPos.Dequeue();
            nowCnt = cnt.Dequeue();
            
            if(nowY == row && nowX == column)
            {
                isGoal = true;
                ans = max - nowCnt;
            }
            if(map[nowY+1,nowX] != '#' && !passed[nowY+1,nowX])
            {
                yPos.Enqueue(nowY+1);
                xPos.Enqueue(nowX);
                cnt.Enqueue(nowCnt+1);
                passed[nowY+1,nowX] = true;
            }
            if(map[nowY-1,nowX] != '#' && !passed[nowY-1,nowX])
            {
                yPos.Enqueue(nowY-1);
                xPos.Enqueue(nowX);
                cnt.Enqueue(nowCnt+1);
                passed[nowY-1,nowX] = true;
            }
            if(map[nowY,nowX+1] != '#' && !passed[nowY,nowX+1])
            {
                yPos.Enqueue(nowY);
                xPos.Enqueue(nowX+1);
                cnt.Enqueue(nowCnt+1);
                passed[nowY,nowX+1] = true;
            }
            if(map[nowY,nowX-1] != '#' && !passed[nowY,nowX-1])
            {
                yPos.Enqueue(nowY);
                xPos.Enqueue(nowX-1);
                cnt.Enqueue(nowCnt+1);
                passed[nowY,nowX-1] = true;
            }
        }
    }

}