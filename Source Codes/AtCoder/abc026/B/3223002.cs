using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        double result = 0;
        var rs = new double[num];
        for(var i = 0; i < num; i++)
        {
            rs[i] = ToDouble(ReadLine());
        }
        Array.Sort(rs);
        var scope = num%2==1?1:-1;
        for(var i = 0; i < num; i++)
        {
            result += scope * rs[i] * rs[i] * Math.PI;
            scope *= -1;
        }
        WriteLine(result);
    }
}