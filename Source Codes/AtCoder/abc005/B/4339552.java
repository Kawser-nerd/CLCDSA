import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int ans = 100;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, sc.nextInt());
        }
        System.out.println(ans);
    }
}