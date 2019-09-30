import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int max = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 2; j <= 10; j++) {
                int num = (int) Math.pow(i, j);
                if (num > x) {
                    break;
                }
                if (num > max) {
                    max = num;
                }
            }
        }
        System.out.println(max);
    }

}