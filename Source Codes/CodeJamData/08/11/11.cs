using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamRound1
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] myChars = { ' ' };
            string[] fileLines = File.ReadAllLines(@"D:\inputs\round1\A-small-attempt0.in");
            TextWriter outputFile = new StreamWriter(@"D:\outputs\1-small.txt");

            int numCases = int.Parse(fileLines[0]);
            int count = 1;
            for (int i = 1; i < fileLines.Length; i++)
            {
                int numInVector = int.Parse(fileLines[i++]);
                string[] tv1 = fileLines[i++].Split(myChars);
                string[] tv2 = fileLines[i].Split(myChars);
                List<int> v1 = new List<int>();
                List<int> v2 = new List<int>();
                for (int j = 0; j < numInVector; j++)
                {
                    v1.Add(int.Parse(tv1[j]));
                    v2.Add(int.Parse(tv2[j]));
                }
                v1.Sort();
                v2.Sort();
                v2.Reverse();
                int product = 0;
                for (int j = 0; j < numInVector; j++)
                {
                    product += v1[j] * v2[j];
                }
                Console.WriteLine("Case #" + count.ToString() + ": " + product.ToString());
                outputFile.WriteLine("Case #" + count.ToString() + ": " + product.ToString());
                count++;
            }
            outputFile.Close();
        }
        //        char[] myChars = { ' ', ':' };
        //        string[] splits = myTimes.Split(myChars);
    }
}
