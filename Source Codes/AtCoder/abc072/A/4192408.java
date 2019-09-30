import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long t = sc.nextLong();
        if (x > t) {
            System.out.println(x - t);
            return;
        }
        System.out.println(0);
    }

}