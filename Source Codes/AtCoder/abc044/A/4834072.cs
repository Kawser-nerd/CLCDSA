using System;
using static System.Console;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(ReadLine());
        int k = int.Parse(ReadLine());
        int x = int.Parse(ReadLine());
        int y = int.Parse(ReadLine());

        if (n <= k)
        {
            WriteLine(n * x);
        }
        else
        {
            WriteLine(k * x + (n - k) * y);
        }
        ReadKey();
    }
}