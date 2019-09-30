using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace D
{
    class Program
    {
        class Group
        {
            public List<int> workers = new List<int>();
            public HashSet<int> machs = new HashSet<int>();

            public bool IsFullGroup
            {
                get
                {
                    return workers.Count == machs.Count;
                }
            }

            public int GroupNumber
            {
                get
                {
                    return workers.Count - machs.Count;
                }
            }

            public int GetSpendToMerge(Group other)
            {
                return workers.Count * other.machs.Count + other.workers.Count * machs.Count;
            }
        }

        class GroupPair
        {
            public Group a;
            public Group b;
            public int mergeSpend;
        }

        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("D-small-attempt1.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    int n = int.Parse(fileInputReader.ReadLine().Trim());
                    bool[,] isKnowMatrix = new bool[n, n];
                    for (int i = 0; i < n; ++i)
                    {
                        string lineBuffer = fileInputReader.ReadLine().Trim();
                        for (int j = 0; j < n; ++j)
                        {
                            isKnowMatrix[i, j] = (lineBuffer[j] == '1');
                        }
                    }

                    int spend = 0;

                    Dictionary<int, Group> machGroupMap = new Dictionary<int, Group>();
                    List<Group> workGroup = new List<Group>();
                    for (int i = 0; i < n; ++i)
                    {
                        bool isGrouped = false;
                        for (int j = 0; j < n; ++j)
                        {
                            if (isKnowMatrix[i, j])
                            {
                                if (machGroupMap.ContainsKey(j))
                                {
                                    List<int> mergedCoverage = new List<int>();
                                    HashSet<Group> mergingGroups = new HashSet<Group>();
                                    Group target = machGroupMap[j];
                                    for (int k = 0; k < n; ++k)
                                    {
                                        if (isKnowMatrix[i, k] && !target.machs.Contains(k))
                                        {
                                            mergedCoverage.Add(k);
                                            if (machGroupMap.ContainsKey(k))
                                            {
                                                mergingGroups.Add(machGroupMap[k]);
                                            }
                                            target.machs.Add(k);
                                            foreach (var groupWorker in target.workers)
                                            {
                                                isKnowMatrix[groupWorker, k] = true;
                                            }
                                            spend += target.workers.Count;
                                        }
                                    }
                                    foreach (var groupMach in target.machs)
                                    {
                                        if (!isKnowMatrix[i, groupMach])
                                        {
                                            isKnowMatrix[i, groupMach] = true;
                                            ++spend;
                                        }
                                    }
                                    target.workers.Add(i);

                                    foreach (Group toMerge in mergingGroups)
                                    {
                                        MergeDepGroup(target, toMerge, ref isKnowMatrix, ref spend);
                                        workGroup.Remove(toMerge);
                                        foreach (var groupMach in toMerge.machs)
                                        {
                                            mergedCoverage.Add(groupMach);
                                        }
                                    }
                                    foreach (int coverMach in mergedCoverage)
                                    {
                                        machGroupMap[coverMach] = target;
                                    }
                                    isGrouped = true;
                                    break;
                                }
                            }
                        }
                        if (!isGrouped)
                        {
                            Group creatingGroup = new Group();
                            creatingGroup.workers.Add(i);
                            for (int j = 0; j < n; ++j)
                            {
                                if (isKnowMatrix[i, j])
                                {
                                    creatingGroup.machs.Add(j);
                                    machGroupMap.Add(j, creatingGroup);
                                }
                            }
                            workGroup.Add(creatingGroup);
                        }
                    }
                    for (int i = 0; i < n; ++i)
                    {
                        if (!machGroupMap.ContainsKey(i))
                        {
                            Group creatingGroup = new Group();
                            creatingGroup.machs.Add(i);
                            workGroup.Add(creatingGroup);
                        }
                    }

                    workGroup.RemoveAll(x => x.IsFullGroup);
                    while (workGroup.Count > 0)
                    {
                        Group merge1 = null;
                        Group merge2 = null;
                        foreach (Group group1 in workGroup)
                        {
                            List<Group> matchedGroups = workGroup.FindAll(x => x.GroupNumber == -group1.GroupNumber);
                            if (matchedGroups.Count > 0)
                            {
                                matchedGroups.Sort((x, y) => x.GetSpendToMerge(group1).CompareTo(y.GetSpendToMerge(group1)));
                                merge1 = group1;
                                merge2 = matchedGroups[0];
                                break;
                            }
                        }
                        if (merge1 != null)
                        {
                            MergeGroup(merge1, merge2, ref isKnowMatrix, ref spend);
                            workGroup.Remove(merge2);
                        }
                        else
                        {
                            // No Matching Groups
                            workGroup.Sort((x, y) => x.GroupNumber.CompareTo(y.GroupNumber));
                            List<Group> minGroups = new List<Group>(); minGroups.Add(workGroup[0]);
                            List<Group> maxGroups = new List<Group>(); maxGroups.Add(workGroup[workGroup.Count - 1]);
                            for (int i = 1; i < workGroup.Count; ++i)
                            {
                                if (workGroup[i].GroupNumber == workGroup[0].GroupNumber)
                                {
                                    minGroups.Add(workGroup[i]);
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for (int i = workGroup.Count - 2; i > 0; --i)
                            {
                                if (workGroup[i].GroupNumber == workGroup[workGroup.Count - 1].GroupNumber)
                                {
                                    maxGroups.Add(workGroup[i]);
                                }
                                else
                                {
                                    break;
                                }
                            }
                            List<GroupPair> pairList = new List<GroupPair>();
                            foreach (Group group1 in minGroups)
                            {
                                foreach (Group group2 in maxGroups)
                                {
                                    GroupPair curPair = new GroupPair();
                                    curPair.a = group1;
                                    curPair.b = group2;
                                    curPair.mergeSpend = group1.GetSpendToMerge(group2);
                                    pairList.Add(curPair);
                                }
                            }
                            pairList.Sort((x, y) => x.mergeSpend.CompareTo(y.mergeSpend));
                            MergeGroup(pairList[0].a, pairList[0].b, ref isKnowMatrix, ref spend);
                            workGroup.Remove(pairList[0].b);
                        }
                        workGroup.RemoveAll(x => x.IsFullGroup);
                    }

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, spend));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }

        static void MergeDepGroup(Group group1, Group group2, ref bool[,] isKnowMatrix, ref int spend)
        {
            foreach (int g1Worker in group1.workers)
            {
                foreach (int g2Mach in group2.machs)
                {
                    if (!isKnowMatrix[g1Worker, g2Mach])
                    {
                        isKnowMatrix[g1Worker, g2Mach] = true;
                        ++spend;
                    }
                }
            }
            foreach (int g2Worker in group2.workers)
            {
                foreach (int g1Mach in group1.machs)
                {
                    if (!isKnowMatrix[g2Worker, g1Mach])
                    {
                        isKnowMatrix[g2Worker, g1Mach] = true;
                        ++spend;
                    }
                }
            }
            group1.workers.AddRange(group2.workers);
            group1.machs.UnionWith(group2.machs);
        }

        static void MergeGroup(Group group1, Group group2, ref bool[,] isKnowMatrix, ref int spend)
        {
            spend += group1.workers.Count * group2.machs.Count + group2.workers.Count * group1.machs.Count;
            foreach (int g1Worker in group1.workers)
            {
                foreach (int g2Mach in group2.machs)
                {
                    isKnowMatrix[g1Worker, g2Mach] = true;
                }
            }
            foreach (int g2Worker in group2.workers)
            {
                foreach (int g1Mach in group1.machs)
                {
                    isKnowMatrix[g2Worker, g1Mach] = true;
                }
            }
            group1.workers.AddRange(group2.workers);
            group1.machs.UnionWith(group2.machs);
        }
    }
}
