import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        int ans = 0;
        String s[] = new String[N];
        int d[] = new int[N];
        for (int i = 0; i < N; i++) {
            s[i] = sc.next();
            d[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            if (s[i].equals("East")) {
                if (d[i] < A) {
                    ans += A;
                } else if (d[i] > B) {
                    ans += B;
                } else {
                    ans += d[i];
                }
            } else {
                if (d[i] < A) {
                    ans -= A;
                } else if (d[i] > B) {
                    ans -= B;
                } else {
                    ans -= d[i];
                }
            }
        }
        if (ans == 0) {
            System.out.println(0);
            return;
        }
        System.out.println(ans > 0 ? "East" + " " + ans : "West" + " " + Math.abs(ans));
    }
}