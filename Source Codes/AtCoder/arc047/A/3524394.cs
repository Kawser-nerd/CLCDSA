using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var str = ReadLine();
        var counter = 1;
        var result = 0;
        for(var i = 0; i < input[0]; i++)
        {
            switch (str[i])
            {
                case '+':
                    counter++;
                    break;
                case '-':
                    counter--;
                    break;
            }
            if (counter > input[1]) { result++;counter = 1; }
        }
        WriteLine(result);
    }
}