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

        static int[][] dictionary = new int[2000001][];

        static void calcDictionary()
        {
            for (int i = 1; i < dictionary.Length; i++)
            {
                dictionary[i] = calcRecycled(i);
            }
        }

        static int[] calcRecycled(int v)
        {
            List<int> recycled = new List<int>();
            string sv = "" + v;
            for (int i = 1; i < sv.Length; i++)
            {
                string sr = sv.Substring(i) + sv.Substring(0, i);
                int r = int.Parse(sr);
                if (r > v)
                {
                    if (!recycled.Contains(r)) recycled.Add(r);
                }
            }
            return recycled.ToArray();
        }

        static int countRecycled(int A, int B)
        {
            int count = 0;
            for (int i = A; i <= B; i++)
            {
                for (int j = 0; j < dictionary[i].Length; j++)
                {
                    if ((dictionary[i][j] >= A) && (dictionary[i][j] <= B)) count++;
                }
            }
            return count;
        }

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

            calcDictionary();

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
            int A = 0;
            int B = 0;

            //Reading case variables
            processLine(new Action<IEnumerator<string>>[]
            {
                (e) => A = int.Parse(e.Current),
                (e) => B = int.Parse(e.Current)
            });

            count = countRecycled(A, B);
            
            caseResult = ""+count;
            //Result
            streamWriter.WriteLine("Case #" + currentCaseNumber + ": " + caseResult + debugString);
        }
    }

}
