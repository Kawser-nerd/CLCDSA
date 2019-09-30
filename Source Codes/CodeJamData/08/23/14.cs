using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Qualification
{
    class ProblemC
    {

        public ProblemC()
        {
        }

        static int[] Generate(int n)
        {
            int[] result = new int[n];
            int i;
            for (i = 0; i < n; i++)
            {
                result[i] = -1;
            }
            int position = 0;
            int desirableValue = 1;
            int counts = 0;

            int elasped = n;

            while (elasped > 0)
            {
                while (result[position] != -1)
                {
                    position++;
                    if (position >= n) position = 0;
                }

                counts++;
                if (counts == desirableValue)
                {
                    result[position] = desirableValue;
                    desirableValue++;
                    counts = 0;
                    elasped--;
                }
                position++;
                if (position >= n) position = 0;
            }


            return result;
        }


        public void SolveOne(int N, int[] indices, StreamWriter writer)
        {
            int[] res = Generate(N);
            int i;
            for (i = 0; i < indices.Length; i++)
            {
                writer.Write(res[indices[i] - 1]);
                if (i != indices.Length - 1)
                    writer.Write(' ');
            }

        }

        public void SolveAll(string inputFN, string outputFN)
        {
            StreamReader reader = new StreamReader(inputFN);
            StreamWriter writer = new StreamWriter(outputFN);

            int numberOfCases = int.Parse(reader.ReadLine());
            Console.Write("Number of cases = ");
            Console.WriteLine(numberOfCases);
            for (int i = 0; i < numberOfCases; i++)
            {
                int[] indices;
                int N = int.Parse(reader.ReadLine());
                string[] data = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int numOfInd = int.Parse(data[0]);
                indices = new int[numOfInd];
                for (int j = 1; j <= numOfInd; j++)
                    indices[j - 1] = int.Parse(data[j]);
                writer.Write("Case #");
                writer.Write(i + 1);
                writer.Write(": ");
                SolveOne(N, indices, writer);
                writer.WriteLine();

                Console.Write("Case ");
                Console.Write(i + 1);
                Console.WriteLine(" solved!");
            }

            writer.Close();
            reader.Close();
            
        }

        static void Main(string[] args)
        {
            ProblemC prC = new ProblemC();
            prC.SolveAll("C-small.in", "C-small.out");
            Console.WriteLine("Finished!");
            Console.ReadLine();
        }
    }
}
