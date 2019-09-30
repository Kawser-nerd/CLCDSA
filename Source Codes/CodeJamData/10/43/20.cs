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
            int[,,] m_aA = new int[2,101,101];
            int[] x = new int[4];
            int m_nR = Convert.ToInt32(sr.ReadLine());
            for (int i = 0; i < m_nR; i++)
            {
                string[] strTmp = sr.ReadLine().Trim().Split(new char[] { ' ' });
                for (int j = 0; j < 4; j++)
                    x[j] = Convert.ToInt32(strTmp[j]);
                for (int j = x[0]; j <= x[2]; j++)
                    for (int k = x[1]; k <= x[3]; k++)
                        m_aA[0, k, j] = 1;
            }

            bool f = true;
            int step = 0;
            int m1 = 0, m2 = 1;
            while (f)
            {
                f = false;
                step++;
                for (int i = 0; i <= 100; i++)
                    for (int j = 0; j <= 100; j++)
                    {
                        if (m_aA[m1, i, j] == 1)
                        {
                            if ((i != 0 && m_aA[m1, i - 1, j] == 1) || (j != 0 && m_aA[m1, i, j - 1] == 1))
                            {
                                m_aA[m2, i, j] = 1;
                                f = true;
                            } else m_aA[m2, i, j] = 0;
                        }else
                        {
                            if (i != 0 && m_aA[m1, i - 1, j] == 1 && j != 0 && m_aA[m1, i, j - 1] == 1)
                            {
                                m_aA[m2, i, j] = 1;
                                f = true;
                            }else m_aA[m2, i, j] = 0;
                        }
                    }
                int t = m1;
                m1 = m2;
                m2 = t;
            }

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, step));
        }

        sr.Close();
        sw.Close();
    }
}