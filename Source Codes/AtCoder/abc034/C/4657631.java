import java.math.BigDecimal;
        import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int W = sc.nextInt();
        int H = sc.nextInt();

        //  (W + H)! / (W! * H!)
        System.out.println(calc(W-1, H-1));
    }

    private static long calc(long w, long h) {
        long start = Math.max(w, h) + 1;
        long a = 1;
        long b = 1;
        for (long i = start; i <= w + h; i++) {
            a *= i;
            b *= i - start + 1;
            a = a % 1000000007l;
            b = b % 1000000007l;
        }
        return a * pow(b, 1000000005l) % 1000000007l;
    }

    // a^n (mod 1000000007)
    static long  pow(long a,long n){
        long mod = 1000000007l;
        long tmp = 1;
        while(n != 0){
            if(n % 2 == 1)	tmp = tmp * a % mod;
            a = a * a % mod;
            n /= 2;
        }
        return tmp;
    }
}