import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve(new Scanner(System.in));
//        solve(new Scanner(ex));
    }

//    private static final String ex = "gpg";
    private static final String ex = "ggppgggpgg";

    private static void solve(Scanner scanner) {
        char[] s = scanner.nextLine().toCharArray();

        int parCount = 0;
        for (char value : s) {
            if (value == 'p') parCount++;
        }

        int result = -parCount + s.length / 2;

        System.out.println(result);
    }
}