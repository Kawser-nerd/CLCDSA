import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int PLUS = 10000;

    static boolean check(int start, int x, List<Integer> a) {
        boolean[] dp = new boolean[20002];
        dp[start] = true;

        for (int i = 0; i < a.size(); i++) {
            boolean[] next_dp = new boolean[20002];
            for (int j = 0; j < 20002; j++) {
                if (!dp[j]) {
                    continue;
                }
                next_dp[j + a.get(i)] = true;
                next_dp[j - a.get(i)] = true;
            }
            dp = Arrays.copyOf(next_dp, 20002);
        }
        return dp[x];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next();
            int x = sc.nextInt() + PLUS;
            int y = sc.nextInt() + PLUS;

            List<Integer> ax = new ArrayList<>();
            List<Integer> ay = new ArrayList<>();

            boolean isOdd = false;

            for (int i = 0; i < s.length(); i++) {
                int cnt = 0;
                while (i < s.length() && s.charAt(i) == 'F') {
                    cnt++;
                    i++;
                }
                if (isOdd) {
                    ay.add(cnt);
                } else {
                    ax.add(cnt);
                }
                isOdd = !isOdd;
            }

            int nowX = PLUS + ax.get(0);
            int nowY = PLUS;

            if (check(nowX, x, ax.subList(1, ax.size())) && check(nowY, y, ay)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}