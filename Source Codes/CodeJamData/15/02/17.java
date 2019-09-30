package gcj._2015.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

    Scanner scanner;


    private void solve() throws FileNotFoundException {
        File input = new File("data/gcj/2015/qual/B-large.in");
        scanner = new Scanner(input);

        File test = new File("data/gcj/2015/qual/B.out");
        PrintStream out = new PrintStream(new FileOutputStream(test));
        System.setOut(out);

        int testCase = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i <= testCase; i++) {
            System.out.printf("Case #%d: %d\n", i, solveCase());
        }
    }

    private int solveCase() {
        int d = scanner.nextInt();
        int p[] = new int[d];

        int maxp = 0;
        for (int i = 0; i < d; i++) {
            p[i] = scanner.nextInt();
            maxp = Math.max(maxp, p[i]);
        }

        int ans = (int) 1e8;
        for (int max = 1; max <= maxp; max++) {
            int sum = max;
            for (int i = 0; i < d; i++) {
                sum += (p[i] + max - 1) / max - 1;
            }
            ans = Math.min(ans, sum);
        }
        return ans;
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().solve();
    }

}
