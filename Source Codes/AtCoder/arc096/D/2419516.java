import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

@SuppressWarnings("unchecked")
class Main{

    static List<Integer> edges[];
    static long[] m;
    static long[] w;
    static long[] v;
    static long dfs(int p){
        w[p] += m[p];
        v[p] = 1;
        for(int q : edges[p]){
            w[p] += dfs(q);
            v[p] += v[q];
        }
        return w[p];
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N  =scan.nextInt();
        int X =scan.nextInt();
        int D = scan.nextInt();
        m = new long[N];
        edges = new ArrayList[N];
        for(int i=0;i<N;++i)edges[i]=new ArrayList<>();
        m[0] = scan.nextLong();
        for(int i=1;i<N;++i){
            m[i]=scan.nextLong();
            edges[scan.nextInt()-1].add(i);
        }
        w = new long[N];
        v = new long[N];
        dfs(0);
        long[] dp = new long[50*50*50+1];
        Arrays.fill(dp, Long.MAX_VALUE/2);
        dp[0]=0;
//      dp[i][Y] : i?????Y??????????
//      dp[i][Y] = min(dp[i-1][Y-Yj]+Xj , dp[i-1][Y-2*Yj]+2*Xj, ..., dp[i-1][Y-50*Yj]+50*Xj);
//      (X0, Y0) , (X1, Y1), ..., (XN-1, YN-1)?? (X0, Y0), (X0*2, Y0*2), (X0*4, Y0*4), ..., (XN-1*32, YN-1*32) ..01??????
//      dp[i][Y] = Math.min(dp[i-1][Y], dp[i-1][Y-Yj]+Xj);
        for(int i=0;i<N;++i){
            int z = (i==0 ? 50 : Math.min(50,D));
            for(int k=0;z>0;++k){
                int kk = Math.min(z, (1<<k));
                z -= kk;
                for(int y=50*50*50;y>=0;--y)if(y-v[i]*kk>=0)dp[y]=Math.min(dp[y], dp[y-(int)v[i]*kk]+w[i]*(long)kk);
            }
        }

        class eff{
            double xy;
            int id;
            eff(double xy,int id){this.xy=xy;this.id=id;}
        }
        List<eff> list = new ArrayList<>();
        for(int i=0;i<N;++i)list.add(new eff((double)w[i]/(double)v[i], i));
        Collections.sort(list, (a,b)->a.xy > b.xy ? 1:-1);

        long ans = 0;
        for(int y=0;y<=50*50*50;++y){
            //id!=0???D-50?? id==0??????
            long x = X-dp[y];
            long n = y;
            if(x<0)continue;
            for(int i=0;i<N;++i){
                int id = list.get(i).id;
                if(id==0 || Math.max(0,D-50)*w[id]>=x){
                    n += (x/w[id])*v[id];
                    break;
                }else{
                    n += v[id]*Math.max(0,D-50);
                    x -= w[id]*Math.max(0,D-50);
                }
            }
            ans = Math.max(ans, n);
        }
        System.out.println(ans);
    }
}