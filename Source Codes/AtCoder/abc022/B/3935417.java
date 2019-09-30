import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int set = A[i];
            for (int j = i + 1; j < N; j++) {
                if (set == A[j]) {
                    ans++;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}