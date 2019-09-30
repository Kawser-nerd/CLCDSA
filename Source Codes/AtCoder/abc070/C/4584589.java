import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long tmp = sc.nextLong();
        for (int i = 1; i < N; i++) {
            long value = sc.nextLong();
            long gcd = gcd(tmp, value);
            tmp = (Math.max(value, tmp) / gcd) * Math.min(value, tmp);
        }
        System.out.println(tmp);
    }

    static long gcd (long a, long b) {return b > 0 ? gcd(b,a%b) : a; }
}