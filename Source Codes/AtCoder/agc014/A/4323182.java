import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int count = 0;
        while (count < 100) {
            int d = a;
            int e = b;
            int f = c;
            if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
                count++;
                a = (e + f) / 2;
                b = (f + d) / 2;
                c = (d + e) / 2;
                d = a;
                e = b;
                c = f;
            } else {
                break;
            }
        }

        if (count < 100) {
            System.out.println(count);
        } else {
            System.out.print(-1);
        }
    }

}