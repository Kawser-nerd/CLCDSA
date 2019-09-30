import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] a = new long[n][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = sc.nextLong();
            a[i][1] = sc.nextLong();
        }
        long ans = 0L;
        for (int i = n-1; i >= 0; i--) {
            if((a[i][0] + ans)% a[i][1] != 0)
            ans += a[i][1] - ((a[i][0] + ans)% a[i][1]);
        }
        System.out.println(ans);
        sc.close();
    }

}