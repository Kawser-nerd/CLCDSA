using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int n = int.Parse(str[0]);
        int a = int.Parse(str[1]);
        int b = int.Parse(str[2]);
        int t = 0;
        string s;
        int d;
        for (int i = 0; i < n; i++)
        {
            str = Console.ReadLine().Split(' ');
            s = str[0];
            d = int.Parse(str[1]);
            d = (d < a) ? a : (d > b) ? b : d;
            d = (s == "East") ? d : -d;
            t += d;
        }
        if (t == 0)
            Console.WriteLine(0);
        else
        {
            Console.Write((t > 0) ? "East " : "West ");
            Console.Write(Math.Max(t, -t));
            Console.WriteLine();
        }
    }
}