import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
 
public class Main {
 
    public static void main(String[] args) {
        new Main().compute();
    }
 
    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        long[] w = new long[N];
        double[] p = new double[N];
        for (int i = 0; i < N; i++) {
            w[i] = sc.nextLong();
            p[i] = sc.nextDouble() / 100;
        }
        double lb = 0, ub = 1;
        for (int i = 0; i < 100; i++) {
            double mid = (lb + ub) / 2;
            double[] rest = new double[N];
            for (int j = 0; j < N; j++) {
                rest[j] = w[j] * (p[j] - mid);
            }
            Arrays.sort(rest);
            double sum=0;
            for (int j = N - 1; j >= N - K; j--) {
                sum+=rest[j];
            }
            if(sum>=0){
                lb=mid;
            }else{
                ub=mid;
            }
        }
        System.out.println(ub * 100);
    }
}