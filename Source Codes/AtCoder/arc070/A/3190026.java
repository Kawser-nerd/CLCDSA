import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLong()) {
            long X = sc.nextLong();
            long sum = 0;
            long i;
            for (i = 1; sum < X; i++) {
                sum += i;
            }
            System.out.println(i - 1);
        }
    }
}