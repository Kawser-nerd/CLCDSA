using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace ProblemC
{
    class MainClass
    {
        private const char ProblemSet = 'C';


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

                        double u = double.Parse(ins.ReadLine());

                        line = ins.ReadLine();
                        l = line.Split();

                        double[] p = new double[n];

                        for(int i  =0; i  < n; i++)
                        {
                            p[i] = double.Parse(l[i]);
                        }

                        Array.Sort(p);

                        int start = n - k;

                        for (int i = start; i < n; i++)
                        {
                            if (u <= 0)
                                break;
                            
                            double diff = (i < n - 1 ? p[i + 1] : 1) - p[i];

                            double addToEach = Math.Min((u / (i - start + 1)), diff);
                            for (int j = start; j <= i; j++)
                            {
                                p[j] += addToEach;
                                u -= addToEach;
                            }
                        }


                        double probabilityOfTotalSuccess = 1;

                        for (int i = 0; i < n; i++)
                        {
                            probabilityOfTotalSuccess *= p[i];
                        }                       

                        // this only solves case 1
                        outs.WriteLine(probabilityOfTotalSuccess);
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
