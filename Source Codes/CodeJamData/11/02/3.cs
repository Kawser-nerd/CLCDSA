using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {           
        class Combination
        {
            public char A, B, R;

        }
        public class Oposition
        {
            public char A, B;
        }

        static void Main(string[] args)
        {
            TextReader tr = new StreamReader(args[0]);
            var cases = int.Parse(tr.ReadLine());
            for(int caseN = 0;caseN<cases;caseN++)
            {
                Console.Write("Case #"+(caseN+1)+": ");
                var input = tr.ReadLine().Split(' ');
                int c = 0;
                int combCount = int.Parse(input[c++]);
                var combinations = new List<Combination>();
                for (int i = 0; i < combCount;i++)
                {
                    combinations.Add(new Combination {A = input[c][0], B = input[c][1], R = input[c][2]});
                    c++;
                }
                int opCount = int.Parse(input[c++]);
                var oposites = new List<Oposition>();
                for (int i = 0; i < opCount; i++)
                {
                    oposites.Add(new Oposition() {A = input[c][0], B = input[c][1]});
                    c++;
                }
                var task = input[++c];
                var result = new List<char>();
                foreach (var elem in task)
                {                    
                    char elem1 = elem;
                    char prevR = result.Count>0?result[result.Count - 1]:'?';
                    var comb = combinations.Find(co => co.A == elem1 && co.B==prevR || co.B == elem1 && co.A ==prevR);
                    if (comb!=null)
                    {
                        result.RemoveAt(result.Count-1);
                        result.Add(comb.R);
                    } else
                    {
                        var oposite = oposites.Find(op => op.A == elem1 && result.Contains(op.B) || op.B == elem1  && result.Contains(op.A));
                        if (oposite!=null)
                        {
                            result.Clear();                            
                        }
                        else result.Add(elem1);
                    }
                }

                Console.WriteLine("["+string.Join(", ",result.ToArray())+"]");
            }
            Console.ReadKey();

        }
    }
}

