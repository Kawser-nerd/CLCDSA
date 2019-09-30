using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class ABC_007_BFS
{	
    static int row = 0;
    static int column = 0;
    static int sy = 0;
    static int sx = 0;
    static int gy = 0;
    static int gx = 0;
    static int ans = 0;
    static char[,] map;
	public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        row = int.Parse(str[0]);
        column = int.Parse(str[1]);

        map = new char[row,column];

        str = Console.ReadLine().Split(' ');
        sy = int.Parse(str[0])-1;
        sx = int.Parse(str[1])-1;

        str = Console.ReadLine().Split(' ');
        gy = int.Parse(str[0])-1;
        gx = int.Parse(str[1])-1;

        char[] c;
        for(int i = 0 ; i < row ; i++)
        {
            c = Console.ReadLine().ToCharArray();
            for(int j = 0 ; j < column ; j++)
            {
                map[i,j] = c[j];
            }
        }
        BFS(sy,sx);
       
        Console.WriteLine(ans);
    }
    
    public static void BFS(int y , int x)
    {
        Queue<int> yPos = new Queue<int>();
        Queue<int> xPos = new Queue<int>();
        Queue<int> cnt = new Queue<int>();

        yPos.Enqueue(y);
        xPos.Enqueue(x);
        cnt.Enqueue(0);

        int nowY, nowX, nowCnt;

        while(yPos.Count > 0 && xPos.Count > 0)
        {
            nowY = yPos.Dequeue();
            nowX = xPos.Dequeue();
            nowCnt = cnt.Dequeue();

            if(nowY == gy && nowX == gx)
            {
                ans = nowCnt;
                return;
            }
            if(map[nowY+1,nowX] == '.')
            {
                yPos.Enqueue(nowY+1);
                xPos.Enqueue(nowX);
                cnt.Enqueue(nowCnt+1);
                map[nowY+1,nowX] = '-';
            }
            if(map[nowY-1,nowX] == '.')
            {
                yPos.Enqueue(nowY-1);
                xPos.Enqueue(nowX);
                cnt.Enqueue(nowCnt+1);
                map[nowY-1,nowX] = '-';
            }
            if(map[nowY,nowX+1] == '.')
            {
                yPos.Enqueue(nowY);
                xPos.Enqueue(nowX+1);
                cnt.Enqueue(nowCnt+1);
                map[nowY,nowX+1] = '-';
            }
            if(map[nowY,nowX-1] == '.')
            {
                yPos.Enqueue(nowY);
                xPos.Enqueue(nowX-1);
                cnt.Enqueue(nowCnt+1);
                map[nowY,nowX-1] = '-';
            }
        }
    }
}