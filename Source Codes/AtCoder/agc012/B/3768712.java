import java.util.*;

public class Main{
    
    static int[] v,d,c,result,used;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        final int mod = ((int)1e9)+7;
        
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        
        ArrayList<Integer>[] g = new ArrayList[n];
        for(int i=0; i<n; i++){
            g[i] = new ArrayList<>();
        }
        
        for(int i=0; i<m; i++){
            int a = Integer.parseInt(sc.next())-1;
            int b = Integer.parseInt(sc.next())-1;
            g[a].add(b);
            g[b].add(a);
        }
        
        //
        int q = Integer.parseInt(sc.next());
        v = new int[q];
        d = new int[q];
        c = new int[q];
        
        for(int i=0; i<q; i++){
            v[i] = Integer.parseInt(sc.next())-1;
            d[i] = Integer.parseInt(sc.next());
            c[i] = Integer.parseInt(sc.next());
        }
        
        //
        result = new int[n];
        used = new int[n];
        Arrays.fill(used, -1);
        
        for(int t=q-1; t>=0; t--){
            ArrayDeque<Integer> que = new ArrayDeque();
            push(t, v[t], d[t], que);
            
            while(que.size() != 0){
                int i = que.pollFirst();
                if(used[i] != 0){
                    for(int j=0; j<g[i].size(); j++){
                        push(t, g[i].get(j), used[i]-1, que);
                    }
                }
            }
        }
        
        //
        for(int i=0; i<n; i++){
            System.out.println(result[i]);
        }
        
    }
    
    public static void push(int t, int i, int dist, ArrayDeque<Integer> que){
        if(used[i] < dist){
            used[i] = dist;
            if(result[i] == 0){
                result[i] = c[t];
            }
            que.offerLast(i);
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.