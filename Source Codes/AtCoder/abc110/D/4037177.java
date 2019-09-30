import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

import java.util.HashMap;

@SuppressWarnings("unchecked")
public class Main {
    static final int INF = 1000000007;
    static int MAX_EXP = 0;
    static int[] FCT;
    static int[] INV;

    // ?????
    static void primeFactor(HashMap<Integer, Integer> pf, int n) {
        int a = 2;

        // JDK 1.8 Map.merge
        // map value increment
        while (a * a <= n) {
            if (n % a == 0) {
                pf.merge(a, 1, Integer::sum);
                MAX_EXP = Math.max(MAX_EXP, pf.get(a));
                n = n / a;
            } else a++;
        }

        if (n != 1) {
            pf.merge(n, 1, Integer::sum);
            MAX_EXP = Math.max(MAX_EXP, pf.get(n));
        }
    }

    static void factorial(int x) {
        if (x == 0) return;

        FCT = new int[x + 1];
        FCT[0] = 1;
        FCT[1] = 1;
        for (int i = 2; i <= x; i++)
            FCT[i] = modmulti(FCT[i - 1], i);
    }

    static void inverse(int x) {
        if (x == 0) return;

        INV = new int[x + 1];
        INV[0] = 1;
        INV[1] = 1;
        INV[x] = modcalc(FCT[x], INF - 2);
        for (int i = x - 1; 2 <= i; i--)
            INV[i] = modmulti(INV[i + 1], i + 1);
    }

    // Combination WH
    // nCk
    static int combination(int a, int b) {
        int tmp = modmulti(FCT[a], INV[a - b]);
        return modmulti(tmp, INV[b]);
    }

    // a?b??p???????????(a ^ b mod p)
    static int modcalc(int a, int b) {
        // O(log b)
        int d = 0;
        if (b == 0) {
            return 1;
        } else if ((b & 1) == 0) {
            // ?? b???????
            d = modcalc(a, b / 2);
            return modmulti(d, d);
        } else {
            // ?? -1???1?????
            return modmulti(a, modcalc(a, b - 1));
        }
    }

    // a?b??????mod??(a * b mod p)
    static int modmulti(int a, int b) {
        int res = 0;
        int mod = a % INF;
        while (b > 0) {
            if ((b & 1) == 1) {
                res += mod;
                if (res > INF) {
                    res -= INF;
                }
            }
            mod <<= 1;
            if (mod > INF) {
                mod -= INF;
            }
            b >>= 1;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        final String s;

        try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        final String[] sl = s.split(" ");
        int N = Integer.parseInt(sl[0]);
        int M = Integer.parseInt(sl[1]);

        HashMap<Integer, Integer> pf = new HashMap<>();

        primeFactor(pf, M);

        factorial(N + MAX_EXP - 1);

        inverse(N + MAX_EXP - 1);

        int ans = 1;

        for (Integer i : pf.values())
            // (?????????? + N - 1)C(??????????)
            ans = modmulti(ans, combination(i + N - 1, i));

        out.println(ans);

        out.flush();
    }
}