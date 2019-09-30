import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        if(k == 0) {
            System.out.print((long) n * n);
            return;
        }

        long sum = 0;
        for(int i = k + 1; i <= n; i++) {
            sum += (long)(n / i) * (i - k) + Math.max(n%i-k+1, 0);
        }
        System.out.print(sum);
    }
}