using System;
using System.Linq;

namespace ABC104_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var flag1 = s.Contains("A") && s.Where(x => x == 'C').Count() == 1 && s[1] != 'C' && s[s.Length - 1] != 'C';
            if (!flag1)
            {
                Console.WriteLine("WA");
                return;
            }

            s = s.Replace("A", "");
            s = s.Replace("C", "");

            var flag2 = true;
            for (int i = 0; i < s.Length; i++)
            {
                if (char.IsUpper(s[i])) flag2 = false;
            }
            Console.WriteLine(flag2 ? "AC" : "WA");

        }
    }
}