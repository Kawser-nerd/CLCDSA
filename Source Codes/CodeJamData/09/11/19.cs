using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace Prob1
{
    class Program
    {
        static bool IsHappyNumber(int n,int baseNo,Dictionary<int,int> stoppingNos)
        {
            int no = n;
            int m = 0;
            while (no != 0)
            {
                m += (no % baseNo) * (no % baseNo);
                no = no / baseNo;
            }
            if (m == 1)
                return true;
            else
            {
                if (stoppingNos.ContainsKey(m))
                    return false;
                else
                    stoppingNos.Add(m, m);
                return IsHappyNumber(m, baseNo, stoppingNos);

            }
        }
        static void Main(string[] args)
        {
            string[] inputData = File.ReadAllLines("C:\\A-small-attempt1.in");
            int noOfTests = Convert.ToInt32(inputData[0]);
            List<int> results = new List<int>();
            for (int iter = 1; iter < inputData.Length; iter++)
            {
                string lineData = inputData[iter];
                string[] baseStrings = lineData.Split(' ');
                List<int> bases = new List<int>();
                foreach (string baseString in baseStrings)
                {
                    bases.Add(Convert.ToInt32(baseString));
                }
                for (int i = 2; ; i++)
                {
                    bool result = true;
                    
                    foreach(int baseNo in bases)
                    {
                        Dictionary<int, int> stoppingNos = new Dictionary<int, int>();
                        result = IsHappyNumber(i, baseNo, stoppingNos);
                        if (result == false)
                            break;
                    }
                    if (result == true)
                    {
                        results.Add(i);
                        break;
                    }
                }
            }
            List<string> outputData = new List<string>();
            for (int iter = 0; iter < results.Count; iter++)
            {
                outputData.Add(string.Format("Case #{0}: {1}",iter+1,results[iter]));
            }
            File.WriteAllLines("C:\\A-small-attempt1.out", outputData.ToArray());
        }
    }
}
