import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class DSmall {

    private String solve(Scanner in) {
        String s = in.next();
        bt(s, 0, 0L);
        return Long.toBinaryString(res);
    }

    long res = -1;

    private void bt(String s, int i, long l) {
        if (i == s.length()) {
            long root = (long) Math.sqrt(l);
            for (long a = root - 1; a <= root + 1; a++) {
                if (a * a == l) {
                    res = l;
                }
            }
        } else {
            if (s.charAt(i) == '?') {
                bt(s, i + 1, l * 2);
                bt(s, i + 1, l * 2 + 1);
            } else {
                bt(s, i + 1, l * 2 + (s.charAt(i) - '0'));
            }
        }

        //To change body of created methods use File | Settings | File Templates.
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new DSmall().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

}