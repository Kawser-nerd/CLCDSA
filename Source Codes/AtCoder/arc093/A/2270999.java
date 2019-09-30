//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("Test.in"));
        PrintWriter pw = new PrintWriter(System.out);
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.in"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
//        System.out.println("Memory increased:" + (usedMemoryAfter-usedMemoryBefore) / 1000000 );
//        System.out.println("Time used: " + (TIME_END - TIME_START) + ".");

    }


    public static class Task {
        public int dist(int a, int b){
            return Math.abs(a - b);
        }
        //https://arc093.contest.atcoder.jp/tasks/arc093_a
        // 3978
        // Traveling Plan
        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int[] a = new int[n + 2];
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
            }
            int[] prefix = new int[n + 2];
            int[] suffix = new int[n + 2];
            for (int i = 1; i <= n; i++) {
                prefix[i] = prefix[i - 1] + dist(a[i-1], a[i]);
            }
            for (int i = n; i > 0; i--) {
                suffix[i] = suffix[i + 1] + dist(a[i+1], a[i]);
            }
            for (int i = 1; i <= n; i++) {
                pw.println(prefix[i-1] + dist(a[i-1], a[i+1]) + suffix[i+1]);
            }

        }




    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s){  br = new BufferedReader(new InputStreamReader(s));}

        public Scanner(FileReader s) throws FileNotFoundException {br = new BufferedReader(s);}

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