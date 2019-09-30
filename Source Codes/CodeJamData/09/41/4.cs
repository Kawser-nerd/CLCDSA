using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static int Solve(int[] values)
        {
            int res = 0;
            for (int i = 0; i < values.Length; i++)
            {
                if (values[i] > i)
                {
                    int count = 1;
                    for (int j = i + 1; j < values.Length; j++)
                    {
                        if (values[j] <= i)
                        {
                            break;
                        }
                        count += 1;
                    }
                    res += count;
                    int temp = values[i + count];
                    Array.Copy(values, i, values, i + 1, count);
                    values[i] = temp;
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < T; i++)
                    {
                        int N = Int32.Parse(reader.ReadLine());
                        int[] values = new int[N];
                        for (int j = 0; j < N; j++)
                        {
                            string str = reader.ReadLine();
                            for (int k = 0; k < str.Length; k++)
                            {
                                if (str[k] == '1')
                                {
                                    values[j] = k;
                                }
                            }
                        }

                        int res = Solve(values);
                        writer.WriteLine("Case #" + (i + 1) + ": " + res);
                    }
                }
            }
        }
    }
}
