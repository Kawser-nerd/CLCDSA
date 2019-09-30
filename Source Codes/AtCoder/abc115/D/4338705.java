import java.util.Scanner;

public class Main {
    long patty[] = new long[51];
    long size[] = new long[51];

    public void main(Scanner sc) {
        int n = sc.nextInt();
        long x = sc.nextLong();

        patty[0] = 1;
        size[0] = 1;
        for (int i = 1; i <= 50; i++) {
            patty[i] = patty[i - 1] * 2 + 1;
            size[i] = patty[i] * 2 - 1;
        }

        System.out.println(calc(n, x));
    }

    private long calc(int level, long x) {
        if (x == 0) {
            return 0;
        }
        if (x >= size[level]) {
            return patty[level];
        }

        if (x * 2 > size[level]) {
            // ?????????
            return patty[level - 1] + 1 + calc(level - 1, x - size[level - 1] - 2);
        } else {
            // ?????????
            return calc(level - 1, x - 1);
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}