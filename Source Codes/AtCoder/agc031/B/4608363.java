//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {
        private static int mod = 1_000_000_007;
        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            List<Integer> seq = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int y = sc.nextInt();
                if (seq.size() == 0 || seq.get(seq.size() - 1) != y) {
                    seq.add(y);
                }
            }
            n = seq.size();
            long[] val = new long[200001];
            long[] dp = new long[n + 1];
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                int v = seq.get(i);
                dp[i + 1] = (dp[i] + val[v]) % mod;
                val[v] = (val[v] + dp[i]) % mod;
            }
            pw.println(dp[n]);
        }
    }

    // template, actual code is in class Task.
    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("Test.in"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));
        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
//        System.err.println("Memory increased: " + (usedMemoryAfter - usedMemoryBefore) / 1000000);
//        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    // Faster IO with BufferedReader wrapped with Scanner
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}