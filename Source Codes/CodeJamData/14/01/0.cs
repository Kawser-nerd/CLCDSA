using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines("input.txt");
            int t = Convert.ToInt32(lines[0]);
            int num = 1;
            List<string> a = new List<string>();
            for (int _ = 0; _ < t; ++_)
            {
                int r = Convert.ToInt32(lines[num]);
                SortedSet<int> answers = new SortedSet<int>();
                foreach (string p in lines[num + r].Split(' '))
                {
                    answers.Add(Convert.ToInt32(p));
                }
                num += 5;
                r = Convert.ToInt32(lines[num]);
                SortedSet<int> answers2 = new SortedSet<int>();
                foreach (string p in lines[num + r].Split(' '))
                {
                    answers2.Add(Convert.ToInt32(p));
                }
                num += 5;
                answers.IntersectWith(answers2);
                string s = string.Format("Case #{0}: Bad magician!", a.Count + 1); ;
                if (answers.Count == 0)
                {
                    s = string.Format("Case #{0}: Volunteer cheated!", a.Count + 1);
                }
                if (answers.Count == 1)
                {
                    s = string.Format("Case #{0}: {1}", a.Count + 1, answers.First());
                }
                a.Add(s);
            }
            System.IO.File.WriteAllLines("output.txt", a.ToArray());
        }
    }
}
