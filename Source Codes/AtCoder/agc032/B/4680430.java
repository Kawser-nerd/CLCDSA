//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int[][] g = new int[n][n];
            if (n % 2 == 0) {
                for (int i = 0; i < n / 2 - 1; i++) {
                    for (int j = i + 1; j < n - i - 1; j++) {
                        g[i][j] = 1;
                        g[j][n - 1 - i] = 1;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        g[i][j] = 1;
                    }
                }
                for (int i = 0; i < n / 2; i++) {
                    g[i][n - 1 - i - 1] = 0;
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (g[i][j] == 1) {
                        cnt++;
                    }
                }
            }
            pw.println(cnt);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (g[i][j] == 1) {
                        pw.println((i + 1) + " " + (j + 1));
                    }
                }
            }
//            int n = 6;
//            int on = n * (n - 1) / 2;
//            for (int i = 1; i < 1 << on; i++) {
//                int[] size = new int[n];
//                List<int[]> edges = new ArrayList<>();
//                for (int j = 0; j < on; j++) {
//                    if (((1 << j) & i) != 0) {
//                        int x = 0, y = n - 1;
//                        int r = j;
//                        while (r >= y) {
//                            x += 1;
//                            r -= y;
//                            y -= 1;
//                        }
//                        r += x + 1;
//                        size[x] += r + 1;
//                        size[r] += x + 1;
//                        edges.add(new int[]{x + 1, r + 1});
//                    }
//                }
//                boolean fa = true;
//                for (int j = 0; j < n - 1; j++) {
//                    if (size[j] != size[j + 1]) fa = false;
//                }
//                if (fa) {
//                    pw.println(size[0]);
//                    for (int[] edge: edges) {
//                        pw.println(Arrays.toString(edge));
//                    }
//                }
//            }
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