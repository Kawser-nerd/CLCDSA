import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println((sc.nextInt() * 100 + sc.nextInt() * 10 + sc.nextInt()) % 4 == 0 ? "YES" : "NO");
    }
}