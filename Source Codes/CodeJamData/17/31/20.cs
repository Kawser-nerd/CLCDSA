using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace ProblemA
{
    class MainClass
    {
        private const char ProblemSet = 'A';


        private static string GetProgramFilePath()
        {
            string exe = System.Reflection.Assembly.GetEntryAssembly().Location;

            var path = Path.GetFullPath(exe);

            var problemIndex = path.IndexOf("Problem");

            var pathToSource = path.Substring(0, problemIndex + 9);

            return pathToSource + "Problem"+ProblemSet+"/Program.cs";
        }


        private static string GetInputPath()
        {
            var downloads = "/Users/trevordasch/Downloads/";

            return Directory.GetFiles(downloads).Where(f => Path.GetFileName(f).StartsWith(ProblemSet + "-", StringComparison.InvariantCultureIgnoreCase) && f.EndsWith(".in")).OrderBy(f => File.GetLastWriteTimeUtc(f)).LastOrDefault();
        }

        private static string GetOutputSourcePath(string inputPath)
        {
            return inputPath.Replace(".in", ".cs");
        }

        private static string GetOutputPath(string inputPath)
        {
            return inputPath.Replace(".in", ".out");
        }

        private static StreamReader GetInputStream(string inputPath)
        {
            if (string.IsNullOrEmpty(inputPath))
            {
                return new StreamReader(Console.OpenStandardInput());
            }
            else
            {
                return new StreamReader(File.OpenRead(inputPath));
            }
        }
        private static StreamWriter GetOutputStream(string inputPath)
        {
            if (string.IsNullOrEmpty(inputPath))
            {
                return new StreamWriter(Console.OpenStandardOutput());
            }
            else
            {
                var path = GetOutputPath(inputPath);

                if (File.Exists(path))
                {
                    File.Delete(path);
                }
                return new StreamWriter(File.Open(path, FileMode.Create));
            }
        }

        public static void Main(string[] args)
        {
            Console.WriteLine(GetProgramFilePath());

            var inputPath = GetInputPath();
            Console.WriteLine("Running Problem "+ ProblemSet + " on " +inputPath);

            using (var ins = GetInputStream(inputPath))
            {

                using (var outs = GetOutputStream(inputPath))
                {

                    var caseCount = int.Parse(ins.ReadLine());


                    for (int caseNo = 1; caseNo <= caseCount; caseNo++)
                    {
                        outs.Write("Case #" + caseNo + ": ");

                        var line = ins.ReadLine();
                        var l = line.Split();

                        int n = int.Parse(l[0]);
                        int k = int.Parse(l[1]);


                        List<Tuple<long, long>> pairs = new List<Tuple<long, long>>();

                        for (int i = 0; i < n; i++)
                        {
                            line = ins.ReadLine();
                            l = line.Split();

                            long r = long.Parse(l[0]);
                            long h = long.Parse(l[1]);

                            pairs.Add(new Tuple<long, long>(r, h));
                        }

                        pairs.Sort((a, b) => (b.Item2 * b.Item1).CompareTo(a.Item2 * a.Item1));

                        long hSum = 0;

                        long maxR = 0;
                        for (int i = 0; i < k; i++)
                        {
                            hSum += pairs[i].Item1 * pairs[i].Item2 * 2;

                            if (pairs[i].Item1 > maxR)
                            {
                                maxR = pairs[i].Item1;
                            }
                        }

                        long minEdge = pairs[k - 1].Item1 * pairs[k - 1].Item2 * 2;

                        long newMaxR = 0;
                        long newMaxH = 0;
                        long maxEdge = 0;
                        long maxSurface = 0;
                        // check for a better base pancake
                        for (int i = k; i < n; i++)
                        {
                            long edge = pairs[i].Item1 * pairs[i].Item2 * 2;

                            long surface = pairs[i].Item1 * pairs[i].Item1;

                            if (edge + surface > maxEdge + maxSurface)
                            {
                                newMaxR = pairs[i].Item1;
                                newMaxH = pairs[i].Item2;
                                maxEdge = edge;
                                maxSurface = surface;
                            }
                        }

                        if (maxSurface + maxEdge > maxR * maxR + minEdge)
                        {
                            hSum -= minEdge;
                            hSum += maxEdge;
                            maxR = newMaxR;
                        }


                        double area = hSum * Math.PI + maxR * maxR * Math.PI;


                        outs.WriteLine(area);
                    }

                }
            }

            if (!string.IsNullOrEmpty(inputPath))
            {
                var outCs = GetOutputSourcePath(inputPath);
                if (File.Exists(outCs))
                    File.Delete(outCs);

                File.Copy(GetProgramFilePath(), outCs);
            }
        }
    }
}
