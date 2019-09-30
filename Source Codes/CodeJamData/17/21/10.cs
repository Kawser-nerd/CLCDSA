using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace CodeJam2017
{
 
    class Horse
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("input.txt");
            StringWriter output = new StringWriter();

            int n = int.Parse(lines[0]);
            int at = 1;
            for(int i=0;i<n;i++)
            {
                string[] line = lines[at++].Split();
                int D = int.Parse(line[0]);
                int N = int.Parse(line[1]);
                List<int> k = new List<int>();
                List<int> s = new List<int>();
                double maxT = 0;
                for(int j=0;j<N;j++)
                {
                    string[] line2 = lines[at++].Split();
                    k.Add(int.Parse(line2[0]));
                    s.Add(int.Parse(line2[1]));
                    double ki = (double)int.Parse(line2[0]);
                    double si = (double)int.Parse(line2[1]);
                    double dr = D - ki;
                    double ti = dr / si;
                    maxT = Math.Max(maxT, ti);
                }
                double res = D / maxT;

                
                output.WriteLine("Case #" + (i + 1) + ": " + res);
            }
            File.WriteAllText("output.txt", output.ToString());
            Console.WriteLine(output.ToString());
        }
    }
}
