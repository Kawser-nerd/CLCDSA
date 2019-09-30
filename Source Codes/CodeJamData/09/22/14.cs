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
            using (StreamReader sr = new StreamReader("B-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("B-large.out"))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= T; tc++)
                    {
                        string line = sr.ReadLine();
                        line = "0" + line;
                        int len = line.Length;
                        string result = line;

                        for (int i = len - 2; i >= 0; i--)
                        {
                            int temp = -1;
                            bool found = false;
                            for (int j = len - 1; j > i; j--)
                            {
                                if (line[i] < line[j])
                                {
                                    found = true;
                                    if (temp == -1)
                                        temp = j;
                                    if (line[j] < line[temp])
                                    {
                                        temp = j;
                                    }
                                }
                            }
                            if (found)
                            {
                                char[] data = line.ToCharArray();
                                char tdata = data[i];
                                data[i] = data[temp];
                                data[temp] = tdata;

                                string front = new string(data, 0, i+1);
                                string end = new string(data, i + 1, len - i-1);
                                char[] t2 = end.ToCharArray();
                                Array.Sort(t2);
                                end = new string(t2);
                                result = front + end;
                                break;
                            }
                        }

                        if (result.StartsWith("0"))
                            result = result.Substring(1);

                        sw.WriteLine("Case #{0}: {1}", tc, result);
                    }
                }
            }
        }
    }
}
