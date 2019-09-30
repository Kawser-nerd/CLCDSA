using System;

class Atcoder65
{
    public static void Main()
    {
        string top = Console.ReadLine();
        string bot = Console.ReadLine();

        char top0 = top[0];
        char top1 = top[1];
        char top2 = top[2];

        char bot0 = bot[0];
        char bot1 = bot[1];
        char bot2 = bot[2];

        if (top0 == bot2 && top1 == bot1 && top2 == bot0)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
}