import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            int sumOfDigit = getSumOfEachDigit(i);
            if (a <= sumOfDigit && sumOfDigit <= b) {
                sum += i;
            }
        }
        System.out.println(sum);
    }

    private static int getSumOfEachDigit(int num) {
        // num?1234???
        // len: 4
        int len = String.valueOf(num).length();
        int sum = 0;
        // d: 1000
        int d = (int)Math.pow(10, len - 1);
        for (int i = 0; i < len; i++) {
            // nums: [1, 2, 3, 4]
            sum += num / d;
            // num: 234
            num %= d;
            // d: 100
            d /= 10;
        }
        return sum;
    }
}