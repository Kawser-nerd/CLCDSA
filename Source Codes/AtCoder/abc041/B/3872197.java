import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        long X = (long) Math.pow(10, 9) + 7;
        long ans = (long) (A * B % X * C % X);
        System.out.println(ans);
    }
}