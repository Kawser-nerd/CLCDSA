import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        int Ans[] = new int[N];
        int L[] = new int[Q];
        int R[] = new int[Q];
        int T[] = new int[Q];
        for (int i = 0; i < Q; i++) {
            L[i] = sc.nextInt();
            R[i] = sc.nextInt();
            T[i] = sc.nextInt();
            for (int j = L[i] - 1; j < R[i]; j++) {
                Ans[j] = T[i];
            }
        }
        for (int k = 0; k < N; k++) {
            System.out.println(Ans[k]);
        }

    }
}