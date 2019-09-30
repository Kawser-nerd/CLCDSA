import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

class Main{

    static Set<Integer> edges[];
    static boolean[] isWhite;
    static boolean[] used;
    static boolean[] stamped;
    static int path=Integer.MIN_VALUE;

    static int dfs1(int v){
        used[v]=true;
        int res=0;
        int cnt=0;
        for(int u : edges[v]){
            if(used[u])continue;
            int d = dfs1(u);
            if(d>=0){
                res+=d+2;++cnt;
            }
        }
        if(cnt==0&&!isWhite[v])return -1;
        if((isWhite[v]&&cnt%2==1) || (!isWhite[v]&&cnt%2==0)){
            stamped[v]=true;++res;
        }
        return res;
    }
    static int longest(int v){
        used[v]=true;
        PriorityQueue<Integer> que = new PriorityQueue<>(Collections.reverseOrder());
        que.add(0);que.add(0);
        for(int u:edges[v]){
            if(used[u])continue;
            que.add(longest(u));
        }
        int res = que.peek() + (stamped[v] ? 2:0);
        path = Math.max(path, que.poll() + que.poll() + (stamped[v] ? 2:0));
        return res;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N =scan.nextInt();
        edges = new HashSet[N];
        isWhite = new boolean[N];
        used = new boolean[N];
        stamped = new boolean[N];
        for(int i=0;i<N;++i)edges[i]=new HashSet<>();
        for(int i=0;i<N-1;++i){
            int x = scan.nextInt()-1;
            int y = scan.nextInt()-1;
            edges[x].add(y);
            edges[y].add(x);
        }
        String C = scan.next();
        for(int i=0;i<N;++i)isWhite[i]=C.charAt(i)=='W';
        int root = -1;
        for(int i=0;i<N;++i)if(isWhite[i])root=i;
        if(root==-1){
            System.out.println(0);return;
        }
        int ans = 0;
        int cnt = 0;
        used[root]=true;
        for(int u : edges[root]){
            int d = dfs1(u);
            if(d>=0){
                ans+=d+2;++cnt;
            }
        }
        if((!isWhite[root]&&cnt%2==1) || (isWhite[root]&&cnt%2==0)){
            stamped[root]=true;++ans;
        }
        if(ans==1){
            System.out.println(1);return;
        }
        Arrays.fill(used, false);
        longest(root);
        System.out.println(ans - path);


    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.