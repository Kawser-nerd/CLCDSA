import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int N=sc.nextInt();
        int a=sc.nextInt(),b=sc.nextInt();
        int M=sc.nextInt();
        int mod=1000000007;
        int[] min=new int[N+1];
        min[a]=0;
        long[] count=new long[N+1];
        count[a]=1;
        ArrayList<Integer>[] edge=new ArrayList[N+1];
        for(int i=1;i<=N;i++)edge[i]=new ArrayList<>();
        for (int i = 0; i <M; i++) {
            int x=sc.nextInt(),y=sc.nextInt();
            edge[x].add(y);
            edge[y].add(x);
        }
        Queue<Integer> q=new ArrayDeque<>();
        q.add(a);
        Queue<Integer> dist=new ArrayDeque<>();
        dist.add(0);
        while (!q.isEmpty()){
            int vertex=q.poll();
            int d=dist.poll();
            for (Integer child:edge[vertex]){
                if(min[child]==0) {
                    q.add(child);
                    dist.add(d + 1);
                    min[child]=d+1;
                    count[child]=count[vertex];
                }else if(min[child]>d+1){
                    min[child]=d+1;
                    count[child]=count[vertex];
                }else if(min[child]==d+1){
                    count[child]=(count[child]+count[vertex])%mod;
                }
            }
        }
        out.println(count[b]);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.