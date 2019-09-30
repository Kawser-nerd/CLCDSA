using System;
using System.Collections.Generic;
using System.IO;


class Google
{
    static void Main()
    {

        TextReader inputFile = new StreamReader("input.txt");
        TextWriter outputFile = new StreamWriter("output.txt");
        string inputString = inputFile.ReadToEnd();
        string[] inputData = inputString.Split(new char[0], StringSplitOptions.RemoveEmptyEntries);
        int dataIndex = 0;
        inputFile.Close();

        int testCases = int.Parse(inputData[dataIndex++]);
        for (int t = 1; t <= testCases; t++)
        {
            double L = int.Parse(inputData[dataIndex++]);
            double P = int.Parse(inputData[dataIndex++]);
            double C = int.Parse(inputData[dataIndex++]);
   
            double tests = 0;
            tests = Math.Ceiling(Math.Log(Math.Ceiling(Math.Log(P / L, C)), 2));
            outputFile.WriteLine("Case #" + t + ": " + tests);
        }
        outputFile.Close();

    }
}

