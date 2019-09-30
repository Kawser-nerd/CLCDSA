//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        MyScanner sc = new MyScanner(System.in);
//        MyScanner sc = new MyScanner(new FileInputStream("Test.in"));
        PrintWriter pw = new PrintWriter(System.out);
        TIME_START = System.currentTimeMillis();
        Task.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
//        pw.println("Time used: " + (TIME_END - TIME_START) + ".");
        pw.close();
    }

    public static class Task {

        public static void solve(MyScanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int count2 = 0;
            int count1 = 0;
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                if (a % 4 == 0) count2++;
                else if (a % 2 == 0) count1++;
            }
            if (count2 >= n / 2) {
                pw.println("Yes");
            } else {
                int rest = n - (count2 * 2);
                if (count1 >= rest) {
                    pw.println("Yes");
                } else {
                    pw.println("No");
                }
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