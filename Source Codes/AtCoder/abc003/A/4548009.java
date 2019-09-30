import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        long n = sc.nextLong();
        System.out.println((n * (n + 1) / 2) * 10000 / n);
    }
}