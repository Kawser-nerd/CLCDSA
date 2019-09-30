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
            int answer = int.MaxValue;
            int[] nt = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            int n = nt[0];
            int t = nt[1];

            var cLine = new List<int>();
            var tLine = new List<int>();
            for (int i = 0; i < n; i++)
            {
                int[] ct = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                cLine.Add(ct[0]);
                tLine.Add(ct[1]);

            }
            for(int j = 0;j < n;j++)
            {

                if (tLine[j] > t)
                {
                    continue;
                }
                if (cLine[j] < answer)
                {
                    answer = cLine[j];
                }
            }
            if(answer == int.MaxValue)
            {
                Console.WriteLine("TLE");
            }
            else
            {
                Console.WriteLine(answer);
            }

            

            
            Console.ReadLine();

        }
    }
}