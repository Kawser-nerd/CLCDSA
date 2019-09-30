namespace Qualification
{
    using System;
    using System.Collections.Generic;
    using System.IO;

    public class PerfectHarmony
    {
        [STAThread]
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");

            Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
            for (Int64 cs = 1; cs <= m_nCase; cs++)
            {
                string[] strTmp = sr.ReadLine().Trim().Split(new char[] { ' ' });

                Int64 m_N = Convert.ToInt64(strTmp[0]);
                Int64 m_L = Convert.ToInt64(strTmp[1]);
                Int64 m_H = Convert.ToInt64(strTmp[2]);

                strTmp = sr.ReadLine().Trim().Split(new char[] { ' ' });
                Int64[] m_A = new Int64[m_N];
                for (Int64 i = 0; i < m_N; i++)
                    m_A[i] = Convert.ToInt64(strTmp[i]);

                bool f = true;
                Int64 ret = 0;
                for (Int64 i = m_L; i <= m_H; i++)
                {
                    f = true;
                    for (Int64 j = 0; j < m_N; j++)
                        if(m_A[j]%i!=0 && i%m_A[j]!=0)
                        {
                            f = false;
                            break;
                        }
                    if (f)
                    {
                        ret = i;
                        break;
                    }
                }

                if(ret==0)sw.Write(String.Format("Case #{0:G}: NO\n", cs));
                else sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ret));
            }

            sr.Close();
            sw.Close();
        }
    }
}
