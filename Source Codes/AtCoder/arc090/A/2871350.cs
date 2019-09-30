using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static int n;
    static int[,] map;
    static void Main()
    {
        n = int.Parse(Console.ReadLine());
        int[][] a = Enumerable.Repeat(0, 2).Select(_ => Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToArray();
        map = new int[2, n];
        int[] dx = { 1, 0 };
        int[] dy = { 0, 1 };

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for(int k = 0; k < 2; k++){
                    int x = j - dy[k];
                    int y = i - dx[k];
                    int dv = 0;
                    if(x >= 0 && y >= 0)
                    {
                        dv = map[y, x];
                    }
                    map[i, j] = Math.Max(a[i][j] + dv, map[i, j]);
                }
            }
        }
        Console.WriteLine(map[1, n - 1]);
    }
    static void Show()
    {
        Console.WriteLine("----");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Console.Write(map[i, j] + " ");
            }
            Console.Write('\n');
        }
        Console.WriteLine("----");
    }
}