using System;
using System.Collections.Generic;

class AGC031 {
    static void Main() {
        int N;
        long res = 1;
        N = int.Parse(Console.ReadLine());
        char[] s = Console.ReadLine().ToCharArray();
        Dictionary<char, int> hashTable = new Dictionary<char, int>();

        for(int i = 0; i < N; i++) {
            if(hashTable.ContainsKey(s[i])) {
                hashTable[s[i]]++;
            } else {
                hashTable.Add(s[i], 1 + 1);
            }
        }

        foreach(var item in hashTable) {
            res *= item.Value;
            res %= 1000000007;
        }
        res -= 1;
        Console.WriteLine(res);
    }
}