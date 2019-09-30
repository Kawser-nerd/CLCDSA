import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int N = scanner.nextInt();
            double sum = 0;
            for (int i = 0; i < N; i++) {
                double x = scanner.nextDouble();
                String currency = scanner.next();
                switch (currency) {
                    case "JPY":
                        sum += x;
                        break;
                    case "BTC":
                        sum += x * 380000;
                        break;
                }
            }
            System.out.println(sum);
        }
    }
}