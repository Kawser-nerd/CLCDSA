using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem2011_1C_A
{
    class Program
    {
        static StreamReader streamReader;
        static StreamWriter streamWriter;

        static void processLine(Action<string> action)
        {
            action.Invoke(streamReader.ReadLine());
        }

        static void processLine(Action<IEnumerator<string>>[] actions)
        {
            processLine(() => { return streamReader.ReadLine().Split(' '); }, actions);
        }

        static void processLine(Func<string[]> splitFunc, Action<IEnumerator<string>>[] actions)
        {
            string[] parts = splitFunc.Invoke();
            IEnumerator<string> partsEnumerator = (IEnumerator<string>)parts.AsEnumerable<string>().GetEnumerator();
            partsEnumerator.Reset();
            foreach (Action<IEnumerator<string>> action in actions)
            {
                partsEnumerator.MoveNext();
                action.Invoke(partsEnumerator);
            }
        }

        static void Main(string[] args)
        {
            //Using fisrt arg as input file path
            FileStream inputFileStream = new FileStream(args[0], FileMode.Open);
            //Using second arg as output file path
            FileStream outputFileStream = new FileStream(args[1], FileMode.Create);

            //Stream Reader to read lines as strings
            streamReader = new StreamReader(inputFileStream);

            //Stream Writer to write strings as lines
            streamWriter = new StreamWriter(outputFileStream);

            //Reading amount of cases
            int nSamples = 0;
            processLine((s) => { nSamples = int.Parse(s); });

            //Process cases
            for (int i = 1; i <= nSamples; i++)
            {
                if (streamReader.EndOfStream) break;
                processCase(i);
            }
            streamWriter.Flush();
        }

        static public void processCase(int currentCaseNumber)
        {
            string caseResult = "";
            string debugString = "";
            int count = 0;
            int N = 0;
            int S = 0;
            int p = 0;

            //Reading case variables
            processLine(new Action<IEnumerator<string>>[]
            {
                (e) => N = int.Parse(e.Current),
                (e) => S = int.Parse(e.Current),
                (e) => p = int.Parse(e.Current),
                (e) => 
                {
                    for (int i = 0; i < N; i ++)
                    {
                        int t = int.Parse(e.Current);
                        int b = t/3;
                        int r = t%3;
                        if ((b+Math.Min(1, r)) >= p)
                        {
                            count++;
                        } else
                        {
                            if (S > 0)
                            {
                                if (
                                    ((r == 2) && ((b+r) >= p)) ||
                                    ((r == 0) && (b>0) && ((b+1)>= p))
                                    )
                                {
                                    count++;
                                    S--;
                                }
                            }
                        }
                        e.MoveNext();
                    }
                }
            });
            
            caseResult = ""+count;
            //Result
            streamWriter.WriteLine("Case #" + currentCaseNumber + ": " + caseResult + debugString);
        }
    }

}
