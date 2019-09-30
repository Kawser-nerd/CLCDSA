using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C099
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            int[] c = new int[N+1];

            List<int> x = new List<int>();
            int z = 1;
            x.Add(z);
            while (true)
            {
                z *= 6;
                if (z > N) break;
                x.Add(z);
            }
            z = 1;
            while (true)
            {
                z *= 9;
                if (z > N) break;
                x.Add(z);
            }


            int counter = 1;
            List<int> current = new List<int>();
            current.Add(0);

            while (c[N] == 0){
                List<int> next = new List<int>();
                foreach (int n in current)
                {
                    foreach (int m in x)
                    {
                        if (n + m > N) continue;
                        if (c[n + m] == 0)
                        {
                            c[n + m] = counter;
                            next.Add(n + m);
                        }
                    }
                }
                counter++;
                current = next;
            }
            Console.WriteLine(c[N]);
        }

    }
}