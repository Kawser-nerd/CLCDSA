import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();

        int min = 0;
        for (int i = 0; i <= 100000; i++) {
            int price = i * 2 * c
                    + Math.max(0, x - i) * a
                    + Math.max(0, y - i) * b;
            if (min > price || i == 0) {
                min = price;
            }
        }
        System.out.println(min);
    }

}