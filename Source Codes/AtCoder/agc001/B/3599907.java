import java.util.*;

public class Main {
    static long n;
    static long x;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        x = sc.nextLong();
        long ret = solve(n, x);
        System.out.println(ret);
    }


    static long solve(long n, long x) {
        if (n == 3 * x) {
            return n;
        }
        if(2*x > n) {
            x = n - x;
        }
        long y = n - x;
        long tmp = (y / x) * 3 * x;
        long tmp1 = (y % x != 0) ? solve(x + y % x, x) : 0;
        return tmp + tmp1;
    }
}