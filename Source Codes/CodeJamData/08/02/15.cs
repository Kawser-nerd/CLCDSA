using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace TrainTimetable
{
    class Program
    {
        //        C:\Users\Patrick\Desktop\output.txt
        //        C:\Users\Patrick\Dev\VS2008\SavingUniverse\TrainTimetable\Program.cs

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\Patrick\Desktop\b-large.in"))
//            using (var sr = new StreamReader(@"C:\Users\Patrick\Desktop\b-small-attempt0.in"))
//            using (StreamReader sr = new StreamReader(@"C:\Users\Patrick\Desktop\b-small-attempt1.in"))
            using (var sw = new StreamWriter(@"C:\Users\Patrick\Desktop\output.txt"))
            {
                int cases = int.Parse(sr.ReadLine());
                for (int i = 0; i < cases; i++)
                    sw.WriteLine("Case #{0}: {1}", i + 1, SolveCase(sr));
            }
        }

        private static string SolveCase(TextReader sr)
        {
            int turnTime = int.Parse(sr.ReadLine());

            string fromAandB = sr.ReadLine();
            int fromA = int.Parse(fromAandB.Substring(0, fromAandB.IndexOf(' ')));
            int fromB = int.Parse(fromAandB.Substring(fromAandB.IndexOf(' ') + 1));

            List<Operation> operations = new List<Operation>();
            for (int i = 0; i < fromA; i++)
            {
                string line = sr.ReadLine();
                operations.Add(new Operation(line.Substring(0, line.IndexOf(' ')), "depA", 0));
                operations.Add(new Operation(line.Substring(line.IndexOf(' ') + 1), "arrB", turnTime));
            }
            
            for (int i = 0; i < fromB; i++)
            {
                string line = sr.ReadLine();
                operations.Add(new Operation(line.Substring(0, line.IndexOf(' ') ), "depB",0));
                operations.Add(new Operation(line.Substring(line.IndexOf(' ') + 1), "arrA", turnTime));
            }

            var sortedOps = from op in operations
                            orderby op.TimeInMinutes , op.OperationType
                            select op;

            int maxA = 0;
            int maxB = 0;
            int countA = 0;
            int countB = 0;
            foreach (var operation in sortedOps)
            {
                switch (operation.OperationType)
                {
                    case "arrA":
                        countA--;
                        break;
                    case "arrB":
                        countB--;
                        break;
                    case "depA":
                        countA++;
                        if (countA > maxA)
                            maxA = countA;
                        break;
                    case "depB" :
                        countB++;
                        if (countB > maxB)
                            maxB = countB;
                        break;
                }
            }

            return string.Format("{0} {1}", maxA, maxB);
        }

        private class Operation
        {
            public Operation(string time, string operationType, int minutesToAdd)
            {                
                TimeInMinutes = (int) new TimeSpan(int.Parse(time.Substring(0,2)),int.Parse(time.Substring(3,2)),0 ).TotalMinutes + minutesToAdd;
                OperationType = operationType;
            }

            public int TimeInMinutes;
            public string OperationType;  // depA, arrB, depB, arrA
        }
    }
}
