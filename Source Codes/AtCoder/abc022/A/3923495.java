import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int S = sc.nextInt();
        int T = sc.nextInt();
        int W = sc.nextInt();
        int A[] = new int[N];
        A[0] = 0;
        for (int i = 1; i < A.length; i++) {
            A[i] = sc.nextInt();
        }
        int wht = W;
        int ans = 0;
        for (int i = 0; i < A.length; i++) {
            wht += A[i];
            if (wht >= S && wht <= T) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}