using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ChetkoePrilozhenie
{
    class Program
    {
        static char[] vowels = new char[] { 'a', 'e', 'i', 'o', 'u' };
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(@"C:\gcj\A-large.in"))
            using (StreamWriter writer= new StreamWriter(@"c:\gcj\output.txt"))
            {
                var T = Convert.ToInt32(reader.ReadLine());
                for (int i = 1; i <= T; ++i)
                {
                    var t = reader.ReadLine().Split(new[]{'\t', ' '});
                    var line = t[0];
                    var s = new bool[line.Length];
                    var L = Convert.ToInt32(t[1]);

                    for (int j = 0; j < line.Length; ++j)
                        s[j] = !vowels.Contains(line[j]);

                    Int64 ans = 0;
                    int q = 0;
                    var b = -1;
                    for (int j = 0; j < line.Length; ++j)
                    {
                        if (s[j])
                        {
                            ++q;
                        }
                        else
                        {
                            q = 0;
                        }

                        if (q == L)
                        {
                            ans += ((Int64)(j - q - b + 1)) * (line.Length - j);
                            b = j - q + 1;
                            q = L - 1;
                        }
                    }

                    writer.WriteLine("Case #{0}: {1}", i, ans);
                }
            }
        }
    }
}
