import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = 1000000007;
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();

        long ans = a * b % n;
        ans = ans * c % n;

        System.out.println(ans);
    }
}