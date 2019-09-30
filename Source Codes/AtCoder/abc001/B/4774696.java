import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vv;
        int input1 = scanner.nextInt();
        if (input1 < 100) {
            vv = 0;
        } else if (input1 >= 100 && input1 <= 5000) {
            vv = input1 * 10 / 1000;
        } else if (input1 >= 6000 && input1 <= 30000) {
            vv = (input1 / 1000) + 50;
        } else if (input1 >= 35000 && input1 <= 70000) {
            vv = (((input1 / 1000) - 30) / 5) + 80;
        } else if (input1 > 70000) {
            vv = 89;
        } else {
            throw new RuntimeException("Unnexpected input: " + input1);
        }

        System.out.printf("%02d\n", vv);
    }
}