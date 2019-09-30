using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundOne
{
    public class C
    {
        public static void Run()
        {
            var number = 0;
            using (var sr = new StreamReader("C-large.in"))
            {
                using (var sw = new StreamWriter("output.txt"))
                {
                    while (!sr.EndOfStream)
                    {
                        var line = sr.ReadLine();
                        if (number == 0) number = int.Parse(line);
                        for (var c = 1; c <= number; c++)
                        {
                            line = sr.ReadLine();
                            line = sr.ReadLine();
                            List<int> list = line.Split(' ').Select( t => int.Parse(t)-1).ToList();
                            
                            bool[] mark = new bool[list.Count()];

                            bool[] re = new bool[list.Count()];
                            int[] depth = new int[list.Count()];
                            for (int i = 0; i < list.Count(); i++)
                            {
                                depth[i] = 1;
                                for (var j = 0; j < list.Count(); j++)
                                {
                                    mark[j] = false;
                                }
                                int next = i;
                                mark[next] = true;
                                next = list[next];
                                int a = 1;
                                while (true)
                                {
                                    if (mark[next])
                                        break;
                                    a++;
                                    mark[next] = true;
                                    next = list[next];
                                }
                                if (next == i)
                                {
                                    re[i] = true;
                                }
                                else re[i] = false;
                            }
                            for (var i = 0; i < list.Count; i++)
                            {
                                int next = i;
                                if (re[i]) continue;
                                while (true)
                                { 
                                    var pre = next;
                                    next = list[pre];
                                    depth[next] = Math.Max(depth[next], depth[pre] + 1);
                                    if (re[next])
                                        break;
                                }
                            }
                            
                            int ans = 0;
                            var tt = 0;
                            for (int i = 0; i < list.Count(); i++)
                            {
                                for (var j = 0; j < list.Count(); j++)
                                {
                                    mark[j] = false;
                                }
                                int next = i;
                                mark[next] = true;
                                next = list[next];
                                int a = 1;
                                while (true)
                                {
                                    if (mark[next])
                                        break;
                                    a++;
                                    mark[next] = true;
                                    next = list[next];
                                }
                                if (next == i)
                                {
                                    ans = Math.Max(ans, a);
                                    if (a == 2) {
                                        tt += depth[i] + depth[list[i]];
                                    }
                                }
                                    
                            }
                            ans = Math.Max(ans, tt/2);
                                sw.WriteLine(string.Format("Case #{0}: {1}", c, ans));
                        }
                    }
                }
            }
        }
    }
}
