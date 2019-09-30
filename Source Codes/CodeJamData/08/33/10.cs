using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
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
            String[] tmp = sr.ReadLine().Split(' ');
            Int64 m_n = Convert.ToInt64(tmp[0]);
            Int64 m_m = Convert.ToInt64(tmp[1]);
            Int64 m_X = Convert.ToInt64(tmp[2]);
            Int64 m_Y = Convert.ToInt64(tmp[3]);
            Int64 m_Z = Convert.ToInt64(tmp[4]);

            Int64[] m_aA = new Int64[m_m];
            for (int i = 0; i < m_m; i++)
            {
                String t = sr.ReadLine();
                m_aA[i] = Convert.ToInt64(t);
            }

            Int64[] m_aF = new Int64[m_n];
            Int64[] m_aSL = new Int64[m_n];
            for(int i = 0; i < m_n; i++)
            {
                m_aF[i] = 1;
                m_aSL[i] = m_aA[i%m_m];
                m_aA[i%m_m] = (m_X*m_aA[i%m_m] + m_Y*(i + 1))%m_Z;
            }

            for (int i = 1; i < m_n; i++)
                for (int j = 0; j < i; j++)
                    if (m_aSL[i] > m_aSL[j]) m_aF[i] = (m_aF[i] + m_aF[j]) % 1000000007;

            Int64 ret = 0;
            for (int i = 0; i < m_n; i++)
                ret = (ret + m_aF[i])%1000000007;

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ret));
        }
        sr.Close();
        sw.Close();
    }
}