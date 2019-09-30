using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int itemCount = int.Parse(Reader.ReadLine());
        List<int> numList = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToList();

        List<int[]> ans = null;
        for (int i = 0; i < itemCount; i++) {
            List<int> subList = new List<int>(numList);
            ans = GetAns(i, subList);
            if(ans != null) {
                Console.WriteLine(ans.Count);
                ans.Select(a=>string.Join(" ", a.Select(b=>b+1))).ToList().ForEach(a=>Console.WriteLine(a));
                return;
            }
        }
    }

    private List<int[]> GetAns(int fixIdx, List<int> array) {
        List<int> subArray = new List<int>(array);
        List<int[]> ans = GetAnsUpper(fixIdx, subArray, new List<int[]>());
        if(ans != null) {
            ans = GetAnsLower(fixIdx, subArray, ans);
            if(ans != null) {
                return ans;
            }
        }
        subArray = new List<int>(array);
        ans = GetAnsLower(fixIdx, subArray, new List<int[]>());
        if(ans != null) {
            ans = GetAnsUpper(fixIdx, subArray, ans);
            if(ans != null) {
                return ans;
            }
        }
        return null;
    }

    private List<int[]> GetAnsLower(int fixIdx, List<int> array, List<int[]> subAns) {
        List<int[]> ans = new List<int[]>(subAns);
        for (int i = fixIdx - 1; i>= 0; i--)
        {
            if (array[i] <= array[i + 1])
            {
                continue;
            }
            int diff = array[i + 1] - array[i];
            List<int> tmp = array.Where(a => a <= diff).OrderByDescending(a => a).ToList();
            while (tmp.Count == 0 && diff < 0)
            {
                int add = array.OrderBy(a => a).First();
                if (add > 0)
                {
                    return null;
                }
                int addIdx = array.FindIndex(a => a == add);
                ans.Add(new int[] { addIdx, i });
                if (ans.Count > array.Count * 2)
                {
                    return null;
                }
                array[i] += add;
                diff = array[i + 1] - array[i];
                tmp = array.Where(a => a <= diff).OrderByDescending(a => a).ToList();
            }
            if (diff >= 0)
            {
                continue;
            }
            int idx = array.FindIndex(a => a == tmp[0]);
            ans.Add(new int[] { idx, i });
            if (ans.Count > array.Count * 2)
            {
                return null;
            }
            array[i] += tmp[0];
        }
        return ans;
    }

    private List<int[]> GetAnsUpper(int fixIdx, List<int> array, List<int[]> subAns) {
        List<int[]> ans = new List<int[]>(subAns);
        for (int i = fixIdx + 1; i < array.Count; i++)
        {
            if (array[i] >= array[i - 1])
            {
                continue;
            }
            int diff = array[i - 1] - array[i];
            List<int> tmp = array.Where(a => a >= diff).OrderBy(a => a).ToList();
            while (tmp.Count == 0 && diff > 0)
            {
                int add = array.OrderByDescending(a => a).First();
                if (add < 0)
                {
                    return null;
                }
                int addIdx = array.FindIndex(a => a == add);
                ans.Add(new int[] { addIdx, i });
                if(ans.Count > array.Count*2) {
                    return null;
                }
                array[i] += add;
                diff = array[i - 1] - array[i];
                tmp = array.Where(a => a >= diff).OrderBy(a => a).ToList();
            }
            if (diff <= 0)
            {
                continue;
            }
            int idx = array.FindIndex(a => a == tmp[0]);
            ans.Add(new int[] { idx, i });
            if(ans.Count> array.Count*2) {
                return null;
            }
            array[i] += tmp[0];
        }
        return ans;
    }

    private bool IsValid(List<int> array) {
        for (int i = 1; i < array.Count; i++) {
            if(array[i-1]>array[i]) {
                return false;
            }
        }
        return true;
    }

    public class Reader
    {
        private static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"





3
-2 5 -1



";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}