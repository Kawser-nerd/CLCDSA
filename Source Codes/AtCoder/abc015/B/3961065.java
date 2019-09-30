import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A[] = new int[N];
        int sum = 0;
        double count = 0;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            sum += A[i];
            if (A[i] == 0) {
                count++;
            }
        }
        System.out.println((int) Math.ceil(sum / (N - count)));

    }
}