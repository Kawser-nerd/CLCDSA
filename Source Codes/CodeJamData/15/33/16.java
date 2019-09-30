package com.archieve;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.util.Arrays.deepToString;

public class codejam2015_1C_A {
    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    int N;
    Integer C, D, V;
    List<Long> denoms;

    // 0111001101111100111
    // 0100000001110000100
    // len - 1 - (3-1)
    void read() {
        C = sc.nextInt();
        D = sc.nextInt();
        V = sc.nextInt();
        denoms = new ArrayList<Long>();

        for(int i=0; i<D; i++) {
            denoms.add(Long.valueOf(sc.nextInt()));
        }
    }

    void solve() {
        long solution=0;
        long cur = 0;
        int pos=0;

        while(cur < V) {
            for(int i=pos; ; i++) {
                if(denoms.size() <= i || denoms.get(i) > cur+1) {
                    denoms.add(i, cur+1);
                    solution++;
                    break;
                }
                cur += C*denoms.get(i);
                pos++;
                if(cur >= V) break;
            }
        }

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
