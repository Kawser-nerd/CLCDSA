import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
class Main{

    static int[] a;
    static int[] b;
    static int N;
    static int getMaxk(){
        int res = -1;
        for(int i=0;i<N;++i){
            for(int j=1;j<a[i];++j){
                if(a[i]==b[i])continue;
                if(a[i]%j==b[i] || a[i]%j > b[i]*2){
                    res = Math.max(res,j);
                    break;
                }
            }
        }
        return res;
    }

    static boolean chk(){
        for(int i=0;i<N;++i)if(a[i]!=b[i])return false;
        return true;
    }

    static class Edge{
        int to,cost;
        Edge(int to,int cost){
            this.to=to;
            this.cost=cost;
        }
    }

    static List<Edge> edgeList[];
    static int getMaxCost(int s,int t,int res){
        if(s==t)return res;
        int c = 100;
        if(s<=2*t)return 100;
        for(Edge e : edgeList[s]){
            c=Math.min(c,getMaxCost(e.to, t, Math.max(e.cost,res)));
        }
        return c;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        a = new int[N];
        b = new int[N];
        for(int i=0;i<N;++i)a[i]=scan.nextInt();
        for(int i=0;i<N;++i)b[i]=scan.nextInt();
        long ans = 0;

        edgeList = new ArrayList[51];
        for(int i=1;i<=50;++i)edgeList[i]=new ArrayList<>();
        for(int i=1;i<=50;++i){
            for(int j=1;j<=i;++j){
                edgeList[i].add(new Edge(i%j,j));
            }
        }



        while(true){
            int k = 0;
            for(int i=0;i<N;++i)k = Math.max(k,getMaxCost(a[i], b[i], 0));
            if(k==0)break;
            if(k==100){
                ans=-1;
                break;
            }
            for(int i=k;i<=50;++i){
                edgeList[i].get(k-1).cost=0;
            }
            ans += ((long)1<<k);
        }
        System.out.println(ans);

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.