using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test1
{
    class Program
    {
        static void Main(string[] args)
        {

            int n = int.Parse(Console.ReadLine());
            int[] c = new int[n];
            List<int> array = new List<int>();
            for (int i = 0;i<n;i++)
            {
                c[i] = int.Parse(Console.ReadLine());

                if (i == 0)
                {
                    array.Add(c[i]);
                }

                if (array[array.Count() - 1] < c[i])
                {
                    array.Add(c[i]);
                }
                else
                {
                    for(int j = 0; j < array.Count();j++)
                    {
                        if(c[i] < array[j])
                        {
                            array[j] = c[i];
                            break;
                        }
                    }
                }
            }

            Console.WriteLine(n - array.Count());
        }
    }
}