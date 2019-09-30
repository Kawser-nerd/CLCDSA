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
        int n = int.Parse(Console.ReadLine());

        string[] line = Console.ReadLine().Split(' ');
        int t = int.Parse(line[0]);
        int a = int.Parse(line[1]);

        Func<int, double> temp = (temp_a) => t - temp_a * 0.006d;
        Func<int, double> abs = (abs_a) => Math.Abs(a - temp(abs_a));

        int[] H = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

        int index = 0;
        double min = double.MaxValue;
        for(int i = 0; i < H.Length; i++)
        {
            if(IsMin(ref min, abs(H[i])))
            {
                index = i;
            }
        }

        Console.WriteLine(index + 1);
        Console.ReadLine();
    }

    static bool IsMin(ref double min, double value)
    {
        if (min > value)
        {
            min = value;
            return true;
        }
        else
        {
            return false;
        }
    }
}