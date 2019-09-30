import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int result = a + b;
        if (result >= 24) {
            result -= 24;
        }
        System.out.println(result);
    }

}