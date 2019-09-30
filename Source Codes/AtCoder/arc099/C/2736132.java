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
        if(white[v]>=0){if(c%2!=white[v])nibu=false;}
        else{
            white[v]=c;
            for(int u :edges[v])bfs(u, (c+1)%2);
        }
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        boolean[][] edge = new boolean[N][N];
        while(M-->0){
            int a = scan.nextInt()-1;
            int b = scan.nextInt()-1;
            edge[a][b]=edge[b][a]=true;
        }
        edges = new ArrayList[N];
        white = new int[N];
        Arrays.fill(white, -1);
        for(int i=0;i<N;++i)edges[i]=new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<N;++i)for(int j=i+1;j<N;++j)if(!edge[i][j]){
            edges[i].add(j);
            edges[j].add(i);
            set.add(i);
            set.add(j);
        }
        List<Integer> sub = new ArrayList<>();
        for(int i=0;i<N;++i){
            if(set.contains(i) && white[i]<0)bfs(i, 0);
            int nn=0,mm=0;
            for(int j=0;j<N;++j){
                if(white[j]==0)++nn;
                if(white[j]==1)++mm;
                if(white[j]>=0)white[j]=2;
            }
            sub.add(Math.abs(nn-mm));
        }
        if(!nibu)System.out.println(-1);
        else{
            int amari = 0;
            for(int i=0;i<N;++i)if(white[i]<0)++amari;
            boolean[][] dp =new boolean[N+1][N];
            dp[0][0]=true;
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(dp[i][Math.abs(j-sub.get(i))])dp[i+1][j]=true;
                    if(j+sub.get(i)<N && dp[i][j+sub.get(i)])dp[i+1][j]=true;
                }
            }
            int s=0;
            for(int i=N-1;i>=0;--i)if(dp[N][i])s=i;
            int left=-1,right=s-1;
            while(++left + ++right < N-amari);
            while(amari-->0){
                if(right>left)++left;
                else ++right;
            }
            System.out.println((left*(left-1))/2 + (right*(right-1)/2));
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.