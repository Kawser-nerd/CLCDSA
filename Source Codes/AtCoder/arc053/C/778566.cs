using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;



class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int mahoCount = int.Parse(Reader.ReadLine());

        for(int i=0; i<mahoCount; i++) {
            long[] inpt  = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();

            Maho m;
            m.Up = inpt[0];
            m.Down = inpt[1];
            if(m.Down > m.Up) {
                MahoList1.Add(m);
            } else
            {
                MahoList2.Add(m);
            }
        }

        MahoList1.Sort((a,b)=>{return a.Up.CompareTo(b.Up);});
        MahoList2.Sort((a,b)=>{return a.Down.CompareTo(b.Down) * -1;});

        long ans  = 0;
        long current = 0;
        MahoList1.ForEach(a=>{
            current+=a.Up;
            ans = Math.Max(ans, current);
            current-=a.Down;
        });
        MahoList2.ForEach(a=>{
            current+=a.Up;
            ans = Math.Max(ans, current);
            current-=a.Down;
        });
        Console.WriteLine(ans);


    }

    private List<Maho> MahoList1 = new List<Maho>();
    private List<Maho> MahoList2 = new List<Maho>();

    public struct Maho {
        public long Up;
        public long Down;

    }

    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"


5
5 10
10 5
10 15
15 10
20 20


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