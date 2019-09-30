using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1C10A
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "A-large";
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
                int wireNum = int.Parse(f.ReadLine());
                int[] wireA = new int[wireNum];
                int[] wireB = new int[wireNum];
                for(int j = 0; j < wireNum; j++)
                {
                    s = f.ReadLine();
                    subs = s.Split(' ');
                    wireA[j] = int.Parse(subs[0]);
                    wireB[j] = int.Parse(subs[1]);
                }
                computeCase(i + 1, wireNum, wireA, wireB);
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
        }
        public static void computeCase(int c, int wireNum, int[] wireA, int[] wireB)
        {
            int intersections = 0;
            for(int i = 0; i < wireNum; i++)
            {
                for(int j = i+1; j < wireNum; j++)
                {
                    if((wireA[j] - wireA[i])*(wireB[j] - wireB[i]) < 0)
                        intersections++;
                }
            }
            outLines.Add("Case #" + c.ToString() + ": " + intersections);


        }
    }
}
