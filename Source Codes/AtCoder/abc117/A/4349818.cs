using System;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            float t, x;
            float ans;
            string[] str = Console.ReadLine().Split(' ');
            t = float.Parse(str[0]);
            x = float.Parse(str[1]);
            ans = t / x;
            Console.WriteLine(ans);
        }
    }
}