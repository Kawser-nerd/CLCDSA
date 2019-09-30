import java.util.Scanner;

public class Main {

    private static int[] values;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        values = new int[N];
        for (int i = 0; i < N; i++) {
            values[i] = in.nextInt();
        }

        int ans = values[0];

        for (int i = 0; i < N; i++) {
            ans = gcd(ans, values[i]);
        }
        System.out.println(ans);
    }

    private static int gcd(int x, int y) {
        while (true) {
            int tmp = x % y;
            if (tmp == 0) {
                return y;
            }
            x = y;
            y = tmp;
        }
    }
}