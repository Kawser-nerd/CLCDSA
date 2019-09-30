import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), result = 0, combo = 0, color = 0;
        for (int i = 0; i < n; i++) {
            int j = scanner.nextInt();
            combo++;

            if (j != color) {
                result += combo / 2;
                combo = 0;
                color = j;
            }
        }
        System.out.println(result + ++combo / 2);
    }
}