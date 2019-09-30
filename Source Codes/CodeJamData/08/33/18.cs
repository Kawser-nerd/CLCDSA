using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace BaseProject
{
    class Program
    {
        static void Main(string[] args)
        {
            string basePath = @"C:\Documents and Settings\Rac\Pulpit\";
            string inputFile = basePath + "C-small-attempt1.in";
            //string inputFile = basePath + "i.txt";
            string outputFile = basePath+"o.txt";
         
            string result = null;          
            ValidateInputOutputFiles(inputFile, outputFile);  
            string[] input = Load(inputFile);
            RacSolver solver = new RacSolver();
            result = solver.SolveAll(input);
            Save(result,outputFile);
            System.Console.Out.WriteLine(result.ToString());
        }


        #region io
        public static void ValidateInputOutputFiles(string input, string output)
        {
            if(input==output)
                throw new Exception("Input file should be different than output");
        }
        public static string[] Load(string fileName)
        {
            if(!File.Exists(fileName))
                throw new Exception("File doesnt exist! " + Environment.NewLine + Path.GetFullPath(fileName) + Environment.NewLine);
            return File.ReadAllLines(fileName);
        }
        public static void Save(string output, string fileName)
        {
            if(output == null)
                throw new Exception("output equals null! ");
            if(File.Exists(fileName))
                File.Delete(fileName);
            File.AppendAllText(fileName, output);
        }
        #endregion


    }
}
