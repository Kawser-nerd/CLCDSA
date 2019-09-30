using System;
using System.IO;

public class SnapperChain
{
    [STAThread]
    public static void Main(string[] args)
    {
        //StreamReader sr = new StreamReader(args[0]);
        //StreamWriter sw = new StreamWriter(args[1]);
        var sr = new StreamReader("input.txt");
        var sw = new StreamWriter("output.txt");

        int m_nCase = Convert.ToInt32(sr.ReadLine());
        for (int cs = 1; cs <= m_nCase; cs++)
        {
            string[] strTmp = sr.ReadLine().Trim().Split(new[] {' '});
            int m_M = Convert.ToInt32(strTmp[0]);
            int m_N = Convert.ToInt32(strTmp[1]);
            var m_arB = new int[m_M,m_N];
            for (int i = 0; i < m_M; i++)
            {
                string strT = sr.ReadLine().Trim();
                for (int j = 0; j < strT.Length; j++)
                {
                    int y = strT[j];
                    if (y < 65) y -= 48;
                    else y -= 55;
                    for (int k = 3; k >= 0; k--)
                    {
                        m_arB[i, j*4 + k] = ((y & 1) == 1 ? 1 : 0);
                        y = y >> 1;
                    }
                }
            }

            var arA = new int[m_M,m_N,3];
            var ans = new int[600];
            int ai = 0;
            while (true)
            {
                for (int i = 0; i < m_M; i++)
                    for (int j = 0; j < m_N; j++)
                    {
                        arA[i, j, 0] = 1;
                        arA[i, j, 1] = 1;
                        arA[i, j, 2] = 1;
                    }
                int max = 0;
                int im = 0;
                int jm = 0;
                for (int i = 0; i < m_M; i++)
                    for (int j = 0; j < m_N; j++)
                    {
                        if (m_arB[i, j] == 2) continue;
                        if (i != 0 && m_arB[i - 1, j] != m_arB[i, j] && m_arB[i - 1, j] != 2)
                            arA[i, j, 0] = arA[i - 1, j, 0] + 1;
                        if (j != 0 && m_arB[i, j - 1] != m_arB[i, j] && m_arB[i, j - 1] != 2)
                            arA[i, j, 1] = arA[i, j - 1, 1] + 1;
                        if (i != 0 && j != 0 &&
                            m_arB[i, j] == m_arB[i - 1, j - 1] && m_arB[i - 1, j - 1] != 2 &&
                            m_arB[i, j] != m_arB[i, j - 1] && m_arB[i, j - 1] != 2 &&
                            m_arB[i, j] != m_arB[i - 1, j] && m_arB[i - 1, j] != 2)
                            arA[i, j, 2] = Math.Min(Math.Min(arA[i - 1, j - 1, 2] + 1, arA[i, j, 0]), arA[i, j, 1]);
                        if (max < arA[i, j, 2])
                        {
                            max = arA[i, j, 2];
                            im = i;
                            jm = j;
                        }
                    }
                if (max!=0 && ans[max] == 0) ai++;
                ans[max]++;

                for (int i = im; i > im - max; i--)
                    for (int j = jm; j > jm - max; j--)
                        m_arB[i, j] = 2;
                if(max==1 || max==0) break;
            }

            for (int i = 0; i < m_M; i++)
                for (int j = 0; j < m_N; j++)
                    if (m_arB[i, j] != 2) ans[1]++;


            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ai));
            for (int i = 550; i > 0; i--)
                if (ans[i] != 0) sw.Write(String.Format("{0:G} {1:G}\n", i, ans[i]));
        }

        sr.Close();
        sw.Close();
    }
}