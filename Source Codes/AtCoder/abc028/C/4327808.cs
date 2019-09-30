using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        const int INTEGER_COUNT = 5;
        const int INTEGER_MIN_VALUE = 1;
        const int INTEGER_MAX_VALUE = 100;
        const int SELECT_INDEX = 3 - 1;

        static void Main(string[] args)
        {
            var inputText = Console.In.ReadLine();
                        
            var intValues = new List<int>();
            string error;
            if (!GetIntegerValues(inputText, out intValues, out error))
            {
                Console.Out.WriteLine(error);
                return;
            }
            
            var sumHashSet = GetTreeNumberSumSet(intValues);
            var sumList = sumHashSet.OrderByDescending(n => n).ToList();
            
            if (SELECT_INDEX < sumList.Count)
            {
                Console.WriteLine(sumList[SELECT_INDEX].ToString());
            }
            else
            {
                Console.Out.WriteLine(string.Format("?????????????????"));
            }
        }

        private static HashSet<int> GetTreeNumberSumSet(List<int> intValues)
        {
            var sumHashSet = new HashSet<int>();
            for (int i = 0; i < intValues.Count; i++)
            {
                for (int j = 0; j < intValues.Count; j++)
                {
                    if (j == i) continue;
                    for (int k = 0; k < intValues.Count; k++)
                    {
                        if (k == i) continue;
                        if (k == j) continue;
                        var sum = intValues[i] + intValues[j] + intValues[k];
                        sumHashSet.Add(sum);
                    }
                }
            }
            return sumHashSet;
        }
        
        private static bool GetIntegerValues(string inputText, out List<int> intValues, out string error)
        {
            int currentNum = 0;
            intValues = new List<int>();
            error = string.Empty;

            var integerTextArray = inputText.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            if (integerTextArray.Length != INTEGER_COUNT)
            {
                error = string.Format("????????????????????? : {0}", INTEGER_COUNT);
                return false;
            }


            for (int i = 0; i < integerTextArray.Length; i++)
            {
                var integerText = integerTextArray[i];
                int intergerNum;
                if (!int.TryParse(integerText, out intergerNum))
                {
                    Console.Out.WriteLine(string.Format("??????????????????????? : {0}", integerText));
                    return false;
                }

                var inValueRange = INTEGER_MIN_VALUE <= intergerNum && intergerNum <= INTEGER_MAX_VALUE;

                if (!inValueRange)
                {
                    Console.Out.WriteLine(string.Format("???????????????Min : {0}?Max : {1}", INTEGER_MIN_VALUE, INTEGER_MAX_VALUE));
                    return false;
                }

                if (i == 0)
                {
                    currentNum = intergerNum;
                }
                else
                {
                    if (currentNum < intergerNum)
                    {
                        //???
                        currentNum = intergerNum;
                    }
                    else
                    {
                        Console.Out.WriteLine(string.Format("????????????????"));
                        return false;
                    }
                }
                intValues.Add(intergerNum);
            }
            return true;
        }

    }
}