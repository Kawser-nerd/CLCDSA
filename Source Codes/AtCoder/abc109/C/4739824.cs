using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public static class Program
{
    static void Main()
    {
        string[] line1 = Console.ReadLine().Split(' ');
        int N = int.Parse(line1[0]);
        int X = int.Parse(line1[1]);
        string[] line2 = Console.ReadLine().Split(' ');
        int[] place = new int[N];
        int[] distance = new int[N];
        for (int i = 0; i < N; i++)
        {
            place[i] = int.Parse(line2[i]);
            distance[i] = Math.Abs(place[i] - X);
        }
        int result = distance[0];
        for(int i = 1; i < distance.Length; i++)
        {
            result = gcd(result, distance[i]);
        }
        Console.WriteLine(result);
    }
    static int gcd(int x, int y)
    {
        if (x == 0) return y;
        if (y == 0) return x;
        if (x < y) return gcd(x, y % x);
        else return gcd(x % y, y);
    }
}