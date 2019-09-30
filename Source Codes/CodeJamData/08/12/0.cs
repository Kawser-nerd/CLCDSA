using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        const double EPS = 1e-9;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                int n = int.Parse(Console.ReadLine());
                int m = int.Parse(Console.ReadLine());
                bool[,] a = new bool[n,m];
                int[] count = new int[m];
                int[] index = new int[m];
                for (int i = 0; i < m; i++)
                {
                    index[i] = -1;
                    string[] buf = Split(Console.ReadLine(), ' ');
                    for (int j = 1; j < buf.Length; j += 2)
                    {
                        int x = int.Parse(buf[j]) - 1;
                        int y = int.Parse(buf[j + 1]);
                        if(y == 1) index[i] = x;
                        else{
                            a[x,i] = true;
                            count[i]++;
                        }
                    }
                }
                int result = 0;
                int num = 0;
                bool[] malted = new bool[n];
                bool[] flag = new bool[m];
                while (num < m)
                {
                    int p = 0;
                    for(int i=0; i<m; i++)
                        if (!flag[i] && count[i] == 0)
                        {
                            if (index[i] < 0)
                            {
                                result = -1;
                                break;
                            }
                            p++;
                            flag[i] = true;
                            malted[index[i]] = true;
                            for(int j=0; j<m; j++)
                                if (a[index[i], j])
                                {
                                    a[index[i], j] = false;
                                    count[j]--;
                                }
                        }
                    if (result < 0) break;
                    if (p == 0) break;
                    num += p;
                }
                
                string output = null;
                if(result < 0) output = "IMPOSSIBLE";
                else output = Convert(malted);
                Console.WriteLine("Case #{0}: {1}", casen, output);
            }
        }

        static string Convert(bool[] flag)
        {
            string res = "";
            for (int i = 0; i < flag.Length; i++)
            {
                if (i > 0) res += " ";
                if (flag[i]) res += "1";
                else res += "0";
            }
            return res;
        }

        static string[] Split(string str, char ch)
        {
            string[] buf = str.Split(ch);
            List<string> list = new List<string>();
            foreach (string s in buf)
                if (!string.IsNullOrEmpty(s)) list.Add(s);
            return list.ToArray();
        }
    }
}
