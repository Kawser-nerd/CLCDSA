import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Date: May 8, 2010
 * Time: 3:47:50 AM
 *
 * @author Timur Abishev (ttim@yandex-team.ru)
 */
public class C extends Solution {
    public static void main(String[] args) {
        (new C()).run();
    }

    @Override
    void runOneTest(Scanner input, PrintWriter output) {
        int r = input.nextInt();
        int k = input.nextInt();
        int n = input.nextInt();

        int[] g = new int[n];

        for (int i = 0; i < n; i++) {
            g[i] = input.nextInt();
        }

        // pre calc
        int[] nextFirst = new int[n];
        long[] count = new long[n];

        for (int i = 0; i < n; i++) {
            // from i
            int j = (i+1)%n;
            long currentSum = g[i];

            while (j != i) {
                if (currentSum+g[j] > k) {
                    break;
                }
                currentSum += g[j];
                j = (j+1)%n;
            }
            nextFirst[i] = j;
            count[i] = currentSum;
        }

        // calc
        long ans = 0;
        int current = 0;
        for (int i = 0; i < r; i++) {
            ans += count[current];
            current = nextFirst[current];
        }

        output.println(ans);
    }
}

abstract class Solution implements Runnable {
    abstract void runOneTest(Scanner input, PrintWriter output);

    public void run() {
        Scanner input = null;
        PrintWriter output = null;
        try {
            input = new Scanner(new File("input.txt"));
            output = new PrintWriter(new File("output.txt"));
        } catch (FileNotFoundException e) {
        }

        int testCount = input.nextInt();

        for (int test = 1; test <= testCount; test++) {
            output.print("Case #" + test + ": ");
            runOneTest(input, output);
        }

        input.close();
        output.close();
    }
}