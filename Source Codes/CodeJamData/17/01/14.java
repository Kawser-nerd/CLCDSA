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
        if(args.length == 1) {
            String filename = "io/" + args[0] + ".in";
            if (!filename.isEmpty()) try {
                System.setIn(new FileInputStream(filename));
            } catch (FileNotFoundException e) {
                System.out.println(e.getMessage());
                System.exit(1);
            }
        }


        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = Integer.valueOf(in.nextLine());  // Scanner has functions to read ints, longs, strings, chars, etc.
//        List<int[]> cas = new ArrayList<>();
        for (int number = 1; number <= t; number++) {
            String s = in.nextLine();
            char[] cs = s.split(" ")[0].toCharArray();
            int k = Integer.valueOf(s.split(" ")[1]);
            int c = 0;
            int x;
            while (true) {
                x = String.valueOf(cs).indexOf('-');
                if(x==-1 || x>cs.length - k) break;
                for (int i = x; i < x+k; i++) {
                    cs[i] = cs[i] == '-'? '+' : '-';
                }
                c++;
            }
            String res = x==-1? String.valueOf(c) : "IMPOSSIBLE";
            System.out.println("Case #" + number + ": " + res);
        }
//        long startTime = System.nanoTime();

//        List<String> res = cas.stream().map(App::q1).collect(toList());
//        for (int i = 1; i <= t; ++i)
//            System.out.println("Case #" + i + ": " + res.get(i - 1));
//        //System.out.println("Time = " + (double) (System.nanoTime() - startTime) / 1e9 + " s");
    }

    private static String q1(int[] ints) {
        int sum = 0;
        int max = 0;
        int sum2 = 0;
        for (int i = 0; i < ints.length-1; i++) {
            sum += Math.max(0, ints[i] - ints[i+1]);
            max = Math.max(max, ints[i] - ints[i+1]);
        }
        for (int i = 0; i < ints.length-1; i++) {
            sum2 += Math.min(max, ints[i]);
        }

        return String.valueOf(sum+" " + sum2);
    }
}