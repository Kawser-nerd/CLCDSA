using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrrr
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int X = int.Parse(s[1]);

            List<int> Donut = new  List<int>();
            for(int i=0;i<N;i++){
                Donut.Add(int.Parse(Console.ReadLine()));
            }
            Console.WriteLine(
                (X-Donut.Sum())/Donut.Min() + Donut.Count()
            );
        }
    }
}