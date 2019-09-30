using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
		int count = int.Parse(Reader.ReadLine());
		int[] primeList = this.GetPrimeList();
		primeList = primeList.Where(a => a % 5 == 1).ToArray();
		Console.WriteLine(string.Join(" ", primeList.Take(count)));
	}

	private int[] GetPrimeList() {
		bool[] flags = new bool[55555 + 1];
		List<int> ans = new List<int>();
		for (int i = 2; i < flags.Length; i++) {
			if(flags[i]) {
				continue;
			}
			ans.Add(i);
			int max = 55555 / i;
			for (int j = 1; j <= max; j++) {
				flags[i * j] = true;
			}
		}
		return ans.ToArray();
	}

	public class Reader
    {
        static StringReader sr;
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


8


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