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
        String[] tmp;
        for(int cs = 1; cs <=m_nCase; cs++)
        {
            tmp = sr.ReadLine().Split(' ');
            int m_P = Convert.ToInt32(tmp[0]);
            int m_K = Convert.ToInt32(tmp[1]);
            int m_L = Convert.ToInt32(tmp[2]);

            tmp = sr.ReadLine().Split(' ');
            int[] m_aL = new int[m_L];
            for(int i = 0; i < m_L; i++)
                m_aL[i] = Convert.ToInt32(tmp[i]);

            Array.Sort(m_aL);
            Array.Reverse(m_aL);
            Int64 ret = 0;
            int l = 0;
            for (int i = 0; i < m_P; i++)
            {
                for (int j = 0; j < m_K; j++)
                {
                    if (l >= m_L) break;
                    ret += m_aL[l]*(i + 1);
                    l++;
                }
                if (l >= m_L) break;
            }


            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ret));
        }
        sr.Close();
        sw.Close();
    }
}