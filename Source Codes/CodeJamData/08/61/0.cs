using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJApp
{
    class Program
    {
        static int ret;

        static bool isIn(int low, int high, int value) {
            if(value<low||value>high)
                return false;
            return true;
        }

        static bool isInE(int low, int high, int value)
        {
            if (value > low && value < high)
                return true;
            return false;
        }

        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\GCJ\\Data\\A-small3.out");

            TextReader tr = new StreamReader("C:\\GCJ\\Data\\A-small-attempt2.in");
           // TextReader tr = new StreamReader("C:\\GCJ\\Data\\test.txt");

            int N = Int32.Parse(tr.ReadLine());

            int inf = int.MaxValue;

            for (int testNo = 1; testNo <= N; testNo++)
            {

                
                //H = int.Parse(sar[0]);
                int[] ws, hs;
                bool[] bs;
                int nspec = int.Parse(tr.ReadLine());
                ws = new int[nspec];
                hs = new int[nspec];
                bs = new bool[nspec];
                for (int i = 0; i < nspec; i++)
                {
                    string[] sar = (tr.ReadLine()).Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    hs[i] = int.Parse(sar[0]);
                    ws[i] = int.Parse(sar[1]);
                    if (sar[2].Equals("BIRD"))
                        bs[i] = true;
                    else
                        bs[i] = false;
                }
                int th, eh, tW, eW;
                th = inf; eh = -1;
                tW = inf; eW = -1;
                for (int i = 0; i < nspec; i++)
                {
                    if (bs[i])
                    {
                        if (th > hs[i])
                            th = hs[i];
                        if (eh < hs[i])
                            eh = hs[i];
                        if (tW > ws[i])
                            tW = ws[i];
                        if (eW < ws[i])
                            eW = ws[i];
                    }
                }
                int oeh = inf;
                int oth = -1;
                int oeW = inf;
                int otW = -1;
                for(int i=0;i<nspec;i++) {
                    if(!bs[i]) {
                        if(isIn(th,eh,hs[i])) {
                            if(ws[i]>eW) {
                                if(oeW>ws[i])
                                    oeW = ws[i];
                            }
                            if(ws[i]<tW) {
                                if(otW<ws[i])
                                    otW=ws[i];
                            }
                        }
                        if(isIn(tW,eW,ws[i])) {
                            if(hs[i]>eh) {
                                if(oeh>hs[i])
                                    oeh=hs[i];
                            }
                            if(hs[i]<th) {
                                if(oth<hs[i])
                                    oth=hs[i];
                            }
                        }
                    }
                }

                int M = int.Parse(tr.ReadLine());
                tw.WriteLine("Case #" + (testNo) + ":");
                for(int i=0;i<M;i++) {
                    string[] sar = (tr.ReadLine()).Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int ch = int.Parse(sar[0]);
                    int cw = int.Parse(sar[1]);
                    if(isIn(th,eh,ch)&&isIn(tW,eW,cw)) {
                        tw.WriteLine("BIRD");
                        continue;
                    }
                    if(!(isInE(oth,oeh,ch)&&isInE(otW,oeW,cw))) {
                        tw.WriteLine("NOT BIRD");
                        continue;
                    }
                    if (th == inf)
                    {
                        tw.WriteLine("UNKNOWN");
                        continue;
                    }

                    bool written = false;
                    for(int j=0;j<nspec;j++) {
                        if(!bs[j]) {
                            if( ((isIn(eh,oeh,hs[j])||isIn(oth,th,hs[j])))  &&  (isIn(eW,oeW,ws[j])||isIn(tW,otW,ws[j])) ) {

                                if (hs[j] > eh)
                                {
                                    if (ws[j] > eW)
                                    {
                                        if (ch >= hs[j] && cw >= ws[j])
                                        {
                                            tw.WriteLine("NOT BIRD");
                                            written = true;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if (ch >= hs[j] && cw <= ws[j])
                                        {
                                            tw.WriteLine("NOT BIRD");
                                            written = true;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    if (ws[j] > eW)
                                    {
                                        if (ch <= hs[j] && cw >= ws[j])
                                        {
                                            tw.WriteLine("NOT BIRD");
                                            written = true;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if (ch <= hs[j] && cw <= ws[j])
                                        {
                                            tw.WriteLine("NOT BIRD");
                                            written = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(!written)
                        tw.WriteLine("UNKNOWN");
                    
                }
                //tw.WriteLine("Case #" + (testNo) + ": " + "3.14159");
            }
            tw.Flush();
            tw.Close();
        }

    }
}
