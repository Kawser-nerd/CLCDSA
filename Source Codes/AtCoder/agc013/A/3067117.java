import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int start = 0;
        int ans = 0;
        while (start < N) {
            if (start == N - 1) {
                ans++;
                break;
            }
            int end = start + 1;
            while (end < N && A[end] == A[end - 1]) end++;
            if (end == N) {
                ans++;
                break;
            }
            if (A[end] > A[start]) {
                while (end < N && A[end] >= A[end - 1]) end++;
                ans++;
            } else {
                while (end < N && A[end] <= A[end - 1]) end++;
                ans++;
            }
            start = end;
        }
        System.out.println(ans);
    }
}