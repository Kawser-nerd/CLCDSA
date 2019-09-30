using System;
using System.Collections.Generic;
using System.IO;

public class SnapperChain
{
    [STAThread]
    public static void Main(string[] args)
    {
        //StreamReader sr = new StreamReader(args[0]);
        //StreamWriter sw = new StreamWriter(args[1]);
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        int m_nCase = Convert.ToInt32(sr.ReadLine());
        for (int cs = 1; cs <= m_nCase; cs++)
        {
            string[] strTmp = sr.ReadLine().Trim().Split(new char[] { ' ' });
            int m_N = Convert.ToInt32(strTmp[0]);
            int[,] m_arA = new int[2, m_N];
            for(int i = 0; i < m_N; i++)
            {
                strTmp = sr.ReadLine().Trim().Split(new char[] { ' ' });
                m_arA[0, i] = Convert.ToInt32(strTmp[0]);
                m_arA[1, i] = Convert.ToInt32(strTmp[1]);
            }

            int rez = 0;
            for (int i = 0; i < m_N - 1; i++)
                for (int j = i + 1; j < m_N; j++)
                    if ((m_arA[0, i] < m_arA[0, j] && m_arA[1, i] > m_arA[1, j]) ||
                        (m_arA[0, i] > m_arA[0, j] && m_arA[1, i] < m_arA[1, j])) rez++;

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, rez));
        }

        sr.Close();
        sw.Close();
    }
}