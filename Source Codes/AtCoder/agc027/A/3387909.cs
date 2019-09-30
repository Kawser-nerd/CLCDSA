using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class Program
{
    static void Main(string[] args)
    {
        string[] s = Console.ReadLine().Split(' ');
        string N = s[0];
        long x = long.Parse(s[1]);
        long[] a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

        long temp = 0;
        Array.Sort(a);
        if(a.Sum() < x)
        {
            Console.WriteLine(a.Length - 1);
            return;
        }

        for(long i = 0; i < a.Length; i++)
        {
            x -= a[i];

            //temp = i;
            if(x < 0)
            {
                break;
            }
            temp++;
        }
        Console.WriteLine(temp);
    }
}