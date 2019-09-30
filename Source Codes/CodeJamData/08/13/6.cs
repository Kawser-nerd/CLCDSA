using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Program {
        static void Main(string[] args) {
            string fi = "i5.txt", fo = "o.txt";
            if (args.Length > 0) fi = args[0];
            if (args.Length > 1) fo = args[1];
            StreamReader sr = new StreamReader(fi);
            StreamWriter sw = new StreamWriter(fo);
            string line = sr.ReadLine();
            int n = Convert.ToInt32(line);
            Numbers o = new Numbers();
            for (int i = 0; i < n; i++) {
                sw.Write("Case #");
                sw.Write(i + 1);
                sw.Write(":");
                o.gen(sw, sr);
            }
            sr.Close();
            sw.Close();
        }
    }
}
