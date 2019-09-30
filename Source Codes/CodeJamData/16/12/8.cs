using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int C = 1; C <= T; C++)
            {
                Console.Write("Case #" + C + ":");
                int N = int.Parse(Console.ReadLine());
                SortedSet<int> set = new SortedSet<int>();
                for (int i = 0; i < 2 * N - 1; i++)
                {
                    string line = Console.ReadLine();
                    foreach (var s in line.Split(null))
                    {
                        int v = int.Parse(s);
                        if (set.Contains(v))
                            set.Remove(v);
                        else
                            set.Add(v);
                    }
                }
                foreach (var s in set)
                {
                    Console.Write(" " + s);
                }
                Console.WriteLine();
            }
        }
    }
}
