//package com.company;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        MyScanner sc = new MyScanner(System.in);
//        MyScanner sc = new MyScanner(new FileInputStream("Test.in"));
        PrintWriter pw = new PrintWriter(System.out);
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));
        TIME_START = System.currentTimeMillis();
        Task.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
//        pw.println("Time used: " + (TIME_END - TIME_START) + ".");
        pw.close();
    }

    public static class Task {
        static final int MOD = 1000000007;
        static long[][] dp;
        static long[] fact;
        static long[] invfact;
        static int N, A, B, C, D;
        public static void solve(MyScanner sc, PrintWriter pw) throws IOException {
            N = sc.nextInt();
            A = sc.nextInt();
            B = sc.nextInt();
            C = sc.nextInt();
            D = sc.nextInt();
            precompute();
            dp = new long[2][N + 1];
            dp[(A - 1) % 2][0] = 1;
            for (int i = A; i <= B; i++) {
                int cutI = i % 2;
                int prevI = (i - 1) % 2;
                for (int j = C; j <= D; j++) {
                    int count = i * j;
                    if (count > N) break;
                    long subChoose = fact[count] * pow(invfact[i], j) % MOD * invfact[j] % MOD;
                    for (int k = count; k <= N; k++) {
                        long choose = fact[k] * invfact[count] % MOD * invfact[k - count] % MOD;
                        long add = dp[prevI][k - count] * subChoose % MOD * choose % MOD;
                        dp[cutI][k] += add;
                        if (dp[cutI][k] >= MOD) dp[cutI][k] -= MOD;
                    }
                }
                for (int j = 0; j <= N; j++) {
                    dp[cutI][j] += dp[prevI][j];
                    if (dp[cutI][j] >= MOD) dp[cutI][j] -= MOD;
                }
                Arrays.fill(dp[prevI], 0);

            }
            pw.println(dp[B % 2][N]);
        }

        public static long pow(long a, int b) {
            if (b == 0) return 1;
            if ((b & 1) == 0) return pow(a * a % MOD, b >> 1);
            return  (a * pow(a * a % MOD, b >> 1) % MOD);
        }

        public static void precompute(){
            fact = new long[1001];
            invfact = new long[1001];
            fact[0] = 1; invfact[0] = (int)pow(1, MOD - 2);
            for (int i = 1; i < 1001; i++) {
                fact[i] = i * fact[i - 1];
                fact[i] %= MOD;
                invfact[i] = (int) pow(fact[i], MOD - 2);
            }
        }



    }

    static class MyScanner {
        StringTokenizer st;
        BufferedReader br;

        public MyScanner(InputStream s){  br = new BufferedReader(new InputStreamReader(s));}

        public MyScanner(FileReader s) throws FileNotFoundException {br = new BufferedReader(s);}

        public String next() throws IOException
        {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {return Integer.parseInt(next());}

        public long nextLong() throws IOException {return Long.parseLong(next());}

        public String nextLine() throws IOException {return br.readLine();}

        public double nextDouble() throws IOException { return Double.parseDouble(next()); }

        public boolean ready() throws IOException {return br.ready();}
    }
}