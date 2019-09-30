import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args) {
        int n = s.nextInt();
        int max = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int tmp = s.nextInt();
            if (max < tmp) {
                max = tmp;
            }
            sum += tmp;
        }
        System.out.println(max < (sum - max) ? "Yes" : "No");
    }
}