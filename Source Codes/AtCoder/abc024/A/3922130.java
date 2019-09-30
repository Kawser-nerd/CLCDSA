import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();
        int T = sc.nextInt();
        if (S + T >= K) {
            System.out.println(A * S + B * T - C * (S + T));
        } else {
            System.out.println(A * S + B * T);
        }
    }
}