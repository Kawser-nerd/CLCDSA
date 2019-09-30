package com.google.codejam2014.round2;

import java.io.*;
import java.util.*;

public class UpAndDown {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    UpAndDown() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
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
        int n = nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Map<Integer, List<Integer>> positions = new TreeMap<>();
        for(int i = 0; i < n; i++) {
            int x = a[i];
            List<Integer> list = positions.get(x);
            if(list == null) {
                list = new ArrayList<>();
                positions.put(x, list);
            }
            list.add(i);
        }
        class SegmentTree {
            int q = 1024;
            int[] a = new int[2 * q];

            void inc(int i) {
                for(i += q; i > 0; i >>= 1) {
                    a[i]++;
                }
            }

            int sum(int l, int r) {
                int sum = 0;
                for(l += q, r += q; l < r; l >>= 1, r >>= 1) {
                    if(l % 2 == 1) {
                        sum += a[l++];
                    }
                    if(r % 2 == 1) {
                        sum += a[--r];
                    }
                }
                return sum;
            }
        }
        SegmentTree segmentTree = new SegmentTree();
        int ans = 0;
        for (List<Integer> list : positions.values()) {
            int i = 0, j = list.size() - 1;
            while(i <= j) {
                int pi = list.get(i);
                int pj = list.get(j);
                int fi = Math.min(pi - segmentTree.sum(0, pi), n - 1 - pi - segmentTree.sum(pi + 1, n));
                int fj = Math.min(pj - segmentTree.sum(0, pj), n - 1 - pj - segmentTree.sum(pj + 1, n));
                if(fi <= fj) {
                    ans += fi;
                    segmentTree.inc(pi);
                    i++;
                } else {
                    ans += fj;
                    segmentTree.inc(pj);
                    j--;
                }
            }
        }
        writer.println(ans);
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
        new UpAndDown().solve();
    }
}
