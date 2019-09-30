//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {
        private static int mod = 1_000_000_007;

        public int[] getFullChange(List<Integer> on) { // n odd
            int n = on.size();
            if (n == 1) {
                return new int[]{on.get(0)};
            }
            List<Integer> rf = new ArrayList<>();
            for (int i = 0; i < on.size() - 2; i++) {
                rf.add(on.get(i));
            }
            int[] sub = getFullChange(rf);
            int s2 = on.get(on.size() - 2);
            int s3 = on.get(on.size() - 1);
            int[] changes = new int[(1 << n) - 1];
            int idx = 0;
            changes[idx++] = s2;
            changes[idx++] = s3;
            changes[idx++] = s2;
            changes[idx++] = sub[0];
            changes[idx++] = s3;
            changes[idx++] = s2;
            changes[idx++] = s3;
            for (int i = 1; i < sub.length; i++) {
                changes[idx++] = sub[i];
                changes[idx++] = s3;
                changes[idx++] = s2;
                changes[idx++] = s3;
            }

            if (idx != changes.length) {
                throw new RuntimeException();
            }
            return changes;
        }

        public int[] getSufChanges(List<Integer> off) {
            if (off.size() == 0) return new int[]{};
            int n = off.size();
            if (n == 1) {
                return new int[]{off.get(0)};
            }
            List<Integer> sma = new ArrayList<>(off);
            sma.remove(sma.size() - 1);
            int[] sufChange = getSufChanges(sma);
            int[] ref = new int[sufChange.length * 2 + 1];
            for (int i = 0; i < sufChange.length; i++) {
                ref[i] = sufChange[i];
                ref[i + sufChange.length + 1] = sufChange[i];
            }
            ref[sufChange.length] = off.get(off.size() - 1);
            return ref;
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = a ^ b;
            if (Integer.bitCount(c) % 2 == 0) {
                pw.println("NO");
                return;
            }
            List<Integer> off = new ArrayList<>();
            List<Integer> on = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (((1 << i) & c) != 0) {
                    on.add(i);
                } else {
                    off.add(i);
                }
            }
            int[] changes = new int[(1 << n) - 1];
            int[] suf = getSufChanges(off);
            int[] full = getFullChange(on);
            int idx = 0;
            for (int i = 0; i < full.length; i++) {
                for (int j = 0; j < suf.length; j++) {
                    changes[idx++] = suf[j];
                }
                changes[idx++] = full[i];
            }
            for (int i = 0; i < suf.length; i++) {
                changes[idx++] = suf[i];
            }
            pw.println("YES");
            Set<Integer> has = new HashSet<>();
            has.add(a);
            pw.print(a);
            for (int i = 0; i < changes.length; i++) {
                a ^= 1 << changes[i];
                if (has.contains(a)) {
                    throw new RuntimeException();
                } else {
                    has.add(a);
                }
                pw.print(" " + a);
            }
            if (has.size() != (1 << n) ) {
                throw new RuntimeException();
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
}