using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        if (int.Parse(s) % m1(s) == 0)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }

    static int m1(string s)
    {
        var sum = 0;
        for (int i = 0; i < s.Length; i++)
        {
            sum += s[i] - '0';
        }
        return sum;
    }
}