import java.util.*;

public class Main {


    public static void main(String[] args) {
        new Main().execute();
    }

    public void execute() {
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        int T[] = new int[N];

        for (int i = 0; i < N; i++) {
            T[i] = sc.nextInt();
        }

        int minTime = Integer.MAX_VALUE;

        for (int ptn = 0, bound = 1 << N; ptn < bound; ptn++) {
            boolean [] pattern = getPatten(N,ptn);
            int nikuTimeA = 0;
            int nikuTimeB = 0;
            for (int i=0; i<N; i++){
                if (pattern[i]){
                    nikuTimeA += T[i];
                }else{
                    nikuTimeB += T[i];
                }
            }
            int nikuTime = Math.max(nikuTimeA, nikuTimeB);
            minTime = Math.min(minTime, nikuTime);
        }

        System.out.println(minTime);

        sc.close();
    }

    private boolean[] getPatten(int n, int ptn) {
        boolean[] pattern = new boolean[n];
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            if ((ptn & mask) > 0) {
                pattern[i] = true;
            }
        }
        return pattern;
    }
}