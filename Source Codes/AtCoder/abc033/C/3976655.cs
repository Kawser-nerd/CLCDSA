using System;
using System.Linq;

namespace ABC033_C
{
    class Program
    {
        static string Solve()
        {
            int count = 0;
            string[] culc = Console.ReadLine().Split('+');
            for (int i = 0; i < culc.Count(); i++)
            {
                if (!culc[i].Contains("0"))
                {
                    count++;
                }
            }
            return count.ToString();
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}