package gcj._2015.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class D {

    Scanner scanner;


    private void solve() throws FileNotFoundException {
        File input = new File("data/gcj/2015/qual/D-large.in");
        scanner = new Scanner(input);

        File test = new File("data/gcj/2015/qual/D.out");
        PrintStream out = new PrintStream(new FileOutputStream(test));
        System.setOut(out);

        int testCase = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i <= testCase; i++) {
            System.out.printf("Case #%d: %s\n", i, solveCase() ? "GABRIEL" : "RICHARD");
        }
    }

    private boolean solveCase() {
        int x = scanner.nextInt();
        int r = scanner.nextInt();
        int c = scanner.nextInt();

        if (r > c) {
            int tmp = r;
            r = c;
            c = tmp;
        }

        if (r * c % x != 0) {
            return false;
        }
        if (x == 1) {
            return true;
        }
        if (x == 2) {
            return true;
        }
        if (x == 3) {
            return r >= 2;
        }
        if (x == 4) {
            return r == 3 && c >= 4 || r > 3;
        }
        if (x == 5) {
            return r == 3 && c >= 10 || r > 3;
        }
        if (x == 6) {
            return r > 3;
        }
        return false;
    }

    public static void main(String[] args) throws FileNotFoundException {
        new D().solve();
    }

}
