import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int min = 1000000000;
        int dif = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (a < min) {
                min = a;
            } else if (dif == a - min) {
                ans++;
            } else if (dif < a - min) {
                dif = a - min;
                ans = 1;
            }
        }
        System.out.println(ans);
    }
}