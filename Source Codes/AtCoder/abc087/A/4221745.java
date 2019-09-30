import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextInt();
        long a = sc.nextInt();
        long b = sc.nextInt();

        System.out.println((x - a) % b);
    }

}