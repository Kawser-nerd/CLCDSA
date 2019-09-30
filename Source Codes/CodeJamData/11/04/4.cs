using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoroSort
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
            for (int index = 2; index < fileText.Length; index += 2)
            {
                string candy = CalculateAnswer(fileText[index]).ToString();
                fileOutputText[outputLine] = "Case #" + caseNum.ToString() + ": " + candy + ".000000";
                outputLine++;
                caseNum++;
            }
            File.WriteAllLines(fileOutput, fileOutputText, Encoding.ASCII);
        }

        internal static int CalculateAnswer(string listOfCandy)
        {
            string[] splitters = new string[1] { " " };
            string[] candiesString = listOfCandy.Split(splitters, StringSplitOptions.RemoveEmptyEntries);
            int index = 1;
            int numberInOrder = 0;
            foreach (string candy in candiesString)
            {
                int newCandy = int.Parse(candy);
                if (index == newCandy)
                {
                    ++numberInOrder;
                }
                ++index;
            }

            return candiesString.Length - numberInOrder;
        }

        static void Main(string[] args)
        {
            Program.Calculate("../../D-large.in", "../../D-large.out");
            System.Console.WriteLine("Dog");
        }

    }
}
