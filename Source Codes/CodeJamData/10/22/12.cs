using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Collections.Generic;

namespace GoogleCodeJam
{
    public abstract class Problem
    {
        protected static readonly string CurrentDirectory =
            Path.GetDirectoryName(Assembly.GetExecutingAssembly().GetName().CodeBase).Remove(0, 6);

        private StreamReader _reader;
        private StreamWriter _writer;

        protected Problem()
        {
            ProblemName = GetType().Name;
        }

        #region IO
        protected void WriteLine(string line)
        {
            _writer.WriteLine(line);
            _writer.Flush();
        }

        protected string ReadLine()
        {
            return _reader.ReadLine();
        }

        protected string[] ReadArray()
        {
            return ReadLine().Split(' ');
        }
        #endregion

        public string ProblemName { get; private set; }

        public void SolveAll()
        {
            foreach (var fileName in Directory.GetFiles(CurrentDirectory, string.Format("{0}-*.in", ProblemName)))
            {
                try
                {
                    var outputFileName = Path.ChangeExtension(fileName, ".out");
                    _reader = new StreamReader(fileName);
                    _writer = new StreamWriter(outputFileName);
                    var testCount = int.Parse(ReadLine());
                    for (var i = 0; i < testCount; i++)
                    {
                        _writer.Write("Case #{0}: ", i + 1);
                        Solve();
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    Console.WriteLine(ex.StackTrace);
                }
                finally
                {
                    _reader.Close();
                    _writer.Close();
                }
            }
        }

        public abstract void Solve();
    }

    internal class Program
    {
        private static void Main()
        {
            foreach (var type in Assembly.GetExecutingAssembly().GetTypes().Where(type => typeof (Problem).IsAssignableFrom(type) && type != typeof (Problem)))
            {
                try
                {
                    ((Problem) Activator.CreateInstance(type)).SolveAll();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    Console.WriteLine(ex.StackTrace);
                }
            }
        }
    }

    public class B : Problem
    {
        
        public override void Solve()
        {
            var str = ReadArray();
            int n = int.Parse(str[0]),
                k = int.Parse(str[1]),
                b = int.Parse(str[2]),
                t = int.Parse(str[3]);
            int[] x = new int[n],
                v = new int[n];
            str = ReadArray();
            for (var i = 0; i < n; i++)
                x[i] = int.Parse(str[i]);
            str = ReadArray();
            var g = new bool[n];
            var cnt = 0;
            for (var i = 0; i < n; i++)
            {
                v[i] = int.Parse(str[i]);
                g[i] = (1L*x[i] + v[i]*t) >= b;
                if (g[i])
                    cnt++;
            }
            if (cnt < k)
            {
                WriteLine("IMPOSSIBLE");
                return;
            }
            int pos = n - 1, result = 0;
            var z = new int[n];
            for (var i = n - 1; i >= 0; i--)
            {
                if (i < n - 1)
                    z[i] += z[i + 1];
                if (g[i])
                {
                    k--;
                    if (k == 0)
                    {
                        pos = i;
                        break;
                    }
                }
                else
                    z[i]++;
            }
            for (var i = pos; i < n; i++)
                if (g[i])
                    result += z[i];
            WriteLine(result.ToString());
        }
    }
}