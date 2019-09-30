import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        long denom = (long) N * N * N;
        long numer = (long) (K - 1) * (N - K) * 6;
        numer += (N - 1) * 3;
        numer++;
        System.out.println((double) numer / denom);
    }
}