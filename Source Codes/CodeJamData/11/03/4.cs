using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CandySplitting
{
    class Program
    {
        internal static void Calculate(string fileInput, string fileOutput)
        {
            string[] splitters = new string[1] { " " };
            string[] fileText = File.ReadAllLines(fileInput);
            string[] fileOutputText = new string[fileText.Length - 1];
            int outputLine = 0;
            int caseNum = 1;
            for (int index = 2; index < fileText.Length; index+= 2)
            {
                string candy = CalculateAnswer(fileText[index]);
                fileOutputText[outputLine] = "Case #" + caseNum.ToString() + ": " + candy;
                outputLine++;
                caseNum++;
            }
            File.WriteAllLines(fileOutput, fileOutputText, Encoding.ASCII);
        }

        internal static string CalculateAnswer(string listOfCandy)
        {
            string[] splitters = new string[1] { " " };
            string[] candiesString = listOfCandy.Split(splitters, StringSplitOptions.RemoveEmptyEntries);
            List<int> candies = new List<int>(candiesString.Length);
            int xorTotal = 0;
            Int64 sum = 0;
            foreach (string candy in candiesString)
            {
                int newCandy = int.Parse(candy);
                candies.Add(newCandy);
                xorTotal = xorTotal ^ newCandy;
                sum += newCandy;
            }
            if (xorTotal != 0)
            {
                return "NO";
            }

            return (sum - candies.Min()).ToString();
        }

        static void Main(string[] args)
        {
            Program.Calculate("../../C-large.in", "../../C-large.out");
            System.Console.WriteLine("Dog");
        }
    }
}
