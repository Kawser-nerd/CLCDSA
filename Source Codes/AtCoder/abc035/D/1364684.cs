using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        int matiCount = (int)inpt[0];
        int roadCount = (int)inpt[1];
        long timeLimit = inpt[2];

        long[] okane = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        for (int i = 0; i < roadCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
            int matiFrom = (int)inpt[0] - 1;
            int matiTo = (int)inpt[1] - 1;
            long cost = inpt[2];
            if(!Road.ContainsKey(matiFrom)) {
                this.Road.Add(matiFrom, new Dictionary<int, long>());
            }
            this.Road[matiFrom].Add(matiTo, cost);
			if (!RoadRev.ContainsKey(matiTo))
			{
				this.RoadRev.Add(matiTo, new Dictionary<int, long>());
			}
            this.RoadRev[matiTo].Add(matiFrom, cost);
		}

        long[] FromStart = new long[matiCount];
        long[] ToStart = new long[matiCount];
        Queue<int> task = new Queue<int>();
        task.Enqueue(0);
        while(task.Count > 0) {
            int cur = task.Dequeue();
            long step = FromStart[cur];
            if(!this.Road.ContainsKey(cur)) {
                continue;
            }
            foreach(int next in Road[cur].Keys) {
                if ((next != 0 && FromStart[next] == 0) || FromStart[next]>step+Road[cur][next]) {
					FromStart[next] = step + Road[cur][next];
					task.Enqueue(next);
				}
            }
        }
        task.Enqueue(0);
        while(task.Count() > 0) {
			int cur = task.Dequeue();
            long step = ToStart[cur];
			if (!this.RoadRev.ContainsKey(cur))
			{
				continue;
			}
			foreach (int next in RoadRev[cur].Keys)
			{
				if ((next != 0 && ToStart[next] == 0) || ToStart[next] > step + RoadRev[cur][next])
				{
					ToStart[next] = step + RoadRev[cur][next];
					task.Enqueue(next);
				}
			}
		}

        long ans = okane[0] * timeLimit;
        for (int i = 1; i < matiCount; i++) {
            if (FromStart[i]==0||ToStart[i]==0) {
                continue;
            }
            long tm = FromStart[i] + ToStart[i];
            ans = Math.Max(ans, okane[i] * (timeLimit - tm));
        }
        Console.WriteLine(ans);
    }



    private Dictionary<int, Dictionary<int, long>> Road = new Dictionary<int, Dictionary<int, long>>();
	private Dictionary<int, Dictionary<int, long>> RoadRev = new Dictionary<int, Dictionary<int, long>>();

	public class Reader
	{
		private static StringReader sr;
		public static bool IsDebug = false;
		public static string ReadLine()
		{
			if (IsDebug)
			{
				if (sr == null)
				{
					sr = new StringReader(InputText.Trim());
				}
				return sr.ReadLine();
			}
			else
			{
				return Console.ReadLine();
			}
		}
		private static string InputText = @"


2 2 3
1 3
1 2 2
2 1 1


";
	}

	public static void Main(string[] args)
	{
#if DEBUG
		Reader.IsDebug = true;
#endif
		Program prg = new Program();
		prg.Proc();
	}
}