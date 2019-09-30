/**
 * Created by wei on 4/11/15.
 */
import java.io.*;
import java.util.*;


public class SolutionD {
    static Scanner scan = new Scanner (System.in);
    static PrintStream out = System.out;

    private static boolean doable(TreeSet<Long> demo, long C, long value) {
        Iterator iter = demo.descendingIterator();
        while (iter.hasNext()){
            long d = (Long)(iter.next());
            if (value % d == 0 && value/d <= C)
                return true;

            value -= Math.min (value/d, C) * d;
        }

        return false;
    }

    private static void solve() {
        long C = scan.nextLong(), D = scan.nextLong(), V = scan.nextLong();

        TreeSet<Long> demo = new TreeSet<Long>();
        for (int i = 0; i < D; ++i)
            demo.add(scan.nextLong());
        long value = 1;
        while (value <= V) {
            if (demo.contains(value)) {
                value = value * (C + 1);
            }
            else if (!doable(demo, C, value)) {
                demo.add(value);
                value = value * (C + 1);
            }
            else {
                long sum = 0;
                for (long t : demo) {
                    if (t <= value)
                        sum += C * t;
                }
                value = Math.max (value + 1, sum);
            }
        }

        out.println (demo.size () - D);
    }


    public static void main(String[] args) {
        int T = scan.nextInt();

        for (int i = 1; i <= T; ++i) {
            System.out.print("Case #" + i + ": ");
            solve();
        }

    }
}
