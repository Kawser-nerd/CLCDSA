using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejamc
{
    class Program
    {
        static void Main(string[] args)
        {
            int r, n, m, k;
            Console.ReadLine();
            string[] data = Console.ReadLine().Split(' ');
            r = int.Parse(data[0]);
            n = int.Parse(data[1]);
            m = int.Parse(data[2]);
            k = int.Parse(data[3]);

            Console.WriteLine("Case #1:");
            for (int test = 0; test < r; test++)
            {
                int[] results = new int[k];
                data = Console.ReadLine().Split(' ');
                for (int i = 0; i < k; i++)
                {
                    results[i] = int.Parse(data[i]);
                }
                bool found = false;
                for (int n1 = 2; n1 <= m; n1++)
                {
                    if (found)
                        break;
                    for (int n2 = 2; n2 <= m; n2++)
                    {
                        if (found)
                            break;
                        for (int n3 = 2; n3 <= m; n3++)
                        {
                            bool currentResult = true;
                            for (int i = 0; i < k; i++)
                            {
                                if (results[i] == 1 || results[i] == n1 || results[i] == n2 || results[i] == n3 ||
                                    results[i] == n1 * n2 || results[i] == n1 * n3 || results[i] == n2 * n3 || results[i] == n1 * n2 * n3)
                                    continue;
                                else
                                {
                                    currentResult = false;
                                    break;
                                }
                            }
                            if (currentResult)
                            {
                                Console.WriteLine("{0}{1}{2}", n1, n2, n3);
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
            

        }
    }
}
