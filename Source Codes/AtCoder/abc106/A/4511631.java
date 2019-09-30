import java.util.Scanner;

public class Main {
    public static String process(int a, int b) {
        return String.valueOf(a*b-a-b+1);
    }

    // Util Func

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // process
        final String result = process(a, b);

        // output
        System.out.println(result);
    }
}