import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long A = sc.nextLong();
        long B = sc.nextLong();

        long min = A * (N - 1) + B;
        long max = A + (N - 1) * B;

        out.println(Math.max(0, max - min + 1));
    }
}