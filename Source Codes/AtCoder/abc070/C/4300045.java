import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        long ans=1;
        for (int i = 0; i < n; i++) {
            long t = sc.nextLong();
            long g = gcd(ans, t);
            ans=t/g*ans;
        }
        out.println(ans);
    }
    static long gcd (long a, long b) {
        long temp;
        while((temp = a%b)!=0) {
            a = b;
            b = temp;
        }
        return b;
    }
}