using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Program
{

	public void Proc()
	{
        int inpt = int.Parse(Reader.ReadLine());
        for (int i = 0; i < inpt; i++) {
            Haiten.Add(int.Parse(Reader.ReadLine()));
        }
        int ans = GetAns(0, 0);
        Console.WriteLine(ans);
    }

    private List<int> Haiten = new List<int>();

    private Dictionary<int, Dictionary<int, int>> dic = new Dictionary<int, Dictionary<int, int>>();

    private int GetAns(int idx, int subTotal) {
        if(idx >= Haiten.Count) {
            if(subTotal % 10 == 0) {
                return 0;
            } else {
                return subTotal;
            }
        }
        if(!dic.ContainsKey(idx)) {
            dic.Add(idx, new Dictionary<int, int>());
        }
        if(dic[idx].ContainsKey(subTotal)) {
            return dic[idx][subTotal];
        }
        int ans = GetAns(idx + 1, subTotal + this.Haiten[idx]);
        ans = Math.Max(ans, GetAns(idx + 1, subTotal));
        dic[idx][subTotal] = ans;
        return ans;
    }


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


3
10
20
30

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