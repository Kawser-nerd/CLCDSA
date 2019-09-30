using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Beg118D
{
    class Program
    {
        public static Dictionary<int, int> dpResults = new Dictionary<int, int>();
        static void Main(string[] args)
        {
            var matchNum = new int[9] { 2, 5, 5, 4, 5, 6, 3, 7, 6 };

            var read = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var N = read[0];
            var M = read[1];

            var A = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var AWithMatchNumDict = A.ToDictionary(x => x, x => matchNum[x - 1]);
            var retDict = new Dictionary<int, int>();
            foreach (var a in A)
                retDict.Add(a, 0);

            //var success = MaxCombination(N, AWithMatchNumDict, ref retDict);
            //if (!success) throw new ArgumentException("not successful");
            var maxLength = Dp(N, AWithMatchNumDict);
            dpResults.Add(0, 0);
            var NForLoop = N;
            while(NForLoop >0)
            {
                foreach(var aWithVal in AWithMatchNumDict.OrderBy(x => -x.Key))
                {
                    if(NForLoop >= aWithVal.Value && dpResults[NForLoop - aWithVal.Value] == dpResults[NForLoop] - 1)
                    {
                        retDict[aWithVal.Key] += 1;
                        NForLoop -= aWithVal.Value;
                        break;
                    }
                }
            }

            string ret = "";
            var sortedKeys = retDict.Keys.ToList();
            sortedKeys.Sort();
            foreach(var key in sortedKeys)
            {
                for(int i = retDict[key];i>0;i--)
                {
                    ret = key.ToString() + ret;
                }
            }

            Console.WriteLine(ret);
        }

        public static int Dp(int N, Dictionary<int, int> numWithMatchNumDict)
        {
            if (N == 0) return 0;
            else if (N < 0) return int.MinValue;
            else
            {
                if(!dpResults.Keys.Contains(N))
                {
                    var res = numWithMatchNumDict.Select(pair => Dp(N - pair.Value, numWithMatchNumDict)).Max() + 1;
                    dpResults.Add(N, res);
                }
                return dpResults[N];
            }

        }
        public static bool MaxCombination(int N, Dictionary<int,int> numWithMatchNumDict, ref Dictionary<int, int> retDict)
        {
            var test = new List<Dictionary<int, int>>();
            var minMatchNumVal = numWithMatchNumDict.Values.Min();
            var numMinMatchNumVals = numWithMatchNumDict.Where(x => x.Value == minMatchNumVal);
            var tempDict = new Dictionary<int, int>(numWithMatchNumDict);
            foreach(var pair in numMinMatchNumVals)
            {
                tempDict.Remove(pair.Key);
            }
            var numMinMatchNumVal = numMinMatchNumVals.Select(x => x.Key).Max();

            if (N % minMatchNumVal == 0)
            {
                retDict.Add(numMinMatchNumVal, N / minMatchNumVal);
                return true;
            }
            else if (tempDict.Count == 0)
                return false;
            else
            {
                var iMax = N / minMatchNumVal - 1;
                if (!retDict.Keys.Contains(numMinMatchNumVal)) retDict.Add(numMinMatchNumVal, iMax);
                int i = iMax;
                var result = false;
                for (; i >= 0; i--)
                {
                    retDict[numMinMatchNumVal] = i;
                    result = MaxCombination(N - i * minMatchNumVal, tempDict, ref retDict);
                    if (result)
                        return true;
                }

                return result;
            }
        }
    }
}