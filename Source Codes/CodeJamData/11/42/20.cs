using System;
using System.Collections.Generic;
using System.Text;

namespace Blade
{
  class Program
  {
    static void Main(string[] args)
    {
      string[] inputLines = IO.ReadInputLines();
      List<string> outputLines = new List<string>();

      int nofTestCases = IO.GetInteger(inputLines[0], 0);
      int currentInputLine = 1;

      for (int iTestCase = 0; iTestCase < nofTestCases; iTestCase++)
      {
        int[] line1 = IO.GetIntArray(inputLines[currentInputLine]);
        currentInputLine++;
        int R = line1[0];
        int C = line1[1];
        int D = line1[2];

        int[,] sheet = new int[R, C];
        for (int iR = 0; iR < R; iR++)
        {
          string line = inputLines[currentInputLine];
          currentInputLine++;

          for (int iC = 0; iC < C; iC++)
          {
            sheet[iR, iC] = D + Convert.ToInt32(line.Substring(iC, 1));
          }
        }

        int result = 0;
        int K = Math.Min(R, C);
        for (int iK = K; iK >= 3; iK--)
        {
          int xMin2 = iK;
          int xMax2 = 2 * C - iK;
          int yMin2 = iK;
          int yMax2 = 2 * R - iK;

          for (int ix2 = xMin2; ix2 <= xMax2; ix2++)
          {
            for (int iy2 = yMin2; iy2 <= yMax2; iy2++)
            {
              if (HasCenteredPtGravity(sheet, ix2, iy2, iK))
              {
                result = iK;
                break;
              }
            }
            if (result != 0)
              break;
          }
          if (result != 0)
            break;
        }

        if (result != 0)
          outputLines.Add(String.Format("Case #{0}: {1}", iTestCase + 1, result));
        else
          outputLines.Add(String.Format("Case #{0}: {1}", iTestCase + 1, "IMPOSSIBLE"));
      }

      IO.WriteOutputFile(outputLines);
    }

    private static bool HasCenteredPtGravity(int[,] sheet, int ix2, int iy2, int K)
    {
      int xMin2 = ix2 - K + 1;
      int xMax2 = ix2 + K - 1;

      int yMin2 = iy2 - K + 1;  
      int yMax2 = iy2 + K - 1;

      int xMin = (xMin2 - 1) / 2;
      int xMax = (xMax2 - 1) / 2;

      int yMin = (yMin2 - 1) / 2;
      int yMax = (yMax2 - 1) / 2;

      long weightX = 0;
      long weightY = 0;

      for (int ibx = xMin; ibx <= xMax; ibx++)
      {
        int ibx2 = ibx * 2 + 1;
        for (int iby = yMin; iby <= yMax; iby++)
        {
          int iby2 = iby * 2 + 1;

          //exclude corners:
          if (
            (ibx == xMin && iby == yMin) ||
            (ibx == xMax && iby == yMin) ||
            (ibx == xMin && iby == yMax) ||
            (ibx == xMax && iby == yMax)
            )
            continue;

          weightX += sheet[iby, ibx] * (ibx2 - ix2);
          weightY += sheet[iby, ibx] * (iby2 - iy2);
        }
      }
      return (weightX == 0 && weightY == 0);
    }
  }
}
