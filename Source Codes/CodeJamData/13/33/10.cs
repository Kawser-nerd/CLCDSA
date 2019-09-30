using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs, System.Text.Encoding.Default);
            sr.BaseStream.Position = 0;
            StreamWriter sw = new StreamWriter("output.txt");

            int T = int.Parse(sr.ReadLine());
            for (int Ti = 0; Ti < T; Ti++)
            {
                int N = int.Parse(sr.ReadLine());

                int[] day = new int[N];
                int[] num = new int[N];
                int[] point_a = new int[N];
                int[] point_b = new int[N];
                int[] pow = new int[N];
                int[] delta_day = new int[N];
                int[] delta_point = new int[N];
                int[] delta_pow = new int[N];

                for (int Ni = 0; Ni < N; Ni++)
                {
                    string[] str = sr.ReadLine().Split(' ');
                    day[Ni] = int.Parse(str[0]);
                    num[Ni] = int.Parse(str[1]);
                    point_a[Ni] = int.Parse(str[2]);
                    point_b[Ni] = int.Parse(str[3]);
                    pow[Ni] = int.Parse(str[4]);
                    delta_day[Ni] = int.Parse(str[5]);
                    delta_point[Ni] = int.Parse(str[6]);
                    delta_pow[Ni] = int.Parse(str[7]);
                }
                int TN = 0;
                for (int i = 0; i < N; i++)
                {
                    TN += num[i];
                }
                int[] RTday = new int[TN];
                int[] RTpoint_a = new int[TN];
                int[] RTpoint_b = new int[TN];
                int[] RTpow = new int[TN];


                int ii = 0;
                for (int Ni = 0; Ni < N; Ni++)
                {
                    for(int i=0;i<num[Ni];i++)
                    {
                        RTday[ii] = day[Ni] + delta_day[Ni] * i;
                        RTpoint_a[ii] = point_a[Ni] + delta_point[Ni] * i;
                        RTpoint_b[ii] = point_b[Ni] + delta_point[Ni] * i;
                        RTpow[ii] = pow[Ni] + delta_pow[Ni] * i;
                        ii++;
                    }
                }

                int[] nnn = new int[TN];
                for (int i = 0; i < TN; i++)
                {
                    for (int j = 0; j < TN-1; j++)
                    {
                        if (RTday[j] > RTday[j+1])
                        {
                            int temp = RTday[j];
                            RTday[j] = RTday[j + 1];
                            RTday[j + 1] = temp;
                            
                            temp = RTpoint_a[j];
                            RTpoint_a[j] = RTpoint_a[j + 1];
                            RTpoint_a[j + 1] = temp;

                            temp = RTpoint_b[j];
                            RTpoint_b[j] = RTpoint_b[j + 1];
                            RTpoint_b[j + 1] = temp;

                            temp = RTpow[j];
                            RTpow[j] = RTpow[j + 1];
                            RTpow[j + 1] = temp;
                        }
                    }
                } // sort all

                int[] H = new int[2000000];
                int count = 0;
                int ddd = 0;
                // run
                bool go = true;
                while (go)
                {
                    go = false;
                    for (int i = 0; i < TN; i++)
                    {
                        if (ddd < RTday[i])
                        {
                            go = true;
                        }
                    }
                    for (int i = 0; i < TN; i++)
                    {
                        if (ddd == RTday[i])
                        {
                            bool OK = false;
                            for (int p = RTpoint_a[i]; p < RTpoint_b[i]; p++)
                            {
                                if (H[p + 1000000] < RTpow[i])
                                {
                                    OK = true;
                                }
                            }
                            if (OK)
                            {
                                count++;
                            }
                        }

                    }
                    for (int i = 0; i < TN; i++)
                    {
                        if (ddd == RTday[i])
                        {
                            for (int p = RTpoint_a[i]; p < RTpoint_b[i]; p++)
                            {
                                if (H[p + 1000000] < RTpow[i])
                                {
                                    H[p + 1000000] = RTpow[i];
                                }
                            }
                        }
                    }
                    ddd++;
                }


                sw.WriteLine("Case #" + (Ti + 1) + ": " + count.ToString());
            }
            sr.Dispose();
            sw.Dispose();
        }
        static bool isP(int n)
        {
            int t = 0;
            int i = 1;
            while (t <= n)
            {
                t += i;
                i++;
                if (t > n)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
