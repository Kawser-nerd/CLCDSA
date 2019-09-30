import java.util.Scanner;

public class Main {

    private static int findSumOfDigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = Integer.parseInt(scan.next());
        int sumOfDigit = findSumOfDigit(n);

        System.out.println(n % sumOfDigit == 0 ? "Yes" : "No");

    }
}