using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace GoogleCodeJam2015Q1C_2
{
    public class Problem
    {
        public Problem()
        {
            var pathname = "Sample.txt";
            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        double result = 0.0d;
                        bool found = false;
                        string[] lines = sr.ReadLine().Split(' ');
                        int K = int.Parse(lines[0]);
                        int L = int.Parse(lines[1]);
                        int S = int.Parse(lines[2]);

                        string keyboard = sr.ReadLine();
                        string target = sr.ReadLine();
                        char[] arr = keyboard.ToCharArray();

                        for (int i = 0; i < target.Length; i++)
                        {
                            if (!keyboard.Contains(target[i]))
                            {
                                result = 0.0d;
                                found = true;
                                break;
                            }
                        }

                        if (!found)
                        {
                            var words = new List<string>();
                            words.AddRange(arr.Select(c => c.ToString()));

                            for (int i = 1; i < S; i++)
                            {
                                var tmp= new List<string>();
                                for (int j = 0; j < K; j++)
                                {
                                    foreach (var w in words)
                                    {
                                        tmp.Add(w + arr[j]);
                                    }
                                }
                                words = tmp;
                            }

                            long bananaMax = 0;
                            Dictionary<int, int> answer = new Dictionary<int, int>();
                            foreach (var w in words)
                            {
                                int bananaForWord = 0;
                                string toSearch = w;
                                int index = toSearch.IndexOf(target);
                                while (index > -1)
                                {
                                    bananaForWord++;
                                    toSearch = toSearch.Substring(index + 1);
                                    index = toSearch.IndexOf(target);
                                }
                                bananaMax = bananaForWord > bananaMax ? bananaForWord : bananaMax;
                                if (!answer.ContainsKey(bananaForWord))
                                    answer[bananaForWord] = 0;
                                
                                answer[bananaForWord]++;
                            }
                            int totalWord = words.Count;
                            long exp = 0;
                            foreach (var p in answer)
                            {
                                exp += (p.Key * p.Value);
                            }
                            result = bananaMax - ((double)exp / (double)(totalWord));
                        }

                        sw.WriteLine("Case #{0}: {1}", sc, result.ToString("F7",CultureInfo.InvariantCulture));
                    }
                    sw.Flush();
                }

            }
        }


    }
}
