using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        var a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

        // a[0]?????????
        long num1 = 0;
        long sum = 0;
        for (int i = 0; i < a.Length; i++)
        {
            if (i % 2 == 0)
            {
                if (sum + a[i] <= 0)
                {
                    num1 += (1 - (sum + a[i]));
                    sum = 1;
                }
                else
                {
                    sum += a[i];
                }
            }
            else
            {
                if (sum + a[i] >= 0)
                {
                    num1 += (sum + a[i]) - (-1);
                    sum = -1;
                }
                else
                {
                    sum += a[i];
                }
            }
        }

        // a[0]?????????
        long num2 = 0;
        sum = 0;
        for (int i = 0; i < a.Length; i++)
        {
            if (i % 2 == 1)  // ???????
            {
                if (sum + a[i] <= 0)
                {
                    num2 += (1 - (sum + a[i]));
                    sum = 1;
                }
                else
                {
                    sum += a[i];
                }
            }
            else
            {
                if (sum + a[i] >= 0)
                {
                    num2 += (sum + a[i]) - (-1);
                    sum = -1;
                }
                else
                {
                    sum += a[i];
                }
            }
        }
        
        Console.WriteLine(Math.Min(num1, num2));

    }
}