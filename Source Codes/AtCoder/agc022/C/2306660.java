//package maximumcup2018;
import java.util.*;

public class Main {

    static public int n;
    static int[] A = new int[50];
    static int[] B = new int[50];

    public Boolean fun(Long bit){
        boolean[][] arr = new boolean[51][51];
        for(int i = 0; i <= 50; i++) {
                arr[i][i] = true;
        }
        for(int i = 1;i <= 50; i++){
            if((bit & (1L<<i)) != 0){
                for(int j = 0;j <= 50;j++){
                    arr[j][j%i] = true;
                }
            }
        }

        for(int k = 0;k <= 50;k++){
            for(int i = 0;i <= 50;i++){
                for(int j = 0;j <= 50;j++){
                    arr[i][j] |= arr[i][k] & arr[k][j];
                }
            }
        }

        Boolean flag = true;

        for(int i = 0;i < n;i++){
            if(!arr[A[i]][B[i]])flag = false;
        }

        return flag;

    }

    public void solve(){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        for(int i = 0;i < n;i++) {
            A[i] = sc.nextInt();
        }
        for(int i = 0;i < n;i++) {
            B[i] = sc.nextInt();
        }

        Long ans = (1L << 51) - 1;

        if(!fun(ans)) {
            System.out.println(-1);
            return;
        }

        for(int i = 51;i >= 0;i--){
            Long tmp = ans & ~(1L << i);
            if(fun(tmp))ans = tmp;
        }

        System.out.println(ans);

    }

    public static void main(String[] args){
        new Main().solve();
    }
};