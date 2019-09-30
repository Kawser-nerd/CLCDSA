import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int P = sc.nextInt();
        int Q = sc.nextInt();
        int R = sc.nextInt();
        int[][] z =new int[n][m];
        for(int i=0;i<R;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            z[x-1][y-1] = sc.nextInt();
        }
        HashSet<Integer> boyCan = new HashSet<>();
        calCan(boyCan,m,Q);
        int ans = 0;
        for(Integer w:boyCan){
            int cur = w;
            ArrayList<Integer> boys = new ArrayList<>();
            for(int i=0;i<19;i++){
                if((cur&(1<<i))>0) boys.add(i);
            }
            int sum = 0;
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for(int girl=0; girl<n; girl++){
                int now = 0;
                for(int boy:boys) now += z[girl][boy];
                pq.add(now);
                sum += now;
                if(pq.size()>P) sum -= pq.poll();
            }
            ans = Math.max(ans,sum);
        }
        System.out.println(ans);
    }
    static void calCan(HashSet<Integer> boyCan, int m, int Q){
        for(int i=1;i<=(1<<m)-1;i++){
            if(numOfOne(i)==Q) boyCan.add(i);
        }
    }
    static int numOfOne(int s){
        int cnt = 0;
        while(s>0){
            if(s%2==1) cnt++;
            s = s/2;
        }
        return cnt;
    }
}