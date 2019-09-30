import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int cnt = 0;
        if (a == b && b == c) {
            if (a % 2 == 1) {
                System.out.println(0);
                return;
            }
            System.out.println(-1);
            return;
        }
        while (true) {
            if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
                break;
            }
            int atmp = a;
            int btmp = b;
            int ctmp = c;
            a = (btmp + ctmp) / 2;
            b = (atmp + ctmp) / 2;
            c = (atmp + btmp) / 2;
            cnt++;
        }
        System.out.println(cnt);
    }
}