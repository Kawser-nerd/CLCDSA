using System;
using System.Collections.Generic;
using System.IO;
using System.Collections;

public class Numbers
{
    static int[,] pain;
    static bool[] minB = new bool[320];
    static int m_PP;
    static int minA = 1000;
    static int A = 0;
    static int[] colUs = new int[3];
    static int cuI = 0;
    static void Era(int n)
    {
        if (n == m_PP)
        {
            bool ok = true;
            for(int y = 1; y <= 10000; y++)
            {
                bool f = false;
                for(int i = 0; i < m_PP; i++)
                    if (minB[i] && pain[1, i] <= y && y <= pain[2, i])
                    {
                        f = true;
                        break;
                    }
                if (!f)
                {
                    ok = false;
                    break;
                }
            }
            if (ok && A < minA) minA = A;
            return;
        }

        minB[n] = false;
        Era(n+1);

        bool ff = false;
        for(int i = 0; i < cuI; i++)
            if (colUs[i] == pain[0, n])
            {
                ff = true;
                break;
            }
        if (!ff && cuI == 3)return;
        if (!ff)
        {
            colUs[cuI] = pain[0, n];
            cuI++;
        }
        minB[n] = true;
        A++;
        Era(n+1);
        A--;
        minB[n] = false;
        if (!ff)
            cuI--;
    }

    [STAThread]
    public static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("B_in.txt");
        StreamWriter sw = new StreamWriter("B_out.txt");

        Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
        
        for (Int64 cs = 1; cs <= m_nCase; cs++)
        {
            minA = 1000;
            String[] tmpA;
            string[] colors = new string[320];
            int cI = 0;

            //List<KeyValuePair<int, int>>[] pain = new List<KeyValuePair<int,int>>[320];
            pain = new int[3, 320];
            m_PP = Convert.ToInt32(sr.ReadLine());
            for(Int32 PP = 0; PP < m_PP; PP++)
            {
                tmpA = sr.ReadLine().Split(' ');
                string c = tmpA[0];
                pain[1,PP] = Convert.ToInt32(tmpA[1]);
                pain[2,PP] = Convert.ToInt32(tmpA[2]);
                bool f = false;
                for(int i = 0; i < cI; i++)
                    if (colors[i] == c)
                    {
                        pain[0, PP] = i;
                        f = true;
                        break;
                    }

                if (!f)
                {
                    colors[cI] = c;
                    pain[0, PP] = cI;
                    cI++;
                }
            }

            Era(0);



            //bool[,] m_aP = new bool[m_H + 20, m_W + 20];
            //Int64[,] m_aRez = new Int64[m_H + 20, m_W + 20];





            if (minA == 1000) sw.Write(String.Format("Case #{0:G}: IMPOSSIBLE\n", cs));
            else sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, minA));
        }
        sr.Close();
        sw.Close();
    }
}