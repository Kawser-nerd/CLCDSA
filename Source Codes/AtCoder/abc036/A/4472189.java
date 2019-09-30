import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (b % a == 0) {
            System.out.println(b / a);
        } else {
            System.out.println(b / a + 1);
        }
    }

}