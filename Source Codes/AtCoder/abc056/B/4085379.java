import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        if (a + w >= b && a <= b + w) {
            System.out.println(0);
        } else if (a + w < b) {
            System.out.println(Math.abs(a + w - b));
        } else {
            System.out.println(Math.abs(b + w - a));
        }
    }
}