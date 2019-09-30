import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        int M = sc.nextInt();
        int[] l1 = new int[N+1];
        int ans = 0;
        for(int i = 1;i < N+1;i++)  l1[i] = -1;
        for(int i = 0;i < M;i++){
            int ai = sc.nextInt();
            int bi = sc.nextInt();
            l1[bi] = Math.max(ai, l1[bi]);
        }
        int right = N;
        int left = 0;
        while(true){
            if(right == 1)  break;
            if(l1[right] > 0){
                left = l1[right];
            }else{
                right--;
                continue;
            }
            while(true){
                if(left == right){
                    ans++;
                    break;
                }
                left = Math.max(left, l1[right]);
                right--;
            }
        }
        System.out.println(ans);
    }
}