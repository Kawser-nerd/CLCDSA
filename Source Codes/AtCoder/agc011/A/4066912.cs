using System;
using System.Collections.Generic;
using System.Linq;
class Scanner //????
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
    static void Main(string[] args) {
        int N = cin.Int();
        int C = cin.Int();
        int K = cin.Int();
        var T = new int[N];
        for (int i = 0; i < N; i++) {
            T[i] = cin.Int();
        }
        Array.Sort(T);

        int first = 0, cnt = 0;
        while (true) {
            if (first >= N) break;
            else if (first + C - 1 >= N) {
                if (T[N - 1] <= T[first] + K) { //???????
                    cnt++;
                    first = N;
                    break;
                }
                else {
                    int index = first;
                    while (T[index] <= T[first] + K) index++;
                    first = index;
                    cnt++;
                }
            }
            else {
                if (T[first + C - 1] <= T[first] + K) { //C??????????
                    cnt++;
                    first += C;
                }
                else { //?????????????K????????????
                    int index = first;
                    while (T[index] <= T[first] + K) index++;
                    first = index;
                    cnt++;
                }
            }
        }
        Console.WriteLine(cnt);
        Console.ReadLine();
    }
}