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
        int input = int.Parse(ReadLine());
        WriteLine(input * (input + 1) / 2);
        ReadKey();
    }
}