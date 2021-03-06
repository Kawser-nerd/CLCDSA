using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
    static Int64[,] m_nodeType;
    private static Int64[,] m_memoiz;
    static Int64 m_nNodeR;
    static Int64 m_nNodeL;

    public static Int64 MinMemoi(Int64 cur, Int64 nex)
    {
        if (nex == -1) return cur;
        if (cur == -2 || cur == -1 )return nex;
        return Math.Min(cur, nex);
        
    }

    public static Int64 FindNum(Int64 cNode, Int64 cVal)
    {
        if (m_memoiz[cVal, cNode] != -2) return m_memoiz[cVal, cNode];
        if (cNode > m_nNodeR)
        {
            if (m_nodeType[0, cNode] == cVal)m_memoiz[cVal, cNode] = 0;
            else m_memoiz[cVal, cNode] = -1;
            return m_memoiz[cVal, cNode];
        }

        Int64 calc = -2;
        if(cVal==0)
        {
            Int64 t1 = FindNum(2 * cNode, 0);
            Int64 t2 = FindNum(2 * cNode+1, 0);
            if (t1 >= 0 && t2 >= 0)
                calc = MinMemoi(calc, t1 + t2);
            if (m_nodeType[0, cNode] == 1)
            {
                t1 = FindNum(2 * cNode, 1);
                t2 = FindNum(2 * cNode+1, 0);
                if (t1 >= 0 && t2 >= 0)
                    calc = MinMemoi(calc, t1 + t2);

                t1 = FindNum(2 * cNode, 0);
                t2 = FindNum(2 * cNode+1, 1);
                if (t1 >= 0 && t2 >= 0)
                    calc = MinMemoi(calc, t1 + t2);
            }
        }else
        {
            Int64 t1 = FindNum(2 * cNode, 1);
            Int64 t2 = FindNum(2 * cNode + 1, 1);
            if (t1 >= 0 && t2 >= 0)
                calc = MinMemoi(calc, t1 + t2);
            if (m_nodeType[0, cNode] == 0)
            {
                t1 = FindNum(2 * cNode, 1);
                t2 = FindNum(2 * cNode + 1, 0);
                if (t1 >= 0 && t2 >= 0)
                    calc = MinMemoi(calc, t1 + t2);

                t1 = FindNum(2 * cNode, 0);
                t2 = FindNum(2 * cNode + 1, 1);
                if (t1 >= 0 && t2 >= 0)
                    calc = MinMemoi(calc, t1 + t2);
            }
        }

        if(m_nodeType[1,cNode]==1)
        {
            m_nodeType[1, cNode] = 0;
            if (m_nodeType[0, cNode] == 0) m_nodeType[0, cNode] = 1;
            else m_nodeType[0, cNode] = 0;

            Int64 t = FindNum(cNode, cVal);
            calc = MinMemoi(calc, t+1);

            if (m_nodeType[0, cNode] == 0) m_nodeType[0, cNode] = 1;
            else m_nodeType[0, cNode] = 0;
            m_nodeType[1, cNode] = 1;
        }

        m_memoiz[cVal, cNode] = calc;

        return m_memoiz[cVal, cNode];
    }

    [STAThread]
    public static void Main(string[] args)
    {
        //StreamReader sr = new StreamReader(args[0]);
        //StreamWriter sw = new StreamWriter(args[1]);
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
        String[] tmpA;
        String tmp;
        for (Int64 cs = 1; cs <= m_nCase; cs++)
        {
            tmpA = sr.ReadLine().Split(' ');
            Int64 m_M = Convert.ToInt64(tmpA[0]);
            Int64 m_V = Convert.ToInt64(tmpA[1]);

            m_nNodeR = (m_M - 1) / 2;
            m_nNodeL = (m_M + 1) / 2;

            m_nodeType = new Int64[2,m_M+1];
            m_memoiz = new Int64[2,m_M+1];
            for (Int64 i = 1; i <= m_nNodeR; i++)
            {
                tmpA = sr.ReadLine().Split(' ');
                m_nodeType[0,i] = Convert.ToInt64(tmpA[0]);
                m_nodeType[1,i] = Convert.ToInt64(tmpA[1]);
                m_memoiz[0, i] = -2;
                m_memoiz[1, i] = -2;
            }
            for (Int64 i = m_nNodeR+1; i <= m_M; i++)
            {
                m_nodeType[0, i] = Convert.ToInt64(sr.ReadLine());
                m_memoiz[0, i] = -2;
                m_memoiz[1, i] = -2;
            }

            Int64 ret = FindNum(1, m_V);
            if (ret < 0) sw.Write(String.Format("Case #{0:G}: IMPOSSIBLE\n", cs));
            else sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ret));
        }
        sr.Close();
        sw.Close();
    }
}