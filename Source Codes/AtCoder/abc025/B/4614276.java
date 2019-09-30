import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        String[] s = new String[n];
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
            d[i] = sc.nextInt();
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int dis = d[i];
            if (dis < a) {
                if (s[i].charAt(0) == 'E') {
                    ans += a;
                } else {
                    ans -= a;
                }
            } else if (dis > b) {
                if (s[i].charAt(0) == 'E') {
                    ans += b;
                } else {
                    ans -= b;
                }
            } else {
                if (s[i].charAt(0) == 'E') {
                    ans += dis;
                } else {
                    ans -= dis;
                }

            }
        }
        if (ans < 0) {
            System.out.print("West ");
            System.out.println(-ans);
        } else if (ans > 0) {
            System.out.print("East ");
            System.out.println(ans);
        } else {
            System.out.println(0);
        }
        sc.close();
    }
}