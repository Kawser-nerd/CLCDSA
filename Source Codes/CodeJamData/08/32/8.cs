using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var N = int.Parse(sr.ReadLine());

            for (int i = 0; i < N; i++)
            {
                string temp = sr.ReadLine();
                long len = temp.Length;
                long sub = 1;
                for (int j = 0; j < len - 1; j++)
                    sub *= 3;

                long result = 0;
                for (int j = 0; j < sub; j++)
                {
                    long t = j;
                    long subres = 0;
                    long tempstr = temp[0] - '0';
                    bool flag = false;
                    int index = 1;
                    while (index < temp.Length)
                    {
                        if (t % 3 == 0)
                        {
                        }
                        if (t % 3 == 1)
                        {
                            if (!flag)
                                subres += tempstr;
                            else
                                subres -= tempstr;
                            tempstr = 0;
                            flag = false;
                        }
                        if (t % 3 == 2)
                        {
                            if (!flag)
                                subres += tempstr;
                            else
                                subres -= tempstr;
                            tempstr = 0;
                            flag = true;
                        }
                        tempstr = tempstr * 10 + temp[index] - '0';
                        t /= 3;
                        index++;
                    }
                    if (!flag)
                        subres += tempstr;
                    else
                        subres -= tempstr;

                    if (subres % 2 == 0 ||
                       subres % 5 == 0 ||
                       subres % 3 == 0 ||
                       subres % 7 == 0)
                        result++;
                }

                sw.WriteLine("Case #" + (i + 1) + ": " + result);
            }
            sw.Close();
        }
    }
}
