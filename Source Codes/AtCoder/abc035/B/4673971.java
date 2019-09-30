import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int t = sc.nextInt();

        int x = 0;
        int y = 0;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'L': x--; break;
                case 'R': x++; break;
                case 'U': y++; break;
                case 'D': y--; break;
                default: cnt++;
            }
        }

        int ans = Math.abs(x) + Math.abs(y);
        if (t == 1) {
            ans += cnt;
        } else {
            if (ans >= cnt) {
                ans -= cnt;
            } else {
                cnt -= ans;
                if (cnt % 2 == 0)
                    ans = 0;
                else
                    ans = 1;
            }
        }

        System.out.println(ans);
    }
}