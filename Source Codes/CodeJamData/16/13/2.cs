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
            using (FileStream fileInputStream = new FileStream("C-large.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    int n = int.Parse(fileInputReader.ReadLine());
                    int[] bffList = new int[n];
                    string[] lineBuf = fileInputReader.ReadLine().Trim().Split(' ');
                    for (int i = 0; i < n; ++i)
                    {
                        bffList[i] = int.Parse(lineBuf[i]) - 1;
                    }

                    List<List<int>> inverseBff = new List<List<int>>();
                    for (int i = 0; i < n; ++i)
                    {
                        List<int> inverseBffCurrent = new List<int>();
                        for (int j = 0; j < n; ++j)
                        {
                            if (i == j)
                                continue;
                            if (bffList[j] == i)
                            {
                                inverseBffCurrent.Add(j);
                            }
                        }
                        inverseBff.Add(inverseBffCurrent);
                    }

                    List<List<int>> circleList = new List<List<int>>();
                    int maxCircleLength = 0;
                    List<List<int>> freeSegmentSeedList = new List<List<int>>();
                    for (int i = 0; i < n; ++i)
                    {
                        HashSet<int> isVisited = new HashSet<int>();
                        List<int> currentCircle = new List<int>();
                        isVisited.Add(i);
                        currentCircle.Add(i);
                        int nextVisit = bffList[i];
                        while (!isVisited.Contains(nextVisit))
                        {
                            currentCircle.Add(nextVisit);
                            isVisited.Add(nextVisit);
                            nextVisit = bffList[nextVisit];
                        }
                        if (nextVisit == i)
                        {
                            if (currentCircle.Count == 2)
                            {
                                if (currentCircle[0] < currentCircle[1])
                                {
                                    freeSegmentSeedList.Add(currentCircle);
                                }
                            }
                            else
                            {
                                circleList.Add(currentCircle);
                                if (currentCircle.Count > maxCircleLength)
                                {
                                    maxCircleLength = currentCircle.Count;
                                }
                            }
                        }
                    }

                    int lengthSum = 0;
                    foreach (List<int> currentSegmentSeed in freeSegmentSeedList)
                    {
                        lengthSum += 2 + GetInverseDepthLength(inverseBff, currentSegmentSeed[0], 0, currentSegmentSeed[1]) + GetInverseDepthLength(inverseBff, currentSegmentSeed[1], 0, currentSegmentSeed[0]);
                    }

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, Math.Max(maxCircleLength, lengthSum)));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }

        static int GetInverseDepthLength(List<List<int>> inverseBff, int start, int currentLength, int except)
        {
            List<int> current = inverseBff[start];
            if (current.Count == 0)
            {
                return currentLength;
            }

            List<int> subDepthList = new List<int>();
            foreach (int next in current)
            {
                if (next == except)
                    continue;
                subDepthList.Add(GetInverseDepthLength(inverseBff, next, currentLength + 1, except));
            }
            if (subDepthList.Count == 0)
            {
                return currentLength;
            }
            return subDepthList.Max();
        }
    }
}
