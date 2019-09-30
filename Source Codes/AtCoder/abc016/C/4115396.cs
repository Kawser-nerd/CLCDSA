using System;
using System.Collections.Generic;
using System.Linq;
class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner() {
        s = new string[0];
        i = 0;
    }

    public string next() {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int Int() {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0) {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++) {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long() {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0) {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++) {
            Array[i] = Long() + add;
        }
        return Array;
    }
}
class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        var M = cin.Int();

        var A = new int[M];
        var B = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = cin.Int();
            B[i] = cin.Int();
        }

        for (int i = 1; i <= N; i++) {
            var que = new Queue<int>();
            var isFriend = new bool[13];
            isFriend[i] = true;
            for (int j = 0; j < M; j++) {
                if (A[j] == i) {
                    isFriend[B[j]] = true;
                    que.Enqueue(B[j]);
                }
                else if (B[j] == i) {
                    isFriend[A[j]] = true;
                    que.Enqueue(A[j]);
                }
            }

            int cnt = 0;
            while(que.Count > 0) {
                int dequeue = que.Dequeue();
                for (int j = 0; j < M; j++) {
                    if(A[j] == dequeue && isFriend[B[j]] == false) {
                        cnt++;
                        isFriend[B[j]] = true;
                    }
                    if(B[j] == dequeue && isFriend[A[j]] == false) {
                        cnt++;
                        isFriend[A[j]] = true;
                    }
                }
            }
            Console.WriteLine(cnt);
        }
        Console.ReadLine();
    }
}