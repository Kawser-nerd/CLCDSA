import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        if (k % 2 == 0) {
            System.out.println(k * k / 4);
            return;
        }
        System.out.println(k / 2 * (k + 1) / 2);
    }

}