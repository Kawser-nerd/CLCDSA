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
        int a = int.Parse(ReadLine());
        int b = int.Parse(ReadLine());
        int h = int.Parse(ReadLine());

        WriteLine((a + b) * h / 2);

        ReadKey();
    }
}