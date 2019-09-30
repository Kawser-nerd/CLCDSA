import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int tall = 0;
        for (int i = 1; i <= b - a; i++) {
            tall += i;
        }
        System.out.println(tall - b);
    }

}