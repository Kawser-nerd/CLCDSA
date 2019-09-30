using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    public class Solver
    {
        int answer;
        int A, B, C;

        public void Run()
        {
            using (FileStream input = new FileStream("B-small-attempt0.in", FileMode.Open))
            //using (FileStream input = new FileStream("input.txt", FileMode.Open))
            using (FileStream output = new FileStream("output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0; tt < test; tt++)
                {
                    ReadInput(reader);
                    SolveTask();
                    WriteOutput(writer, tt + 1);
                }
            }

        }

        private void SolveTask()
        {
            answer = 0;
            for (int i = 0; i < A; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    if ((i & j) < C)
                    {
                        answer++;
                    }
                }
            }
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            //writer.WriteLine("{0} {1} {2}",A, B, C);
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, answer.ToString()));
        }

        private void ReadInput(StreamReader reader)
        {
            string[] str = reader.ReadLine().Split(' ');
            A = Int32.Parse(str[0]);
            B = Int32.Parse(str[1]);
            C = Int32.Parse(str[2]);
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            (new Solver()).Run();
        }

    }
}
