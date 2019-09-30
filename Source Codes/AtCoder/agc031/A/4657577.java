import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        sc.close();

        int n30 = 30;
        long[] num = new long[n30];

        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            int ic = c - 'a';
            num[ic]++;
        }

        final long DIV = 1000000007;
        long ans = 1;

        for(int i=0; i<n30; i++){
            ans *= num[i] + 1;
            ans %= DIV;
        }

        ans -= 1;
        if(ans < 0) ans += DIV;

        System.out.println(ans);
    }
}