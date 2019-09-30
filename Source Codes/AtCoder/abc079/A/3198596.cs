using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Console.ReadLine();
        if ((num[0] == num[1] && num[1] == num[2] && num[0] == num[2]) || (num[1] == num[2] && num[2] == num[3] && num[3] == num[1])) Console.WriteLine("Yes");
        else Console.WriteLine("No");
    }
}