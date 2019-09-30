using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace R1C10B
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "B-large";
        static void Main(string[] args)
        {
            StreamReader f = new StreamReader(file + ".in");
            string s = f.ReadLine();
            string[] subs = s.Split(' ');
            s = subs[0];
            int numCase = int.Parse(s);
            //s = subs[1];
            //int numSetup = int.Parse(s);
            //s = subs[2];
            //int someConstant = int.Parse(s);
            //for (int i = 0; i < numSetup; i++)
            //{
            ////create some sort of data structure to use
            //}
            for (int i = 0; i < numCase; i++)
            {
                // get all the data for your case here
                computeCase(i + 1, f.ReadLine());
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
        }
        public static void computeCase(int c, string line)
        {
            string[] subs = line.Split(' ');
            int low = int.Parse(subs[0]);
            int high = int.Parse(subs[1]);
            int factor = int.Parse(subs[2]);
            double firstnum = Math.Log(((double)high) / ((double)low), factor);
            double secondnum = Math.Log(firstnum, 2);
            int answer = (int)secondnum;
            if (secondnum > (int)secondnum)
                answer++;

            if (answer < 0)
                answer = 0;
            outLines.Add("Case #" + c.ToString() + ": " + answer);


        }
    }
}
