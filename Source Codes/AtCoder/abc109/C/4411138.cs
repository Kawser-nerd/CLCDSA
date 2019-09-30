using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int X = int.Parse(input[1]);
        input = Console.ReadLine().Split(' ');

        // X??????????????
        List<int> list = new List<int>() { X };
        for(int i=0; i<N; i++)
        {
            list.Add(int.Parse(input[i]));
        }

        list.Sort();

        // ???????
        List<int> gcdList = new List<int>();
        for(int i=1; i<list.Count; i++)
        {
            int dis = list[i] - list[i - 1];
            gcdList.Add(dis);
        }

        // gcd?????????????????
        int gcd = gcdList[0];
        for (int i = 1; i < gcdList.Count; i++ )
        {
            gcd = calculationGCD(gcd, gcdList[i]);
        }

        Console.WriteLine(gcd);
        //if (ret)
        //    Console.WriteLine("Yes");
        //else
        //    Console.WriteLine("No");
    }

    static int calculationGCD(int a, int b)
    {
        if(a%b == 0)
        {
            return b;
        }
        else
        {
            return calculationGCD(b, a % b);
        }
    }

}