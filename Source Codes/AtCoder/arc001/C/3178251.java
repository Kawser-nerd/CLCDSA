import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int bias = 100;
        int A = sc.nextInt();
        int B = sc.nextInt();
        if(A==B){
            System.out.println(0);
            System.exit(0);
        }
        HashSet<Integer> fixed = new HashSet<>();
        int[] dic = new int[]{1,5,10,-1,-5,-10};
        B = Math.abs(B-A)+bias;
        int[] dist = new int[2*bias+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[bias]=0;
        myComparator mc = new myComparator();
        PriorityQueue<int[]> pq = new PriorityQueue<>(10,mc);
        pq.add(new int[]{bias,0});
        while(!fixed.contains(B)){
            int[] cur = pq.poll();
            int now = cur[0];
            if(fixed.contains(now)) continue;
            fixed.add(now);
            dist[now]=cur[1];
            for(int w:dic){
                if(!fixed.contains(now+w)){
                    if(now+w>2*bias||now+w<0) continue;
                    if(dist[now+w]>dist[now]+1){
                        dist[now+w]=dist[now]+1;
                        pq.add(new int[]{now+w,dist[now]+1});
                    }
                }
            }
        }
        int ans = dist[B];
        System.out.println(ans);
    }
    static class myComparator implements Comparator<int[]>{
        public int compare(int[] a, int[] b){
            return a[1]-b[1];
        }
    }
}