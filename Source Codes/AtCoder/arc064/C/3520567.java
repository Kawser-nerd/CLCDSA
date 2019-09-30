import java.util.*;
import java.io.*;

import static java.lang.System.in;

class Main{
    static ArrayList<Edge>[] map;
    static int n;
    public static void main(String[] args)throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        String temp;
        String[] buf;
        Scanner sc = new Scanner(System.in);
        temp = reader.readLine();
        buf=temp.split(" ");
        double[] end = new double[]{Double.parseDouble(buf[0]),Double.parseDouble(buf[1]),Double.parseDouble(buf[2]),Double.parseDouble(buf[3])};
        temp = reader.readLine();
        buf=temp.split(" ");
        n=Integer.parseInt(buf[0]);

        double[][] point = new double[n+2][];
        point[0] = new double[]{end[0],end[1],0};
        point[n+1] = new double[]{end[2],end[3],0};
        for(int i=1;i<=n;i++){
            temp = reader.readLine();
            buf=temp.split(" ");
            point[i] = new double[]{Double.parseDouble(buf[0]),Double.parseDouble(buf[1]),Double.parseDouble(buf[2])};
        }
        map = new ArrayList[n+2];
        for(int i=0;i<n+2;i++) map[i] = new ArrayList<>();
        for(int i=0;i<n+1;i++){
            for(int j=1;j<n+2;j++){
                if(i==j) continue;
                map[i].add(new Edge(j, computeDist(point[i],point[j])));
            }
        }
        double[][] graph = new double[n+2][n+2];
        for(int i=0;i<n+2;i++) Arrays.fill(graph[i],Double.MAX_VALUE/2);
        for(int i=0;i<n+2;i++) graph[i][i] = 0;
        for(int i=0;i<n+1;i++){
            for(int j=1;j<n+2;j++){
                if(i==j) continue;
                graph[i][j] = computeDist(point[i],point[j]);
            }
        }

        long startTime = System.currentTimeMillis(); //????????


        //double ans = dijkstra();
        double ans = dij(graph);
        long endTime   = System.currentTimeMillis(); //????????
        long TotalTime = endTime - startTime;       //?????
        System.out.println(ans);
        //System.out.println(TotalTime);
    }
    static double dijkstra(){
        double dist[] = new double[n+2];
        Arrays.fill(dist,Double.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for(Edge e:map[0]) {
            pq.add(e);
            dist[e.to] = e.dist;
        }
        while(pq.size()>0){
            Edge cur = pq.poll();
            if(dist[cur.to]>cur.dist) continue;
            for(Edge e:map[cur.to]){
                if(dist[e.to]>dist[cur.to]+e.dist){
                    dist[e.to] = dist[cur.to]+e.dist;
                    pq.offer(new Edge(e.to,dist[e.to]));
                }
            }
        }
        return dist[n+1];
    }
    static double dij(double[][] graph){
        double[] dist = new double[n+2];
        Arrays.fill(dist,Double.MAX_VALUE/2);
        for(int i=0;i<n+2;i++) dist[i] = graph[0][i];
        boolean[] used = new boolean[n+2];
        used[0] = true;
        while(true){
            int v= -1;
            for(int u=1;u<=n+1;u++){
                if(!used[u]&&(v==-1||dist[u]<dist[v])) v=u;
            }
            if(v==-1) break;
            used[v] = true;
            for(int k=1;k<=n+1;k++){
                dist[k] = Math.min(dist[k],dist[v]+graph[v][k]);
            }
        }
        return dist[n+1];
    }
    static double computeDist(double[] a, double[] b){
        double r2 = Math.pow(a[0]-b[0],2)+Math.pow(a[1]-b[1],2);
        return Math.max(0.0,Math.sqrt(r2)-a[2]-b[2]);
    }
    static class Edge implements Comparable<Edge>{
        int to;
        double dist;
        public Edge(int t, double d){
            this.to = t;
            this.dist = d;
        }
        public int compareTo(Edge e){
            if(Math.abs(this.dist-e.dist)<Math.pow(10,-11)) return 0;
            return this.dist>e.dist?1:-1;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.