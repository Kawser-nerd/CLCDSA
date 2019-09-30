import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (b < 0) {
            if (a == b) {
                System.out.println("Positive");
            } else {
                if ((b - a) % 2 == 0) {
                    System.out.println("Negative");
                } else {
                    System.out.println("Positive");
                }
            }
        } else if (a <= 0) {
            System.out.println("Zero");
        } else {
            System.out.println("Positive");
        }

    }

}