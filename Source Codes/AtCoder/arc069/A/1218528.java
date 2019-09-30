import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long M = scanner.nextLong();

        if (M > N*2) {
            long surplus = M - N*2;
            System.out.println(N+surplus/4);
        } else {
            System.out.println(M/2);
        }
    }
}