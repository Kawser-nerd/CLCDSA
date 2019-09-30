using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Diagnostics;

namespace TaskSolution
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };

            TextReader tr = new StreamReader(Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "input.txt"));
            TextWriter tw = new StreamWriter(@"c:\output.txt");

            int caseMax = Convert.ToInt32(tr.ReadLine());
            for (int caseIndex = 0; caseIndex < caseMax; caseIndex++)
            {
                int solution = 0;

                string[] meta = tr.ReadLine().Split(sep);
                int cells = Convert.ToInt32(meta[0]);
                int release = Convert.ToInt32(meta[1]);

                List<int> oreleaseIds = new List<int>();
                string[] ss = tr.ReadLine().Split(sep);
                for (int i = 0; i < release; i++)
                {
                    oreleaseIds.Add(Convert.ToInt32(ss[i]) - 1);
                }
                List<int> indexes = new List<int>();
                for (int i = 0; i < release; i++)
                {
                    indexes.Add(i);
                }
                bool end = false;
                int best = int.MaxValue;
                while (!end)
                {

                    
                    List<int> releaseIds = new List<int>();
                    for (int i = 0; i < release; i++)
                    {
                        releaseIds.Add(oreleaseIds[indexes[i]]);
                    }
                    List<bool> empty = new List<bool>();
                    for (int i = 0; i < cells; i++)
                    {
                        empty.Add(false);
                    }
                    int gold = 0;
                    while (releaseIds.Count != 0)
                    {
                        int up = 0;
                        int down = 0;

                        int jelolt = releaseIds[0];
                        for (int j = jelolt - 1; j > -1 && !empty[j]; j--)
                        {
                            if (!empty[j]) down++;
                        }
                        for (int j = jelolt + 1; j < cells && !empty[j]; j++)
                        {
                            if (!empty[j]) up++;
                        }
                        gold = gold + up + down;
                        releaseIds.RemoveAt(0);
                        empty[jelolt] = true;
                    }


                    if (gold < best)
                    {
                        best = gold;
                    }

                    back:
                    indexes[release - 1]++;
                    for (int i = release - 1; i > -1; i--)
                    {
                        if (indexes[i] >= release)
                        {
                            if (i > 0)
                            {
                                indexes[i - 1]++;
                                indexes[i] = 0;
                            }
                            else
                            {
                                end = true;
                            }
                        }
                    }
                    List<int> contained = new List<int>();
                    for (int i = 0; i < indexes.Count; i++)
                    {
                        if (!contained.Contains(indexes[i]))
                        {
                            contained.Add(indexes[i]);
                        }
 
                    }
                    if (contained.Count != release && !end)
                        goto back;
                }
                solution = best;

                Console.WriteLine(String.Format("Case #{0}: {1}", caseIndex + 1, solution));
                tw.WriteLine(String.Format("Case #{0}: {1}", caseIndex + 1, solution));
            }
                tw.Close();
                Console.WriteLine("Ready:)");
                Console.ReadLine();

            
        }
    }
}
