import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (n % 2 == 0) {
            System.out.println(n);
            return;
        }
        System.out.println(2 * n);
    }

}