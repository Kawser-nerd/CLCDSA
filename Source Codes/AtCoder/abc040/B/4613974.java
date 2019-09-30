import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int ans = 100000;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i * j > n)
                    break;
                ans = Math.min(ans, Math.abs(i - j) + (n - i*j));
            }
        }
        
        System.out.println(ans);
    }
}