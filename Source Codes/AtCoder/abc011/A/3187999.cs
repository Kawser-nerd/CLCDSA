using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        if (num == 12) Console.WriteLine(1);
        else Console.WriteLine(num + 1);
    }
}