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

    public class C : Problem
    {
        private const int Hi = 501;
        private const int Mod = 100003;

        private static int[] N = new int[Hi + 1];
        static C()
        {
            var c = new int[Hi + 1,Hi + 1];
            c[0, 0] = 1;
            for (var i = 1; i < Hi; i++)
            {
                c[i, 0] = c[i, i] = 1;
                for (var j = 1; j < i; j++)
                    c[i, j] = (c[i - 1, j] + c[i - 1, j - 1])%Mod;
            }
            var a = new int[Hi + 1,Hi + 1];
            for (var i = 2; i <= Hi; i++)
                a[i, 1] = 1;
            for (var n = 3; n <= Hi; n++)
                for (var cnt = 2; cnt < n; cnt++)
                    for (var k = 1; k < cnt; k++)
                    {
                        if (n == 4 && cnt == 3)
                        {
                            
                        }
                        a[n, cnt] = (a[n, cnt] + (a[cnt, k]*c[n - cnt - 1, cnt - k - 1])%Mod)%Mod;
                    }
            for (var i = 0; i <= Hi; i++)
                for (var j = 0; j <= Hi; j++)
                    N[i] = (N[i] + a[i, j])%Mod;
        }

        public override void Solve()
        {
            var n = int.Parse(ReadLine());
            WriteLine(N[n].ToString());
        }
    }
}