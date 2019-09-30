using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToDouble(ReadLine());
        var result = (int)num-1;
        for(var i=2;i<=Math.Floor(Math.Pow(num, (double)1 / 2)); i++)
        {
            var counter = 0;
            while (num - i*(counter+1) >= 0)
            {
                counter++;
            }
            var n = Math.Abs(counter - i) + num-counter*i;
            if (result > n) result = (int)n;
        }
        WriteLine(result);
       
    }
}