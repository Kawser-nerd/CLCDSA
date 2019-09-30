import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int K = sc.nextInt();
        int P[] = new int[K];
        for (int i = 0; i < K; i++) {
            P[i] = sc.nextInt();
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (i != j && P[i] == P[j]) {
                    System.out.println("NO");
                    return;
                }
            }
            if (P[i] == a || P[i] == b) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}