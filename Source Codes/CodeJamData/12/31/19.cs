using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round_1B_Problem_B
{
    public class CaseData
    {
        private readonly List<List<int>> m_Classes;


        public CaseData(List<List<int>> classes)
        {
            m_Classes = classes;
        }

        public string Solve()
        {
            var classBitArray = new BitArray[m_Classes.Count];
            for (int i = 0; i < m_Classes.Count;i++)
            {
                classBitArray[i] = new BitArray(m_Classes.Count);
                bool foundDiamond = ExpandClasses(classBitArray[i], i);
                if(foundDiamond)
                {
                    return "Yes";
                }
            }
            return "No";
        }


        private bool ExpandClasses(BitArray classBitArray, int i)
        {
            if(classBitArray.Get(i) == true)
            {
                return true;
            }
            classBitArray.Set(i, true);
            foreach(var classIndex in m_Classes[i])
            {
                var foundDiamound = ExpandClasses(classBitArray, classIndex);
                if(foundDiamound)
                {
                    return true;
                }
            }
            return false;
        }
    }

    class Program
    {
        const string INPUT_FILE = "A-large.in";
        const string OUTPUT_FILE = "A-large.out";

        static void Main(string[] args)
        {
            var lines = new List<string>();
            using (var sr = new StreamReader(INPUT_FILE))
            {
                while (!sr.EndOfStream)
                {
                    lines.Add(sr.ReadLine());
                }
            }

            var numTestCases = int.Parse(lines[0]);

            var outputLines = new List<string>();
            int currentLineNumber = 1;
            var cases = new List<CaseData>();
            for (int i = 0; i < numTestCases; i++)
            {
                var caseData = lines[currentLineNumber];
                currentLineNumber++;

                var ints = new List<long>();
                {
                    var tokens = caseData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count == 1);
                var numClasses = ints[0];
                int processingClass = 1;
                var classes = new List<List<int>>();

                while(processingClass <= numClasses)
                {
                    var classInheritance = new List<int>();
                    var classData = lines[currentLineNumber];
                    currentLineNumber++;
                    var tokens = classData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    for(int j=1;j<tokens.Length;j++)
                    {
                        var classNumber = int.Parse(tokens[j]) - 1;
                        if (classNumber >= 0)
                        {
                            classInheritance.Add(classNumber);
                        }
                    }
                    classes.Add(classInheritance);
                    processingClass++;
                }

                cases.Add(new CaseData(classes));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + caseData.Solve();
                outputLines.Add(output);
            }

            using (var sw = new StreamWriter(OUTPUT_FILE))
            {
                foreach (var line in outputLines)
                {
                    sw.Write(line + "\n");
                }
            }
        }

    }
}
