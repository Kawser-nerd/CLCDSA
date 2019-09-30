#region Using
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Globalization;
using System.Data.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Linq;

[assembly: AssemblyTitle("1")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("CSoft Development")]
[assembly: AssemblyProduct("1")]
[assembly: AssemblyCopyright("Copyright © CSoft Development 2008")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCulture("")]
[assembly: ComVisible(false)]
[assembly: Guid("e4262f53-7e02-4570-b31f-ad28272f907c")]
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]
#endregion

namespace DarkStar
{
  partial class Solver
  {
    public void Run()
    {
      int nCaseCount = ReadInt();
      for (int i = 0; i < nCaseCount; i++)
      {
        Case pCase = new Case();
        pCase.N = ReadLine();
        pCase.Run(i+1, this);
      }
    }
  }
    
  class Case
  {
    public int L { get { return N.Length; } }
    public string N;

    public void Run(int nCaseIndex, Solver pSolver)
    {
      var pNum = new int [L+1];
      pNum[0] = 0;
      for(int i=0; i<L; i++)
        pNum[i+1] = pSolver.S2I(N.Substring(i, 1));

      var pList = new List<int>();

      for (int i = pNum.Length - 1; i >= 1; i--)
      {
        pList.Add(pNum[i]);
        if (pNum[i] > pNum[i - 1])
        {
          int nMove = pNum[i - 1];
          pList.Sort();
          for(int j=0; j<pList.Count; j++)
            if (pList[j] > nMove)
            {
              pNum[i - 1] = pList[j];
              pList.RemoveAt(j);
              pList.Add(nMove);
              break;
            }

          pList.Sort();
          for (int j = i; j < pNum.Length; j++)
            pNum[j] = pList[j - i];
          break;
        }
      }

      StringBuilder sRes = new StringBuilder();
      for (int i = 0; i < pNum.Length; i++)
        if (i != 0 || pNum[i] != 0)
          sRes.Append(pNum[i]);

      pSolver.WriteFormat("Case #{0}: {1}", nCaseIndex, sRes.ToString());
    }
  }

  #region Main
  class Program
  {
    static void Main(string[] args)
    {
      try
      {
        string sPathIn = args[0];
        string sPathDir = Path.GetDirectoryName(sPathIn);
        if (!string.IsNullOrEmpty(sPathDir))
          sPathDir += Path.DirectorySeparatorChar;
        string sPathOut = sPathDir + Path.GetFileNameWithoutExtension(sPathIn) + "-out" + Path.GetExtension(sPathIn);
        using (StreamReader pInput = new StreamReader(sPathIn))
        using (StreamWriter pOutput = new StreamWriter(sPathOut))
        {
          Solver pSolver = new Solver(pInput, pOutput);
          pSolver.Run();
        }

      	Console.WriteLine("Ok. Result:");
        if(sPathIn == "_test.txt")
          Console.WriteLine(File.ReadAllText(sPathOut));
        Console.ReadLine();
      }
      catch (System.Exception e)
      {
      	Console.WriteLine("Error: " + e.Message);
        Console.WriteLine(e.StackTrace);
        Console.ReadLine();
        return;
      }
    }
  }
  #endregion

  partial class Solver
  {
    #region Constructor
    StreamReader m_pInput;
    StreamWriter m_pOutput;
    public Solver(StreamReader pInput, StreamWriter pOutput)
    {
      m_pInput = pInput;
      m_pOutput = pOutput;
    }
    #endregion

    #region Reading
    // Strings
    public string ReadLine()
    {
      string sLine = m_pInput.ReadLine();
      if (sLine == null)
        throw new Exception("EOF during reading");
      return sLine;
    }

    public string[] ReadLines(int nCount)
    {
      string[] aRes = new string[nCount];
      for (int i = 0; i < nCount; i++)
        aRes[i] = ReadLine();
      return aRes;
    }

    public string[] S2SS(string sText, char[] aSeparators, StringSplitOptions eOptions)
    {
      return sText.Split(aSeparators, eOptions);
    }
    public string[] S2SS(string sText)
    {
      return S2SS(sText, new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
    }

    public delegate T S2Data<T>(string sText);
    T ReadData<T>(string sText, S2Data<T> Func)
    {
      return Func(sText);
    }
    public T[] ReadDatas<T>(string[] sText, S2Data<T> Func)
    {
      T[] aRes = new T[sText.Length];
      for(int i=0; i<sText.Length; i++)
        aRes[i] = Func(sText[i]);
      return aRes;
    }

    public int ReadInt()
    {
      return ReadData<int>(ReadLine(), S2I);
    }

    // Data
    public int S2I(string sLine)
    {
      return Convert.ToInt32(sLine);
    }
    public double S2D(string sLine)
    {
      return Convert.ToDouble(sLine, CultureInfo.InvariantCulture);
    }
    public int S2T(string sLine)
    {
      string[] aPart = sLine.Split(':');
      return S2I(aPart[0]) * 60 + S2I(aPart[aPart.Length - 1]);
    }
    #endregion

    #region Writing
    public void WriteString(string sText)
    {
      m_pOutput.WriteLine(sText);
    }

    public void WriteFormat(string sFormat, params object[] aParams)
    {
      WriteString(string.Format(CultureInfo.InvariantCulture, sFormat, aParams));
    }
    #endregion
  }

}
