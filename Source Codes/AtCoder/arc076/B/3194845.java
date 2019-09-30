import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] rec = new int[N][];
        int[] a = new int[N];
        int[] b = new int[N];
        for(int i=0;i<N;i++){
            a[i]=sc.nextInt();
            b[i]=sc.nextInt();
        }
        for(int i=0;i<N;i++){
            int x = a[i];
            int y = b[i];
            rec[i] = new int[]{i,x,y};
        }
        ArrayList<Edge>[] map = new ArrayList[N];
        for(int i=0;i<N;i++) map[i]=new ArrayList<>();
        Arrays.sort(rec, new myComX());
        for(int i=0;i<N-1;i++){
            int dist = rec[i+1][1]-rec[i][1];
            map[rec[i][0]].add(new Edge(rec[i+1][0],dist));
            map[rec[i+1][0]].add(new Edge(rec[i][0],dist));
        }
        Arrays.sort(rec,new myComY());
        for(int i=0;i<N-1;i++){
            int dist = rec[i+1][2]-rec[i][2];
            map[rec[i][0]].add(new Edge(rec[i+1][0],dist));
            map[rec[i+1][0]].add(new Edge(rec[i][0],dist));
        }
        HashSet<Integer> vis = new HashSet<>();
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        vis.add(0);
        for(Edge e:map[0]) pq.add(e);
        long ans = 0;
        while(vis.size()<N){
            Edge cur = pq.poll();
            int now = cur.to;
            if(vis.contains(now)) continue;
            vis.add(now);
            ans += cur.len;
            for(Edge e:map[now]){
                if(!vis.contains(e.to)) pq.add(e);
            }
        }
        System.out.println(ans);
    }

    static class myComX implements Comparator<int[]>{
        public int compare(int[] a, int[] b){return a[1]-b[1];}
    }
    static class myComY implements Comparator<int[]>{
        public int compare(int[] a, int[] b){return a[2]-b[2];}
    }
    static class Edge implements Comparable<Edge>{
        int to;
        int len;

        public Edge(int t, int l){
            this.to = t;
            this.len = l;
        }

        @Override
        public int compareTo(Edge o) {
            return this.len-o.len;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.