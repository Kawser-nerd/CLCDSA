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

            createDictionary(googlerese, english);

            //Process cases
            for (int i = 1; i <= nSamples; i++)
            {
                if (streamReader.EndOfStream) break;
                processCase(i);
            }
            streamWriter.Flush();
        }

        static string googlerese = "y qeeejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
        static string english = "a zooour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

        static Dictionary<char, char> dictionary = new Dictionary<char, char>();

        static private void createDictionary(string g, string e)
        {
            for (int i = 0; i < Math.Min(g.Length, e.Length); i++)
            {
                char c = g[i];
                char ec = e[i];
                if (!dictionary.ContainsKey(c))
                {
                    dictionary.Add(c, ec);
                }
            }
        }


        static private string toEnglish(char c)
        {
            if (dictionary.ContainsKey(c)) return ""+dictionary[c];
            foreach (char newC in "abcdefghijklmnopqrstuvwxyz")
            {
                if (!dictionary.ContainsValue(newC))
                {
                    dictionary.Add(c, newC);
                    return ""+newC;
                }
            }
            return "-";
        }

        static public void processCase(int currentCaseNumber)
        {
            string caseResult = "";
            string debugString = "";

            string googlereseString = "";
            string englishString = "";
            //Reading case variables
            processLine((s)=>googlereseString=s);
            
            for (int i = 0; i < googlereseString.Length; i++)
            {
                englishString += toEnglish(googlereseString[i]);
            }

            caseResult = englishString;
            //Result
            streamWriter.WriteLine("Case #" + currentCaseNumber + ": " + caseResult + debugString);
        }
    }

}
