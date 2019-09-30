import java.util.Scanner;

public class Pogo {

    private static void out(int t, String ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
        return;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x == 0 && y == 0) {
                out(t, "");
                continue;
            }
            char xplus, xminus, yplus, yminus;
            if (x >= 0) {
                xplus = 'E';
                xminus = 'W';
            } else {
                x = -x;
                xplus = 'W';
                xminus = 'E';
            }
            if (y >= 0) {
                yplus = 'N';
                yminus = 'S';
            } else {
                y = -y;
                yplus = 'S';
                yminus = 'N';
            }
            final int sum = x + y;
            int wa = 0;
            int i = 1;
            for (; i < sum + 10; i++) {
                wa += i;
                int diff = wa - sum;
                if (diff >= 0 && diff % 2 == 0) {
                    break;
                }
            }

            char[] ans2 = null;
            int dummy = 0;
            while (dummy++ < 1) {
                int rev = (wa - sum) / 2;
                x += rev;
                char[] ans = new char[i];
                // System.out.println(rev + "," + x);
                // pick up numbers up to rev and set xminus
                for (int k = i; k > 0 && rev > 0; k--) {
                    if (k <= rev) {
                        ans[k - 1] = xminus;
                        rev -= k;
                    }
                }
                // System.out.println(Arrays.toString(ans));
                // pick up numbers up to x and set xplus
                for (int k = i; k > 0 && x > 0; k--) {
                    if (ans[k - 1] == 0 && k <= x) {
                        ans[k - 1] = xplus;
                        x -= k;
                    }
                }
                if (x != 0) {
                    break;
                }
                // System.out.println(Arrays.toString(ans));
                // set yplus to remainings
                for (int k = 0; k < i; k++) {
                    if (ans[k] == 0) {
                        ans[k] = yplus;
                    }
                }
                // System.out.println(Arrays.toString(ans));
                ans2 = ans;
            }
            if (ans2 == null) {
                int rev = (wa - sum) / 2;
                y += rev;
                char[] ans = new char[i];
                // System.out.println(rev + "," + x);
                // pick up numbers up to rev and set xminus
                for (int k = i; k > 0 && rev > 0; k--) {
                    if (k <= rev) {
                        ans[k - 1] = yminus;
                        rev -= k;
                    }
                }
                // System.out.println(Arrays.toString(ans));
                // pick up numbers up to x and set xplus
                for (int k = i; k > 0 && y > 0; k--) {
                    if (ans[k - 1] == 0 && k <= y) {
                        ans[k - 1] = yplus;
                        y -= k;
                    }
                }
                if (y != 0) {
                    System.err.println("error!!!!");
                    return;
                }
                // System.out.println(Arrays.toString(ans));
                // set yplus to remainings
                for (int k = 0; k < i; k++) {
                    if (ans[k] == 0) {
                        ans[k] = xplus;
                    }
                }
                // System.out.println(Arrays.toString(ans));
                ans2 = ans;
            }

            StringBuilder sb = new StringBuilder();
            for (int k = 0; k < i; k++) {
                sb.append(ans2[k]);
            }
            out(t, sb.toString());
        }
    }
}
