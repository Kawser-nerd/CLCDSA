import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Date: May 8, 2010
 * Time: 3:26:49 AM
 *
 * @author Timur Abishev (ttim@yandex-team.ru)
 */
public class A extends SolutionT {
    public static void main(String[] args) {
        (new A()).run();    
    }

    @Override
    void runOneTest(Scanner input, PrintWriter output) {
        int n = input.nextInt();
        int k = input.nextInt();

        k = k%(1 << n);

        if ((k+1) == (1 << n)) {
            output.println("ON");
        } else {
            output.println("OFF");
        }
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