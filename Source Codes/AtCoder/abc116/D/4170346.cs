using System;
using System.Linq;
using System.Collections.Generic;

class Dmondai
{
    static void Main()
    {
        var line = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
        var N = line[0];
        var K = line[1];
        var list = new List<long[]>();
        var netaAllCount = 0L;
        for (int i=0;i<N;++i)
        {
            var line1 = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
            list.Add(new long[2]{ line1[0],line1[1]});
        }
        list = list.OrderBy(x => x[0]).ThenByDescending(x => x[1]).ToList();
        for (int i=N-1;0<i;--i)
        {
            if (list[i][0] != list[i - 1][0])
            {
                list[i][0] = 1;
                netaAllCount++;
            }
            else list[i][0] = 0;
        }
        list[0][0] = 1;
        list = list.OrderByDescending(x => x[1]).ThenByDescending(x=>x[0]).ToList();
        var selectedList = list.Take(K).ToList();
        var selectedNeta = 0L;
        var selectedOishisa = 0L;
        var stack = new Stack<long>();
        for (int i=0;i<K;++i)
        {
            selectedNeta += selectedList[i][0];
            selectedOishisa += selectedList[i][1];
            if (selectedList[i][0] == 0) stack.Push(selectedList[i][1]);
        }
        var ans = selectedOishisa + selectedNeta * selectedNeta;
        for (int i=K;i<N;++i)
        {
            if (list[i][0] == 0) continue;
            if (/*K <= selectedNeta ||*/ stack.Count() < 1 /*|| netaAllCount <= selectedNeta*/) break;
            selectedNeta += list[i][0];
            selectedOishisa = selectedOishisa + list[i][1] - stack.Pop();
            var temp= selectedOishisa + selectedNeta * selectedNeta;
            ans = temp < ans ? ans : temp;
        }
        Console.WriteLine(ans);
    }
}