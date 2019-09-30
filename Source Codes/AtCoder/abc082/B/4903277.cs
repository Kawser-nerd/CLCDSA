using System;
using System.Linq;

namespace B___Two_Anagrams
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var t = Console.ReadLine();
            var length = Math.Max(s.Length, t.Length);

            var s_arr = new string(s.OrderBy(x => x).ToArray()).PadRight(length);
            var t_arr = new string(t.OrderByDescending(x => x).ToArray()).PadRight(length);

            for (int i = 0; i < length; i++)
            {
                if (s_arr[i] != t_arr[i])
                {
                    Console.WriteLine(s_arr[i] < t_arr[i] ? "Yes" : "No");
                    return;
                }
            }
            Console.WriteLine("No");
        }
    }
}