using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Pair : IComparable<Pair>
{
	public Pair() { }
	public Pair(int time, int type) { this.time = time; this.type = type; }
	public int time=0;
	public int type=0;

	public int CompareTo(Pair other)
	{
		if (time < other.time) return -1;
		else if (time > other.time) return 1;
		else
		{
			if (type < other.type) return -1;
			else if (type > other.type) return 1;
			else return 0;
		}
	}
}

class Program
{
	static int N, T, NA, NB;
	static List<Pair> pa;
	static List<Pair> pb;

	static void getPair(string tmp, out Pair departure, out Pair arrival)
	{
		departure = new Pair();
		arrival = new Pair();
		string[] ta = tmp.Split(':', ' ');
		int a1, a2, b1, b2;
		a1 = int.Parse(ta[0]);
		a2 = int.Parse(ta[1]);
		b1 = int.Parse(ta[2]);
		b2 = int.Parse(ta[3]);
		departure.time = a1 * 60 + a2;
		departure.type = 1;
		arrival.time = b1 * 60 + b2 + T;
		arrival.type = 0;
	}
	static void Main(string[] args)
	{
		string infile = "b-large.in";
		string outfile = "b-large.out";
		TextReader tr = new StreamReader(infile);
		TextWriter tw = new StreamWriter(outfile);
		N = int.Parse(tr.ReadLine());
		for (int i = 0; i < N; ++i)
		{
			T = int.Parse(tr.ReadLine());
			string tmp = tr.ReadLine();
			NA = int.Parse(tmp.Split(' ')[0]);
			NB = int.Parse(tmp.Split(' ')[1]);
			pa = new List<Pair>(NA);
			pb = new List<Pair>(NB);
			Pair apair, bpair;
			for (int j = 0; j < NA; ++j)
			{
				getPair(tr.ReadLine(),out apair, out bpair);
				pa.Add(apair);
				pb.Add(bpair);
			}
			for (int j = 0; j < NB; ++j)
			{
				getPair(tr.ReadLine(), out bpair, out apair);
				pa.Add(apair);
				pb.Add(bpair);
			}
			pa.Sort();
			pb.Sort();
			int nAtrains = 0, nBtrains = 0;
			int cAtrains = 0, cBtrains = 0;
			for (int j = 0; j < pa.Count; ++j)
			{
				Pair p = pa[j];
				if (p.type == 0) ++nAtrains;
				else
				{
					if (nAtrains - 1 < 0) ++cAtrains;
					else --nAtrains;
				}
			}
			for (int j = 0; j < pb.Count; ++j)
			{
				Pair p = pb[j];
				if (p.type == 0) ++nBtrains;
				else
				{
					if (nBtrains - 1 < 0) ++cBtrains;
					else --nBtrains;
				}
			}
			tw.WriteLine("Case #{0}: {1} {2}",i+1, cAtrains, cBtrains);
		}
		tw.Close();
	}
}
