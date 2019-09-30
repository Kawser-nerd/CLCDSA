using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string infile = "in.txt";
            string outfile = "out.txt";

            TextReader tr = new StreamReader(new FileStream(infile, FileMode.Open));
            if (File.Exists(outfile))
                File.Delete(outfile);
            TextWriter tw = new StreamWriter(new FileStream(outfile, FileMode.Create));

            int T = int.Parse(tr.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string[] s = tr.ReadLine().Split(' ');
                int N = int.Parse(s[0]);
                int K = int.Parse(s[1]);

                tw.WriteLine(string.Format("Case #{0}: {1}", (t + 1), (K + 1) % (1 << N) == 0 ? "ON" : "OFF"));
            }

            tw.Flush();
            tw.Close();
        }
    }
}
