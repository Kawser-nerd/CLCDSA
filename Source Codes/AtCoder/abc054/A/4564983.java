import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a == 1) {
            a = 20;
        }
        if (b == 1) {
            b = 20;
        }
        if (a == b) {
            System.out.println("Draw");
        } else if (a < b) {
            System.out.println("Bob");
        } else {
            System.out.println("Alice");
        }
        sc.close();
    }
}