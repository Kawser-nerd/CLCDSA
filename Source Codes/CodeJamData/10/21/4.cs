using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemA
{
	static void Main(string[] args)
	{
		//TextReader sr = new StreamReader(@"c:\temp\a.in");
        //TextReader sr = new StreamReader(@"c:\temp\a-small-attempt0.in");
		TextReader sr = new StreamReader(@"c:\temp\a-large.in");
		//		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\a.out");
		//TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

    class Directory 
    {
        public Dictionary<string, Directory> SubDirectories = new Dictionary<string, Directory>();
        
        public int Create(string path)
        {
            if (path == "") return 0;
            int ix = path.IndexOf('/');
            if (ix < 0) {
                if (SubDirectories.ContainsKey(path))
                    return 0;
                SubDirectories.Add(path, new Directory());
                return 1;
            }
            string first = path.Substring(0,ix);
            string second = path.Substring(ix+1);
            int cnt = 0;
            if (!SubDirectories.ContainsKey(first))
            {
                SubDirectories.Add(first, new Directory());
                cnt++;
            }
            return cnt + SubDirectories[first].Create(second);
        }
    }

	private static void Solve(TextReader sr, TextWriter sw)
	{
        var parts = sr.ReadLine().Split(' ');
        int N = int.Parse(parts[0]);
        int M = int.Parse(parts[1]);
        Directory root = new Directory();
        for (int i = 0; i < N; i++)
        {
            string path = sr.ReadLine().Substring(1);
            root.Create(path);
        }
        List<string> toCreate = new List<string>();
        for (int i = 0; i < M; i++)
        {
            string path = sr.ReadLine().Substring(1);
            toCreate.Add(path);
        }
        toCreate.Sort((x, y) => x.Length - y.Length);
        int sum = 0;
        foreach (string path in toCreate)
        {
            sum += root.Create(path);
        }
        sw.WriteLine(sum);
	}

}
