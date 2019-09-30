import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        long numOfT = 1;
        long numOfA = 1;
        for (int i = 0; i < n; i++) {
            long t = sc.nextLong();
            long a = sc.nextLong();

            long xt = numOfT % t == 0 ? numOfT / t : numOfT / t + 1;
            long xa = numOfA % a == 0 ? numOfA / a : numOfA / a + 1;
            long x = Math.max(xt, xa);
            numOfT = t * x;
            numOfA = a * x;
        }
        System.out.println(numOfT + numOfA);
    }
}