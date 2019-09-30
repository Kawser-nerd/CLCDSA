using System;
using System.Collections.Generic;
using System.Text;

namespace CJ2010_R1C_B
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
        long L = IO.GetInteger(inputLines[currentInputLine], 0);
        long P = IO.GetInteger(inputLines[currentInputLine], 1);
        long C = IO.GetInteger(inputLines[currentInputLine], 2);

        long s = L;
        int nofFactors = 0;
        while (s < P)
        {
          s *= C;
          nofFactors++;
        }
        //nofFactors--;

        int x = 0;
        int h = 1;
        while (h < nofFactors)
        {
          h *= 2;
          x++;
        }

        outputLines.Add(String.Format("Case #{0}: {1}", iTestCase + 1, x));

        currentInputLine++;
      }

      IO.WriteOutputFile(outputLines);
    }
  }
}
