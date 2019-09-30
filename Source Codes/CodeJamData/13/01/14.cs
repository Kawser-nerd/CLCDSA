using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_QR_A
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_A_la.txt");
            TextWriter writer = new StreamWriter("../../output_A_la.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {
                bool notFinished = false;
                string[] b = new string[4];
                for (int i = 0; i < 4; i++)
                {
                    b[i] = reader.ReadLine();
                    if (b[i].Contains('.'))
                        notFinished = true;
                }
                string empty = reader.ReadLine();
                
                string ans = "";
                char[] p = new char[] { 'X', 'O' };

                //Check rows
                for (int j = 0; j < 2; j++)
                {
                    for (int r = 0; r < 4; r++)
                    {
                        int inRow = 0;
                        for (int c = 0; c < 4; c++)
                        {
                            char ch = b[r][c];
                            if (ch == p[j] || ch == 'T')
                                inRow++;
                        }
                        if (inRow == 4)
                        {
                            ans = p[j] + " won";
                            break;
                        }
                    }
                }

                //Check cols
                if (ans == "")
                {
                    for (int j = 0; j < 2; j++)
                    {
                        for (int c = 0; c < 4; c++)
                        {
                            int inCol = 0;
                            for (int r = 0; r < 4; r++)
                            {
                                char ch = b[r][c];
                                if (ch == p[j] || ch == 'T')
                                    inCol++;
                            }
                            if (inCol == 4)
                            {
                                ans = p[j] + " won";
                                break;
                            }
                        }
                    }
                
                }

                //Check diag
                if (ans == "")
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int inDiag = 0;
                        for (int r = 0; r < 4; r++)
                        {
                            char ch = b[r][r];
                            if (ch == p[j] || ch == 'T')
                                inDiag++;
                        }
                        if (inDiag == 4)
                        {
                            ans = p[j] + " won";
                            break;
                        }

                        inDiag = 0;
                        for (int r = 0; r < 4; r++)
                        {
                            char ch = b[r][3 - r];
                            if (ch == p[j] || ch == 'T')
                                inDiag++;
                        }
                        if (inDiag == 4)
                        {
                            ans = p[j] + " won";
                            break;
                        }
                    }
                }

                if (ans == "")
                    ans = notFinished ? "Game has not completed" : "Draw";
                                
                writer.WriteLine("Case #" + tc + ": " + ans);
            }

            reader.Close();
            writer.Close();
        }

    }
}
