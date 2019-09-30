using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int[] inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();
        this.CityDic = new City[inpt[0] + 1];
        for(int i=1; i<=inpt[0]; i++) {
            this.CityDic[i] = new City(i);
        }

        int roadCount = inpt[1];
        this.RoadList = new Road[roadCount];
        for(int i=0; i<roadCount; i++) {
            this.RoadList[i] = new Road(Reader.ReadLine());
        }

        this.RoadList = this.RoadList.OrderByDescending(a=>a.Year).ToArray();

        int queryCount = int.Parse(Reader.ReadLine());
        this.queryList = new Query[queryCount];
        for(int i=0; i<queryCount; i++) {
            this.queryList[i] = new Query(i, Reader.ReadLine());
        }
        this.queryList = this.queryList.OrderByDescending(a=>a.Year).ToArray();

        int idx = 0;
        int[] ans = new int[queryCount];
        foreach (Query que in queryList)
        {
            while (idx < this.RoadList.Length && this.RoadList[idx].Year > que.Year)
            {
                City c1 = this.CityDic[this.RoadList[idx].City1];
                City c2 = this.CityDic[this.RoadList[idx].City2];

                City cRoot1 = c1.Root;
                City cRoot2 = c2.Root;
                if(cRoot1.Number == cRoot2.Number) {
                    idx++;
                    continue;
                }
                if(cRoot1.Count > cRoot2.Count) {
                    cRoot2.Parent = cRoot1;
                    cRoot1.Count+=cRoot2.Count;
                } else
                {
                    cRoot1.Parent = cRoot2;
                    cRoot2.Count+=cRoot1.Count;
                }
                idx++;
            }
            ans[que.Index] = this.CityDic[que.Start].Root.Count;
        }
        

        Console.SetOut(new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        ans.ToList().ForEach(a=>Console.WriteLine(a));
        Console.Out.Flush();


    }


    private Query[] queryList;

    public class Query {
        public int Index;
        public int Start;
        public int Year;

        public Query(int idx, string init) {
            this.Index = idx;
            int[] inpt = init.Split(' ').Select(a=>int.Parse(a)).ToArray();
            this.Start = inpt[0];
            this.Year = inpt[1];
        }
    }


    private City[] CityDic;

    private Road[] RoadList;
    public class Road {
        public int City1;
        public int City2;
        public int Year;
        public Road(string init) {
            int[] inpt = init.Split(' ').Select(a=>int.Parse(a)).ToArray();
            this.City1 = inpt[0];
            this.City2 = inpt[1];
            this.Year= inpt[2];
        }
    }
    public class City {
        public int Number = 0;

        public City Parent = null;

        private City TempRoot = null;

        public City Root {
            get {
                if(this.Parent == null) {
                    return this;
                } else if(TempRoot != null && TempRoot.Parent == null)
                {
                    return TempRoot;
                } else {
                    this.TempRoot = this.Parent.Root;
                    return this.TempRoot;
                }
            }
        }
        public int Count = 0;

        public City(int cityNum) {
            this.Number = cityNum;
            this.Count = 1;
        }
    }

    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"



4 5
1 2 10
1 2 1000
2 3 10000
2 3 100000
3 1 200000
4
1 0
2 10000
3 100000
4 0


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