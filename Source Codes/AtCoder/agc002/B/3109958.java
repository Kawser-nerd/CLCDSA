import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] x = new int[M];
        int[] y = new int[M];
        for(int i=0;i<M;i++){
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        int[] num = new int[N+1];
        Arrays.fill(num,1);
        boolean[] red = new boolean[N+1];
        red[1]=true;
        for(int i=0;i<M;i++){
            int from = x[i];
            int to = y[i];
            if(red[from]) red[to]=true;
            num[from]--;
            num[to]++;
            if(num[from]==0) red[from]=false;
        }
        int ans = 0;
        for(int i=1;i<=N;i++){
            if(red[i]) ans++;
        }
        System.out.println(ans);
    }
}