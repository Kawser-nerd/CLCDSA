using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    public static void Main(string[] args)
    {
        var S = Console.ReadLine();
        var n_0 = S.Count(n => n == '0');
        var n_1 = S.Count(n => n == '1');
        Console.WriteLine(S.Count() - Math.Abs(n_0 - n_1));
    }
}