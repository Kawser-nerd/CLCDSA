import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long ans = 0;
        for (long i = 1; i < 1000000000L; i *= 10) {
            long digit = N % (i * 10) / i;
            ans += N / (i * 10) * i;
            if (digit == 1) {
                ans += N % i + 1;
            } else if (digit != 0) {
                ans += i;
            }
        }
        System.out.println(ans);
    }
}