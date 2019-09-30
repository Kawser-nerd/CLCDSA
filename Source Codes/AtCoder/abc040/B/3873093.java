import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mn = 100001;
        for (int i = 1; i * i <= n; i++) {
            int dif = Math.abs(i - (n / i));
            int rem = n - i * (n / i);
            mn = Math.min(mn, dif + rem);
        }
        System.out.println(mn);
    }
}