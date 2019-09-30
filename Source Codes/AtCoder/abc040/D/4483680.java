/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
?????????????????????????ex.-1/2=0??????>k??????????????????
???>=k???????????????
toLowerCase()???????????????????????????
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
        int n=sc.nextInt(),m=sc.nextInt();
        Queue<Point>[] road=new ArrayDeque[200001];
        for (int i = 0; i < m; i++) {
            int a=sc.nextInt(),b=sc.nextInt(),y=sc.nextInt();
            if(road[y]==null)road[y]=new ArrayDeque<>();
            road[y].add(new Point(a,b));
        }
        int q=sc.nextInt();
        Queue<Point>[] resident=new ArrayDeque[200001];
        for (int i = 0; i < q; i++) {
            int v=sc.nextInt(),w=sc.nextInt();
            if(resident[w]==null)resident[w]=new ArrayDeque<>();
            resident[w].add(new Point(i,v));
        }
        UF.init(n+1);
        int[] ans=new int[q];
        for (int i = 200000; i > -1; i--) {
            while (resident[i]!=null&&resident[i].size()>0){
                Point p=resident[i].poll();
                ans[p.x]=UF.us(p.y);
            }
            while (road[i]!=null&&road[i].size()>0){
                Point p=road[i].poll();
                UF.unite(p.x,p.y);
            }
        }
        for (int k:ans)out.println(k);
    }
    //Union Find?
    static class UF{
        static int[] par;
        static int[] size;
        static int[] rank;
        //???
        static void init(int n){
            par=new int[n];
            size=new int[n];
            rank=new int[n];
            for (int i = 0; i <n ; i++) {
                par[i]=i;
                size[i]=1;
                rank[i]=0;
            }
        }
        //?????
        static int root(int x){
            if(par[x]==x){
                return x;
            }else{
                return par[x]=root(par[x]);
            }
        }
        //?????????
        static boolean same(int x,int y){
            return root(x)==root(y);
        }
        //??
        static void unite(int x,int y){
            x=root(x);
            y=root(y);
            if(x==y)return;
            if(rank[x]<rank[y]){
                par[x]=y;
                size[y]+=size[x];
            }else {
                par[y]=x;
                size[x]+=size[y];
                if(rank[x]==rank[y])rank[x]++;
            }
        }
        //a?????????
        static int us(int a){
            return size[root(a)];
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.