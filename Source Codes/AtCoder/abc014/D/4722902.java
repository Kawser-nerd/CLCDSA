/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
?????????????????????????ex.-1/2=0??????>k??????????????????
???>=k???????????????
toLowerCase()???????????????????????????
ArrayDeque??pop?push?Stack????????
*/
//?????Ctrl+D
import java.util.*;
import java.awt.*;
import java.awt.geom.Point2D;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        ArrayList<Integer>[] list=new ArrayList[n+1];
        for (int i = 1; i < n + 1; i++) {
            list[i]=new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int x=sc.nextInt();
            int y=sc.nextInt();
            list[x].add(y);
            list[y].add(x);
        }
        int Q=sc.nextInt();
        int[] a=new int[Q];
        int[] b=new int[Q];
        for (int i = 0; i < Q; i++) {
            a[i]=sc.nextInt();
            b[i]=sc.nextInt();
        }
        LCA.Init(n,list,1);
        for (int i = 0; i < Q; i++) {
            //out.println("a:"+LCA.depth[a[i]]+" b:"+LCA.depth[b[i]]+" LCA:"+LCA.get(a[i],b[i])+" LCA.depth:"+LCA.depth[LCA.get(a[i],b[i])]);
            out.println(LCA.depth[a[i]]+LCA.depth[b[i]]-2*LCA.depth[LCA.get(a[i],b[i])]+1);
        }
    }
    static class LCA{
        static int log2_n;
        static ArrayList<Integer>[] g;
        static int[][] parent;
        static int[] depth;
        static void Init(int n,ArrayList<Integer>[] lists,int root){
            g=lists;
            log2_n=(int)(log(n)/log(2))+1;
            parent=new int[log2_n][n+1];
            depth=new int[n+1];
            dfs(root,-1,0);
            for (int k = 0; k + 1<log2_n; k++) {
                for (int v = 1; v < n + 1; v++) {
                    if(parent[k][v]<0){
                        parent[k+1][v]=-1;
                    }else {
                        parent[k+1][v]=parent[k][parent[k][v]];
                    }
                }
            }
        }
        static void dfs(int v,int p,int d){
            parent[0][v]=p;
            depth[v]=d;
            for (Integer e:g[v]){
                if(e!=p)dfs(e,v,d+1);
            }
        }
        static int get(int u,int v) {
            if (depth[u] > depth[v]) {
                int t = u;
                u = v;
                v = t;
            }
            for (int k = 0; k < log2_n; k++) {
                if (((depth[v] - depth[u]) >> k & 1) == 1) {
                    v = parent[k][v];
                }
            }
            if (u == v) return u;
            for (int k = log2_n - 1; k >= 0; k--) {
                if(parent[k][u]!=parent[k][v]){
                    u=parent[k][u];
                    v=parent[k][v];
                }
            }
            return parent[0][u];
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.