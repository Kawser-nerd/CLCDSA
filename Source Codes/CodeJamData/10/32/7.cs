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
            Int64 m_L = Convert.ToInt64(strTmp[0]);
            Int64 m_P = Convert.ToInt64(strTmp[1]);
            Int64 m_C = Convert.ToInt64(strTmp[2]);

            int rez = 0;
            while (m_L * m_C < m_P)
            {
                double x = Math.Sqrt(m_L*m_P);
                Int64 r = Convert.ToInt64(Math.Round(x));
                if (x > r) m_L = r;
                else m_P = r;
                rez++;
            }

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, rez));
        }

        sr.Close();
        sw.Close();
    }
}