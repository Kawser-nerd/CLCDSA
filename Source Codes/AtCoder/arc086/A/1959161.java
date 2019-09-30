import java.util.PriorityQueue;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n= scan.nextInt();
        int k = scan.nextInt();
        int cnt[] = new int[n];
        for(int i=0;i<n;++i){
            int m = scan.nextInt() -1;
            cnt[m]++;
        }
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for(int i=0;i<n;++i){
            if(cnt[i]>0)que.add(cnt[i]);
        }
        int ans = 0;
        while(que.size() > k)ans += que.poll();
        System.out.println(ans);
    }
}