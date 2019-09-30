import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        if (a + b <= b + c) {
            if (a + b <= c + a) {
                System.out.println(a + b);
            } else {
                System.out.println(c + a);
            }
        } else if (b + c <= c + a) {
            System.out.println(b + c);
        } else {
            System.out.println(c + a);
        }
    }
}