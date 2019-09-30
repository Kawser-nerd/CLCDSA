using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Magicka
{
    class Program
    {
        internal static void Calculate(string fileInput, string fileOutput)
        {
            string[] splitters = new string[1] { " " };
            string[] fileText = File.ReadAllLines(fileInput);
            string[] fileOutputText = new string[fileText.Length - 1];
            int outputLine = 0;
            for (int index = 1; index < fileText.Length; index++)
            {
                string[] game = fileText[index].Split(splitters, StringSplitOptions.RemoveEmptyEntries);;
                char[,] makes = FillMakeArray(game);
                bool[,] antis = FillAntiArray(game);
                StringBuilder results = CalculateResults(game, makes, antis);
                for (int i = results.Length - 1; i > 0; --i)
                {
                    results.Insert(i, ", ");
                }
                fileOutputText[outputLine] = "Case #" + index.ToString() + ": [" + results.ToString() +"]";
                outputLine++;
            }
            File.WriteAllLines(fileOutput, fileOutputText, Encoding.ASCII);
        }

        internal static char[,] FillMakeArray(string[] game)
        {
            char[,] makes = new char[26, 26];
            int numberOfMakes = int.Parse(game[0]);
            for (int i = 1; i < numberOfMakes + 1; i++)
            {
                //for each make, look at the index of the game parse tree and get the elements and put them in the make
                string make = game[i];
                int index0 = make[0] - 65;
                int index1 = make[1] - 65;
                makes[index0, index1] = make[2];
                makes[index1, index0] = make[2];
            }
            return makes;
        }

        internal static bool[,] FillAntiArray(string[] game)
        {
            bool[,] antis = new bool[26, 26];
            int numberOfMakes = int.Parse(game[0]);
            int numberOfAntis = int.Parse(game[1 + numberOfMakes]);
            int startOfAntis = 2 + numberOfMakes;
            for (int i = startOfAntis; i < numberOfAntis + startOfAntis; i++)
            {
                //for each anti, look at the index of the game parse tree and get the elements and put true in
                string anti = game[i];
                int index0 = anti[0] - 65;
                int index1 = anti[1] - 65;
                antis[index0, index1] = true;
                antis[index1, index0] = true;
            }
            return antis;
        }

        internal static StringBuilder CalculateResults(string[] game, char[,] makes, bool[,] antis)
        {
            char[] crapCharArray = new char[1];
            char crapChar = crapCharArray[0];
            string bases = "QWERASDF";
            int numberOfMakes = int.Parse(game[0]);
            int numberOfAntis = int.Parse(game[1 + numberOfMakes]);
            int startOfElements = 2 + numberOfMakes + numberOfAntis + 1;
            int numberOfElements = int.Parse(game[startOfElements - 1]);
            string elements = game[startOfElements];
            bool hasPreviousChar = true;
            char previousChar = elements[0];
            StringBuilder result = new StringBuilder();
            result.Append(elements[0]);
            bool[] hasAppeared = new bool[26];
            for (int i = 1; i < numberOfElements; i++)
            {
                char currentChar = elements[i];
                result.Append(currentChar);
                char newElement = hasPreviousChar ? makes[currentChar - 65, previousChar - 65] : crapChar;
                if (newElement > 0)
                {
                    //We will form a new element
                    result.Remove(result.Length - 2, 2); //remove previous characters
                    result.Append(newElement);
                    previousChar = newElement;
                    hasPreviousChar = true;
                    //Dont bother to update hasAppeared since no one should care, only base elements can be in that list
                }
                else
                {
                    //we have to check whether this causes an anti!
                    if (hasPreviousChar)
                    {
                        hasAppeared[previousChar - 65] = true; //only updated after it's not combined with next element!
                    }
                    bool explosion = false;
                    foreach (char abase in bases)
                    {
                        if (hasAppeared[abase - 65] && antis[abase - 65, currentChar - 65])
                        {
                            explosion = true;
                            break;
                        }
                    }

                    if (explosion)
                    {
                        //update everything!
                        hasPreviousChar = false;
                        result = new StringBuilder();
                        hasAppeared = new bool[26];
                    }
                    else
                    {
                        //update to new char we wrote earlier in the loop
                        previousChar = currentChar;
                        hasPreviousChar = true;
                    }
                }
            }
            return result;
        }
        
        static void Main(string[] args)
        {
            Program.Calculate("../../B-large.in", "../../B-large.out");
            System.Console.WriteLine("Dog");
        }
    }
}
