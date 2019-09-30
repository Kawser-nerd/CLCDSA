using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {

        static void Main(string[] args)
        {
            //StreamReader sr=new StreamReader(File.Open("B-small-attempt0.in",FileMode.Open));
            decimal []r;
            decimal []c;
            int tt= int.Parse(Console.ReadLine());
            decimal x,v;
            StreamWriter s=new StreamWriter(File.Open("o.out", FileMode.Create));
            for(int cc=1; cc <= tt; cc++)
            {
                string[] ss=Console.ReadLine().Split(new char[] { ' ' });
                int n = int.Parse(ss[0]);
                v = decimal.Parse(ss[1]);
                x = decimal.Parse(ss[2]);

                r = new decimal[n];
                c = new decimal[n];
                for(int i=0; i < n; i++) {
                    ss = Console.ReadLine().Split(new char[] { ' ' });
                    r[i] = decimal.Parse(ss[0]);
                    c[i] = decimal.Parse(ss[1]);
                }
                
                bool lose=false;
                decimal ans=0;

                if(n == 1)
                {
                    if(c[0] == x)
                        ans = v / r[0];
                    else
                        lose = true;
                }
                else
                {
                    if((c[0] - x) == 0 && (c[1] - x) == 0)
                    {
                        ans = v / (r[0] + r[1]);
                    }
                    else
                    if((c[0] - x) == 0)
                    {

                        ans = v / r[0];
                    }
                    else if((c[1] - x) == 0)
                    {
                        ans = v / r[1];
                    }
                    else if((c[0] - x) * (c[1] - x) < 0)
                    {
                        decimal rate=(c[0] - x) / (x - c[1]);
                        ans = Math.Max(v * (rate / (rate + 1)) / r[1], v * (1 / (rate + 1)) / r[0]);
                    }
                    else
                    {
                        lose = true;
                    }
                }

                if(lose)
                {
                    Console.WriteLine("Case #" + cc.ToString() + ": IMPOSSIBLE");
                    s.WriteLine("Case #" + cc.ToString() + ": IMPOSSIBLE");
                }
                else
                {
                    Console.WriteLine("Case #" + cc.ToString() + ": " + ans.ToString("0.########"));
                    s.WriteLine("Case #" + cc.ToString() + ": " + ans.ToString("0.########"));
                }
            }
        }
    }
}
