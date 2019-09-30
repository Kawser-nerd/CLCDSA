using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProgrammingContest.GoogleCodeJam._2010.Qual
{
    class A
    {
        public static void Main(string[] args)
        {
            using (FileStream os = new FileStream(@"result.txt", FileMode.Create))
            using (StreamWriter sw = new StreamWriter(os))
            using (FileStream fs = new FileStream(args[0], FileMode.Open))
            using (StreamReader sr = new StreamReader(fs))
            {
                int t = int.Parse(sr.ReadLine());
                for (int i = 0; i < t; i++)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    int n = int.Parse(s[0]);
                    int k = int.Parse(s[1]);

                    int x = 1<<n;
                    sw.WriteLine("Case #{0}: {1}", i+1, (k+1) % x == 0 ? "ON":"OFF");
                }
            }
        }
    }
}
