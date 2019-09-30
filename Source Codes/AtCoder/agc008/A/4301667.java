import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();

        int count = Integer.MAX_VALUE;

        if (x <= y) {
            count = Math.min(count, y - x);
        }

        x = x * (-1);

        if (x <= y) {
            count = Math.min(count, y - x + 1);
        }

        y = y * (-1);
        if (x <= y) {
            count = Math.min(count, y - x + 2);
        }

        x = x * (-1);
        if (x <= y) {
            count = Math.min(count, y - x + 1);
        }
        System.out.println(count);

    }

}