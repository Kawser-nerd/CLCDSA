using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        //  I, O, T, J, L, S, Z
        this.ICount = inpt[0];
        this.OCount = inpt[1];
        this.JCount = inpt[3];
        this.LCount = inpt[4];
        long ans = Math.Max(this.GetVal(1), this.GetVal(0)) + this.OCount;
        
        Console.WriteLine(ans);
      
    }


    private long GetVal(long join3)
    {

        long tmp = Math.Min(ICount, Math.Min(join3, Math.Min(this.JCount, this.LCount)));
        long ans = tmp * 3;
        long remainI = this.ICount - tmp;
        long remainJ = this.JCount - tmp;
        long remainL = this.LCount - tmp;

        ans += (remainI / 2) * 2;
        ans += (remainJ / 2) * 2;
        ans += (remainL / 2) * 2;
        return ans;
    }




    private long OCount = 0;
    private long ICount = 0;
    private long JCount = 0;
    private long LCount = 0;



    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

0 0 10 0 0 0 0



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