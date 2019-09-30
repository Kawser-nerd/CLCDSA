using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Jam
{
    class Program
    {
        string run(string[] a, string[] b, int r, int c)
        {
            HashSet<int> cnt = new HashSet<int>();
            List<int> first = new List<int>();
            List<int> second = new List<int>();
            for (int n = 0; n < a.Length; n++)
            {
                cnt.Add(Int32.Parse(a[n]));
                cnt.Add(Int32.Parse(b[n]));
                first.Add(Int32.Parse(a[n]));
                second.Add(Int32.Parse(b[n]));
            }

            if (cnt.Count < 7) return "Bad magician!";

            for (int n = 0; n < first.Count; n++)
                if (second.IndexOf(first[n]) != -1)
                    return first[n].ToString();

            return "Volunteer cheated!";
        }
        static void Main(string[] args)
        {
            using (StreamReader f = new StreamReader("A-small-attempt1.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-small-attempt1.out"))
                {
                    int cases = Int32.Parse(f.ReadLine());
                    for (int n = 0; n < cases; n++)
                    {
                        
                        List<string> tmp = new List<string>();
                        for(int m=0; m<10; m++)
                            tmp.Add(f.ReadLine());

                        int a = Int32.Parse(tmp[0]);
                        int b = Int32.Parse(tmp[5]);
                        Program p = new Program();
                        string output = p.run(tmp[a].Split(' '),tmp[b+5].Split(' '), a, b);

                        sw.WriteLine("Case #" + (n + 1).ToString() + ": " + output);
                    }
                }
            }

        }
    }
}
