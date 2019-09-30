using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Text;

namespace CodeJam2009
{
	public class Program
	{
		static void Main(string[] args)
		{
			try
			{
				if (args.Length == 0)
				{
					WriteMessage("use the file name as argument");
					return;
				}
				if (!System.IO.File.Exists(args[0]))
				{
					WriteMessage("specified file not found");
					return;
				}
				string[] FileStrings = System.IO.File.ReadAllLines(args[0]);
				if (FileStrings == null || FileStrings.Length == 0)
					return;
				int casesNumber = 0;
				int startLine = 0;
				object problemParam = null;
                IProblem problem = new ProblemB();
				try
				{
					problemParam = problem.GetProplemParam(out casesNumber, ref startLine, ref FileStrings);
				}
				catch (Exception ex)
				{
					WriteError(string.Format("{0}", ex));
					casesNumber = 0;
				}
				if (casesNumber == 0)
				{
					WriteMessage("error in specifing line numbers");
					return;
				}
				string[] res = new string[casesNumber];
				for (int i = 0; i < casesNumber; i++)
				{
					object caseParam = null;
					try
					{
						caseParam = problem.GetCaseParam(i, ref startLine, ref FileStrings, problemParam);
						res[i] = problem.GetCaseResult(i, caseParam, problemParam);
					}
					catch (Exception ex)
					{
						WriteError(string.Format("case:{0};Ex:{1};", i, ex));
						res[i] = string.Empty;
					}
					WriteMessage(string.Format("case {0,8} of {1,8}", i + 1, casesNumber));
				}
				System.IO.File.WriteAllLines("out.txt", res);
			}
			finally
			{
				WriteMessage("Done");
				System.Console.ReadLine();
			}
		}

		private static void WriteMessage(string Message)
		{
			System.Console.WriteLine(Message);
		}

		private static void WriteError(string Error)
		{
            System.Console.WriteLine(Error);
		}
	}

	public interface IProblem
	{
		object GetProplemParam(out int casesNumber, ref int startLine, ref string[] FileStrings);
		object GetCaseParam(int caseIndex, ref int startLine, ref string[] FileStrings, object ProblemParam);
		string GetCaseResult(int caseIndex, object caseParam, object ProblemParam);
	}

    public class ProblemB : IProblem
    {
        public object GetProplemParam(out int casesNumber, ref int startLine, ref string[] FileStrings)
        {
            casesNumber = int.Parse(FileStrings[startLine++]);
            return null;
        }

        public object GetCaseParam(int caseIndex, ref int startLine, ref string[] FileStrings, object ProblemParam)
        {
            ProblemBParam res = new ProblemBParam();
            int N = int.Parse(FileStrings[startLine++].Trim());

            for (int i = N - 1; i >= 0; i--)
            {
                string s = System.Text.RegularExpressions.Regex.Replace(FileStrings[startLine++].Trim(), "\\s+", " ");
                string[] vals = s.Split(' ');
                res.startX += int.Parse(vals[0]);
                res.startY += int.Parse(vals[1]);
                res.startZ += int.Parse(vals[2]);
                res.vX += int.Parse(vals[3]);
                res.vY += int.Parse(vals[4]);
                res.vZ += int.Parse(vals[5]);
            }
            res.startX /= N;
            res.startY /= N;
            res.startZ /= N;
            res.vX /= N;
            res.vY /= N;
            res.vZ /= N;
            return res;
        }

        public string GetCaseResult(int caseIndex, object caseParam, object ProblemParam)
        {
            double X0 = ((ProblemBParam)caseParam).startX;
            double Y0 = ((ProblemBParam)caseParam).startY;
            double Z0 = ((ProblemBParam)caseParam).startZ;

            double A = ((ProblemBParam)caseParam).vX;
            double B = ((ProblemBParam)caseParam).vY;
            double C = ((ProblemBParam)caseParam).vZ;

            double t = -(X0 * A + Y0 * B + Z0 * C) / (A * A + B * B + C * C);
            if ((t.Equals(double.NaN)) || t < 0)
                t = 0;
            A = X0 + t * A;
            B = Y0 + t * B;
            C = Z0 + t * C;
            double distance = Math.Sqrt(A * A + B * B + C * C);
            return string.Format("Case #{0}: {1} {2}", (caseIndex + 1), distance.ToString("0.00000000").Replace(',', '.'), t.ToString("0.00000000").Replace(',', '.'));
        }
    }

    public class ProblemBParam
    {
        public double startX = 0;
        public double startY = 0;
        public double startZ = 0;

        public double vX = 0;
        public double vY = 0;
        public double vZ = 0;
    }
}
