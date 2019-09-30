import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Eric
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CUnification solver = new CUnification();
        solver.solve(1, in, out);
        out.close();
    }

    static class CUnification {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            char[] arr = s.toCharArray();
            int a = 0;
            int b = 0;
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == '0')
                    a++;
                else
                    b++;
            }
            out.println(Math.min(a, b) * 2);
        }

    }
}