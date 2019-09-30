using System;

namespace To_Infinity
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var k = long.Parse(Console.ReadLine());

            var count = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (1 == int.Parse(s[i].ToString()))
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count >= k)
            {
                Console.WriteLine(1);
                return;
            }
            if (1 == k)
            {
                Console.WriteLine(s[0]);
                return;
            }
            for (int i = 0; i < s.Length; i++)
            {
                if (1 != int.Parse(s[i].ToString()))
                {
                    Console.WriteLine(s[i]);
                    return;
                }
            }
        }
    }
}