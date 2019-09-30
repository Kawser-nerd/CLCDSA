using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace B
{
    class Program
    {
        static string line ;
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("small.in"))
            {
                using (StreamWriter sw = new StreamWriter("small.out"))
                {
                    int N = int.Parse(sr.ReadLine());
                    for ( int i = 1; i <= N; i ++ )
                    {
                        line = sr.ReadLine();

                        if (line.Length == 1)
                        {
                            int x = int.Parse(line);
                            if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
                                sw.WriteLine("Case #{0}: 1", i);
                            else
                                sw.WriteLine("Case #{0}: 0", i);
                        }
                        else
                        {
                            count = 0;
                            rec(0, 0, 0, 0);

                            sw.WriteLine("Case #{0}: {1}", i, count);
                        }
                    }

                    sr.Close();
                    sw.Close();
                }
            }
        }

        static int count = 0;
        private static void rec(int idx, int last, long temp, long res)
        {
            if (last == 0)
            {
                temp = temp * 10 + (line[idx] - '0');
            }
            else if (last == 1)
            {
                res += temp;
                temp = (line[idx] - '0');
            }
            else if (last == 2)
            {
                res -= temp;
                temp = (line[idx] - '0');
            }

            if (idx == line.Length - 1)
            {
                res += temp;
                if (res % 2 == 0 || res % 3 == 0 || res % 5 == 0 || res % 7 == 0)
                {
                    count++;
                }
            }
            else
            {
                rec(idx + 1, 0, temp, res);
                rec(idx + 1, 1, temp, res);
                rec(idx + 1, 2, temp, res);
            }
        }
    }
}
