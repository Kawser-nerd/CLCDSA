import java.util.*;

class Main{
    static HashSet<Integer> seen = new HashSet<>();
    static long[] frac = new long[17];
    static HashSet<Integer>[] map;
    static int[] degree = new int[17];
    static HashMap<Integer,Long> dp = new HashMap<>();
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        map = new HashSet[n+1];
        frac[0] = 1;
        for(int i=1;i<17;i++) frac[i] = i*frac[i-1];
        for(int i=0;i<=n;i++) map[i] = new HashSet<>();
        for(int i=0;i<m;i++){
            int s = sc.nextInt();
            int t = sc.nextInt();
            map[s].add(t);
            seen.add(s); seen.add(t);
            degree[t]++;
        }
        long topo = dfs(0);
        int sz = seen.size();
        long com = frac[n]/frac[sz]/frac[n-sz];
        long ans = frac[n-sz]*topo*com;
        System.out.println(ans);
    }
    static long  dfs(int state){
        if(dp.containsKey(state)) return dp.get(state);
        if(count(state)==seen.size()){
            dp.put(state,1L);
            return 1;
        }
        long ans = 0;
        for(int w:seen){
            if((state&(1<<w))>0||degree[w]>0) continue; // already taken or not ready to be taken
            state |= 1<<w;
            for(int s:map[w]) degree[s]--;
            ans += dfs(state);
            state &= ~(1<<w);
            for(int s:map[w]) degree[s]++;
        }
        dp.put(state,ans);
        return ans;
    }
    static int count(int i){
        int cnt = 0;
        while(i>0){
            cnt += i%2;
            i /= 2;
        }
        return cnt;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.