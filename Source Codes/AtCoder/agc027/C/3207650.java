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
        System.out.println("Memory increased:" + (usedMemoryAfter - usedMemoryBefore) / 1000000);
        System.out.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    public static class Task {
        int N, M;
        int[] value;
        List<Integer>[] edges;
        int[] state;
        int[][] color;
        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            N = sc.nextInt();
            M = sc.nextInt();
            value = new int[N];
            String s = sc.next();
            for (int i = 0; i < N; i++) {
                value[i] = s.charAt(i) - 'A';
            }
            edges = new List[N];
            for (int i = 0; i < N; i++) {
                edges[i] = new ArrayList<>();
            }
            color = new int[N][2];
            for (int i = 0; i < M; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                edges[a].add(b);
                edges[b].add(a);
                color[a][value[b]]++;
                color[b][value[a]]++;
            }
            state = new int[N];
            for (int i = 0; i < N; i++) {
                if (state[i] == 0 && (color[i][0] == 0 || color[i][1] == 0)) {
                    dfs(i);
                }
            }
            for (int i = 0; i < N; i++) {
                if (state[i] == 0) {
                    pw.println("Yes");
                    return;
                }
            }
            pw.println("No");

        }

        public void dfs(int u) {
            state[u] = 1;
            for (int v: edges[u]) {
                color[v][value[u]]--;
                if (color[v][value[u]] == 0 && state[v] == 0) {
                    dfs(v);
                }
            }
            state[u] = 2;
        }
    }

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.