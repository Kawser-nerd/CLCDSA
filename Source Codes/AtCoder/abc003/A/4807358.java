import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            ans += 10000 * i;
        }

        System.out.println(ans / n);
    }

}