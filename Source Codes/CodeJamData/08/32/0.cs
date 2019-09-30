using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{

    public class UglyNumbers
    {
        private static string inputFile = "B1.in";
        private static string outputFile = "output.txt";
        private static FileStream fin;
        private static StreamReader sr;
        private static FileStream fout;
        private static StreamWriter sw;

        private static string number;
        private static long sol;
        private static int[] sign;
        private static int n;

        private static long[, , , ,] d;

        private static void test()
        {
            string tmp = "";
            long sum = 0;
            int k = 0;
            while (k < number.Length)
            {
                int znak = sign[k];
                tmp = "" + number [k];
                while (sign[k + 1] == 0)
                {
                    tmp += number[k + 1];
                    k++;
                }
                sum += Int64.Parse(tmp) * znak;
                k++;
            }


            if (((sum % 2) == 0) || ((sum % 3) == 0) || ((sum % 5) == 0) || ((sum % 7) == 0))
                sol++;
        }

        private static void countSmall(int k)
        {
            if (k == number.Length)
                test();
            else
            {
                for (int i = -1; i <= 1; i++)
                {
                    sign[k] = i;
                    countSmall(k + 1);
                }
            }
        }

        private static int ostatak(string m, int k)
        {
            int n = m.Length;
            int ost = 0;
            for (int i = n - 1; i >= 0; i--)
                ost = (ost * 10 + (m[n - 1 - i] - '0')) % k;
            return ost;
        }

        private static void count()
        {
            n = number.Length;
            d = new long[2, 3, 5, 7, n + 1];
            for (int x2 = 0; x2 < 2; x2++)
                for (int x3 = 0; x3 < 3; x3++)
                    for (int x5 = 0; x5 < 5; x5++)
                        for (int x7 = 0; x7 < 7; x7++)
                            d[x2, x3, x5, x7, 0] = 0;

            number = "_" + number;
            for (int k = 1; k <= n; k++)
            {
                for (int x2 = 0; x2 < 2; x2++)
                    for (int x3 = 0; x3 < 3; x3++)
                        for (int x5 = 0; x5 < 5; x5++)
                            for (int x7 = 0; x7 < 7; x7++)
                                d[x2, x3, x5, x7, k] = 0;

                string tmp = "";
                for (int i = k - 1; i >= 0; i--)
                {
                    tmp = number[i + 1] + tmp;

                    int o2 = ostatak(tmp, 2);
                    int o3 = ostatak(tmp, 3);
                    int o5 = ostatak(tmp, 5);
                    int o7 = ostatak(tmp, 7);

                    if (i == 0)
                        d[o2, o3, o5, o7, k] += 1;

                    for (int x2 = 0; x2 < 2; x2++)
                        for (int x3 = 0; x3 < 3; x3++)
                            for (int x5 = 0; x5 < 5; x5++)
                                for (int x7 = 0; x7 < 7; x7++)
                                {
                                    d[(x2 + o2) % 2, (x3 + o3) % 3, (x5 + o5) % 5, (x7 + o7) % 7, k] += d[x2, x3, x5, x7, i];                    
                                    d[(x2 - o2 + 2) % 2, (x3 - o3 + 3) % 3, (x5 - o5 + 5) % 5, (x7 - o7 + 7) % 7, k] += d[x2, x3, x5, x7, i];
                                }
                }
            }

            sol = 0;
            for (int x2 = 0; x2 < 2; x2++)
                for (int x3 = 0; x3 < 3; x3++)
                    for (int x5 = 0; x5 < 5; x5++)
                        for (int x7 = 0; x7 < 7; x7++)
                            if (x2 * x3 * x5 * x7 == 0)
                                sol += d[x2, x3, x5, x7, n];
        }

        public static void Solve()
        {
            fin = new FileStream(inputFile, FileMode.Open, FileAccess.Read);
            sr = new StreamReader(fin);
            fout = new FileStream(outputFile, FileMode.Create, FileAccess.Write);
            sw = new StreamWriter(fout);

            int numTestCases = Int32.Parse(sr.ReadLine());
            for (int t = 1; t <= numTestCases; t++)
            {
                number = sr.ReadLine();
                count();
                string output = "Case #" + t + ": " + sol;
                sw.WriteLine(output);
                Console.WriteLine(output);
            }

            sw.Close(); fout.Close();
            sr.Close(); fin.Close();
        }


    }

}
