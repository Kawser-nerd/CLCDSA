import java.util.*;

public class Main {
  Scanner sc = new Scanner(System.in);
  void solve(){
       int H = sc.nextInt();
        int W = sc.nextInt();
        int[][] C = new int[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int x = sc.nextInt();
                if ((i + j) % 2 == 0)
                    C[i][j] = x;
                else
                    C[i][j] = -x;
            }
        }

        for (int i = 1; i < H; i++) {
            for (int j = 0; j < W; j++) {
                C[i][j] += C[i - 1][j];
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 1; j < W; j++) {
                C[i][j] += C[i][j - 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < H; i++) {
            for (int j = i; j < H; j++) {
                for (int k = 0; k < W; k++) {
                    for (int l = k; l < W; l++) {
                        int tmp = C[j][l];
                        if (i > 0) tmp -= C[i - 1][l];
                        if (k > 0) tmp -= C[j][k - 1];
                        if (i > 0 && k > 0) tmp += C[i - 1][k - 1];
                        if (tmp == 0) {
                            ans = Math.max(ans, (j - i + 1) * (l - k + 1));
                        }
                    }
                }
            }
        }  
      
        System.out.println(ans);      
  }    
  
  public static void main(String[] args) {
         Scanner s = new Scanner(System.in);    
         Main main = new Main();         
         main.solve();                 
  }
  
}