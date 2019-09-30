import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();

        int ans = 0;
        for (int i = 0; i < N; i++) {
            long a = sc.nextLong();
            if (a % 2 != 0) continue;

            int cnt = 0;
            while (a % 2 == 0) {
                a = a / 2;
                cnt++;
            }
            ans += cnt;
        }
        System.out.println(ans);
    }
}