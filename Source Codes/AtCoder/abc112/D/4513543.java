import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextInt();
        long m = sc.nextInt();
        long ans = 1;
        for (long a = 1; a * a <= m; a++) {
            if(m % a != 0){
                continue;
            }
            long b = m / a;
            if(a * n <= m){
                ans = Math.max(ans, a);
            }
            if(b * n <= m){
                ans = Math.max(ans, b);
            }
        }
        System.out.println(ans);
    }
}