package com.google.codejam2014.round2;

import java.io.*;
import java.util.*;

public class DoNotBreakTheNile {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    DoNotBreakTheNile() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("fast_output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        final int w = nextInt();
        final int h = nextInt();
        final int b = nextInt();
        class Building {
            int[] segX, segY;

            int dist(int[] a, int b[]) {
                if(a[1] < b[0]) {
                    return b[0] - a[1] - 1;
                }
                if(b[1] < a[0]) {
                    return a[0] - b[1] - 1;
                }
                return 0;
            }

            int dist(Building b) {
                return Math.max(dist(segX, b.segX), dist(segY, b.segY));
            }

            Building(int x0, int y0, int x1, int y1) {
                this.segX = new int[]{x0, x1};
                this.segY = new int[]{y0, y1};
            }
        }
        Building[] buildings = new Building[b + 1];
        for(int k = 1; k <= b; k++) {
            int x0 = nextInt();
            int y0 = nextInt();
            int x1 = nextInt();
            int y1 = nextInt();
            buildings[k] = new Building(x0, y0, x1, y1);
        }
        int n = b + 2;
        int[][] len = new int[n][n];
        for(int i = 1; i <= b; i++) {
            for(int j = 1; j <= b; j++) {
                len[i][j] = buildings[i].dist(buildings[j]);
            }
            len[0][i] = len[i][0] = buildings[i].segX[0];
            len[n - 1][i] = len[i][n - 1] = w - 1 - buildings[i].segX[1];
        }
        len[0][n - 1] = len[n - 1][0] = w;
        int[] d = new int[n];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        boolean[] used = new boolean[n];
        for(int k = 0; k < n; k++) {
            int u = n - 1;
            for(int i = 0; i < n - 1; i++) {
                if(!used[i] && d[i] < d[u]) {
                    u = i;
                }
            }
            if(u == n - 1) break;
            used[u] = true;
            for(int v = 0; v < n; v++) {
                d[v] = Math.min(d[v], d[u] + len[u][v]);
            }
        }
        writer.println(d[n - 1]);
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
            writer.flush();
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new DoNotBreakTheNile().solve();
    }
}
