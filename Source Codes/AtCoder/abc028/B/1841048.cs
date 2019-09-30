using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        string s = Console.ReadLine();
        Console.WriteLine("{0} {1} {2} {3} {4} {5}",s.Count(c => c == 'A'), s.Count(c => c == 'B'), s.Count(c => c == 'C'), s.Count(c => c == 'D'),s.Count(c => c == 'E'), s.Count(c => c == 'F'));
    }
}