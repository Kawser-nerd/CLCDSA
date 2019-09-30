import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long x = sc.nextLong();
        long ax = a / x;
        long bx = b / x;
        long ans = bx - ax;
        if (a % x == 0) {
            ans++;
        }
        System.out.println(ans);
        sc.close();
    }
}