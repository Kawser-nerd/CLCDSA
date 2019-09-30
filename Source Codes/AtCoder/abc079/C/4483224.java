import java.util.*;

public class Main {
    public void main(Scanner sc) {
        char s[] = sc.next().toCharArray();
        char ans[] = new char[7];

        for (int i = 0; i < 4; i++) {
            ans[i * 2] = s[i];
        }
        for (int tmp = 0; tmp < (1 << 3); tmp++) {
            for (int b = 0; b < 3; b++) {
                ans[b * 2 + 1] = ((((tmp & (1 << b)) >> b) == 1) ? '+' : '-');
            }
            if (check(ans)) {
                System.out.println(new String(ans) + "=7");
                break;
            }
        }
    }

    private boolean check(char str[]) {
        int ans = str[0] - '0';
        for (int i = 0; i < 3; i++) {
            if (str[i * 2 + 1] == '+') {
                ans += str[i * 2 + 2] - '0';
            } else {
                ans -= str[i * 2 + 2] - '0';
            }
        }

        return ans == 7;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}