import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        long a = scanner.nextLong(), k = scanner.nextInt();
        if (k == 0) {
            System.out.println(2000000000000L - a);
        } else {
            int ans = 1;
            while ((a += a * k + 1) < 2000000000000L)
                ans++;
            System.out.println(ans);
        }
    }
}