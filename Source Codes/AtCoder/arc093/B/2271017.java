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


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int A = sc.nextInt();
            int B = sc.nextInt();
            A--;//white
            B--;//black
            int[][] grid = new int[100][100];
            for (int i = 50; i < 100; i++) {
                Arrays.fill(grid[i], 1);
            }
            for (int i = 0; i < 50; i+=2) {
                for (int j = (i & 1); j < 100; j+= 2) {
                    if (A > 0) {
                        grid[i][j] = 1;
                        A--;
                    }
                }
            }

            for (int i = 99; i >= 0; i-=2) {
                for (int j = (i & 1); j < 100; j += 2) {
                    if (B > 0) {
                        grid[i][j] = 0;
                        B--;
                    }
                }
            }
            pw.println("100 100");
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    pw.print(grid[i][j] == 1 ? '.': '#');
                }
                pw.println();
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