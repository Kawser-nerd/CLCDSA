import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        System.out.println(Math.max(Math.max(a * 10 + b + c, a + b * 10 + c), a + b + c * 10));
    }
}