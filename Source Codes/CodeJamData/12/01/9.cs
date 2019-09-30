using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tongues
{
    class A
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("c:\\codejam\\2012\\qual\\A-small-attempt0.in");
            StreamWriter sw1 = new StreamWriter("c:\\codejam\\2012\\qual\\A-small1.out");
            StreamWriter sw2 = new StreamWriter("c:\\codejam\\2012\\qual\\A-small2.out");

            Stopwatch watch = new Stopwatch();
            watch.Start();

            const string input =        "abcdefghijklmnopqrstuvwxyz"; 
            const string output1 =      "yhesocvxduiglbkrqtnwjpfmaz";
            const string output2 =      "yhesocvxduiglbkrztnwjpfmaq";

            int T = Int32.Parse(sr.ReadLine());
            foreach (int caseN in Enumerable.Range(1, T))
            {

                string line = sr.ReadLine();
                string ans1 = String.Concat(line.Select(ch => ch == ' ' ? ' ' : output1[ch - 'a']));
                string ans2 = String.Concat(line.Select(ch => ch == ' ' ? ' ' : output2[ch - 'a']));

                sw1.WriteLine(String.Format("Case #{0}: {1}", caseN, ans1));
                sw2.WriteLine(String.Format("Case #{0}: {1}", caseN, ans2));

                //Console.WriteLine(String.Format("Case #{0}: {1}ms", caseN, watch.ElapsedMilliseconds));

                sw1.Flush();
                sw2.Flush();

            }

            sr.Close();
            sw1.Close();
            sw2.Close();

        }
    }
}
