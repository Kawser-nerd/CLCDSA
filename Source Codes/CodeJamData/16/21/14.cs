using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace jam
{



    abstract class AJam
    {
        public List<string> GetResults(IList<string> lines)
        {
            var results = new List<string>();
            foreach (var test in EnumerateTests(lines))
            {
                results.Add(Solve(test));
            }
            return results;
        }
        public List<string> ParallelGetResults(IList<string> lines)
        {
            var tests = EnumerateTests(lines).ToArray();
            var indexes = Enumerable.Range(0, tests.Length).ToArray();
            var results = new Dictionary<int, string>();
            var parallelOptions = new ParallelOptions();
            parallelOptions.MaxDegreeOfParallelism = 4;
            Parallel.ForEach(indexes, parallelOptions, i => { var r = SolveThreadSafe(tests[i]); lock (results) { results[i] = r; } });
            return results.OrderBy(p => p.Key).Select(p => p.Value).ToList();
        }
        string SolveThreadSafe(TestCase test)
        {
            var instance = System.Activator.CreateInstance(this.GetType()) as AJam;
            return instance.Solve(test);
        }

        public virtual IEnumerable<TestCase> EnumerateTests(IList<string> lines)
        {
            return JamUtils.SplitCases(lines);
        }
        public abstract string Solve(TestCase test);
        public virtual void Test() { }


        public static IEnumerable<string> FormatResult(IEnumerable<string> rawResults, bool writeResults = false)
        {
            int i = 1;
            foreach (var result in rawResults)
            {
                var resultLine = "Case #" + i + ": " + result;
                if (writeResults)
                    Console.WriteLine(resultLine);
                yield return resultLine;
                i++;
            }
        }
        public static IEnumerable<string> FormatResultOneLine(IEnumerable<string> rawResults)
        {
            yield return "Case #1:";
            int i = 1;
            foreach (var result in rawResults)
            {
                yield return result;
                i++;
            }
        }

    }

    public class TestCase
    {
        public string Header;
        public List<string> Lines;

        public override string ToString()
        {
            return Header + "\r\n " + string.Join( "\r\n" ,Lines);
        }

    }

    public static class JamUtils
    {

        public static int ParseNbLines(string header)
        {
            //return header.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
            //             .Select(str => int.Parse(str))
            //             .Sum();
            return int.Parse(header.Split(' ').First()); ;
        }

        public static IEnumerable<TestCase> SplitCases(IList<string> lines, Func<string, int> parseNbLines, bool skipHeader = true)
        {
            int nbCases = int.Parse(lines.First());
            int currentLine = 1;
            for (int i = 0; i < nbCases; i++)
            {
                var header = lines[currentLine];
                if( skipHeader)
                    currentLine++;
                int nbLines = parseNbLines(header);
                var content = lines.Skip(currentLine).Take(nbLines).ToList();
                var testCase = new TestCase() { Header = header, Lines = content };
                yield return testCase;
                currentLine += nbLines;
            }
        }


        public static IEnumerable<TestCase> SplitCases(IList<string> lines)
        {
            return SplitCases(lines, ParseNbLines);
        }

        public static IEnumerable<TestCase> SplitCases(IList<string> lines, int linesPerCase)
        {
            return SplitCases(lines, (s) => linesPerCase, skipHeader:false);
        }

        //public static IEnumerable<TestCase> SplitCasesBis(IList<string> lines)
        //{
        //    int nbCases = int.Parse(lines.First());
        //    int lastReadLine = 0;
        //    for (int i = 0; i < nbCases; i++)
        //    {
        //        lastReadLine++;
        //        var header = lines[lastReadLine];
        //        int nbLines = 2 * ParseNbLines(header) - 1;
        //        var content = lines.Skip(lastReadLine + 1).Take(nbLines).ToList();
        //        var testCase = new TestCase() { Header = header, Lines = content };
        //        yield return testCase;
        //        lastReadLine += nbLines;
        //    }
        //}

    }

    public static class JamUtilsExtensions
    {
        public static T ArgMax<T>(this IEnumerable<T> x, Func<T, double> GetValue)
        {
            double maxValue = double.NegativeInfinity;
            T argmax = default(T);
            foreach (T t in x)
            {
                double value = GetValue(t);
                if (value > maxValue)
                {
                    argmax = t;
                    maxValue = value;
                }
            }
            return argmax;
        }
        public static int IndexOfMax<T>(this IEnumerable<T> x, Func<T, double> GetValue)
        {
            double maxValue = double.NegativeInfinity;
            int index = 0;
            int n = x.Count();
            for (int i = 0; i < n; i++)
            {
                T t = x.ElementAt(i);
                double value = GetValue(t);
                if (value > maxValue)
                {
                    index = i;
                    maxValue = value;
                }
            }
            return index;
        }
        public static X GetOrAddNew<K, X>(this Dictionary<K, X> dico, K key) where X : new()
        {
            if (dico.ContainsKey(key))
            {
                return dico[key];
            }
            else
            {
                X x = new X();
                dico[key] = x;
                return x;
            }
        }

        public static IEnumerable<int> GetIndexesWhere<T>(this IEnumerable<T> list, Func<T, bool> where)
        { 
            int index = 0;
            foreach (var t in list)
            {
                if (where(t))
                    yield return index;
                index++;
            }
        }


    }


}
