using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CandySplitting
{
    class CandySplitting
    {
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= cases; i++)
            {
                Console.Write(string.Format("Case #{0}: ", i));
                new CandySplitting().Solve();
            }
        }

        private void Solve()
        {
            var n = int.Parse(Console.ReadLine());
            var items = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToArray();

            var x = 0;
            for (int i = 0; i < items.Length; i++)
                x = x ^ items[i];

            if (x == 0)
                Console.WriteLine(items.Sum() - items.Min());
            else
                Console.WriteLine("NO");
        }
    }
}
