using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Text;

public class Program
{
    public void Proc() {
        Reader.IsDebug = false;
        long[] inpt = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();

        this.MatiCount = (int)inpt[0];
        this.CostA = (ulong)inpt[1];
        this.CostB = (ulong)inpt[2];

        this.Zahyo = Reader.ReadLine().Split(' ').Select(a=>ulong.Parse(a)).ToArray();

        ulong ans = 0;

        for(int i=0; i<Zahyo.Length-1; i++) {
            ulong kyori = (ulong)(this.Zahyo[i+1] - this.Zahyo[i]);
            if(kyori * CostA > CostB) {
                ans+=CostB;
            } else {
                ans+=CostA*kyori;
            }
        }
        Console.WriteLine(ans);
        
        

    }


    private int MatiCount;
    private ulong CostA;
    private ulong CostB;

    private ulong[] Zahyo;


    public class Reader {
        public static bool IsDebug = true;
        private static System.IO.StringReader SReader;
        private static string InitText = @"


7 1 2
24 35 40 68 72 99 103

";
        public static string ReadLine() {
            if(IsDebug) {
                if(SReader == null) {
                    SReader = new System.IO.StringReader(InitText.Trim());
                }
                return SReader.ReadLine();
            } else {
                return Console.ReadLine();
            }
        }
    }
    public static void Main(string[] args)
    {
        Program prg = new Program();
        prg.Proc();
    }
}