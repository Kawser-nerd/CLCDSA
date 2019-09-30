
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;
    static boolean[] isPrime = new boolean[5000];

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new InputStreamReader(System.in));
        in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintWriter(new FileWriter("output.txt"));
        stk = new StringTokenizer(in.readLine());
        // Start of User Code

        int T = ni();
        for (int t = 1; t <= T; t++) {
            out.printf("Case #%d: %s\n", t, proc());
        }

        // End of User Code
        out.close();
        in.close();
    }

    static String proc() throws Exception {

        int K = ni();


        int S = ni();
        int L = ni();

        String keys = ns();
        String target = ns();
        double[][] A = buildTransitionMatrix(keys, target);
//        for (int i = 0; i < A.length; i++) {
//            for (int j = 0; j < A[i].length; j++) {
//                System.out.printf("%4.3f ", A[i][j]);
//            }
//            System.out.println();
//        }
        double max = maxRepetition(target, keys, L);
//        System.out.println("Max: " + max);

        double[] probs = new double[S + 1];
        probs[0] = 1;

        double sub = 0;
        for (int i = 0; i < L; i++) {
//            System.out.println("After " + i + " letters");
            double[] tmp = new double[S + 1];
//            System.out.println(tmp.length);
            for (int r = 0; r < tmp.length; r++) {
                for (int c = 0; c < tmp.length; c++) {
                    tmp[r] += probs[c] * A[r][c];
                }
            }
//            for (int j = 0; j < tmp.length; j++) {
//                System.out.printf("%4.3f ", tmp[j]);
//            }
//            System.out.println();
            probs = tmp;
            sub += probs[S];
        }

        return (max - sub) + "";
    }

    static double[][] buildTransitionMatrix(String keys, String target) {
        int S = target.length();
        int K = keys.length();
        double atomicProb = 1.0 / K;

        double[][] res = new double[target.length() + 1][target.length() + 1];

        for (int i = 0; i <= S; i++) {
            for (char c : keys.toCharArray()) {
                String tmp = target.substring(0, i) + c;
                for (int j = 0; j <= tmp.length(); j++) {
//                    String tmp1 = target.substring(0, j);
//                    System.out.println(i + " " + j);
//                    String tmp2 = target.substring(i - (j - 1), i) + c;

                    if (target.startsWith(tmp.substring(j))) {
                        res[i + 1 - j][i] += atomicProb;
                        break;
                    }
                }
            }
        }

        return res;
    }

    static int maxRepetition(String target, String keys, int L) {
        boolean ok = true;
        for(char c: target.toCharArray()){
            if(!keys.contains(c +"")){
                ok = false;
                break;
            }
        }
        if(!ok) return 0;


        for (int i = 1; i <= target.length(); i++) {
            if (target.startsWith(target.substring(i))) {
                return 1 + (L - target.length()) / i;
            }
        }
        return -1; // should not come here
    }


    static long modPow(long n, long pow, long mod) {
        return BigInteger.valueOf(n).modPow(BigInteger.valueOf(pow), BigInteger.valueOf(mod)).longValue();
    }

    static long modInv(long n, long mod, boolean isPrimeModuli) {
        if (isPrimeModuli) {
            return modPow(n, mod - 2, mod);
        }
        return BigInteger.valueOf(n).modInverse(BigInteger.valueOf(mod)).longValue();
    }

    // calc factorials
    static long[] fact;

    static void calcFactorials(int n) {
        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    static void calcFactorialsModM(int n, long M) {
        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= M;
        }
    }

    static long ncr(int n, int r) {
        return fact[n] / (fact[n - r] * fact[r]);
    }

    static long ncrModM(int n, int r, long MOD, boolean isPrimeModuli) {
        return fact[n] * modInv(fact[n - r], MOD, isPrimeModuli) * modInv(fact[r], MOD, isPrimeModuli);
    }

    static long toL(String s) {
        return Long.parseLong(s);
    }

    static long toL(BigInteger n) {
        return n.longValue();
    }

    static int toI(String s) {
        return Integer.parseInt(s);
    }

    static double toD(String s) {
        return Double.parseDouble(s);
    }


    static void printf(String format, Object... args) {
        System.out.printf(format, args);
    }

    static int ni() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static long max(long a, long b) {
        return a > b ? a : b;
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}