using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundQ_A
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
                string[] data = line.Split(' ');
                int smax = int.Parse(data[0]);
                int[] s = new int[smax + 1];
                for (int j = 0; j < smax + 1; j++)
                {
                    s[j] = int.Parse(data[1][j].ToString());
                }
                int result = solve(smax, s);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }
            infile.Close();
            outfile.Close();
        }

        static int solve(int smax, int[] s)
        {
            int standing = 0;
            int need = 0;
            for (int i = 0; i < smax + 1; i++ )
            {
                if(standing < i && s[i] > 0)
                {
                    need += i - standing;
                    standing += need;
                }
                standing += s[i];
            }
            return need;
        }
    }
}
