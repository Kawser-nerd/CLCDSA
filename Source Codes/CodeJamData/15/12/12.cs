using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace R1_B
{
    class Program
    {
        static UInt64 calculate(UInt64 t, UInt64[] a, UInt64 B)
        {
            UInt64 result = 0;
            for (int i = 0; i < (int)B; i++)
                result += (t % a[i] == 0 ? t / a[i] : t / a[i] + 1);

            return result;
        }
        static void Main(string[] args)
        {
            string fin = "B-large.in";
            //"input.txt";
            string fout = "B.out";
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);
            int T = Int32.Parse(sr.ReadLine());
            int ans = 0;
            UInt64[] a = new UInt64[1000];
            for (int i = 1; i <= T; i++)
            {
                string txt = sr.ReadLine();
                UInt64 B = UInt64.Parse(txt.Split(' ')[0]);
                UInt64 N = UInt64.Parse(txt.Split(' ')[1]);
                txt = sr.ReadLine();
                string[] mk = txt.Split(' ');
                for (int j = 0; j < (int) B; j++)
                    a[j] = UInt64.Parse(mk[j]);

                if (N <= B) ans = (int) N;
                else
                {
                    UInt64 time = 100000000000;
                    UInt64 left = 0;
                    UInt64 right = time;
                    UInt64 r1;
                    UInt64 r2;
                    while (true)
                    {
                        r1 = calculate(time, a, B);
                        r2 = calculate(time-1, a, B);
                        if (r1 >= N && r2 < N)
                            break;

                        if (r2 >= N)
                        {
                            right = time;
                            time = (time + left) / 2;
                        }

                        else
                        {
                            left = time;
                            time = (time + right) / 2;
                        }
                    }

                        int k = (int)(N - r2);
                        int k1 = 0;
                        for (int j = 0; j < (int)B; j++)
                        {
                            if ((time - 1) % a[j] == 0) k1++;
                            if (k == k1)
                            { ans = j + 1; break; }
                        }
                    
                }
                sw.WriteLine(string.Format("Case #{0}: {1}", i, ans));
            }
            sr.Close();
            sw.Close();
        }
    }
}
