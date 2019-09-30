import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N = sc.nextInt();
        double sum = 0;
        for (int i = 0; i < N; i++) {
            double x = sc.nextDouble();
            String u = sc.next();
            if (u.equals("BTC")) {
                sum += x * 380000;
            } else {
                sum += x;
            }
        }
        System.out.println(sum);
    }
}