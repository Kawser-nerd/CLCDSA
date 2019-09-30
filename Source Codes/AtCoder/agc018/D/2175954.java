import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main{

    static class Edge{
        int to;
        long cost;
        Edge(int to,long cost){
            this.to=to;
            this.cost=cost;
        }
    }
    static List<Edge>[] eList;
    static int[] size;
    static boolean[] used;

    static int dfs(int v){
        int sz = 1;
        used[v]=true;
        for(Edge e : eList[v])if(!used[e.to]){
            sz += dfs(e.to);
        }
        return size[v] = sz;
    }

    static long dfs2(int root){
        long res = 0;
        used[root]=true;
        for(Edge e : eList[root])if(!used[e.to]){
            res += e.cost*2*size[e.to] + dfs2(e.to);
        }
        return res;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        eList = new ArrayList[N];
        size = new int[N];
        used = new boolean[N];
        for(int i=0;i<N;++i)eList[i]=new ArrayList<>();
        for(int i=0;i<N-1;++i){
            int a=scan.nextInt()-1;
            int b=scan.nextInt()-1;
            long c=scan.nextLong();
            eList[a].add(new Edge(b,c));
            eList[b].add(new Edge(a,c));
        }
        dfs(0);
        int root = 0;
        Arrays.fill(used,false);
        while(true){
            if(used[root])break;
            used[root]=true;
            for(Edge e : eList[root]){

                if(!used[e.to]&&size[e.to]>N/2){
                    root = e.to;
                    break;
                }
            }
        }
        Arrays.fill(used,false);
        dfs(root);
        Arrays.fill(used,false);
        long ans = dfs2(root);
        long def = Long.MAX_VALUE;
        for(Edge e : eList[root])def=Math.min(def,e.cost);
        for(Edge e : eList[root])if(N%2==0 && size[e.to]==N/2)def=e.cost;
        System.out.println(ans-def);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.