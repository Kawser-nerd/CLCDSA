using System;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var nums = Array.ConvertAll(ReadLine().Split(' '), decimal.Parse);
        var di = (decimal)(Math.Pow(10, 9) + 7);
        WriteLine((((nums[0]*nums[1])%di)*(nums[2]%di))%di);
    }
}