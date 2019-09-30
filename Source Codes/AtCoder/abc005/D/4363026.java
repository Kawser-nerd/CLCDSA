import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] D = new int[N+1][N+1];
        for (int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                D[i][j] = sc.nextInt();
            }
        }

        int Q = sc.nextInt();
        int[] P = new int[Q];
        for(int i = 0; i < Q; i++){
            P[i] = sc.nextInt();
        }


        // 2?? ??? ????
        int[][] DAccum = new int[N+1][N+1];
        for(int i = 1; i <= N; i++){
            DAccum[i][1] = D[i][1];
            for (int j = 2; j <= N; j++) {
                DAccum[i][j] = DAccum[i][j - 1] + D[i][j];
            }
        }
        for(int i = 2; i <= N; i++){
            for(int j = 1; j <= N; j++){
                DAccum[i][j] += DAccum[i-1][j];
            }
        }

        //for(int i = 0; i <= N; i++){
        //    for(int j = 0; j <= N; j++){
        //        out.print(DAccum[i][j]+",");
        //    }
        //    out.println();
        //}

        // ???????????
        int[][] maxYummy = new int[N+1][N+1];   //???????????????(???)
        for(int[] row: maxYummy){ Arrays.fill(row, -1); }

        for(int p: P){
            int max = 0;
            for(int i = 1; i <= p; i++){
                int x = p / i;
                int y = p / x;

                int tmp_max = 0;

                x = Math.min(x, N);
                y = Math.min(y, N);

                if(maxYummy[x][y] != -1){
                    tmp_max = maxYummy[x][y];
                } else {
                    //out.println(x + "," + y + ";" + tmp_max + "->" + max);
                    for (int x1 = 1; x1 + x - 1 <= N; x1++) {
                        for (int y1 = 1; y1 + y - 1 <= N; y1++) {
                            int[] upperLeft = {x1 - 1, y1 - 1};
                            int[] lowerRight = {x1 + x - 1, y1 + y - 1};

                            int yummy = DAccum[lowerRight[0]][lowerRight[1]]
                                    - DAccum[lowerRight[0]][upperLeft[1]]
                                    - DAccum[upperLeft[0]][lowerRight[1]]
                                    + DAccum[upperLeft[0]][upperLeft[1]];

                            //out.println("=>" + x1 + "," + y1 + ";" + yummy);
                            tmp_max = Math.max(yummy, tmp_max);
                        }
                    }
                    maxYummy[x][y] = tmp_max;
                }
                max = Math.max(max, tmp_max);
            }
            out.println(max);
        }
    }
}