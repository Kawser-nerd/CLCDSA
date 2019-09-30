package zhang00000;

import com.sun.tools.javac.jvm.Code;
import org.apache.commons.math3.complex.Complex;

import java.io.*;
import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.*;


public class App {
    final int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
    final int dj[] = {0, 0, 1, -1, 1, -1, -1, 1};
    final int diK[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    final int djK[] = {-1, 1, 2, 2, 1, -1, -2, -2};

    public static void main(String[] args) {
        if (args.length == 1) {
            String filename = "src/main/java/zhang00000/" + args[0] + ".in";
            if (!filename.isEmpty()) try {
                System.setIn(new FileInputStream(filename));
            } catch (FileNotFoundException e) {
                System.out.println(e.getMessage());
                System.exit(1);
            }
        }

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = Integer.valueOf(in.nextLine());  // Scanner has functions to read ints, longs, strings, chars, etc.
        for (int number = 1; number <= t; number++) {
            long n = in.nextLong();
            long k = in.nextLong();
            int d = Long.toBinaryString(k).length() - 1;
            long prev = (n - k + Long.highestOneBit(k)) >> d;
            long max = prev / 2;
            long min = (prev - 1) / 2;
            System.out.println("Case #" + number + ": " + max + " " + min);
        }
    }

}