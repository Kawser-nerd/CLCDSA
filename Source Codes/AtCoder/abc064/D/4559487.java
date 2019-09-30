import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        String ans = "";
        int cnt = 0;
        String kari = "";
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == ')') { // )
                if (cnt == 0) {
                    ans = "(" + ans + ")";
                } else {
                    kari = kari + ")";
                    cnt--;
                    if (cnt == 0) {
                        ans = ans + kari;
                        kari = "";
                    }
                }
            } else {// (
                cnt++;
                kari = kari + "(";

            }
            if (i == n - 1) {
                ans += kari;
                String tmp = "";
                for (int j = 0; j < cnt; j++) {
                    tmp = tmp + ")";
                }
                ans = ans + tmp;

            }

        }
        System.out.println(ans);
        sc.close();
    }
}