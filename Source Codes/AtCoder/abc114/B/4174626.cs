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

        string s = Console.ReadLine();


        int d = int.MaxValue;

        for (int i = 0; i <= s.Length - 3; i++)
        {
            int r = int.Parse(s.Substring(i, 3));

            d = Math.Min(d, Math.Abs(753 - r));
        }


        Console.WriteLine(d);
        Console.ReadLine();
    }
}