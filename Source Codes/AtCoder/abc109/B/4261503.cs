using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B.Shiritori
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var values = new List<string>();
            bool flg = true;

            for (int i = 0; i < N; i++)
                values.Add(Console.ReadLine());

            if (values.GroupBy(x => x).SelectMany(g => g.Skip(1)).Any())
                flg = false;


            for (int i = 1; i < values.Count; i++)
            {
                if (values[i].ToCharArray().First() != values[i - 1].ToCharArray().Last())
                {
                    flg = false;
                    break;
                }
            }

            if (flg)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}