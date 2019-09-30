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

        Console.WriteLine(n % 111 == 0 ? (n / 111) * 111 : (n / 111 + 1) * 111);
        Console.ReadLine();
    }
}