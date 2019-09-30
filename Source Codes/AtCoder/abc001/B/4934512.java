import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        q_2();
    }

    private static void q_1() {
        try(Scanner scan = new Scanner(System.in)) {
            int h1 = scan.nextInt();
            int h2 = scan.nextInt();

            System.out.println(h1 - h2);
        }
    }

    private static void q_2() {
        try(Scanner scan = new Scanner(System.in)) {
            int m = scan.nextInt();

            if(m < 100) {
                System.out.println("00");
            } else if(100 <= m && m <= 5000) {
                System.out.println(String.format("%02d", (m * 10) / 1000));
            } else if(6000 <= m && m <= 30000) {
                System.out.println(String.format("%02d", (m / 1000) + 50));
            } else if(35000 <= m && m <= 70000) {
                System.out.println(String.format("%02d", ((m / 1000) - 30) / 5 + 80));
            } else if(m > 70000) {
                System.out.println(89);
            }
        }
    }
}