namespace Qualification
{
    using System;
    using System.Collections.Generic;
    using System.IO;

    public class SpaceEmergency
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

                Int64 m_L = Convert.ToInt64(strTmp[0]);
                Int64 m_t = Convert.ToInt64(strTmp[1]);
                Int64 m_N = Convert.ToInt64(strTmp[2]);
                Int64 m_C = Convert.ToInt64(strTmp[3]);
                Int64[] m_A = new Int64[m_C];
                Int64[] B = new Int64[10010];
                for (Int64 i = 0; i < m_C; i++)
                {
                    m_A[i] = Convert.ToInt64(strTmp[4 + i]);
                    B[m_A[i]] += m_N/m_C + (m_N%m_C > i ? 1 : 0);
                }

                Int64 curT = 0;
                Int64 ans = 0;
                Int64 j = 0;
                for (Int64 i = 0; i < m_N; i++)
                {
                    if(curT+m_A[j]*2>m_t)
                    {
                        B[m_A[j]]--;
                        bool ch = false;
                        for (Int64 k = 10001; k > 0; k--)
                        {
                            if (B[k] != 0)
                            {
                                while (m_L > 0 && B[k] > 0)
                                {
                                    ans += k;
                                    B[k]--;
                                    m_L--;
                                }
                                while (B[k] > 0)
                                {
                                    ans += k * 2;
                                    B[k]--;
                                }
                            }
                            if (!ch)
                            {
                                Int64 tt = (m_t - curT);
                                Int64 at = m_A[j] - tt/2;
                                if (at >= k)
                                {
                                    if(m_L>0)
                                    {
                                        ans += at;// (Int64)Math.Ceiling(at);
                                        m_L--;
                                    }
                                    else ans += (Int64)(at * 2);

                                    ans += tt;
                                    ch = true;
                                }
                            }
                        }
                        break;
                    }else
                    {
                        curT += m_A[j]*2;
                        B[m_A[j]]--;
                    }

                    j++;
                    j %= m_C;
                }



                sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, curT + ans));
            }

            sr.Close();
            sw.Close();
        }
    }
}
