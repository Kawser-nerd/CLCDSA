using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader tr = new StreamReader(@"D:\Downloads\b-large.in"))
            using (TextWriter tw = new StreamWriter(@"D:\Downloads\output.txt"))
            {
                int n = int.Parse(tr.ReadLine());
                for (int cas=1; cas<=n; ++cas)
                {
                    char[] test = tr.ReadLine().ToCharArray();
                    bool f = true;
                    for (int i=1; i<test.Length; ++i)
                    {
                        if (test[i-1] < test[i])
                        {
                            f = false;
                            break;
                        }
                    }
                    if (f)
                    {
                        Array.Resize(ref test, test.Length + 1);
                        test[test.Length - 1] = '0';
                        Array.Reverse(test);
                        int i = 0;
                        while (test[i] == '0') ++i;
                        test[0] = test[i];
                        test[i] = '0';
                        tw.WriteLine("Case #{0}: {1}", cas, new string(test));
                        continue;
                    }
                    int p = test.Length - 1;
                    while (test[p-1] >= test[p]) --p;
                    --p;
                    int k = p + 1;
                    while (k < test.Length-1 && test[p] < test[k+1]) ++k;
                    char tmp = test[p];
                    test[p] = test[k];
                    test[k] = tmp;
                    Array.Reverse(test, p + 1, test.Length - p - 1);
                    tw.WriteLine("Case #{0}: {1}", cas, new string(test));
                }
            }
        }
    }
}
