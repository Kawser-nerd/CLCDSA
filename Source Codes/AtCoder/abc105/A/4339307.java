import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt(), k = sc.nextInt();
        System.out.println(n % k == 0 ? 0 : 1);
    }
}