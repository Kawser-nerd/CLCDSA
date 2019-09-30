import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Integer min = null;
        for (int i = 1; i <= Math.max(1, n / 2); i++) {
            int j = n / i;
            int result = Math.abs(i - j) + n - i * j;
            if (min == null || result < min) {
                min = result;
            }
        }
        System.out.println(min);
    }
}