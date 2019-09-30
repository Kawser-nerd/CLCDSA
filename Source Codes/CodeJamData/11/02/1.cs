using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/*
 * Input
 
    5
    0 0 2 EA
    1 QRI 0 4 RRQR
    1 QFT 1 QF 7 FAQFDFQ
    1 EEZ 1 QE 7 QEEEERA
    0 1 QW 2 QW
 
 *  Output
	Case #1: [E, A]
    Case #2: [R, I, R]
    Case #3: [F, D, T]
    Case #4: [Z, E, R, A]
    Case #5: 
 */

namespace ProblemB
{
    class Program
    {
        static void Solve(int caseNo, StreamReader sr, StreamWriter sw)
        {
            string[] argv = sr.ReadLine().Split();
            Dictionary<string, char> combines = new Dictionary<string, char>();
            List<string> opposes = new List<string>();
            int i = 0;
            int C = Convert.ToInt32(argv[i++]);
            for (int j = 0; j < C; j++, i++)
            {
                try
                {
                    combines.Add(new string(new char[] { argv[i][0], argv[i][1] }), argv[i][2]);
                    combines.Add(new string(new char[] { argv[i][1], argv[i][0] }), argv[i][2]);
                }
                catch(Exception e){}
            }
            int D = Convert.ToInt32(argv[i++]);
            for (int j = 0; j < D; j++, i++)
                opposes.Add(argv[i]);

            int N = Convert.ToInt32(argv[i++]);
            string seq = argv[i];

            StringBuilder result = new StringBuilder();

            for(i = 0; i < seq.Length; i++)            
            {
                result.Append(seq[i]);
                if (result.Length >= 2)
                {
                    char newValue;
                    if (combines.TryGetValue(result.ToString(result.Length - 2, 2), out newValue))
                    {
                        result = result.Remove(result.Length - 2, 2);
                        result = result.Append(newValue);
                    }

                    foreach (string oppose in opposes) {
                        if (result.ToString().Contains(oppose[0]) && result.ToString().Contains(oppose[1]))
                            result.Clear();
                    }                    
                }
            }

            Console.Write("Case #{0}: [", caseNo);
            sw.Write("Case #{0}: [", caseNo);
            string str = result.ToString();
            for (i = 0; i < str.Length; i++) {
                Console.Write(str[i]);
                sw.Write(str[i]);
                if (i < str.Length - 1)
                {
                    Console.Write(", ");
                    sw.Write(", ");
                }
            }
            Console.Write("]\n");
            sw.Write("]\n");
        }

        static void Main(string[] args)
        {
            string file = args[0];
            StreamReader sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
            StreamWriter sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));
            int maxCase = Convert.ToInt32(sr.ReadLine());

            int caseNo = 1;
            while (caseNo <= maxCase)
            {
                Solve(caseNo, sr, sw);
                caseNo++;
            }

            sr.Close();
            sw.Close();
        }
    }
}
