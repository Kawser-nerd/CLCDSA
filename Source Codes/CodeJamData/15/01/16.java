package gcj._2015.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

    Scanner scanner;


    private void solve() throws FileNotFoundException {
        File input = new File("data/gcj/2015/qual/A-large.in");
        scanner = new Scanner(input);

        File test = new File("data/gcj/2015/qual/A.out");
        PrintStream out = new PrintStream(new FileOutputStream(test));
        System.setOut(out);

        int testCase = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i <= testCase; i++) {
            System.out.printf("Case #%d: %d\n", i, solveCase());
        }
    }

    private int solveCase() {
        int smax = scanner.nextInt();
        String s = scanner.next();

        int need = 0;
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int audNum = s.charAt(i) - '0';
            if (audNum == 0) {
                continue;
            }
            if (total < i) {
                need += i - total;
                total += i - total;
            }
            total += audNum;
        }
        return need;
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().solve();
    }

}
