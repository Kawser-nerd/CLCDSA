import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        sc.close();

        int a = n * 800;
        int b = n / 15 * 200;

        System.out.println(a - b);
    }
}