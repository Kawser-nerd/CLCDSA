using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012_Round_1C
{
    class Out_of_Gas
    {
        static String sFileName = "B-small-attempt0";
        static String sInputFile = "";   // 읽을 파일 이름 
        static String sOutputFile = "";  // 저장할 파일 이름

        static StreamReader SRead = null;
        static StreamWriter SWrite = null;

        static void Main(string[] args)
        {
            sInputFile = @"\" + sFileName + ".in";
            sOutputFile = @"\" + sFileName + ".out";

            openFile();

            solveProblem();

            closeFile();

        }

        private static void solveProblem()
        {
            string sResult = "File 쓰기 TEST~!!";

            try
            {
                int iCases = Convert.ToInt32(SRead.ReadLine());

                String sFileLine = String.Empty;

                for (int idxCase = 1; idxCase <= iCases; idxCase++ )
                {
                    sFileLine = SRead.ReadLine();
                    String[] saContent = sFileLine.Split(' ');
                    Double dDistance = Convert.ToDouble(saContent[0]);
                    int iPosCount = Convert.ToInt32(saContent[1]);
                    int iAccel = Convert.ToInt32(saContent[2]);

                    Double[,] daaCar = new Double[iPosCount,2];                    
                    
                    // 거리와 가장 가까운 것 찾기.
                    Double[] daBelow = new Double[2]{0,0};                    
                    Double[] daSame = new Double[2]{0,0};
                    Double[] daAbove = new Double[2]{Double.MaxValue,Double.MaxValue};
                    
                    for (int idxPos = 1; idxPos <= iPosCount; idxPos++ )
                    {
                        sFileLine = SRead.ReadLine();
                        String[] saPos = sFileLine.Split(' ');

                        daaCar[idxPos-1,0] = Convert.ToDouble(saPos[0]);
                        daaCar[idxPos-1,1] = Convert.ToDouble(saPos[1]);

                        if (daaCar[idxPos - 1,1] == dDistance)
                        {
                            daSame[0] = daaCar[idxPos-1,0];
                            daSame[1] = daaCar[idxPos - 1,1];
                        }
                        else if (daaCar[idxPos - 1,1] > dDistance)
                        {
                            if (daAbove[1] > daaCar[idxPos - 1,1])
                            {
                                daAbove[0] = daaCar[idxPos - 1,0];
                                daAbove[1] = daaCar[idxPos - 1,1];
                            }
                        }
                        else if (daaCar[idxPos - 1,1] < dDistance)
                        {
                            if (daBelow[1] < daaCar[idxPos - 1,1])
                            {
                                daBelow[0] = daaCar[idxPos - 1,0];
                                daBelow[1] = daaCar[idxPos - 1,1];
                            }
                        }
                    }

                    // 해당 거리일 때의 시간 구하기.
                    Double dCarTime;
                    if (daSame[1] != 0)
                    {
                        dCarTime = daSame[0];
                    }
                    else
                    {
                        Double dV = (daAbove[1] - daBelow[1]) / (daAbove[0] - daBelow[0]);
                        dCarTime = ((dDistance - daBelow[1]) / dV) + daBelow[0];
                    }

                    // 0.5 * A * t^2 = Distance
                    sFileLine = SRead.ReadLine();
                    Double[] daAcc = new Double[iAccel];
                    saContent = sFileLine.Split(' ');

                    sResult = String.Format("Case #{0:D}:", idxCase);
                    SWrite.WriteLine(sResult);
                    for (int idxAcc = 0; idxAcc < iAccel; idxAcc++ )
                    {
                        Double dAcc = Convert.ToDouble(saContent[idxAcc]);
                        Double dTime = Math.Sqrt(dDistance/0.5/dAcc);

                        if(dTime <= dCarTime)
                        {
                            dTime = dCarTime;
                        }

                        sResult = String.Format("{0:F7}", dTime);
                        SWrite.WriteLine(sResult);
                    }

                    SWrite.Write("\n");

                }
                //SWrite.WriteLine(sResult);
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception occured" + e);
            }

        }

        private static void closeFile()
        {
            try
            {
                SRead.Close();
                SWrite.Close();
            }
            catch (IOException e)
            {
                Console.WriteLine("I/O error occured" + e);
            }

        }

        private static void openFile()
        {
            try
            {
                SRead = new StreamReader(Environment.CurrentDirectory + sInputFile, System.Text.Encoding.ASCII);
                SWrite = new StreamWriter(Environment.CurrentDirectory + sOutputFile, false, System.Text.Encoding.ASCII);
            }
            catch (IOException e)
            {
                Console.WriteLine("I/O error occured" + e);
            }
        }
    }
}
