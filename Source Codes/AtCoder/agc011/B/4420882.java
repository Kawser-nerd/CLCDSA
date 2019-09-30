import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            long pos = -1;
            long n = in.nextLong();
            long[] a = new long[(int)n];
            for (int i = 0; i < n; ++i) a[i] = in.nextLong();
            Arrays.sort(a);
            for (int i = 0; i < n - 1; ++i) {
                a[i + 1] += a[i];
                if (a[i] * 3 < a[i + 1]) {
                    pos = i;
                }
            }
            System.out.println(n - pos - 1);
        }
    }
}