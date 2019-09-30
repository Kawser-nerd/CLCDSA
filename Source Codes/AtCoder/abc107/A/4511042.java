import java.util.Scanner;

public class Main {
    public static String process(int N, int i) {
        return String.valueOf(N - i + 1);
    }

    // Util Func

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int i = sc.nextInt();

        // process
        final String result = process(N, i);

        // output
        System.out.println(result);
    }
}