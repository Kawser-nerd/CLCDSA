import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        double min = 0;
        for (int i = 1; i < 100000; i++) {
            double pow = Math.pow(i, 2);
            if (pow > n) {
                break;
            }
            min = pow;
        }
        System.out.println((int) min);
    }

}