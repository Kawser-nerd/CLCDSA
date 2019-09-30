package com.archieve;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import static java.util.Arrays.deepToString;

public class codejam2015_1C_B {
    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    int K, L, S;
    long Total, Bananas;
    String keys, target;

    void read() {
        K = sc.nextInt();
        L = sc.nextInt();
        S = sc.nextInt();
        Total = Bananas = 0;

        keys = sc.next();
        target = sc.next();
    }

    int count_occ(String soFar) {
        if (soFar.length() == S) {
            return countMatches(soFar, target);
        }
        int max = 0, thisCount;
        for (char ch : keys.toCharArray()) {
            thisCount = count_occ(soFar + ch);
            if (thisCount > max) {
                max = thisCount;
            }
        }

        return max;
    }

    int countMatches(String str, String pattern) {
        if(str.length() < pattern.length()) return 0;

        if(str.startsWith(pattern)) {
            return 1+countMatches(str.substring(1), pattern);
        } else {
            return countMatches(str.substring(1), pattern);
        }
    }
    void avgBanana(String soFar) {
        if (soFar.length() == S) {
            Total++;
            Bananas += countMatches(soFar, target);
            return;
        }
        for (char ch : keys.toCharArray()) {
            avgBanana(soFar + ch);
        }
    }

    void solve() {
        double solution = 0;
        int maxBananas = count_occ("");
        avgBanana("");

        solution = maxBananas - Bananas*1.0d/Total;

        out.println(solution);
        System.out.println(solution);
    }

    void output(double a) {
        out.println(a);
        System.out.println(a);
    }

    void run() {
        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        sc = new Scanner(in);
        int caseN = sc.nextInt();
        for (int caseID = 1; caseID <= caseN; caseID++) {
            read();
            out.printf("Case #%d: ", caseID);
            System.out.printf("Case #%d: ", caseID);
            solve();
            System.out.flush();
        }
        out.close();
    }

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    public static void main(String[] args) {
        try {
            System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (codejam2015_1C_B.class.getName() + ".in"))));
        } catch (Exception e) {
        }
        new codejam2015_1C_B().run();
    }
}
