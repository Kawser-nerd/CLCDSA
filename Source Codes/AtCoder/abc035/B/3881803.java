import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int T = sc.nextInt();
        int x = 0;
        int y = 0;
        int q = 0;

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'L') {
                x--;
            } else if (S.charAt(i) == 'R') {
                x++;
            } else if (S.charAt(i) == 'U') {
                y++;
            } else if (S.charAt(i) == 'D') {
                y--;
            } else {
                q++;
            }
        }
        int ans = Math.abs(x) + Math.abs(y);
        int max = ans + q;
        int min = ans - q;
        if (ans < q) {
            int d = q - ans;
            if (d % 2 == 1)
                min = 1;
            else
                min = 0;
        }

        System.out.println(T == 1 ? max : min);

    }
}