import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int thrdDigit = Integer.parseInt(String.valueOf(n).substring(0, 1));
        int repdigit = thrdDigit * 100 + thrdDigit * 10 + thrdDigit;

        if (n <= repdigit) {
            System.out.println(repdigit);
            return;
        }
        int nextRepDigit = (thrdDigit + 1) * 100 + (thrdDigit + 1) * 10 + thrdDigit + 1;
        System.out.println(nextRepDigit);

    }

}