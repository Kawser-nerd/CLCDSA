import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        // i ???Ai????
        int min[] = new int[N];
        min[0] = A[0];
        for (int i = 1; i < N; i++) {
            if (A[i] < min[i-1]) {
                min[i] = A[i];
            } else {
                min[i] = min[i-1];
            }
        }
        // i ???Ai????
        int max[] = new int[N];
        max[N-1] = A[N-1];
        for (int i = N - 2; i >= 0; i--) {
            if (A[i] > max[i+1]) {
                max[i] = A[i];
            } else {
                max[i] = max[i+1];
            }
        }
        // ??????
        int maxgap = 0;
        for (int i = 0; i < N; i++) {
            if (maxgap < max[i] - min[i]) {
                maxgap = max[i] - min[i];
            }
        }
        // maxgap??????????
        // ??????????????
        int prevmax = 0; // ?????max
        int prevmin = 0; // ?????min
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (max[i]-min[i]==maxgap && (prevmax!=max[i] || prevmin!=min[i])) {
                count++;
            }
            prevmax = max[i];
            prevmin = min[i];
        }
        System.out.println(count);
    }
}