import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Counter {

    public static void main(String... args) throws IOException {
//        System.out.println(count("10"));
//        System.out.println(count("20"));

        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("Counter.out"));
        int loops = in.nextInt();
        in.nextLine();
        for (int loop = 0; loop < loops; loop++) {
            long ans = count(in.nextLine());


            out.printf("Case #%d: %d%n", loop + 1, ans);
        }

        in.close();
        out.close();
    }

    private static long count(String s) {
        if (s.length() == 1) {
            return Long.valueOf(s);
        } else {
            String low = "";
            for (int i = 0; i < s.length() - 1; i++) {
                low += "9";
            }
            long ret = count(low); //to get to 999999...
            int v1 = s.length() / 2;
            int v2 = (s.length() + 1) / 2;

            long a = ret + Long.valueOf(reverse(s.substring(0, v1))) + Long.valueOf(s.substring(v1)) + 1;
            if (Long.valueOf(s.substring(v1)) == 0)
                a = Long.MAX_VALUE;
            long b = ret + Long.valueOf(reverse(s.substring(0, v2))) + Long.valueOf(s.substring(v2)) + 1;
            if (Long.valueOf(s.substring(v2)) == 0)
                b = Long.MAX_VALUE;
            long c = ret + Long.valueOf(s) - Long.valueOf(low);
            long d = Long.MAX_VALUE;
            if (s.charAt(s.length() - 1) == '0')
                d = count("" + (Long.valueOf(s) - 1)) + 1;

//            if (a != b)
//                System.out.println("ok");


            return Math.min(a, Math.min(b, Math.min(c, d)));
        }
    }

    static String reverse(String s) {
        StringBuilder a = new StringBuilder(s);
        a.reverse();
        return a.toString();
    }
}
