using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {                   
        static int patrikAdd(int a, int b)
        {
            int result = 0 ;
            int bit = 0;
            while (a>0 || b>0)
            {
                result += ( ( (a & 1) + (b & 1)) & 1 ) << bit++;
                a = a >> 1;
                b = b >> 1;
               
            }
            return result;
        }
        static int patrikCalc(List<int> l)
        {
            return l.Aggregate(0, patrikAdd);
        }
        public class Solution
        {
            public List<int> Patrick;
            public List<int> Sean;
            public Solution[] next()
            {
                var results = new List<Solution>();
                if (Sean.Count>0)
                //for(int pn = 0; pn<Sean.Count;pn++)
                // Sean we will give him only 1 candy                
                {
                    int pn = 0;
                    var cand = Sean[pn];
                    var nSeans = new List<int>(Sean);
                    nSeans.RemoveAt(pn);
                    var nPatr = new List<int>(Patrick);
                    nPatr.Add(cand);
                    results.Add(new Solution(){ Patrick = nPatr, Sean = nSeans});
                }
                return results.ToArray();
            }

            public override string ToString()
            {
                return string.Format("Sean: {0}, Patrick: {1}", string.Join(",",Sean), string.Join(",",Patrick));
            }

            private int patrics = -1;
            private int seans = -1;
            private int seansN = -1;

            private void Calc()
            {
                patrics = patrikCalc(Patrick);
                seans = patrikCalc(Sean);
                seansN = Sean.Sum();
            }
            public int PatricsSum { get { if (patrics == -1) Calc(); return patrics; } }
            public int SeanSum { get { if (seans == -1) Calc(); return seans; } }
            public int SeanNormal { get { if (seansN == -1) Calc(); return seansN; } }
            public bool Good { get { return PatricsSum == SeanSum && Patrick.Count>0; } }

        }
        static void Main(string[] args)
        {           
            TextReader tr = new StreamReader(args[0]);
            var cases = int.Parse(tr.ReadLine());
            for(int caseN = 0;caseN<cases;caseN++)
            {
                Console.Write("Case #"+(caseN+1)+": ");
                tr.ReadLine();
                var pack = new List<int>(from p in  tr.ReadLine().Split(' ') select int.Parse(p));
                pack.Sort();
                var solution = new Solution() { Sean = pack, Patrick = new List<int>() };                
                var todo = new Queue<Solution>();
                todo.Enqueue(solution);
                while (todo.Count>0)
                {
                    //Console.WriteLine("[s=" + todo.Count + "]");
                    solution = todo.Dequeue();
                    if (solution.Good) break;
                    foreach (var nextSol in solution.next())
                    {
                        todo.Enqueue(nextSol);
                    }
                }                
                Console.WriteLine(solution.Good?solution.SeanNormal.ToString():"NO");
            }
            Console.ReadKey();

        }
    }
}

