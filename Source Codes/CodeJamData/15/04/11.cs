using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundQ_D
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
                string[] lines = line.Split(' '); // total number of d
                int x = int.Parse(lines[0]);
                int r = int.Parse(lines[1]);
                int c = int.Parse(lines[2]);
                string result = solve(x, r, c);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }
            infile.Close();
            outfile.Close();
        }

        static string solve(int x, int r, int c)
        {
            bool ok = true;
            if (x >= 7)
                ok = false;
            else if (x > r && x > c)
                ok = false;
            else if (r * c % x != 0)
                ok = false;
            else if ((x + 1) / 2 > Math.Min(r, c))
                ok = false;
            else if (x == 1 || x == 2 || x == 3)
                ok = true;
            else if (x == 4)
                ok = Math.Min(r, c) > 2;
            else if (x == 5)
                ok = Math.Min(r, c) != 3 || Math.Max(r, c) != 5;
            else if (x == 6)
                ok = Math.Min(r, c) > 3;
            if (ok)
                return "GABRIEL";
            return "RICHARD";
        }
    }
}
