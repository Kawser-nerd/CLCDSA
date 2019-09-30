import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Main{
    static List<Integer> edges[];
    static int white[];
    static boolean nibu=true;
    static void bfs(int v, int c){
        if(white[v]>=0){
            if(c%2!=white[v])nibu=false;
            return;
        }
        white[v]=c;
        for(int u :edges[v])bfs(u, (c+1)%2);
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        boolean[][] edge = new boolean[N][N];
        for(boolean[] arr: edge)Arrays.fill(arr, false);
        while(M-->0){
            int a = scan.nextInt()-1;
            int b = scan.nextInt()-1;
            edge[a][b]=true;
            edge[b][a]=true;
        }
        edges = new ArrayList[N];
        white = new int[N];
        Arrays.fill(white, -1);
        for(int i=0;i<N;++i)edges[i]=new ArrayList<>();
        int root = -1;
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<N;++i)for(int j=i+1;j<N;++j)if(!edge[i][j]){
            edges[i].add(j);
            edges[j].add(i);
            set.add(i);
            set.add(j);
        }
        List<Integer> n = new ArrayList<>();
        List<Integer> m = new ArrayList<>();
        for(int i=0;i<N;++i){
            if(set.contains(i) && white[i]<0){
                bfs(i, 0);
            }
            int nn=0,mm=0;
            for(int j=0;j<N;++j){
                if(white[j]==0)++nn;
                if(white[j]==1)++mm;
                if(white[j]==0||white[j]==1)white[j]=2;
            }
            if(mm>nn){
                int tmp=mm;
                mm=nn;nn=tmp;
            }
            n.add(nn);
            m.add(mm);
        }
        if(!nibu){
            System.out.println(-1);
        }else{
            int amari = 0;
            for(int i=0;i<N;++i){
                if(white[i]<0)++amari;
            }
            List<Integer> sub = new ArrayList<>();
            for(int i=0;i<n.size();++i)sub.add(n.get(i)-m.get(i));
            boolean[][] dp =new boolean[N+1][N];
            dp[0][0]=true;
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(dp[i][Math.abs(j-sub.get(i))])dp[i+1][j]=true;
                    if(j+sub.get(i)<N && dp[i][j+sub.get(i)])dp[i+1][j]=true;
                }
            }
            int s=0;
            for(int i=0;i<N;++i)if(dp[N][i]){
                s=i;break;
            }
            int left=0,right=N;
            if(s<amari){
                left=N/2;right=N-left;
            }else{
                s-=amari;
                while(right-left>s){
                    left++;--right;
                }
            }
            System.out.println((left*(left-1))/2 + (right*(right-1)/2));
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.