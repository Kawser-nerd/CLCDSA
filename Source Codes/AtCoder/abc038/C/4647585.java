import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int[] values = new int[N+1];

        for (int i = 0; i < N; i++) {
            values[i] = sc.nextInt();
        }
        values[N] = 0;

        long ans = 0;
        long count = 1;
        for (int i = 0; i < N; i++) {
            if (values[i] < values[i + 1]) {
                count++;
            } else {
                ans += (count * (count + 1)) / 2;
                count = 1;
            }
        }

        System.out.println(ans);
    }

}