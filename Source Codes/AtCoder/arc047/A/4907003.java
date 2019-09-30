import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), l = scanner.nextInt(), t = 1, ans = 0;
        for (char c : scanner.next().toCharArray())
            if ((c == '+' ? ++t : --t) > l)
                ans += t = 1;
        System.out.println(ans);
    }
}