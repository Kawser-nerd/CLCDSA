import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        int n = s.length();
        int ans = 0;
        boolean haszero = false;
        if (n == 1) {
            if (s.charAt(0) == '0') {
                System.out.println(0);
            } else {
                System.out.println(1);
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            // ?????
            if (i == n - 1) {
                if (s.charAt(i - 1) == '+') {
                    if (c != '0') {
                        ans++;
                    }
                } else {
                    if (c == '0') {
                        haszero = true;
                    }
                    if (haszero) {

                    } else {
                        ans++;
                    }
                }
                break;
            }
            if (i % 2 == 0) {
                // ??
                if (c == '0') {
                    haszero = true;
                } else {

                }

            } else {
                if (c == '+') {
                    if (haszero) {
                        haszero = false;
                    } else {
                        ans++;

                    }
                } else {

                }
            }
        }
        System.out.println(ans);

    }
}