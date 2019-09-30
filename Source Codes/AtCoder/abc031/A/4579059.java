import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int d = sc.nextInt();
        System.out.println(Math.max(a * (d + 1), (a + 1) * d));

    }

}