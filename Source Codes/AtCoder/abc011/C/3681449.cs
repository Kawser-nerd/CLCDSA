using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var ng = new List<int>();
            for (int i = 0; i < 3; i++)
            {
                ng.Add(int.Parse(Console.ReadLine()));
            }
            var count = 100;

            if (ng.All(x => x != n))
            {
                while (n > 0)
                {
                    if (ng.All(x => x != n - 3) && n - 3 >= 0)
                    {
                        n -= 3;
                    }
                    else
                    {
                        if (ng.All(x => x != n - 2) && n - 2 >= 0)
                        {
                            n -= 2;
                        }
                        else
                        {
                            if (ng.All(x => x != n - 1) && n - 1 >= 0)
                            {
                                n -= 1;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    count--;
                }
            }
            

            if (n == 0 && !(count < 0))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}