import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), m = cin.nextInt();
        System.out.println(((n - m) * 100 + 1900 * m) * pow(2, m));
    }

    private static int pow(int a, int b) {
        int res = 1;
        for (int i = 0; i < b; ++i) {
            res *= a;
        }
        return res;
    }
}