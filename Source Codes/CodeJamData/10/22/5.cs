using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Pick
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader reader = new StreamReader(@"e:\codejam2010\in.txt");
            //TextWriter writer = Console.Out;
            //StreamReader reader = new StreamReader(@"e:\codejam2010\B-small-attempt1.in");
            //StreamWriter writer = new StreamWriter(@"e:\codejam2010\B-small-attempt1.out");
            StreamReader reader = new StreamReader(@"e:\codejam2010\B-large.in");
            StreamWriter writer = new StreamWriter(@"e:\codejam2010\B-large.out");            

            int cases = int.Parse(reader.ReadLine());
            List<int> loca = new List<int>();
            List<int> speed = new List<int>();
            for (int casei = 1; casei <= cases; ++casei)
            {
                string st = reader.ReadLine();
                string[] sp = st.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(sp[0]);
                int m = int.Parse(sp[1]);
                int barn = int.Parse(sp[2]);
                int time = int.Parse(sp[3]);

                st = reader.ReadLine();
                sp = st.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                loca.Clear();
                for (int i = 0; i < n; ++i) loca.Add(int.Parse(sp[i]));
                st = reader.ReadLine();
                sp = st.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                speed.Clear();
                for (int i = 0; i < n; ++i) speed.Add(int.Parse(sp[i]));

                int cnt = 0;
                int ans = 0;
                for (int i = n - 1; i >= 0 && cnt < m; --i)
                    if (loca[i] + speed[i] * time >= barn)
                    {
                        ans += n - 1 - i - cnt;
                        ++cnt;
                    }
                if (cnt < m) writer.WriteLine("Case #{0}: IMPOSSIBLE", casei);
                else writer.WriteLine("Case #{0}: {1}", casei, ans);
            }

            writer.Flush();
            writer.Close();
            //Console.ReadLine();
            reader.Close();
        }
    }
}
