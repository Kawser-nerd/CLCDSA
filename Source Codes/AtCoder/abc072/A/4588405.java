import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int t = sc.nextInt();

        if (x > t) {
            System.out.println(x - t);
        } else {
            System.out.println(0);
        }
    }
}