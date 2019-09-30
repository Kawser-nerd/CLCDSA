import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        int N = sc.nextInt();
        
        int[] cntR = new int[R];
        int[] cntC = new int[C];
        List<List<Integer>> adjs = new ArrayList<>();
        for(int i=0; i<C; ++i) {
            adjs.add(new ArrayList<>());
        }
        for(int i=0; i<N; ++i) {
            int r = sc.nextInt() - 1;
            int c = sc.nextInt() - 1;
            cntR[r]++;
            cntC[c]++;
            adjs.get(c).add(r);
        }
        
        int[] sumR = new int[N+1];
        for(int c : cntR) {
            sumR[c]++;
        }
        
        long res = 0;
        for(int c=0; c<C; ++c) {
            int obj = K - cntC[c];
            if(obj < 0) continue;
            res += sumR[obj];
            for(int n : adjs.get(c)) {
                if(cntR[n] == obj) res--;
                if(cntR[n] == obj+1) res++;
            }
        }
        System.out.println(res);
    }
}