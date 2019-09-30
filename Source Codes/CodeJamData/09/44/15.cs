using System.IO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GoogleComp
{
    class Program4
    {
        const string directory = @"C:/temp";
        const string question = "D";

        static void Main(string[] args)
        {
//            string sample = String.Format("{0}/{1}-sample.in", directory, question);
            string small = String.Format("{0}/{1}-small-attempt1.in", directory, question);
            string large = String.Format("{0}/{1}-large.in", directory, question);

            string input = small;
            var reader = new InputReader(input);

            List<Object> results = new List<object>();
            int N = reader.readInt();
            Trace.WriteLine(string.Format("Computing output for {0} test cases", N));
            for (int i = 0; i < N; i++)
            {
                object result = performTest(reader);
                results.Add(result);
            }

            string output = String.Format("{0}.txt", input);
            PrintResult(output, results);
        }

        private static object performTest(InputReader reader)
        {
            
            var plants = new List<Plant>();
            int numPlants = reader.readInt();
            for (int i = 0; i < numPlants; i++)
            {
                var ints = reader.readInts();
                var p = new Plant {x = ints[0], y = ints[1], R = ints[2]};
                plants.Add(p);
            }

            if (plants.Count == 1)
            {
                return plants[0].R;
            } else if (plants.Count == 2)
            {
                return Math.Max(plants[0].R, plants[1].R);
            }

            // find all possibilities and then lowest
            double s1 = getRadius(plants, 0, 1, 2);
            double s2 = getRadius(plants, 0, 2, 1);
            double s3 = getRadius(plants, 1, 2, 0);

            return Math.Min(Math.Min(s1, s2), s3);
        }

        private static double getRadius(List<Plant> plants, int first, int second, int third)
        {
            double minRadius = Program4.minRadius(plants[first], plants[second]);
            return Math.Max(minRadius, plants[third].R);
        }

        private static double minRadius(Plant p1, Plant p2)
        {
            double distance = Math.Sqrt(Math.Pow(p1.x - p2.x, 2) + Math.Pow(p1.y - p2.y, 2));
            return (distance + p1.R + p2.R) / 2;
        }

        private class Plant
        {
            public double x { get; set; }
            public double y { get; set; }
            public int R { get; set; }
        }

        private class Point
        {
            public decimal x { get; set; }
            public decimal y { get; set; }
        }

        private static void PrintResult(string output, IEnumerable<Object> results)
        {
            Trace.WriteLine(string.Format("Writing output file {0}", output));

            File.Delete(output);
            StreamWriter writer = File.CreateText(output);

            int testCase = 1;
            foreach(Object result in results) {
                string caseResult = string.Format("Case #{0}: {1}", testCase++, result.ToString());
                writer.WriteLine(caseResult);
                Trace.WriteLine(caseResult);
            }
            writer.Close();
        }

        private class InputReader
        {
            private int currentLine = 0;
            private string[] inputLines;

            public InputReader(string fileName)
            {
                Trace.WriteLine(string.Format("Reading input file {0}", fileName));
                inputLines = File.ReadAllLines(fileName);
	        }
        	
	        public int readInt() 
            {
		        return Int32.Parse(readLine());
	        }
        	
	        public int[] readInts()
            {
                string line = readLine();
                string[] numbers = line.Split(' ');
		        int[] retVal = new int[numbers.Length];
                for (int i = 0; i < numbers.Length; i++)
                {
			        retVal[i] = Int32.Parse(numbers[i]);
		        }
        		
		        return retVal;
	        }

            public string readLine()
            {
                return inputLines[currentLine++];
	        }

            public List<string> readLines(int numLines)
            {
                List<string> retVal = new List<string>();
		        for (int i = 0; i < numLines; i++) {
			        retVal.Add(readLine());
		        }
        		
		        return retVal;
	        }
        }
    }
}
