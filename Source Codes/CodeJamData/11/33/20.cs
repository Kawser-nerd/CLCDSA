using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{

    class Program
    {

        static void Main(string[] args)
        {

            FileStream output = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(output);

            FileStream input = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(input);


            int nTestCases = int.Parse(sr.ReadLine());

            for (int t = 1; t <= nTestCases; t++)
            {

                string line = sr.ReadLine();

                string[] splitted = line.Split();
                int N = int.Parse(splitted[0]);
                int L = int.Parse(splitted[1]);
                int H = int.Parse(splitted[2]);

                line = sr.ReadLine();
                splitted = line.Split();
                int[] x = new int[splitted.Length];
                for (int i = 0; i < splitted.Length; i++) x[i] = int.Parse(splitted[i]);


                int ret = -1;
                for (int i = L; i <= H; i++)
                {
                    bool ok = true;
                    for (int j = 0; ok && j < x.Length; j++)
                    {
                        if (x[j] % i != 0 && i % x[j] != 0)
                        {
                            ok = false;
                        }
                    }
                    if (ok)
                    {
                        ret = i;
                        break;
                    }
                }

                sw.Write("Case #" + t.ToString() + ": ");
                if (ret == -1)
                {
                    sw.WriteLine("NO");
                }
                else
                {
                    sw.WriteLine(ret);
                }
                sw.Flush();
            }



        }
    }
}
