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
        int[] nmxy = Console.ReadLine().Split(' ').Select(ti => int.Parse(ti)).ToArray();
        int n = nmxy[0];
        int m = nmxy[1];
        int x = nmxy[2];
        int y = nmxy[3];

        int[] xs = Console.ReadLine().Split(' ').Select(ti => int.Parse(ti)).ToArray();
        int[] ys = Console.ReadLine().Split(' ').Select(ti => int.Parse(ti)).ToArray();

        int xm = xs.Max() + 1;
        int ym = ys.Min();

        bool xin = (x < xm) && (xm <= y);
        bool yin = (x < ym) && (ym <= y);

        bool nc = ym >= xm;
        bool nw = nc && xin && yin;

        Console.WriteLine(nw ? "No War" : "War");
        Console.ReadLine();
    }
}