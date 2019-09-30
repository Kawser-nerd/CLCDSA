import java.math.BigDecimal;
        import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int Q = sc.nextInt();

        int[] stones = new int[N+1];
        for (int i = 0; i < Q; i++) {
            int start = sc.nextInt() - 1;
            int end = sc.nextInt();
            stones[start] += 1;
            stones[end] += -1;
        }

        for (int i = 0; i < N; i++) {
            if (i > 0) stones[i] += stones[i-1];
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(stones[i] % 2 == 0 ? '0' : '1');
        }
        System.out.println(sb.toString());
    }
}