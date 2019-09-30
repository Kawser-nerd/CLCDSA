using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundOne
{
    public class B
    {
        public static void Run()
        {
            var number = 0;
            using (var sr = new StreamReader("B-large (1).in"))
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
                            int n = int.Parse(line);
                            List<List<int>> list = new List<List<int>>();
                            for (var i = 0; i < 2 * n - 1; i++)
                            {
                                line = sr.ReadLine();
                                list.Add(line.Split(' ').Select(int.Parse).ToList());
                            }

                            var index = new List<int>();
                            var mark = new List<bool>();
                            for (var i = 0; i < 2 * n - 1; i++){
                                index.Add(-1);
                                mark.Add(false);
                            }
                                
                            
                            for (int i = 0; i < n; i++)
                            {
                                var min = int.MaxValue;
                                int cnt = 0;
                                for (int j = 0; j < 2 * n - 1; j++)
                                    if(mark[j] == false)
                                { 
                                    if(list[j][i] == min)
                                    {
                                        cnt++;
                                    }
                                    else if (list[j][i] < min)
                                    {
                                        cnt = 1;
                                        min = list[j][i];
                                    }
                                }
                                for (int j = 0; j < 2 * n - 1; j++)
                                    if(mark[j] == false)
                                {
                                    if (list[j][i] == min)
                                    {
                                        index[j] = i;
                                        mark[j] = true;
                                    }
                                }
                            }
                            List<int> ans = new List<int>();
                            for (var i = 0; i < 2 * n - 1; i++)
                            {
                                List<int> temp = new List<int>();
                                for (int j = 0; j < 2 * n - 1; j++)
                                {
                                    var k = index[j];
                                    var m = i - k;
                                    if (m >= 0 && m < n)
                                    {
                                        temp.Add(list[j][m]);
                                    }
                                }
                                temp.Sort();
                                if (temp.Count() % 2 == 1)
                                {
                                    for (var j = 0; j < temp.Count(); j += 2)
                                    {
                                        if (j == temp.Count() - 1 || temp[j] != temp[j + 1])
                                        {
ans.Add(temp[j]);
break;
                                        }
                                            
                                    }
                                }
                            }

                                sw.WriteLine(string.Format("Case #{0}: {1}", c, string.Join(" ", ans.Select(a => a.ToString()))));
                        }
                    }
                }
            }
        }
    }

}
