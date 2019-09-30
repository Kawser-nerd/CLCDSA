using System;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var s = Console.ReadLine();
            if (s.Length % 2 == 0) s = s.Substring(0, s.Length - 2);
            else s = s.Substring(0, s.Length - 1);
            while (s.Substring(0, s.Length / 2) != s.Substring(s.Length / 2))
            {
                s = s.Substring(0, s.Length - 2);
            }
            Console.WriteLine(s.Length);
        }
    }
}