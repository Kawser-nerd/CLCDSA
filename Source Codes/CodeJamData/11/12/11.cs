using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace GoogleCodeJamKiller
{
    class Program
    {
        public class GameObject
        {
            public List<string> WordList = new List<string>();
            public List<string> SeanLetters = new List<string>();
        }

        static void Main(string[] args)
        {
            List<GameObject> gameObjects = ReadData();

            StringBuilder strBuilder = new StringBuilder();

            for (int i = 0; i < gameObjects.Count(); i++)
            {
                GameObject gameObject = gameObjects[i];                

                strBuilder.Append(string.Format("Case #{0}:", i+ 1)); 

                for (int j = 0; j < gameObject.SeanLetters.Count(); j++)
                {
                    Dictionary<string, int> wordsToSteps = new Dictionary<string, int>();

                    for (int k = 0; k < gameObject.WordList.Count; k++)
                    {
                        int steps = 0;
                        string letters = (string)gameObject.SeanLetters[j].Clone();

                        List<string> availableWords = gameObject.WordList.ToArray().ToList();

                        string currentWord = gameObject.WordList[k];

                        availableWords = availableWords.Where((word) => word.Length == currentWord.Length).ToList();

                        if (availableWords.Count() == 1)
                        {
                            wordsToSteps[currentWord] = steps;
                            continue;
                        }

                        wordsToSteps[currentWord] = Play(availableWords, letters, currentWord, steps);
                    }

                    int maxValue = wordsToSteps.Values.Max();

                    foreach (string word in gameObject.WordList)
                    {
                        if (wordsToSteps[word] == maxValue)
                        {
                            strBuilder.Append(" " + word);
                            break;
                        }
                    }
                }

                strBuilder.AppendLine();
            }

            File.WriteAllText(@"C:\temp\outputFile2.txt", strBuilder.ToString());

        }

        private static int Play(List<string> availableWords, string letters, string currentWord, int steps)
        {
            char letter;

            while (availableWords.Count() != 1)
            {
                do
                {
                    letter = letters[0];
                    letters = letters.Substring(1);
                } while (availableWords.Where((word) => word.Contains(letter)).Count() == 0);

                if (!currentWord.Contains(letter))
                {
                    availableWords = availableWords.Where((word) => !word.Contains(letter)).ToList();
                    steps++;
                    continue;
                }

                int[] wordIndices = GetAllIndices(currentWord, letter);

                availableWords = availableWords.Where((word) => ArraysEqual(wordIndices, GetAllIndices(word, letter))).ToList();
            }

            return steps;

        }

        static bool ArraysEqual(Array a1, Array a2)
        {
            if (a1 == a2)
            {
                return true;
            }

            if (a1 == null || a2 == null)
            {
                return false;
            }

            if (a1.Length != a2.Length)
            {
                return false;
            }

            IList list1 = a1, list2 = a2;

            for (int i = 0; i < a1.Length; i++)
            {
                if (!Object.Equals(list1[i], list2[i]))
                {
                    return false;
                }
            }
            return true;
        }

        private static int[] GetAllIndices(string x, char y)
        {
            int index = 0;
            List<int> result = new List<int>();
            int output;
            
            while ((output = x.IndexOf(y, index)) != -1)
            {
                result.Add(output);
                index = output + 1;
            }

            return result.ToArray();
        }

        static List<GameObject> ReadData()
        {
            List<GameObject> gameObjects = new List<GameObject>();

            string[] inputData = File.ReadAllLines(@"C:\temp\inputFile2.txt");

            int caseNumber = Convert.ToInt32(inputData[0]);

            int currentLine = 1;

            for (int i = 1; i < caseNumber + 1; i++)
            {
                GameObject gameObject = new GameObject();

                currentLine = ReadInternal(inputData, currentLine, gameObject);

                gameObjects.Add(gameObject);
            }

            return gameObjects;
        }

        private static int ReadInternal(string[] inputData, int currentLine, GameObject gameObject)
        {
            string length = inputData[currentLine];

            string[] dataCount = length.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            int numWords = Convert.ToInt32(dataCount[0]);
            int numLists = Convert.ToInt32(dataCount[1]);

            currentLine++;

            for (int i = 0; i < numWords; i++)
            {
                gameObject.WordList.Add(inputData[currentLine]);
                currentLine++;
            }

            for (int j = 0; j < numLists; j++)
            {
                gameObject.SeanLetters.Add(inputData[currentLine]);
                currentLine++;
            }

            return currentLine;
        }
    }
}
