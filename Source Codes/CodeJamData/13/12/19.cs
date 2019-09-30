using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CodeJam;
using System.Numerics;

namespace Proj
{
    class Program
    {
        static int[] AValues;
        static int N = 0;
        static int[] UsedE;
        static int MaxE;
        static int R;   

        static int CalcEnergy(int Index)
        {
            int Res = MaxE;
            for (var i = 0; i < Index; i++)
            {
                Res = Res - UsedE[i] + R;
                if (Res > MaxE)
                    Res = MaxE;
            }
            return Res;
        }

        static int Correct()
        {
            int Res = MaxE;
            int Correct = 0;
            for (var i = 0; i < N; i++)
            {
                if (Res - UsedE[i] < 0)
                {
                    int CurCorrect = -(Res - UsedE[i]);
                    if (CurCorrect > Correct)
                        Correct = CurCorrect;
                    Res = UsedE[i];
                }
                Res = Res - UsedE[i] + R;
                if (Res > MaxE)
                    Res = MaxE;                
            }
            return Correct;
        }

        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem("D:\\CodeJam\\test.in"))
            {
                var TestCount = prob.ReadLineInt32();                

                for (var i = 0; i < TestCount; i++)
                {
                                     
                    prob.ReadInts(out MaxE, out R, out N);
                    AValues = prob.ReadInt32Array();
                    UsedE = new int[N];

                    bool[] Tested = new bool[N];
                    int MaxGain = 0;
                    int MaxGainInd = -1;

                    bool Again = true;

                    while (Again)
                    {
                        Again = false;
                        MaxGain = 0;
                        MaxGainInd = -1;

                        for (var k = 0; k < N; k++)
                        {
                            if ((Tested[k] == false) && (AValues[k] > MaxGain))
                            {
                                MaxGainInd = k;
                                MaxGain = AValues[k];
                            }
                        }
                        if (MaxGainInd > -1)
                        {
                            Tested[MaxGainInd] = true;
                            UsedE[MaxGainInd] = CalcEnergy(MaxGainInd);
                            if (UsedE[MaxGainInd] > 0)
                            {

                                Again = true;
                            }
                            UsedE[MaxGainInd] -= Correct();
                            if (UsedE[MaxGainInd] > 0)
                            {
                                
                                Again = true;
                            }
                            else
                                UsedE[MaxGainInd] = 0;
                            if (Correct() < 0)
                                Again = false;
                        }
                    }


                    int Gain = 0;
                    for (var k = 0; k < N; k++)
                    {
                        Gain += UsedE[k] * AValues[k];
                    }
                    prob.OutputCase(Gain);
                }
            }

        }
    }
}
