using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam2013
{
    public class A
    {
        public void Run()
        {
           //string filename = "A-sample";
            //string filename = "A-small";
            string filename = "A-large";

            var lines = File.ReadAllLines(filename + ".in");
            int r = 0;
            var Ts = lines[r++];
            var T = int.Parse(Ts);
            var file = new System.IO.StreamWriter(filename + ".out");
            for (int i = 0; i < T; i++)
            {
                var l1s = lines[r++];
                var l1=l1s.Split(' ').Select(int.Parse).ToArray();
                int A = l1[0];
                int N = l1[1];
                var l2s = lines[r++];
                var mo = l2s.Split(' ').Select(int.Parse).ToArray();

                var res = Result(A,mo);

                file.WriteLine("Case #" + (i + 1) + ": " + res);
            }
            file.Close();
        }



        public int Result(int a, int[] mo)
        {
            if (a == 1) return mo.Length;
            while (mo.Any(x => x < a))
            {
                var newmo = mo.Where((x => x >= a)).ToArray();
                a += mo.Where((x => x < a)).Sum();
                mo = newmo;
            }
            if (mo.Length == 0) return 0;
            int originalA=a;
            mo = mo.OrderBy(x => x).ToArray();
            int ope = 0;
            for (int i = 0; i < mo.Length; i++)
            {
                if (a > mo[i]) a += mo[i];
                else {
                    a = 2 * a - 1;
                    i--;
                    ope++;
                }
            }

            var res = ope;
            var rimosso = 1 + Result(originalA, mo.Take(mo.Length - 1).ToArray());
            if (rimosso < res) res = rimosso;
            
            return res;
        }

    }
}
