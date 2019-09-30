using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("B-small.in"))
            {
                using (StreamWriter sw = new StreamWriter("B-small.out"))
                {
                    int C = int.Parse(sr.ReadLine());
                    for (int z = 1; z <= C; z++)
                    {
                        string[] elem = sr.ReadLine().Split(' ');
                        int N = int.Parse(elem[0]);
                        int M = int.Parse(elem[1]);
                        int A = int.Parse(elem[2]);

                        bool found = false;
                        for (int x1 = 0; x1 <= N && !found; x1++)
                        {
                            for (int y1 = 0; y1 <= M && !found; y1++)
                            {
                                for (int x2 = 0; x2 <= N && !found; x2++)
                                {
                                    for (int y2 = 0; y2 <= M && !found; y2++)
                                    {
                                        if (Area2(0, 0, x1, y1, x2, y2) == A)
                                        {
                                            found = true;
                                            sw.WriteLine("Case #{0}: {1} {2} {3} {4} {5} {6}", z, 0, 0, x1, y1, x2, y2);
                                            goto finish;
                                        }
                                    }
                                }
                            }   
                        }
                    finish :
                        if (!found) sw.WriteLine("Case #{0}: IMPOSSIBLE", z);                        
                    }
                    sw.Close(); sr.Close();
                }
            }
        }

        static long Area2(long ax, long ay, long bx, long by, long cx, long cy)
        {
            return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
        }
    }
}
