import java.util.*;

class Main{
    static ArrayList<Integer>[] map;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        if(x==1){
            System.out.println(n-2);
            System.exit(0);
        }
        map = new ArrayList[n+1];
        for(int i=0;i<=n;i++) map[i]=new ArrayList<>();
        for(int i=0;i<n-1;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            map[a].add(b);
            map[b].add(a);
        }
        long ans = 0;
        for(int i=1;i<=n;i++){
            int first=1,second=0;
            for(int w:map[i]){
                int[] cur = dfs(w,i,x/2-1);
                first+=cur[0];
                second = Math.max(second,cur[1]);
            }
            if(x%2==1) first+=second;
            ans =Math.max(ans,first);
        }
        System.out.println(n-ans);
    }
    static int[] dfs(int root, int from, int level){
        if(level==0) return new int[]{1,map[root].size()-1};
        int first=1,second=0;
        for(int w:map[root]){
            if(w==from) continue;
            int[] cur = dfs(w,root,level-1);
            first += cur[0];
            second += cur[1];
        }
        return new int[]{first,second};
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.