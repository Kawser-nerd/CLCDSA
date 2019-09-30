import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        if (a + b + 1 >= c) {
            System.out.println(b + c);
        } else {
            System.out.println(b + (a + b + 1));
        }
    }
}