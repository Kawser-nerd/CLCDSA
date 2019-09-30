using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                string sLine = oSR.ReadLine();
                string[] aLine = sLine.Split(' ');
                int R = int.Parse(aLine[0]);
                int C = int.Parse(aLine[1]);
                int N = int.Parse(aLine[2]);

                int nS = Solve(R, C, N);

                // write answer
                oAnswer.AppendFormat("Case #{0}: {1}", i + 1, nS);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Solve(int R, int C, int N)
        {
            int nBigRowF = C / 2 + (C & 1);
            int nBigRowE = C - nBigRowF;
            int nSmallRowF = C / 2;
            int nSmallRowE = C - nSmallRowF;

            int nNoB_A = R / 2 + (R & 1);
            int nNoS_A = R - nNoB_A;
            int nNoB_B = R / 2;
            int nNoS_B = R - nNoB_B;

            int nStep1_A = nNoB_A * nBigRowF + nNoS_A * nSmallRowF;
            int nStep1_B = nNoB_B * nBigRowF + nNoS_B * nBigRowE;

            int nCorB, nCorS;
            if((C & 1) == 1)
            {
                nCorB = 0;
                nCorS = 2;
            }
            else
            {
                nCorB = 1;
                nCorS = 1;
            }

            int nStep2_A, nStep2_B;
            int nStep2_1A = 0, nStep2_1B = 0;
            if (R == 1 || C == 1)
            {
                if(R == 1)
                {
                    nStep2_A = nBigRowE;
                    nStep2_B = nSmallRowE;

                    if(C == 1)
                    {
                    }
                    else if (C == 2)
                    {
                        nStep2_1B = 1;
                        nStep2_1A = 1;
                        nStep2_A--;
                        nStep2_B--;
                    }
                    else
                    {
                        if ((C & 1) == 1)
                        {
                            nStep2_1B = 2;
                            nStep2_B -= 2;
                        }
                        else
                        {
                            nStep2_1A = 1;
                            nStep2_1B = 1;
                            nStep2_A--;
                            nStep2_B--;
                        }
                    }
                }
                else
                {
                    // C == 1
                    nStep2_A = R / 2;
                    nStep2_B = R / 2 + (R & 1);

                    if (R == 1)
                    {
                    }
                    else if (R == 2)
                    {
                        nStep2_1B = 1;
                        nStep2_1A = 1;
                        nStep2_A--;
                        nStep2_B--;
                    }
                    else
                    {
                        if ((R & 1) == 1)
                        {
                            nStep2_1B = 2;
                            nStep2_B -= 2;
                        }
                        else
                        {
                            nStep2_1A = 1;
                            nStep2_1B = 1;
                            nStep2_A--;
                            nStep2_B--;
                        }
                    }
                }
            }
            else
            {
                if ((R & 1) == 1)
                {
                    if (R > 1)
                    {
                        nStep2_A = 2 * nCorB;
                        nStep2_B = 2 * nCorS;
                    }
                    else
                    {
                        nStep2_A = nCorB;
                        nStep2_B = nCorS;
                    }
                }
                else
                {
                    nStep2_A = nCorB + nCorS;
                    nStep2_B = nCorB + nCorS;
                }
            }

            int nHolB = (C - 1) / 2;
            int nHolS = (C - 2) / 2;
            if(nHolB < 0)
                nHolB = 0;
            if(nHolS < 0)
                nHolS = 0;

            int nFrameA, nFrameB;
            int x = R - 2;
            if ((x & 1) == 1)
            {
                nFrameA = x / 2 + 1;
                nFrameB = x / 2;
            }
            else
            {
                nFrameA = nFrameB = x / 2;
            }

            int nFFrameA, nFFrameB;

            if ((C & 1) == 1)
            {
                nFFrameA = 2 * nFrameA;
                nFFrameB = 2 * nFrameB;
            }
            else
            {
                nFFrameB = nFFrameA = nFrameA + nFrameB;
            }

            if (nFFrameA < 0)
                nFFrameA = 0;
            if (nFFrameB < 0)
                nFFrameB = 0;
            
            int nStep3_A, nStep3_B;
            if (R == 1 || C == 1)
            {
                nStep3_A = 0;
                nStep3_B = 0;
            }
            else
            {
                if (R == 1)
                {
                    nStep3_A = nHolB;
                    nStep3_B = nHolS;
                }
                else
                {
                    if ((R & 1) == 1)
                    {
                        nStep3_A = 2 * nHolB + nFFrameA;
                        nStep3_B = 2 * nHolS + nFFrameB;
                    }
                    else
                    {
                        nStep3_A = nHolS + nHolB + nFFrameA;
                        nStep3_B = nHolS + nHolB + nFFrameB;
                    }
                }
            }

            int nStep4_A, nStep4_B;
            if(R < 3 || C < 3)
            {
                nStep4_A = 0;
                nStep4_B = 0;
            }
            else
            {
                int nNoBig_A = (R - 2) / 2;
                int nNoSmall_A = R - 2 - nNoBig_A;
                int nNoSmall_B = (R - 2) / 2;
                int nNoBig_B = R - 2 - nNoBig_A;

                nStep4_A = nNoBig_A * nBigRowE + nNoSmall_A * nSmallRowE - nFFrameA;
                nStep4_B = nNoBig_B * nBigRowE + nNoSmall_B * nSmallRowE - nFFrameB;
            }

            int nS_A = 0, nS_B = 0;
            int NA = N, NB = N;

            if (NA >= nStep1_A)
            {
                NA -= nStep1_A;
            }
            else NA = 0;

            if (NB >= nStep1_B)
            {
                NB -= nStep1_B;
            }
            else NB = 0;

            if (NA > 0)
            {
                if (NA >= nStep2_1A)
                {
                    nS_A += nStep2_1A;
                    NA -= nStep2_1A;
                }
                else
                {
                    nS_A += NA;
                    NA = 0;
                }
            }

            if (NB > 0)
            {
                if (NB >= nStep2_1B)
                {
                    nS_B += nStep2_1B;
                    NB -= nStep2_1B;
                }
                else
                {
                    nS_B += 2 * NB;
                    NB = 0;
                }
            }

            if (NA > 0)
            {
                if(NA >= nStep2_A)
                {
                    nS_A += 2 * nStep2_A;
                    NA -= nStep2_A;
                }
                else
                {
                    nS_A += 2 * NA;
                    NA = 0;
                }
            }

            if (NB > 0)
            {
                if (NB >= nStep2_B)
                {
                    nS_B += 2 * nStep2_B;
                    NB -= nStep2_B;
                }
                else
                {
                    nS_B += 2 * NB;
                    NB = 0;
                }
            }

            if (NA > 0)
            {
                if (NA >= nStep3_A)
                {
                    nS_A += 3 * nStep3_A;
                    NA -= nStep3_A;
                }
                else
                {
                    nS_A += 3 * NA;
                    NA = 0;
                }
            }

            if (NB > 0)
            {
                if (NB >= nStep3_B)
                {
                    nS_B += 3 * nStep3_B;
                    NB -= nStep3_B;
                }
                else
                {
                    nS_B += 3 * NB;
                    NB = 0;
                }
            }

            if (NA > 0)
            {
                if (NA >= nStep4_A)
                {
                    nS_A += 4 * nStep4_A;
                    NA -= nStep4_A;
                }
                else
                {
                    nS_A += 4 * NA;
                    NA = 0;
                }
            }

            if (NB > 0)
            {
                if (NB >= nStep4_B)
                {
                    nS_B += 4 * nStep4_B;
                    NB -= nStep4_B;
                }
                else
                {
                    nS_B += 4 * NB;
                    NB = 0;
                }
            }

            if (nS_A < nS_B)
                return nS_A;
            else return nS_B;
        }
    }
}
