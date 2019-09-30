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

        int[] items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        int[] idxs = new int[len];
        int[] subtotal = new int[len];

        long ans = 0;
        for (int i = 0; i < len; i++) {
            if(i==0) {
                idxs[0] = 0;
                subtotal[0] = items[0];
            } else {
                idxs[i] = idxs[i - 1];
                subtotal[i] = subtotal[i - 1] - items[i - 1];
            }
            int end = idxs[i];
            int sub = subtotal[i];
            for (int j = idxs[i] + 1; j < len; j++) {
                int sum = sub + items[j];
                int xor = sub ^ items[j];
                if(sum != xor) {
                    break;
                }
                sub = xor;
                end = j;
            }
            subtotal[i] = sub;
            idxs[i] = end;
            ans += (end - i + 1);
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



19
885 8 1 128 83 32 256 206 639 16 4 128 689 32 8 64 885 969 1


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