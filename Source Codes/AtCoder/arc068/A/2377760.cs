using System;

namespace ARC068
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var X = long.Parse(Console.ReadLine());
            var ans = X / 11 * 2;
            if (1 <= X % 11 && X % 11 <= 6) ans += 1;
            else if (7 <= X % 11) ans += 2;
            Console.WriteLine(ans);
        }
    }
}