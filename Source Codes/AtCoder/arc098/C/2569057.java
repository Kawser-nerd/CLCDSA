import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N  =scan.nextInt();
        int K = scan.nextInt();
        int Q = scan.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        for(int i=0;i<N;++i){
            A[i]=scan.nextInt();
            B[i]=A[i];
        }
        Arrays.sort(B);
        int ans = 1000000001;
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for(int i=0;i<N;++i){
            if(i+Q-1>=N || B[i+Q-1]-B[i]>=ans)continue;
            int left=-1, right=ans;
            while(right-left>1){
                int center=(right+left)/2;
                int cnt=0;
                que.clear();
                for(int j=0;j<N;++j){
                    if(A[j]<B[i])que.clear();
                    else{
                        que.add(A[j]);
                        if(que.size()>=K){
                            if(que.poll()-B[i]<=center)++cnt;
                            if(cnt>=Q){
                                break;
                            }
                        }
                    }
                }
                if(cnt>=Q)right=center;
                else left=center;
            }
            ans = Math.min(ans, right);
        }
        System.out.println(ans);


    }
}