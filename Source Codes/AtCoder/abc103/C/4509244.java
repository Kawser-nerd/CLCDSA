import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        long[] values = new long[N];

        for (int i = 0; i < N; i++) {
            values[i] = sc.nextLong();
        }
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += (values[i] - 1);
        }
        System.out.println(ans);
    }
}