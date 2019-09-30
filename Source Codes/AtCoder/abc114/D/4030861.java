import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        boolean[] pr = new boolean[N+1];
        int count = 0;
        for(int i = 2;i < N+1;i++)  pr[i] = true;
        for(int i = 2;i < N+1;i++){
            if(pr[i]){
                count++;
                for(int j = 2*i;j < N+1;j += i) pr[j] = false;
            }
        }
        final int C = count;
        int[] prn = new int[C];
        int id = 0;
        for(int i = 0;i < N+1;i++){
            if(pr[i]){
                int b = i;
                while(b <= N){
                    prn[id] += N/b;
                    b *= i;
                }
                id++;
            }
        }
        int ans = 0;
        for(int i = 0;i < C;i++){
            for(int j = 0;j < C;j++){
                for(int k = j+1;k < C;k++){
                    if(i != j && i != k && prn[i] >= 2 && prn[j] >= 4 && prn[k] >= 4) ans++;
                }
            }
        }
        for(int i = 0;i < C;i++){
            for(int j = 0;j < C;j++){
                if(i != j && prn[i] >= 2 && prn[j] >= 24)   ans++;
            }
        }
        for(int i = 0;i < C;i++){
            for(int j = 0;j < C;j++){
                if(i != j && prn[i] >= 4 && prn[j] >= 14)   ans++;
            }
        }
        if(C > 0 && prn[0] >= 74)    ans++;
        System.out.println(ans);
    }
}