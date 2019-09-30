using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().ToCharArray();
        var t = Console.ReadLine().ToCharArray();

        Array.Sort(s);
        Array.Sort(t, (a, b) => b - a);

        if (0 > new string(s).CompareTo(new string(t)))
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}