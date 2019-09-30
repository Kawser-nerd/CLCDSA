import java.util.*;
import java.util.stream.IntStream;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), ng[] = {scanner.nextInt(), scanner.nextInt(), scanner.nextInt()};
        if (ng[0] != n && ng[1] != n && ng[2] != n) {
            for (int i = 0; i < 100 && n > 0; i++) {
                boolean[] b = new boolean[3];
                for (int j = 0; j < 3; j++)
                    if (n > ng[j] && n - ng[j] <= 3)
                        b[3 - n + ng[j]] = true;
                OptionalInt j = IntStream.range(0, 3).filter(k -> !b[k]).findFirst();
                if (!j.isPresent())
                    break;
                n -= 3 - j.getAsInt();
            }
        }
        System.out.println(n > 0 ? "NO" : "YES");
    }
}