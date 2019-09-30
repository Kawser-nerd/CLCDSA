import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong() * 10;
        long ans = 0;
        for (long i = 10; i < 10000000000L; i *= 10) {
            long digit = N % (i * 10) / i;
            ans += N / (i * 10) * i / 10;
            if (digit == 1) {
                ans += N % i / 10 + 1;
            } else if (digit != 0) {
                ans += i / 10;
            }
        }
        System.out.println(ans);
    }
}