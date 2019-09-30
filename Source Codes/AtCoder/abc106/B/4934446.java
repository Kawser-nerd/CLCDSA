import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {

        int n = sc.nextInt();


        int count = 0;
        for (int i=105; i <= n; i += 2) {
            if (numOfDivisors(i) == 8)
                count++;
        }

        System.out.println(count);


    }

    private static int numOfDivisors(int n) {
        int c = 0;
        for (int i=1; i <= n; i++) {
            if (n % i == 0)
                c++;
        }
        return c;
    }

}