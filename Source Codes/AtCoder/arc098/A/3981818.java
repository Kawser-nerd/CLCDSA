import java.util.*;

public class Main{
    public static void main(String[] argc){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();
        int total_E = 0;
        int[] x = new int[N+1];
        x[0] = 0;

        for(int i=0;i<N;i++){
            if(S.charAt(i) == 'E'){
                total_E++;
                x[i+1] = x[i] + 1;
            }else{
                x[i+1] = x[i];
            }
        }

        int ans = (int) 1e9;

        for(int i=0;i<N;i++){
            ans = Math.min(ans, total_E + i - x[i+1] -x[i]);
        }

        System.out.println(ans);
    }
}