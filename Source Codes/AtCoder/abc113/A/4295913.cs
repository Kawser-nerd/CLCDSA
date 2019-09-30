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
        string[] line = Console.ReadLine().Split(' ');
        int x = int.Parse(line[0]);
        int y = int.Parse(line[1]);

        Console.WriteLine(x + y / 2);
        Console.ReadLine();
    }
}