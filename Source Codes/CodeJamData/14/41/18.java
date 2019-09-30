package com.google.codejam2014.round2;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DataPacking {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    DataPacking() throws IOException {
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
        int x = nextInt();
        int[] s = new int[n];
        for(int i = 0; i < n; i++) {
            s[i] = nextInt();
        }
        Arrays.sort(s);
        int limit = x / 2;
        int i1 = 0;
        int i2 = n - 1;
        int ans = 0;
        while(s[i2] > limit && i2 > i1) {
            ans++;
            if(s[i2] + s[i1] <= x) {
                i1++;
            }
            i2--;
        }
        int left = i2 - i1 + 1;
        ans += left / 2 + left % 2;
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
        new DataPacking().solve();
    }
}
