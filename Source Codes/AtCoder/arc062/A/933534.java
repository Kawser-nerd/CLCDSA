import java.util.*;

class Main {
        public static void main(String args[]) {
                try (Scanner sc = new Scanner(System.in)) {
                        int N = sc.nextInt();
                        long A = 1, B = 1;
                        for (int i = 0; i < N; i++) {
                                long X = sc.nextInt(), Y = sc.nextInt();
                                long num;
                                A = ((A - 1) / X + 1) * X;
                                B = Math.max(B, A / X * Y);
                                B = ((B - 1) / Y + 1) * Y;
                                A = Math.max(A, B / Y * X);
                        }
                        System.out.println(A + B);
                }
        }
}