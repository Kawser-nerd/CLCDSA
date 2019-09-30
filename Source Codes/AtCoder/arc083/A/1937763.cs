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
        this.AddWater1 = inpt[0];
        this.AddWater2 = inpt[1];
        this.AddSuger1 = inpt[2];
        this.AddSuger2 = inpt[3];
        this.MaxRate = inpt[4];
        this.MaxTotal = inpt[5];

        SugarWater ans = GetAns(0, 0);
        Console.WriteLine(ans.Total + " " + ans.Suger);
    }

    private Dictionary<int, Dictionary<int, SugarWater>> dic = new Dictionary<int, Dictionary<int, SugarWater>>();

    private SugarWater GetAns(int water, int sugar) {
        if(sugar+water>this.MaxTotal) {
            return new SugarWater();
        }
        SugarWater ans = new SugarWater(water, sugar);
        if (ans.Rate > MaxRate)
        {
            return new SugarWater();
        }
        if(!dic.ContainsKey(water)) {
            dic.Add(water,new Dictionary<int, SugarWater>());
        }
        if(dic[water].ContainsKey(sugar)) {
            return dic[water][sugar];
        }
        SugarWater[] tmp = new SugarWater[4];
        tmp[0] = GetAns(water + AddWater1 * 100, sugar);
        tmp[1] = GetAns(water + AddWater2 * 100, sugar);
        tmp[2] = GetAns(water, sugar + AddSuger1);
        tmp[3] = GetAns(water, sugar + AddSuger2);
        foreach(SugarWater sw in tmp) {
            if(sw.Rate==ans.Rate) {
                if(sw.Total<ans.Total) {
                    ans = sw;
                }
            } else if(sw.Rate>ans.Rate) {
                ans = sw;
            }
        }
        dic[water][sugar] = ans;
        return ans;
    }

    private int AddSuger1;
    private int AddSuger2;

    private int AddWater1;
    private int AddWater2;

    private int MaxRate;
    private int MaxTotal;

    public class SugarWater {
        public int Water;
        public int Suger;
        public decimal Rate {
            get{
                if(Water==0) {
                    return -1;
                }
                return Suger / (Water / 100m);
            }
        }
        public int Total {
            get {
                return this.Water + Suger;
            }
        }
        public SugarWater() {
            this.Water = 0;
            this.Suger = 0;
        }
        public SugarWater(int w, int s) {
            this.Water = w;
            this.Suger = s;
        }
        public SugarWater Duplicate() {
            return new SugarWater(this.Water, this.Suger);
        }
    }


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



17 19 22 26 55 2802


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