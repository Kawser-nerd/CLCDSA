import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static final int INF = 1000000007;
    static int[] FCT;

    static void factorial(int x) {
        FCT = new int[x + 1];
        FCT[0] = 1;
        FCT[1] = 1;
        for (int i = 2; i <= x; i++) {
            FCT[i] = modmulti(FCT[i - 1], i);
        }
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

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        final String[] sl = s.split(" ");

        // ????????????
        // ????? ???? - 1
        int W = Integer.parseInt(sl[0]) - 1;
        int H = Integer.parseInt(sl[1]) - 1;

        // ???n???????(????)?
        // r????????
        // nCr
        // = nPr / r!
        // = n! / {(n - r)! * r!}

        // (W + H)C(W > H ? W : H)
        // = (W + H)! / {(W + H - biggerWH)! * biggerWH!}

        // (W + H)!
        int idx = W + H;
        factorial(idx);
        int x = FCT[idx];

        // (W + H - biggerWH)!
        idx = Math.min(W, H);
        int y = FCT[idx];

        // biggerWH!
        idx = Math.max(W, H);
        int z = FCT[idx];

        // ??
        int inverse = modcalc(modmulti(y, z), INF - 2);

        int ans = modmulti(x, inverse);

        out.println(ans);

        out.flush();
    }
}