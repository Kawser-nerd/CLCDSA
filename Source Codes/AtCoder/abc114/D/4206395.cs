using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Numerics;

public class Program
{
    public static void Main(string[] args)
    {
        //string[] line = Console.ReadLine().Split(' ');
        //Divisor(2141231);

        int n = int.Parse(Console.ReadLine());

        e = new int[n + 1];

        for (int i = 2; i <= n; i++)
        {
            int cur = i;
            for (int j = 2; j <= i; j++)
            {
                while(cur % j == 0)
                {
                    e[j]++;
                    cur = cur / j;
                }
            }
        }

        int r = num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) + num(5) * (num(5) - 1) * (num(3) - 2) / 2;
        Console.WriteLine(r);
        Console.ReadLine();
    }

    static int[] e;
    public static int num(int m)
    {
        return e.Where(i => i >= m - 1).Count();
    }
}