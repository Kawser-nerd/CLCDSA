using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

	public void Proc()
	{
        this.BlockLength = int.Parse(Reader.ReadLine());
        this.Map[0] = Reader.ReadLine().ToArray();
        this.Map[1] = Reader.ReadLine().ToArray();
        long ans = 1;
        int idx = 0;
        bool prevTate = true;
        while(idx<BlockLength) {
            if(Map[0][idx]==Map[1][idx]) {
                if(idx==0) {
                    ans = 3;
                } else if(prevTate) {
                    ans = ans * 2;
                }
                prevTate = true;
                idx++;
            } else {
                if(idx == 0) {
                    ans = 6;
                } else if(!prevTate) {
                    ans = ans * 3;
                } else {
                    ans = ans * 2;
                }
                prevTate = false;
                idx += 2;
            }

            ans = ans % Mod;
        }
        Console.WriteLine(ans%Mod);
    }

    private int BlockLength = 0;

    private long Mod = 1000000000 + 7;


    private Dictionary<char, int[]> MapDic = new Dictionary<char, int[]>();

    private char[][] Map = new char[2][];

    private Dictionary<string, long> dic = new Dictionary<string, long>();

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



52
RvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn
RLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn


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