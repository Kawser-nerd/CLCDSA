//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {

        public class Edge {
            int a;
            int b;
            boolean inCycle;

            public Edge(int a, int b) {
                this.a = a;
                this.b = b;
            }

            public int get(int yt) {
                if (a == yt) return b;
                return a;
            }
        }
        List<Edge>[] edges;

        public int labelOneCycle(int u, int v, int[] state) {
            state[u] = 1;
            for (Edge e: edges[u]) {
                if (e.inCycle) continue;
                if (state[e.get(u)] == 2) continue;
                if (e.get(u) == v) continue;
                if (state[e.get(u)] == 1) {
                    e.inCycle = true;
                    return e.get(u);
                } else {
                    int end = labelOneCycle(e.get(u), u, state);
                    if (end >= 0) {
                        e.inCycle = true;
                        if (u == end) return -2;
                        return end;
                    }
                    if (end == -2) return -2;
                }
            }
            state[u] = 2;
            return -1;
        }

        public boolean existEdge() {
            for (List<Edge> edge : edges) {
                for (Edge e : edge) {
                    if (!e.inCycle) return true;
                }
            }
            return false;
        }

        public boolean isVertexIn(int u) {
            for (Edge e: edges[u]) {
                if (!e.inCycle) return true;
            }
            return false;
        }

        public boolean isTwoCycle() {
            int[] state = new int[edges.length];
            labelOneCycle(0, -1, state);
            if (!existEdge()) {
                throw new RuntimeException();
            }
            Arrays.fill(state, 0);
            for (int i = 0; i < edges.length; i++) {
                if (isVertexIn(i)) {
                    labelOneCycle(i, -1, state);
                    return !existEdge();
                }
            }
            throw new RuntimeException();
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int m = sc.nextInt();
            edges = new List[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<>();
            }
            int[] deg = new int[n];
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                deg[a]++;
                deg[b]++;
                Edge e = new Edge(a, b);
                edges[a].add(e);
                edges[b].add(e);
            }
            int countdeg4 = 0;
            int countdeghi = 0;
            for (int i = 0; i < n; i++) {
                if (deg[i] % 2 != 0) {
                    pw.println("No");
                    return;
                }
                if (deg[i] == 4) {
                    countdeg4++;
                } else if (deg[i] > 4) {
                    countdeghi++;
                }
            }
            if (countdeghi > 0 || countdeg4 >= 3) {
                pw.println("Yes");
            } else if (countdeg4 == 2) {
                pw.println(isTwoCycle() ? "No": "Yes");
            } else {
                pw.println("No");
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.