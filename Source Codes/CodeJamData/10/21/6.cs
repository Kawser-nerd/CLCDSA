using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace File
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader reader = new StreamReader(@"E:\codejam2010\in.txt");
            //TextWriter writer = Console.Out;
            //StreamReader reader = new StreamReader(@"E:\codejam2010\A-small-attempt0.in");
            //StreamWriter writer = new StreamWriter(@"E:\codejam2010\A-small-attempt0.out");
            StreamReader reader = new StreamReader(@"E:\codejam2010\A-large.in");
            StreamWriter writer = new StreamWriter(@"E:\codejam2010\A-large.out");
            
            int cases = int.Parse(reader.ReadLine());
            HashSet<string> set = new HashSet<string>();
            for (int casei = 1; casei <= cases; ++casei)
            {
                string st = reader.ReadLine();
                string[] sp = st.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(sp[0]);
                int m = int.Parse(sp[1]);

                set.Clear();
                for (int i = 0; i < n; ++i) set.Add(reader.ReadLine());
                set.Add("");

                int ans = 0;
                for (int i = 0; i < m; ++i)
                {
                    st = reader.ReadLine();
                    int len = st.Length;
                    string tmp = "";
                    for (int j = 0; j < len; ++j) 
                    {
                        if (st[j] == '/')
                            if (!set.Contains(tmp))
                            {
                                set.Add(tmp);
                                ++ans;
                            }
                        tmp = tmp + st[j];
                    }
                    if (!set.Contains(st))
                    {
                        set.Add(st);
                        ++ans;
                    }
                }

                writer.WriteLine("Case #{0}: {1}", casei, ans);
            }

            writer.Flush();
            writer.Close();
            Console.ReadLine();
            reader.Close();
        }
    }
}
