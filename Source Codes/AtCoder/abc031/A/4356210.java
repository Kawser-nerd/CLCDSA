import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int d = sc.nextInt();
        int ans = Math.max((a + 1) * d, a * (d + 1));
        System.out.println(ans);
    }
}