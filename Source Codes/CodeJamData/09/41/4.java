import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A.in"));
        PrintWriter out = new PrintWriter("A.out");

        int t = in.nextInt();in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        in.nextLine();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            String s = in.nextLine();
            int j = n - 1;
            while (s.charAt(j) == '0' && j > 0) j--;
            a[i] = j;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (a[j] > i) j++;
            int t = a[j];
            for (int k = j; k > i; k--) a[k] = a[k - 1];
            a[i] = t;
            res += (j - i);
        }

        return "" + res;
    }

}