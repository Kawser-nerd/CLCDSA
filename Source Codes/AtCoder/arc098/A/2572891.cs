using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int len = int.Parse(Reader.ReadLine());
        string inpt = Reader.ReadLine();

        int[] turnLeft = new int[len];
        int[] turnRight = new int[len];

        for (int i = 1; i < len; i++) {
            turnRight[i] = turnRight[i - 1];
            if(inpt[i - 1] == 'W') {
                turnRight[i]++;
            }
        }
        for (int i = len - 2; i >= 0; i--) {
            turnLeft[i] = turnLeft[i + 1];
            if(inpt[i + 1] == 'E') {
                turnLeft[i]++;
            }
        }

        int ans = len;
        for (int i = 0; i < len; i++) {
            ans = Math.Min(ans, turnLeft[i] + turnRight[i]);
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


5
WEEWW



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