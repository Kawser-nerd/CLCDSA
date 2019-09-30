using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ????t?F?[?Y
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);
        int X = int.Parse(input[2]);
        int Y = int.Parse(input[3]);
        string[] xpoint = Console.ReadLine().Split(' ');
        string[] ypoint = Console.ReadLine().Split(' ');

        int maxX = X, minY = Y;
        for (int i = 0; i < N; i++)
        {
            int x = int.Parse(xpoint[i]);
            if (x > maxX)
                maxX = x;
        }

        for (int i = 0; i < M; i++)
        {
            int y = int.Parse(ypoint[i]);
            if (y < minY)
                minY = y;
        }

        bool ret = false;
        // X??Y??Z??S?T??
        for (int z = X + 1; z <= Y; z++)
        {
            if (maxX < z && minY >= z)
            {
                ret = true;
                break;
            }
        }

        //?o??
        //Console.WriteLine(ret);
        if (ret)
            Console.WriteLine("No War");
        else
            Console.WriteLine("War");
    }

}