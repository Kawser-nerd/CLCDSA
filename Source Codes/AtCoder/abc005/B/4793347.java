import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 101;
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            ans = Math.min(ans, m);
        }
        System.out.println(ans);
    }
}