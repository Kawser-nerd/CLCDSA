using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public static class Program
{
    static void Main()
    {
        char[] S = Console.ReadLine().ToCharArray();
        char[] T = Console.ReadLine().ToCharArray();
        int []S_frequency = new int[26];
        int[] T_frequency = new int[26];
        for(int i = 0; i < 26; i++)
        {
            S_frequency[i] = 0;
            T_frequency[i] = 0;
        }
        for(int i = 0; i < S.Length; i++)
        {
            S_frequency[S[i] - 'a']++;
            T_frequency[T[i] - 'a']++;
        }
        Array.Sort(S_frequency);
        Array.Sort(T_frequency);
        String ans = "Yes";
        for(int i = 0; i < 26; i++)
        {
            if (S_frequency[i] != T_frequency[i]) { ans = "No"; }
        }
        Console.WriteLine(ans);
    }
}