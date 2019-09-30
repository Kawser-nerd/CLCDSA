import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

import static java.math.BigInteger.ZERO;

/**
 * Date: May 8, 2010
 * Time: 3:47:50 AM
 *
 * @author Timur Abishev (ttim@yandex-team.ru)
 */
public class B extends Solution {
    public static void main(String[] args) {
        (new B()).run();    
    }

    public static BigInteger lcm(BigInteger value1, BigInteger value2) {
        return value1.multiply(value2).divide(value1.gcd(value2));
    }
    
    @Override
    void runOneTest(Scanner input, PrintWriter output) {
        int n = input.nextInt();
        BigInteger[] t = new BigInteger[n];

        for (int i = 0; i < n; i++) {
            t[i] = input.nextBigInteger();
        }

        // find max
        BigInteger max = ZERO;
        for (int i = 0; i < n; i++) {
            max = max.max(t[i]);
        }

        BigInteger gcd = ZERO;
        for (int i = 0; i < n; i++)
            if (!t[i].equals(max)) {
                gcd = gcd.gcd(max.add(t[i].negate()));
            }

        // gcd - is answer for y
        BigInteger currentOffset = gcd.add(t[0].mod(gcd).negate());

        for (int i = 0; i < n; i++) {
            if (!currentOffset.equals(gcd.add(t[i].mod(gcd).negate()))) {
                System.out.println("Botva");
            }
        }        

        if (currentOffset.equals(gcd)) {
            currentOffset = ZERO;
        }

        output.println(currentOffset);
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
