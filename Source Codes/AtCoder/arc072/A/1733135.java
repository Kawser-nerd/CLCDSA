import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        long ans1 = 0;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (i % 2 == 1 && sum <= 0) {
                ans1 += 1 - sum;
                sum = 1;
            } else if (i % 2 == 0 && sum >= 0) {
                ans1 += sum + 1;
                sum = -1;
            }
        }

        long ans2 = 0;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (i % 2 == 0 && sum <= 0) {
                ans2 += 1 - sum;
                sum = 1;
            } else if (i % 2 == 1 && sum >= 0) {
                ans2 += sum + 1;
                sum = -1;
            }
        }

        System.out.println(Math.min(ans1, ans2));
    }
}