//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.util.*;

public class Main {
    public static class Task{

        public int findLessIndex(long[] arr, long val) {
            int lo = 0, hi = arr.length;
            while (lo < hi - 1) {
                int mid = (lo + hi) >> 1;
                if (arr[mid] <= val) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            return lo;
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int A = sc.nextInt();
            int B = sc.nextInt();
            int Q = sc.nextInt();
            long[] s = new long[A + 2];
            long[] t = new long[B + 2];
            for (int i = 1; i <= A; i++) {
                s[i] = sc.nextLong();
            }
            for (int i = 1; i <= B; i++) {
                t[i] = sc.nextLong();
            }
            s[0] = t[0] = Long.MIN_VALUE / 10;
            s[A + 1] = t[B + 1] = Long.MAX_VALUE / 10;
            for (int i = 0; i < Q; i++) {
                long x = sc.nextLong();
                int si = findLessIndex(s, x);
                int ti  = findLessIndex(t, x);
                long sLow = s[si];
                long sHigh = s[si + 1];
                long tLow = t[ti];
                long tHigh = t[ti + 1];
                long v1 = Math.max(sHigh, tHigh) - x;
                long v2 = Math.max(x - sLow, x - tLow);
                long v3 = - sLow + tHigh + Math.min(x - sLow, tHigh - x);
                long v4 = - tLow + sHigh + Math.min(x - tLow, sHigh - x);
                long v = Math.min(Math.min(v1, v2), Math.min(v3, v4));
                pw.println(v);
            }
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