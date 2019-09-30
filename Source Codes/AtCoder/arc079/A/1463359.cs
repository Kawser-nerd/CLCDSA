using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        this.IslCount = inpt[0];
        int shipCount = inpt[1];

        for (int i = 0; i < shipCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
            if(!Ship.ContainsKey(inpt[0])) {
                Ship.Add(inpt[0], new Dictionary<int, bool>());
            }
            if(!Ship.ContainsKey(inpt[1])) {
                Ship.Add(inpt[1], new Dictionary<int, bool>());
            }
            Ship[inpt[0]][inpt[1]] = true;
            Ship[inpt[1]][inpt[0]] = true;
        }

        string ans = "IMPOSSIBLE";
        if(this.CanReach(1, 2)) {
            ans = "POSSIBLE";
        }
        Console.WriteLine(ans);
    
    }

    private int IslCount;

    private bool CanReach(int idx, int remain) {
        if(idx == this.IslCount) {
            return true;
        }
        if(remain<=0) {
            return false;
        }
        if(Ship.ContainsKey(idx)) {
            foreach(int nextIsl in Ship[idx].Keys) {
                if(nextIsl == 1) {
                    continue;
                }
                if(CanReach(nextIsl, remain-1)) {
                    return true;
                }
            }
        }
        return false;
    }
    private Dictionary<int, Dictionary<int, bool>> Ship = new Dictionary<int, Dictionary<int, bool>>();


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



3 2
1 2
2 3

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