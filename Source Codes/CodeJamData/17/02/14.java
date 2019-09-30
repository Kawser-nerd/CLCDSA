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
            long res = helper(n, 0);
            System.out.println("Case #" + number + ": " + res);
        }
    }

    public static long helper(long n, int start) {
        if (n < 10) {
            return n < start ? -1 : n;
        }
        String s = String.valueOf(n);
        long l1 = 0;
        if (start > 0) {
            char[] cs = new char[s.length()];
            Arrays.fill(cs, (char) ('0' + start));
            l1 = Long.valueOf(String.valueOf(cs));
        }
        if (l1 > n) return -1;

        long l2 = Long.valueOf(s.substring(1));
        if(s.charAt(1) == '0') return n-l2-1;
        return n - l2 + helper(l2, s.charAt(0) - '0');
    }
}