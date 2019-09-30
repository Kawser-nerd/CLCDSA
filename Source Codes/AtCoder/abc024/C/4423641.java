import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int K = sc.nextInt();

        int L[] = new int[D];
        int R[] = new int[D];
        for(int i = 0; i < D ; i++){
            L[i] = sc.nextInt();
            R[i] = sc.nextInt();
        }

        int S[] = new int[K];
        int T[] = new int[K];
        for(int i = 0; i < K; i++){
            S[i] = sc.nextInt();
            T[i] = sc.nextInt();
        }

        List<Integer> moving = new ArrayList();  //??????
        int[] movingDay = new int[K];            //???????
        for(int k = 0; k < K; k++){
            moving.add(k);
        }

        for(int d = 0; d < D; d++){
            List<Integer> tmp_moving = new ArrayList<Integer>();
            for(int k: moving){
                if(S[k] < T[k] && L[d] <= S[k]) {          // ??????????
                    if(T[k] <= R[d]){
                        S[k] = T[k];
                    } else {
                        S[k] = Math.max(S[k], R[d]);
                    }
                } else if(S[k] > T[k] && S[k] <= R[d]) {   // ??????????
                    if(T[k] >= L[d]){
                        S[k] = T[k];
                    } else {
                        S[k] = Math.min(S[k], L[d]);
                    }
                }

                // ????
                if(S[k] == T[k]){
                    movingDay[k] = d+1;
                } else {
                    tmp_moving.add(k);
                }
            }
            moving = tmp_moving;
        }

        for(int k = 0; k < K; k++){
            out.println(movingDay[k]);
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.