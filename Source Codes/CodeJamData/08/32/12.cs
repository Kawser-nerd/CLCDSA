using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
    private static int[] m_aN;
    private static int[,] memoiz;
    private static int m_len;

    public static bool CheackNum(Int64 num)
    {
        if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) return true;
        else return false;
    }

    public static Int64 FindNum(int pos, Int64 num, int zn)
    {
        Int64 curNum = m_aN[pos];

        if (zn == 0) num += curNum;
        else num -= curNum;
                
        Int64 ret = 0;

        for(int i = pos+1; i < m_len; i++)
        {
            ret += FindNum(i, num, 0);
            ret += FindNum(i, num, 1);
            if (zn == 0) num = num + (-curNum+curNum*10+m_aN[i]);
            else num = num - (-curNum + curNum * 10 + m_aN[i]);
            curNum = curNum*10 + m_aN[i];
        }
        if (CheackNum(num)) ret+=1;

        return ret;
    }

    [STAThread]
    public static void Main(string[] args)
    {
        //StreamReader sr = new StreamReader(args[0]);
        //StreamWriter sw = new StreamWriter(args[1]);
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        int m_nCase = Convert.ToInt32(sr.ReadLine());
        for(int cs = 1; cs <=m_nCase; cs++)
        {
            String tmp = sr.ReadLine();
            m_len = tmp.Length;
            m_aN = new int[m_len];
            for (int i = 0; i < m_len; i++)
                m_aN[i] = Convert.ToInt32(tmp.Substring(i, 1));

            memoiz = new int[m_len, 17];

            Int64 ret = FindNum(0, 0, 0);

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ret));
        }
        sr.Close();
        sw.Close();
    }
}