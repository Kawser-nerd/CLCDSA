import sun.security.x509.EDIPartyName;

import java.io.*;
import java.util.*;

public class Main {

    static long N;
    static long X;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);

        N = sc.nextLong();
        X = sc.nextLong();

        System.out.println( solve() );
    }

    static long solve() {
        long ans = N;
        long a = X;
        long b = N-X;

        if( a < b ) {
            long t = a;
            a = b;
            b = t;
        }
        while(true) {
            long q = a / b;
            long r = a % b;

            if( r == 0 ) {
                ans += (q * 2 * b) - b;
                break;

            } else {
                ans += b * 2 * q;
                a = b;
                b = r;
            }
        }
        return ans;
    }

    static class FastScanner {

        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
} ./Main.java:1: warning: EDIPartyName is internal proprietary API and may be removed in a future release
import sun.security.x509.EDIPartyName;
                        ^
1 warning