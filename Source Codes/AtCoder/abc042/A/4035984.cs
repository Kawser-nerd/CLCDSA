using System;
using static System.Console;
using System.Linq;

class Program
{
    static void Main()
    {
        int[] input = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

        int count_5 = 0;
        int count_7 = 0;

        foreach (int n in input)
        {
            if (n == 5)
            {
                count_5++;
            }
            else if (n == 7)
            {
                count_7++;
            }
        }

        if (count_5 == 2 && count_7 == 1)
        {
            WriteLine("YES");
        }
        else
        {
            WriteLine("NO");
        }

        ReadKey();
    }
}