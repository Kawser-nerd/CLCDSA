import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static void printArr(long[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(int[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static int Q1 = 0;
    public static int QI = 1;
    public static int QJ = 2;
    public static int QK = 3;
    public static int[][] table = new int[][] {
            new int[] {Q1,   QI,   QJ,   QK},
            new int[] {QI, Q1+4,   QK, QJ+4},
            new int[] {QJ, QK+4, Q1+4,   QI},
            new int[] {QK,   QJ, QI+4, Q1+4}
    };
    public static int[] inverses = new int[] {Q1, QI+4, QJ+4, QK+4, Q1+4, QI, QJ, QK};

    public static int charToQ(char c) {
        if (c == 'i') return QI;
        if (c == 'j') return QJ;
        return QK;
    }
    public static int multiply(int x, int y) {
        boolean negative = (x >= 4) ^ (y >= 4);
        int product = table[x%4][y%4];
        return (product + (negative ? 4 : 0)) % 8;
    }
    public static int product(int[] prefix, int i, int j) {
        return multiply(inverses[prefix[i]], prefix[j]);
    }
    public static int[] prefixProducts(char[] arr) {
        int n = arr.length;
        int[] products = new int[n+1];
        products[0] = Q1;

        int cur = Q1;
        for (int i = 0; i < n; i++) {
            cur = multiply(cur, charToQ(arr[i]));
            products[i+1] = cur;
        }
        return products;
    }
    public static int pow(int x, long n) {
        int cur = Q1;
        for (; n > 0; n--) cur = multiply(cur, x);
        return cur;
    }

    public static int getI(int n, int[] pref) {
        int block = pref[n];
        for (int iBlocks = 0; iBlocks < 4; iBlocks++)
            for (int i = 1; i <= n; i++) {
                if (multiply(pow(block, iBlocks), product(pref, 0, i)) != QI) continue;
                return iBlocks * n + i;
            }
        return -1;
    }
    public static int getK(int n, int[] pref) {
        int block = pref[n];
        for (int kBlocks = 0; kBlocks < 4; kBlocks++)
            for (int i = n-1; i >= 0; i--) {
                if (multiply(product(pref, i, n), pow(block, kBlocks)) == QK)
                    return kBlocks * n + (n - i);
            }
        return -1;
    }

    public static boolean solve(char[] arr, long X) {
        int n = arr.length;
        int[] pref = prefixProducts(arr);
        int total = pow(pref[n], X % 4);
        if (total != Q1+4) return false;

        long minI = getI(n, pref);
        if (minI == -1) return false;
        long minK = getK(n, pref);
        if (minK == -1) return false;
        return (minI + minK) < (X * n);
    }

    public static void main(String[] args) throws IOException {
        //br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            nextInt();
            long X = nextLong();
            char[] arr = nextToken().toCharArray();
            String soln = solve(arr, X) ? "YES" : "NO";

            System.out.printf("Case #%d: %s%n", t, soln);
        }
    }
}
