using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var a = s[0];
        var b = s[2];

        if (a == 'H')
        {
            Console.WriteLine(b);
        }
        else
        {
            Console.WriteLine(b == 'H' ? 'D' : 'H');
        }
    }
}