using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundQ_B
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader infile = new StreamReader("input.txt");
            StreamWriter outfile = new StreamWriter("output.txt");
            string line = infile.ReadLine();
            int T = int.Parse(line); // case num
            for (int i = 0; i < T; i++)
            {
                line = infile.ReadLine();
                int d = int.Parse(line); // total number of d
                line = infile.ReadLine();
                string[] s = line.Split(' ');
                int[] p = new int[d]; // array of d, d[i] = number of pancakes of d[i]
                for (int j = 0; j < d; j++)
                {
                    p[j] = int.Parse(s[j]);
                }
                int result = solve(d, p);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }
            infile.Close();
            outfile.Close();
        }

        static int solve(int d, int[] p)
        {
            int result = max(d, p);
            for (int i = 2; i < result; i++)
            {
                double sum = 0;
                for(int j=0; j<d; j++)
                {
                    sum += Math.Floor((double)(p[j] - 1) / i);
                }
                sum += i;
                if(sum < result)
                {
                    result = (int)sum;
                }
            }
            return result;
        }

        static int max(int d, int[] p)
        {
            int result = -1;
            for(int i=0; i<d; i++)
            {
                if(p[i] > result)
                {
                    result = p[i];
                }
            }
            return result;
        }
    }
}
