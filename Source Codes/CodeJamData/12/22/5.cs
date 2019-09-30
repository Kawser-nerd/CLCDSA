using System;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace GCJ_base
{
    public abstract class Gcj
    {
        protected char Problem;
        protected bool Small;
        protected int Attempt;

        protected abstract string ComputeCase(TextReader reader);

        public void Run()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
#if DEBUG
            using (TextReader reader = Console.In)
            using (TextWriter writer = Console.Out)
#else
            string size = Small ? string.Format("small-attempt{0}", Attempt) : "large";
            string inputFile = string.Format(@"C:\Users\Svick\Downloads\{0}-{1}.in", Problem, size);
            string outputFile = string.Format(@"C:\Users\Svick\Desktop\GCJ\{0}-{1}.txt", Problem, size);
            using (TextReader reader = new StreamReader(inputFile))
            using (TextWriter writer = new StreamWriter(outputFile))
#endif
            {
                int N = int.Parse(reader.ReadLine());
                var sb = new StringBuilder();
                for (int i = 0; i < N; i++)
                {

                    string result = ComputeCase(reader);
                    string resultLine = string.Format("Case #{0}: {1}", i + 1, result);
#if !DEBUG
                    Console.WriteLine(resultLine);
#endif
                    sb.AppendLine(resultLine);
                }

                writer.Write(sb);
            }
        }
    }
}