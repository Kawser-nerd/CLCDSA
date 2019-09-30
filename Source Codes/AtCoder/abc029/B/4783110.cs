using System;
class chomad
{
    static void Main(string[] args)
    {
        int x = 0;
        for (int i = 0; i < 12; ++i)
        {
            var n = Console.ReadLine().Contains("r");
            if (n == true) x += 1;
        }
        Console.WriteLine(x);
    }
}