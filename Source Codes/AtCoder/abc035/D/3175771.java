import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] distGo = new long[N+1];
        long[] distBack = new long[N+1];
        int M = sc.nextInt();
        int T = sc.nextInt();
        HashMap<Integer,Long>[] go = new HashMap[N+1];
        HashMap<Integer,Long>[] back = new HashMap[N+1];
        for(int i=0;i<=N;i++) {
            back[i]=new HashMap<>();
            go[i]=new HashMap<>();
        }
        long[] A = new long[N+1];
        for(int i=1;i<=N;i++) A[i]=sc.nextLong();
        int[] a = new int[M];
        int[] b = new int[M];
        long[] c = new long[M];
        for(int i=0;i<M;i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextLong();
        }
        for(int i=0;i<M;i++){
            go[a[i]].put(b[i],c[i]);
            back[b[i]].put(a[i],c[i]);
        }
        Dijkstra(distGo, go);
        Dijkstra(distBack,back);
        long ans = 0;
        for(int i=1;i<=N;i++){
            if(distGo[i]== Long.MAX_VALUE||distBack[i]== Long.MAX_VALUE) continue;
            long cur = (long)T-distGo[i]-distBack[i];
            if(cur>0) ans = Math.max(ans,cur*A[i]);
        }
        System.out.println(ans);

    }
    static void Dijkstra(long[] dist, HashMap<Integer,Long>[] map){
        HashSet<Long> fixed = new HashSet<>();
        Arrays.fill(dist,Long.MAX_VALUE);
        dist[1]=0;
        myComparator mc = new myComparator();
        PriorityQueue<long[]> pq = new PriorityQueue<>(10,mc);
        pq.add(new long[]{1,0});
        while(pq.size()>0){
            long[] cur = pq.poll();
            if(fixed.contains(cur[0])) continue;
            fixed.add(cur[0]);
            int now = (int) cur[0];
            for(Integer w:map[now].keySet()){
                if(!fixed.contains(w)){
                    if(dist[w]>dist[now]+map[now].get(w)){
                        dist[w] = dist[now]+map[now].get(w);
                        pq.add(new long[]{w,dist[w]});
                    }
                }
            }
        }
    }
    static class myComparator implements Comparator<long[]>{
        public int compare(long[] a, long[] b){
            if(a[1]<b[1]) return -1;
            else if(a[1]==b[1]) return 0;
            return 1;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.