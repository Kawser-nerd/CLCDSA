using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int inptCount = int.Parse(Reader.ReadLine());

        this.items = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();
        long ans = 0;
        if (items[0] == 0)
        {
            ans = GetAns(1, 1) + 1;
            ans = Math.Min(ans, GetAns(1, -1) + 1);
        }
        else 
        {
            ans = GetAns(1, items[0]);
            if (items[0] > 0)
            {
                ans = Math.Min(ans, GetAns(1, -1) + items[0] + 1);
            }
            else
            {
                ans = Math.Min(ans, GetAns(1, 1) + Math.Abs(items[0]) + 1);
            }
        }
        Console.WriteLine(ans);
    }

    private long GetAns(int idx, long subtotal)
    {
        if (idx >= items.Length)
        {
            return 0;
        }
        if (subtotal < 0 && subtotal + items[idx] > 0)
        {
            return GetAns(idx + 1, subtotal + items[idx]);
        }
        else if (subtotal > 0 && subtotal + items[idx] < 0)
        {
            return GetAns(idx + 1, subtotal + items[idx]);
        }
        else if(subtotal > 0)
        {
            return GetAns(idx + 1, -1) + (subtotal + items[idx] + 1);
        }
        else
        {
            return GetAns(idx + 1, 1) + Math.Abs(subtotal + items[idx]) + 1;
        }

    }

    private long[] items;


    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"



6
-1 4 3 2 -5 4


";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}