import java.util.*;
import java.io.*;

public class Main{

  public static void main(String[] args) {
    try(BufferedReader in = new BufferedReader(new InputStreamReader(System.in))){
      String[] NMQ = in.readLine().split(" ");
      int N = Integer.parseInt(NMQ[0]);
      int M = Integer.parseInt(NMQ[1]);
      int Q = Integer.parseInt(NMQ[2]);

      boolean[][] S = new boolean[N][M];
      for(int i = 0; i < N; i++){
        String a =  in.readLine();
        for(int j = 0; j < M; j++){
          if (a.charAt(j) == '1'){
            S[i][j] = true;
          }
        }
      }

      int[][] V = new int[N][M];
      int[][] H = new int[N][M];
      int[][] E = new int[N][M];

      for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
          V[i][j] = (i-1 < 0 ? 0 : V[i-1][j]) + (j-1 < 0 ? 0 : V[i][j-1] + (S[i][j] && S[i][j-1] ? 1 : 0)) - (i-1 < 0 || j-1 < 0 ? 0 : V[i-1][j-1]);
          H[i][j] = (i-1 < 0 ? 0 : H[i-1][j] + (S[i][j] && S[i-1][j] ? 1 : 0)) + (j-1 < 0 ? 0 : H[i][j-1]) - (i-1 < 0 || j-1 < 0 ? 0 : H[i-1][j-1]);
          E[i][j] = (i-1 < 0 ? 0 : E[i-1][j]) + (j-1 < 0 ? 0 : E[i][j-1]) - (i-1 < 0 || j-1 < 0 ? 0 : E[i-1][j-1]) + (S[i][j] ? 1 : 0);
        }
      }

      for (int q = 0; q < Q ; q++) {
        String[] a =  in.readLine().split(" ");
        int x1 = Integer.parseInt(a[0]) - 1;
        int y1 = Integer.parseInt(a[1]) - 1;
        int x2 = Integer.parseInt(a[2]) - 1;
        int y2 = Integer.parseInt(a[3]) - 1;

        int e = E[x2][y2] - (x1-1 < 0 ? 0 : E[x1-1][y2]) - (y1-1 < 0 ? 0 : E[x2][y1-1]) + (x1-1 < 0 || y1-1 < 0 ? 0 :E[x1-1][y1-1]);
        int v = V[x2][y2] + (x1-1 < 0 ? 0 : -V[x1-1][y2] + V[x1-1][y1]) - V[x2][y1];
        int h = H[x2][y2] - H[x1][y2] + (y1-1 < 0 ? 0 : -H[x2][y1-1] + H[x1][y1-1]);

        System.out.println(e-v-h);
      }

    }catch(IOException e){
      e.printStackTrace();
    }
  }
}