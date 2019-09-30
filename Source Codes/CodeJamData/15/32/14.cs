using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("B-small-attempt0.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    string[] caseBuffer = fileInputReader.ReadLine().Split(' ');
                    int k = int.Parse(caseBuffer[0]);
                    int l = int.Parse(caseBuffer[1]);
                    int s = int.Parse(caseBuffer[2]);

                    string keysBuf = fileInputReader.ReadLine().Trim();
                    List<char> keyChars = new List<char>(keysBuf.ToCharArray());

                    string wordBuf = fileInputReader.ReadLine().Trim();
                    List<char> wordChars = new List<char>(wordBuf.ToCharArray());

                    // Check Key Existance
                    HashSet<char> keyCharSet = new HashSet<char>();
                    foreach (char curKeyChar in keyChars)
                    {
                        keyCharSet.Add(curKeyChar);
                    }
                    bool isImpossibleWord = false;
                    foreach (char curWordChar in wordChars)
                    {
                        if (!keyCharSet.Contains(curWordChar))
                        {
                            isImpossibleWord = true;
                            break;
                        }
                    }
                    if (isImpossibleWord)
                    {
                        fileOutputWriter.WriteLine(string.Format("Case #{0}: 0.0", caseCounter));
                        continue;
                    }

                    int maxOverlapping = 0;
                    for (int i = 1; i < l; ++i)
                    {
                        bool isAllMatched = true;
                        for (int j = 0; j < l - i; ++j)
                        {
                            if (wordChars[j] != wordChars[i + j])
                            {
                                isAllMatched = false;
                                break;
                            }
                        }
                        if (isAllMatched)
                        {
                            maxOverlapping = l - i;
                            break;
                        }
                    }

                    int maxWordCount = 0;
                    if (maxOverlapping == 0)
                    {
                        maxWordCount = s / l;
                    }
                    else
                    {
                        maxWordCount = 1 + (s - l) / (l - maxOverlapping);
                    }

                    List<int> resultData = new List<int>();
                    char[] creatingBuf = new char[s];
                    BacktrackCases(keyChars, wordChars, s, creatingBuf, 0, resultData);

                    long remainCount = 0;
                    foreach (int giveCount in resultData)
                    {
                        remainCount += maxWordCount - giveCount;
                    }

                    double expectedRemain = (double)remainCount / (double)resultData.Count;

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1:0.0#######}", caseCounter, expectedRemain));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }

        static void BacktrackCases(List<char> keyChars, List<char> wordChars, int s, char[] curBuf, int curLen, List<int> resultData)
        {
            if (curLen >= s)
            {
                int wordCount = 0;
                for (int i = 0; i < s - wordChars.Count + 1; ++i)
                {
                    bool isMatched = true;
                    for (int j = 0; j < wordChars.Count; ++j)
                    {
                        if (curBuf[i + j] != wordChars[j])
                        {
                            isMatched = false;
                            break;
                        }
                    }
                    if (isMatched)
                    {
                        ++wordCount;
                    }
                }
                resultData.Add(wordCount);
            }
            else
            {
                for (int i = 0; i < keyChars.Count; ++i)
                {
                    curBuf[curLen] = keyChars[i];
                    BacktrackCases(keyChars, wordChars, s, curBuf, curLen + 1, resultData);
                }
            }
        }
    }
}
