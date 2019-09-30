using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Program
{

	public void Proc()
	{
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        int mamonoCount = (int)inpt[0];
        this.BigDamage = inpt[1];
        this.SmallDamage = inpt[2];

        SortedDictionary<long, int> mons = new SortedDictionary<long, int>();

        for (int i = 0; i < mamonoCount; i++) {
            long mon = long.Parse(Reader.ReadLine());
            if(mons.ContainsKey(mon)) {
                mons[mon]++;
            } else {
                mons.Add(mon, 1);
            }
        }
        long minKaisu = mons.First().Key / BigDamage;
        long maxKaisu = mons.Last().Key / SmallDamage + 1;

        long ans = GetAns(minKaisu, maxKaisu, mons);
        Console.WriteLine(ans);
    }

    private long GetAns(long min, long max, SortedDictionary<long, int> dic) {
        if(max-min <= 1) {
            if(CanBuild(min, dic)) {
                return min;
            }
            return max;
        }
        long mid = (max + min) / 2;
        if(CanBuild(mid, dic)) {
            return GetAns(min, mid, dic);
        } else {
            return GetAns(mid, max, dic);
        }
    }

    private bool CanBuild(long target , SortedDictionary<long, int> dic) {
        long diff = BigDamage - SmallDamage;
        long tmp = (long)dic.Where(a => a.Key > SmallDamage * target).Select(a => Math.Ceiling(((decimal)a.Key - (SmallDamage*target)) / (BigDamage - SmallDamage)) * a.Value).Sum();
        return tmp <= target;
    }


    private long SmallDamage;
    private long BigDamage;


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


2 10 4
20
20


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