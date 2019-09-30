using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main
{
    class Program
    {
        static void Main(string[] arg)
        {

            //int[] line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int n = int.Parse(Console.ReadLine());
            var list = new List<int>();

            for(int i = 0;i < n; i++)
            {
                int p = int.Parse(Console.ReadLine());
                list.Add(p);
            }
            int sum = list.Sum();
            sum -= list.Max() / 2;
            Console.WriteLine(sum);

            Console.ReadLine();

        }
    }
}