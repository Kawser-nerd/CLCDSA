import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        boolean p = false;
        boolean m = false;
        if (a + b == c) {
            p = true;
        }
        if (a - b == c) {
            m = true;
        }
        if (p && m) {
            System.out.println("?");
        } else if (p) {
            System.out.println("+");
        } else if (m) {
            System.out.println("-");
        } else {
            System.out.println("!");
        }

        sc.close();
    }
}