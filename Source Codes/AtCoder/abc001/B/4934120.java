import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        q_1();
    }

    private static void q_1() {
        try(Scanner scan = new Scanner(System.in)) {
            int h1 = scan.nextInt();
            int h2 = scan.nextInt();

            System.out.println(h1 - h2);
        }
    }
}