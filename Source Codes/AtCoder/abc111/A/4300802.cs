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
        string n = Console.ReadLine();

        Console.WriteLine(n.Replace('9', 'b').Replace('1', '9').Replace('b', '1'));
        Console.ReadLine();
    }
}