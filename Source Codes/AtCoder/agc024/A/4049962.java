import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long k = sc.nextLong();
        if (k % 2 == 1) {
            System.out.println(b - a);
        } else {
            System.out.println(a - b);
        }
    }

}