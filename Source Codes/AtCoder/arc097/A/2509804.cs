using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
		string inpt = Reader.ReadLine();
		int idx = int.Parse(Reader.ReadLine()) - 1;
		List<char> charList = inpt.Distinct().OrderBy(a => a).ToList();
		if(charList.Count > 5) {
			charList = charList.Take(5).ToList();
		}

		List<string> words = new List<string>();
		foreach(char c in charList) {
			for (int i = 0; i < inpt.Length; i++) {
				if(inpt[i] != c) {
					continue;
				}
				for (int j = 1; j <= 5; j++) {
					if(i+j>inpt.Length) {
						continue;
					}
					string tmp = inpt.Substring(i, j);
					if(!words.Contains(tmp)) {
						words.Add(tmp);
					}
				}
			}
			if (words.Count >= 5)
            {
                break;
            }
		}
		words.Sort();
		Console.WriteLine(words[idx]);
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


atcoderandatcodeer
5


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