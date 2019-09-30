using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                max = Math.Max(max, a[i]);
            }
            int[] ls = new int[max + 1];
            for (int i = 0; i < n; i++)
            {
                ls[a[i]]++;
            }
            if(max % 2 ==0)
            {
                for (int i = 0; i < max/2; i++)
                {
                    if(ls[i]>0)
                    {
                        Console.WriteLine("Impossible");
                        return;
                    }
                }
                if (ls[max / 2] != 1)
                {
                    Console.WriteLine("Impossible");
                    return;
                }
                for (int i = max/2 + 1; i <= max; i++)
                {
                    if(ls[i]<2)
                    {
                        Console.WriteLine("Impossible");
                        return;
                    }
                }
            }
            else
            {
                for (int i = 0; i < (max + 1)/ 2; i++)
                {
                    if (ls[i] > 0)
                    {
                        Console.WriteLine("Impossible");
                        return;
                    }
                }
                if (ls[(max + 1) / 2] != 2)
                {
                    Console.WriteLine("Impossible");
                    return;
                }
                for (int i = (max + 1) / 2 + 1; i <= max; i++)
                {
                    if (ls[i] < 2)
                    {
                        Console.WriteLine("Impossible");
                        return;
                    }
                }
            }
            Console.WriteLine("Possible");
        }
    }
}