package com.archieve;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import static java.util.Arrays.deepToString;

public class codejam2015_1C_A {
    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    int N;
    Integer R, C, W;

    // 0111001101111100111
    // 0100000001110000100
    // len - 1 - (3-1)
    void read() {
        R = sc.nextInt();
        C = sc.nextInt();
        W = sc.nextInt();
    }

    void solve() {
        long solution=0;
        solution += (R-1)*(C/W);

        solution += (C-1)/W;
        solution += W;

        out.println(solution);
        System.out.println(solution);
    }

    void output(long a) {
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
            System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (codejam2015_1C_A.class.getName() + ".in"))));
        } catch (Exception e) {
        }
        new codejam2015_1C_A().run();
    }
}
