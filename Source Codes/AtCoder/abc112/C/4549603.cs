using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    struct Point
    {
        public int x;
        public int y;
        public int h;
        public Point(int x ,int y,int h)
        {
            this.x = x;
            this.y = y;
            this.h = h;
        }
    }
    static void Main(string[] args)
    {
        int N = int.Parse(System.Console.ReadLine());
        var list = new List<Point>();
        for (int i = 0; i < N; i++)
        {
            string[] temp = System.Console.ReadLine().Split(' ');
            int x = int.Parse(temp[0]);
            int y = int.Parse(temp[1]);
            int h = int.Parse(temp[2]);
            list.Add(new Point(x, y, h));
        }
        for(int cx = 0; cx <= 100; cx++)
        {
            for (int cy = 0; cy <= 100; cy++)
            {
                bool flag=true;
                int ch = -1;
                int hMax = int.MaxValue;
                for(int i = 0; i < N; i++)
                {
                    int x = list[i].x;
                    int y = list[i].y;
                    int h = list[i].h;
                    int d = Math.Abs(cx - x) + Math.Abs(cy - y);
                    if (h > 0)
                    {
                        int buf = h + d;
                        if (ch > 0 && ch != buf)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            ch = buf;
                        }
                    }
                    else
                    {
                        hMax = Math.Min(hMax, d);
                    }
                }
                if (flag && ch <= hMax)
                {
                    Console.WriteLine($"{cx} {cy} {ch}");
                }
            }
        }
    }
}