
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        long p = in.nextLong();
        p--;
        long b = 1;
        if (p == ((1L << n) - 1)) {
            b = ((1L << n) - 1) + 2;
        } else {
            long pp = (1L << n) - 1 - (p + 1);
            for (int i = n - 1; i >= 0; i--) {
                if (((pp >> i) & 1) == 0) {
                    b *= 2;
                } else {
                    for (int j = i - 1; j >= 0; j--) {
                        if (((pp >> j) & 1) == 0) {
                            b *= 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        long pp = (1L << n) - 1 - p;
        long c = 1;
//        System.out.println(pp);
        for (int i = n - 1; i >= 0; i--) {
            if (((pp >> i) & 1) == 1) {
                c *= 2;
            } else {
                for (int j = i - 1; j >= 0; j--) {
                    if (((pp >> j) & 1) == 1) {
                        c *= 2;
                        break;
                    }
                }
                break;
            }
        }
        return (b - 2) + " " + ((1L << n) - c);
    }
}