using System;

namespace ABC059B
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();

            char before = '0';
            char grand_before = '0';

            for (int i = 0; i < s.Length; i++)
            {
                char current = s[i];
                if (before == current)
                {
                    Console.WriteLine("" + i + " " + (i + 1));
                    return;
                }
                if (grand_before == current)
                {
                    Console.WriteLine("" + (i - 1) + " " + (i + 1));
                    return;
                }

                grand_before = before;
                before = current;
            }
            Console.WriteLine("-1 -1");
        }
    }
}