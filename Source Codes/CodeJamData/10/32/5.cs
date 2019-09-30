using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2010
{
    class R1C_B
    {
        public static void Main(String[] args)
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\B.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\B.out"))
                {
                    int cs = int.Parse(sr.ReadLine());
                    for (int ci = 0; ci < cs; ci++)
                    {
                        //int n = int.Parse(sr.ReadLine());
                        string[] strs = sr.ReadLine().Split(' ');
                        long l = int.Parse(strs[0]);
                        long p = int.Parse(strs[1]);
                        long c = int.Parse(strs[2]);
                        int v = (int)Math.Ceiling(-1e-9 + Math.Log((int)Math.Ceiling(-1e-9 + Math.Log((double)p / (double)l) / Math.Log(c))) / Math.Log(2));
                        int v2 = (int)Math.Ceiling(Math.Log((int)Math.Ceiling(Math.Log((double)p / (double)l) / Math.Log(c))) / Math.Log(2));
                        if (v != v2)
                        {
                            Console.WriteLine(l + " " + p + " " + c + " " + (double)p / l + " " + v2 + " " + v + " " + (ci+1));
                            //return;
                        }
                        //Console.WriteLine("Case #" + (ci + 1) + ": " + v2);
                        sw.WriteLine("Case #" + (ci + 1) + ": " + v2);
                    }
                }
            }
        }
        static void hh()
        {
        }
    }
}
