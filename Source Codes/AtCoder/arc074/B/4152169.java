import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        PriorityQueue<Integer> mae = new PriorityQueue<Integer>();
        PriorityQueue<Integer> ato = new PriorityQueue<Integer>((Integer x1, Integer x2) -> x2 - x1);
        long[] maeSum = new long[N+1];
        long[] atoSum = new long[N+1];
        long ans = Long.MIN_VALUE;
        int[] A = new int[N * 3];
        for (int i = 0; i < N * 3; i++) {
            int a = sc.nextInt();
            A[i] = a;
            if (i < N) {
                mae.add(a);
                maeSum[0] += a;
            } else if (i >= N * 2) {
                ato.add(a);
                atoSum[N] += a;
            }
        }
        for (int i = N; i < N * 2; i++) {
            int k = i - (N-1);
            if(A[i] > mae.peek()){
                maeSum[k] = maeSum[k - 1] - mae.poll() + A[i];
                mae.add(A[i]);
            }else{
                maeSum[k] = maeSum[k - 1];
            }
        }
        for(int i = N *2 -1; i >= N; i--){
            int k = i - N;
            if(A[i] < ato.peek()){
                atoSum[k] = atoSum[k + 1] - ato.poll() + A[i];
                ato.add(A[i]);
            }else{
                atoSum[k] = atoSum[k + 1];
            }
        }
        for(int i = 0; i <= N; i++){
            ans = Math.max(ans, maeSum[i] - atoSum[i]);
        }
        System.out.println(ans);
        sc.close();
    }

}