using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ08Qual2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                Dictionary<string, int> labels = new Dictionary<string, int>();
                int turnaboutTime = int.Parse(lines[index]);
                index++;
                string[] bits = lines[index].Split(' ');
                index++;
                int outTripCount = int.Parse(bits[0]);
                int inTripCount = int.Parse(bits[1]);
                List<DateTime> outTimes1 = new List<DateTime>();
                List<DateTime> outTimes2 = new List<DateTime>();
                for (int j = 0; j < outTripCount; j++)
                {
                    string[] bits2 = lines[index].Split(' ');
                    index++;
                    outTimes1.Add(DateTime.Parse(bits2[0]));
                    outTimes2.Add(DateTime.Parse(bits2[1]));
                }
                List<DateTime> inTimes1 = new List<DateTime>();
                List<DateTime> inTimes2 = new List<DateTime>();
                for (int j = 0; j < inTripCount; j++)
                {
                    string[] bits2 = lines[index].Split(' ');
                    index++;
                    inTimes1.Add(DateTime.Parse(bits2[0]));
                    inTimes2.Add(DateTime.Parse(bits2[1]));
                }
                int a;
                int b;
                Solve(turnaboutTime, outTimes1, outTimes2, inTimes1, inTimes2, out a, out b);
                output.Add(string.Format("Case #{0}: {1} {2}", i + 1, a,b));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static void Solve(int turnaboutTime, List<DateTime> outTimes1, List<DateTime> outTimes2, List<DateTime> inTimes1, List<DateTime> inTimes2, out int a, out int b)
        {
            outTimes1.Sort();
            outTimes2.Sort();
            inTimes1.Sort();
            inTimes2.Sort();
            for (int i = 0; i < outTimes2.Count; i++)
            {
                outTimes2[i] = outTimes2[i] + TimeSpan.FromMinutes(turnaboutTime);
            }
            for (int i = 0; i < inTimes2.Count; i++)
            {
                inTimes2[i] = inTimes2[i] + TimeSpan.FromMinutes(turnaboutTime);
            }
            int minA = 0;
            int minB = 0;
            int curA = 0;
            int curB = 0;
            int ot1 = 0;
            int ot2 = 0;
            int it1 = 0;
            int it2 = 0;
            for (DateTime currentTime = DateTime.Parse("00:00"); currentTime <= DateTime.Parse("23:59"); currentTime = currentTime + TimeSpan.FromMinutes(1))
            {
                while (ot2 < outTimes2.Count && outTimes2[ot2] == currentTime)
                {
                    curB++;
                    ot2++;
                }
                while (it2 < inTimes2.Count && inTimes2[it2] == currentTime)
                {
                    curA++;
                    it2++;
                }
                while (ot1 < outTimes1.Count && outTimes1[ot1] == currentTime)
                {
                    curA--;
                    ot1++;
                }
                while (it1 < inTimes1.Count && inTimes1[it1] == currentTime)
                {
                    curB--;
                    it1++;
                }
                if (curA < minA)
                    minA = curA;
                if (curB < minB)
                    minB = curB;
            }
            a = -minA;
            b = -minB;
        }
    }
}
