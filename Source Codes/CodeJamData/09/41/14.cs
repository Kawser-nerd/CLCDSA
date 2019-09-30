using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-large.out"))
                {
                    int count = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= count; tc++)
                    {
                        int N = int.Parse(sr.ReadLine());

                        string[] lines = new string[N];
                        for (int i = 0; i < N; i++)
                            lines[i] = sr.ReadLine();

                        int swapcount = 0;

                        for (int i = 0; i < N; i++)
                        {
                            for (int j = i; j < N; j++)
                            {
                                if (IsValid(lines[j], i))
                                {
                                    for (int k = j; k > i; k--)
                                    {
                                        Swap(lines, k, k - 1);
                                        swapcount++;
                                    }
                                    break;
                                }
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", tc, swapcount);
                    }
                }
            }
        }
        static bool IsValid(string line, int rowindex)
        {
            int length = line.Length;
            for (int i = rowindex + 1; i < length; i++)
            {
                if (line[i] == '1') return false;
            }
            return true;
        }
        static void Swap(string[] lines, int i, int j)
        {
            string temp = lines[i];
            lines[i] = lines[j];
            lines[j] = temp;
        }
    }
}
