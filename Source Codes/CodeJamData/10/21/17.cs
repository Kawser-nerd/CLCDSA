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

    public class A : Problem
    {
        private int ProcessDir(HashSet<string> fs, string dir)
        {
            var result = 0;
            if (dir[0] != '/')
                dir = '/' + dir;
            if (dir[dir.Length - 1] != '/')
                dir += '/';
            for (var i = 1; i < dir.Length; i++)
            {
                if (dir[i] != '/')
                    continue;
                var subdir = dir.Substring(0, i);
                if (fs.Contains(subdir)) 
                    continue;
                fs.Add(subdir);
                result++;
            }
            return result;
        }

        public override void Solve()
        {
            var str = ReadArray();
            int n = int.Parse(str[0]), m = int.Parse(str[1]);
            var fs = new HashSet<string>();
            for (var i = 0; i < n; i++)
                ProcessDir(fs, ReadLine());
            var result = 0;
            for (var i = 0; i < m; i++)
                result += ProcessDir(fs, ReadLine());
            WriteLine(result.ToString());
        }
    }
}