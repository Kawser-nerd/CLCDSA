import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int x = sc.nextInt();
        if (a <= x && a + b >= x) {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }

}