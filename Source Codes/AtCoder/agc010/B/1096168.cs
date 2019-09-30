using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = long.Parse(Console.ReadLine());
            var temp = Console.ReadLine().Split(' ').ToList();
            var list = temp.Select(ln => long.Parse(ln)).ToList();

            long unit_sum = n * (n + 1) / 2;
            if (list.Sum() % unit_sum != 0) { Console.WriteLine("NO"); }
            else
            {
                int n_addition = (int)(list.Sum() / unit_sum);

                var diff = new List<int>();
                for (int i = 0; i < list.Count - 1; i++)
                {
                    diff.Add((int)(list[i + 1] - list[i]));
                }
                diff.Add((int)(list[0] - list[list.Count - 1]));

                var diff2 = diff.Select(ln => ln - n_addition);

                if (diff2.All(ln => (ln % n == 0) && (ln <= 0)) && diff2.Sum() == -n * n_addition) { Console.WriteLine("YES"); }
                else { Console.WriteLine("NO"); }
            }
        }
    }
}