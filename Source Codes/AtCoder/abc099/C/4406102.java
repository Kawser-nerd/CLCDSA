import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int ans = Integer.MAX_VALUE;
        int s1 = n / 6, s2 = n / 9;
        int[] TS = new int[n + 1];
        int[] TN = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            int temp = i;
            while (temp / 6 > 0) {
                TS[i] += temp % 6;
                temp /= 6;
            }
            TS[i] += temp;
            temp = i;
            while (temp / 9 > 0) {
                TN[i] += temp % 9;
                temp /= 9;
            }
            TN[i] += temp;
        }
        for (int i = 0; i <= s1; i++) {
            int six = 6 * i;
            int nine = (n - six) - (n - six) % 9;
            if (six + nine <= n && six <= n && nine <= n) ans = min(ans, TS[six] + TN[nine] + (n - six - nine));
        }
        out.println(ans);
    }
}