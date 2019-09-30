import java.util.Scanner;
import java.util.Arrays;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("B.in"));
        PrintWriter out = new PrintWriter("B.out");

        int t = in.nextInt();in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        String s = in.nextLine().trim();
        if (s.length() == 1) return s + "0";

        char[] a = s.toCharArray();
        int i = s.length() - 2;
        while (i > -1 && a[i] >= a[i + 1])
            i--;
        if (i == -1) {
            Arrays.sort(a);
            i = 0;
            while (a[i] == '0') i++;
            char p = a[i];
            a[i] = '0';
            return p + new String(a);
        } else {
            int j = s.length() - 1;
            while (a[j] <= a[i]) j--;
            char t = a[i];
            a[i] = a[j];
            a[j] = t;
            Arrays.sort(a, i + 1, a.length);
            return new String(a);
        }
    }
}