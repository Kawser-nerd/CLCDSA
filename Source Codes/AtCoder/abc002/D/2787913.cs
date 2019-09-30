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

        int giin = inpt[0];
        int relationCount = inpt[1];

        int maxIdx = 1 << (giin + 1);

        Dictionary<int, Dictionary<int, bool>> relation = new Dictionary<int, Dictionary<int, bool>>();
        for (int i = 0; i < relationCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a) - 1).ToArray();
            if(!relation.ContainsKey(inpt[0])) {
                relation.Add(inpt[0], new Dictionary<int, bool>());
            }
            relation[inpt[0]][inpt[1]] = true;
            if (!relation.ContainsKey(inpt[1]))
            {
                relation.Add(inpt[1], new Dictionary<int, bool>());
            }
            relation[inpt[1]][inpt[0]] = true;
        }

        int ans = int.MinValue;
        for (int i = 0; i < maxIdx; i++) {
            List<int> habatu = new List<int>();
            bool canHabatu = true;
            for (int j = 0; j < giin; j++) {
                if((i&(1<<j)) != 0) {
                    if(habatu.Any(a=>(!relation.ContainsKey(a)) || (!relation[a].ContainsKey(j)))) {
                        canHabatu = false;
                        break;
                    } else {
                        habatu.Add(j);
                    }
                }
            }
            if(canHabatu) {
                ans = Math.Max(ans, habatu.Count);
            }
        }
        Console.WriteLine(ans);
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




12 0



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