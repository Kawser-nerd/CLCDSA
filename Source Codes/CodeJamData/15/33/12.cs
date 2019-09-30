using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("C-small-attempt0.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    string[] caseBuffer = fileInputReader.ReadLine().Split(' ');
                    int c = int.Parse(caseBuffer[0]);
                    int d = int.Parse(caseBuffer[1]);
                    int v = int.Parse(caseBuffer[2]);

                    List<int> originalCoinBuffer = new List<int>();
                    string[] coinBuffer = fileInputReader.ReadLine().Split(' ');
                    for (int i = 0; i < d; ++i)
                    {
                        originalCoinBuffer.Add(int.Parse(coinBuffer[i]));
                    }

                    int minNewDenom = 0;
                    for (int neededNewDenom = 0; neededNewDenom <= v; ++neededNewDenom)
                    {
                        if (SearchIsEnableSet(originalCoinBuffer, neededNewDenom, v))
                        {
                            minNewDenom = neededNewDenom;
                            break;
                        }
                    }

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, minNewDenom));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }

        static bool SearchIsEnableSet(List<int> currentCoinBuffer, int addingCoins, int v)
        {
            if (addingCoins == 0)
            {
                HashSet<int> currentCoins = new HashSet<int>(currentCoinBuffer);
                for (int i = 1; i <= v; ++i)
                {
                    if (!IsRepresentable(currentCoins, i))
                    {
                        return false;
                    }
                }
                return true;
            }
            else
            {
                HashSet<int> currentCoins = new HashSet<int>(currentCoinBuffer);
                for (int i = 1; i <= v; ++i)
                {
                    if (!currentCoins.Contains(i))
                    {
                        currentCoins.Add(i);
                        bool isEnable = SearchIsEnableSet(currentCoins.ToList(), addingCoins - 1, v);
                        if (isEnable)
                            return true;
                        currentCoins.Remove(i);
                    }
                }
                return false;
            }
        }

        static bool IsRepresentable(HashSet<int> enableCoins, int remainValue)
        {
            if (remainValue <= 0)
            {
                return true;
            }

            HashSet<int> subSet = new HashSet<int>(enableCoins);
            foreach (int curCoin in enableCoins)
            {
                if (remainValue == curCoin)
                    return true;
                if (remainValue < curCoin)
                    continue;

                subSet.Remove(curCoin);
                bool isSubRepresentable = IsRepresentable(subSet, remainValue - curCoin);
                if (isSubRepresentable)
                {
                    return true;
                }
                subSet.Add(curCoin);
            }
            return false;
        }
    }
}
