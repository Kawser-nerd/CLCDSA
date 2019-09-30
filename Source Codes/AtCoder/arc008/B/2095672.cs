using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        Console.ReadLine();
        string s = Console.ReadLine();
        string t = Console.ReadLine();
        int[] kanban = new int[26];
        int[] kit = new int[26];

        for (int i = 0; i < s.Length; i++)
        {
            kanban[s[i] - 'A']++;
        }
        for (int j = 0; j < t.Length; j++)
        {
            kit[t[j] - 'A']++;
        }

        int max = 0;
        for (int i = 0; i < kanban.Length; i++)
        {
            if(kanban[i] != 0)
            {
                if(kit[i] == 0)
                {
                    max = -1;
                    break;
                }
                else
                {
                    max = Math.Max(max, kanban[i] / kit[i] + (kanban[i] % kit[i] != 0 ? 1 : 0));
                }
            }
        }
        Console.WriteLine(max);
    }
}