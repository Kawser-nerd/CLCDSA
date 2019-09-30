using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NK = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int max = a[0];
        int difgcd = 0;
        for (int i = 1; i < a.Length; i++)
        {
            max = Math.Max(max,a[i]);
            difgcd = Gcd(Math.Abs(a[i] - a[i - 1]), difgcd);
        }
        string res = "POSSIBLE";
        if(difgcd == 0)
        {
            if (NK[1] == max) Console.WriteLine(res);
            else Console.WriteLine("IM" + res);
        }
        else if ((max >= NK[1] && (max - NK[1]) % difgcd == 0))
        {
            Console.WriteLine(res);
        }
        else
        {
            Console.WriteLine("IM" + res);
        }
    }
    public static int Gcd(int a, int b)
    {
        if (a < b)
            return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}