package gcj._2015.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class C {

    Scanner scanner;


    private void solve() throws FileNotFoundException {
        File input = new File("data/gcj/2015/qual/C-large.in");
        scanner = new Scanner(input);

        File test = new File("data/gcj/2015/qual/C.out");
        PrintStream out = new PrintStream(new FileOutputStream(test));
        System.setOut(out);

        int testCase = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i <= testCase; i++) {
            System.out.printf("Case #%d: %s\n", i, solveCase() ? "YES" : "NO");
        }
    }

    private boolean solveCase() {
        int l = scanner.nextInt();
        long x = scanner.nextLong();
        String s = scanner.next();

        V vOne = V.ONE;
        for (char c : s.toCharArray()) {
            vOne = vOne.mul(V.valueOf(c));
        }
        if (vOne.pow(x) != V.i.mul(V.j).mul(V.k)) {
//            System.out.println(vOne + " " + vOne.pow(x) + " " + V.i.mul(V.j).mul(V.k));
            return false;
        }

        V runningV = V.ONE;
        boolean findI = false;
        for (long i = 0; i < l * 10 && i < l * x; i++) {
            V v = V.valueOf(s.charAt((int) (i % l)));
            runningV = runningV.mul(v);
            if (runningV == V.i) {
                findI = true;
            } else if (findI && runningV == V.i.mul(V.j)) {
                return true;
            }
        }
        return false;
    }

    ////////////////////////////////////////////////////////

    enum V {
        i,
        j,
        k,
        ONE,
        _i,
        _j,
        _k,
        _ONE,;

        /////////////////////

        static V valueOf(char c) {
            if (c == 'i') {
                return i;
            } else if (c == 'j') {
                return j;
            } else if (c == 'k') {
                return k;
            }
            throw new RuntimeException();
        }

        boolean isNeg() {
            return this == _i || this == _j || this == _k || this == _ONE;
        }

        V neg() {
            if (this == _i) {
                return i;
            }
            if (this == _j) {
                return j;
            }
            if (this == _k) {
                return k;
            }
            if (this == _ONE) {
                return ONE;
            }
            if (this == i) {
                return _i;
            }
            if (this == j) {
                return _j;
            }
            if (this == k) {
                return _k;
            }
            if (this == ONE) {
                return _ONE;
            }
            throw new RuntimeException();
        }

        V mul(V v) {
            if (this.isNeg()) {
                return neg().mul(v).neg();
            } else if (v.isNeg()) {
                return mul(v.neg()).neg();
            }
            if (this == ONE) {
                return v == ONE ? ONE : v == i ? i : v == j ? j : k;
            }
            if (this == i) {
                return v == ONE ? i : v == i ? _ONE : v == j ? k : _j;
            }
            if (this == j) {
                return v == ONE ? j : v == i ? _k : v == j ? _ONE : i;
            }
            if (this == k) {
                return v == ONE ? k : v == i ? j : v == j ? _i : _ONE;
            }
            throw new RuntimeException();
        }

        V pow(long p) {
            p %= 4;
            V res = ONE;
            for (int l = 0; l < p; l++) {
                res = res.mul(this);
            }
            return res;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().solve();
    }

}
