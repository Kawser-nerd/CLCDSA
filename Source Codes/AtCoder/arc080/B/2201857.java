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
    //https://arc080.contest.atcoder.jp/tasks/arc080_b
    public static class Task {

        public static void solve(MyScanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] grid = new int[n][m];
            int k = sc.nextInt();
            int x = -1, y = 0;
            int dir = 1; // 1 up, 2 down
            for (int i = 1; i <= k; i++) {
                int count = sc.nextInt();
                for (int j = 0; j < count; j++) {
                    switch (dir) {
                        case 1:
                            if (x + 1 < n) {
                                x++;
                            } else {
                                y++;
                                dir = 2;
                            }
                            grid[x][y] = i;
                            break;
                        case 2:
                            if (x - 1 >= 0) {
                                x--;
                            } else {
                                y++;
                                dir = 1;
                            }
                            grid[x][y] = i;
                            break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    pw.print(grid[i][j] + " ");
                }
                pw.println();
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