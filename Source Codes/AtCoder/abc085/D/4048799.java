import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        int H = sc.nextInt();
        int[] B = new int[N];
        int AM = 0;
        for(int i = 0;i < N;i++){
            int ai = sc.nextInt();
            int bi = sc.nextInt();
            AM = Math.max(AM, ai);
            B[i] = bi;
        }
        Arrays.sort(B);
        long ans = 0;
        for(int i = N-1;i >= 0;i--){
            if(B[i] > AM){
                H -= B[i];
                ans++;
                if(H <= 0)  break;
            }
            if(B[i] <= AM || i == 0){
                ans += H/AM;
                if(H%AM != 0)   ans++;
                break;
            }
        }
        System.out.println(ans);
    }
}