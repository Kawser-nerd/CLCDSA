import java.util.*;
import java.util.stream.Stream;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String first = sc.next();
        String last = sc.next();
        int n = sc.nextInt();
        
        String[] s = new String[n+2];
        for(int i=0; i<n; i++){
            s[i+1] = sc.next();
        }
        
        //?????
        if(first.equals(last)){
            System.out.println(0);
            System.out.println(first);
            System.out.println(last);
            return;
        }
        
        s[0] = first;
        s[n+1] = last;
        
        List<Integer>[] path = new ArrayList[n+2];
        for(int i=0; i<path.length; i++){
            path[i] = new ArrayList<>();
        }
        
        final int INF = 1_000_000_000;
        
        int[] cost = new int[n+2];
        for(int i=1; i<n+2; i++){
            cost[i] = INF;
        }
        
        boolean[] used = new boolean[n+2];
        
        final int FIDX = 0;
        final int LIDX = n+1;
        
        Queue<Integer> q = new ArrayDeque<>();
        q.add(FIDX);
        used[FIDX] = true;
        while(q.size() != 0){
            int now = q.poll();
            String nowStr = s[now];
            
            //used[now] = true;
            
            for(int i=0; i<n+2; i++){
                if(!used[i]){
                    int difcnt = dif(nowStr, s[i]);
                    if(difcnt == 1){
                        cost[i] = Math.min(cost[i], cost[now]+difcnt);
                        path[i].add(now);
                        q.add(i);
                        used[i] = true;
                    }
                }
            }
        }
        
        List<String> ans = new ArrayList<>();
        ans.add(last);
        
        int nowCost = cost[LIDX];
        q.add(LIDX);
        while(q.size() != 0){
            int now = q.poll();
            for(int i=0; i<path[now].size(); i++){
                int next = path[now].get(i);
                if(nowCost-cost[next] == 1){
                    ans.add(s[next]);
                    q.add(next);
                    nowCost--;
                    break;
                }
            }
        }
        
        if(cost[LIDX] != INF){
            System.out.println(cost[LIDX]-1);
            for(int i=ans.size()-1; i>=0; i--){
                System.out.println(ans.get(i));
            }
        }else{
            System.out.println(-1);
        }
        
    }
    
    public static int dif(String nowStr, String si){
        int difcnt = 0;
        for(int i=0; i<nowStr.length(); i++){
            if(nowStr.charAt(i) != si.charAt(i)){
                difcnt++;
                if(difcnt>1){
                    return 1_000_000_000;
                }
            }
        }
        return difcnt;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.