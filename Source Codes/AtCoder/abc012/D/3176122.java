import java.util.*;

class Main{
    static int N;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int M = sc.nextInt();
        HashMap<Integer,Integer>[] map = new HashMap[N+1];
        for(int i=0;i<=N;i++) map[i]=new HashMap<>();
        for(int i=0;i<M;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int t = sc.nextInt();
            map[a].put(b,t);
            map[b].put(a,t);
        }
        int ans = Integer.MAX_VALUE;
        for(int i=1;i<=N;i++){
            ans = Math.min(ans,Dijkstra(i,map));
        }
        System.out.println(ans);
    }
    static int Dijkstra(int start, HashMap<Integer,Integer>[] map){
        HashSet<Integer> fixed = new HashSet<>();
        int[] dist = new int[N+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[start]=0;
        myComparator mc = new myComparator();
        PriorityQueue<int[]> pq = new PriorityQueue<>(10,mc);
        pq.add(new int[]{start,0});
        while(pq.size()>0){
            int[] cur = pq.poll();
            int now = cur[0];
            if(fixed.contains(now)) continue;
            fixed.add(now);
            dist[now]=cur[1];
            for(Integer w:map[now].keySet()){
                if(!fixed.contains(w)){
                    if(dist[w]>dist[now]+map[now].get(w)){
                        dist[w] = dist[now]+map[now].get(w);
                        pq.add(new int[]{w,dist[w]});
                    }
                }
            }
        }
        int ans = Integer.MIN_VALUE;
        for(int i=1;i<=N;i++){
            ans = Math.max(ans,dist[i]);
        }
        return ans;
    }
    static class myComparator implements Comparator<int[]>{
        public int compare(int[] a, int[] b){
            return a[1]-b[1];
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.