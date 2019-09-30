import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S[] = new String[N];
        int P[] = new int[N];
        int sum = 0;
        for (int i = 0; i < N; i++) {
            S[i] = sc.next();
            P[i] = sc.nextInt();
            sum += P[i];
        }
        for (int i = 0; i < N; i++) {
            if (sum / 2 < P[i]) {
                System.out.println(S[i]);
                return;
            }
        }
        System.out.println("atcoder");
    }
}