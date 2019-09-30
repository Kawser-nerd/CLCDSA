import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        } else {
            if (b == 0) {
                return a;
            } else {
                return gcd(b, a % b);
            }
        }
    }
    public static void main(String [] args) {
        final Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long M = scanner.nextLong();
        String s = scanner.next();
        String t = scanner.next();

        final HashMap<Long, String> mapping = new HashMap<>();

        final long length = N * M / gcd(N, M);
        final long k1 = length / N;
        final long k2 = length / M;

        for (int j = 0; j < M; ++j) {
            mapping.put(j * k2, String.valueOf(t.charAt(j)));
        }

        for (int i = 0; i < N; ++i) {
            long currentPos = i * k1;
            if (!mapping.containsKey(currentPos)) {
                mapping.put(currentPos, String.valueOf(s.charAt(i)));
            } else if (!mapping.get(currentPos).equals(String.valueOf(s.charAt(i)))) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(length);
    }
}