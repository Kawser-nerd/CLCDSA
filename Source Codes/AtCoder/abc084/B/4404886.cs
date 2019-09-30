using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        string s = Console.ReadLine();

        bool res = true;

        for (int i = 0; i < a; i++)
            if (s[i] == '-')
                res = false;

        if (s[a] != '-')
            res = false;

        for (int i = a + 1; i < 1 + a + b; i++)
            if (s[i] == '-')
                res = false;

        Console.WriteLine(res ? "Yes" : "No");

    }
}