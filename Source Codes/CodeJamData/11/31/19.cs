namespace Qualification
{
    using System;
    using System.Collections.Generic;
    using System.IO;

    public class HotDogs
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

                int m_R = Convert.ToInt32(strTmp[0]);
                int m_C = Convert.ToInt32(strTmp[1]);

                int[,] m_A = new int[m_R,m_C];
                for (int i = 0; i < m_R; i++)
                {
                    string str = sr.ReadLine().Trim();
                    for (int j = 0; j < m_C; j++)
                        if (str[j] == '.') m_A[i, j] = 0;
                        else m_A[i, j] = 1;
                }

                bool imp = false;
                for (int i = 0; i < m_R; i++)
                {
                    for (int j = 0; j < m_C; j++)
                        if (m_A[i, j] == 1)
                        {
                            if (i == m_R - 1 || j == m_C - 1 || m_A[i, j + 1] != 1 || m_A[i + 1, j] != 1 || m_A[i + 1, j + 1] != 1)
                            {
                                imp = true;
                                break;
                            }else
                            {
                                m_A[i, j] = 2;
                                m_A[i, j+1] = 3;
                                m_A[i+1, j] = 4;
                                m_A[i+1, j+1] = 5;
                            }
                        }
                    if(imp) break;
                }


                sw.Write(String.Format("Case #{0:G}:\n", cs));
                if (imp) sw.Write(String.Format("Impossible\n"));
                else{
                    for (int i = 0; i < m_R; i++)
                    {
                        for (int j = 0; j < m_C; j++)
                        {
                            if (m_A[i, j] == 0) sw.Write(String.Format("."));
                            if (m_A[i, j] == 2) sw.Write(String.Format("/"));
                            if (m_A[i, j] == 3) sw.Write(String.Format("\\"));
                            if (m_A[i, j] == 4) sw.Write(String.Format("\\"));
                            if (m_A[i, j] == 5) sw.Write(String.Format("/"));
                        }
                        sw.Write(String.Format("\n"));
                    }
                }
            }

            sr.Close();
            sw.Close();
        }
    }
}
