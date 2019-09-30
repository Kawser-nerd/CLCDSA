import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = 1;
        for (int i = 0; i < n; i++) {
            long t = sc.nextLong();
            ans = lcm(Math.max(t, ans), Math.min(t, ans));
        }

        System.out.println(ans);
        sc.close();
    }

    public static long gcd(long a, long b){
        if(a < b) return gcd(b, a);
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    public static long lcm(long a, long b){
        long c = a / gcd(a, b);
        return b * c;
    }

}