import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }
    
    int n;
    int[] ans;
    boolean ok(int type, ArrayList<Integer> gs, int[] color, int cur){
      if(cur == n){
        for(int i = 0; i < gs.size(); i++){
          int s = gs.get(i);
          boolean[] used = new boolean[type];
          for(int j = 0; j < n; j++)if(((s>>j)&1)==1){
            used[color[j]] = true;
          }
          for(int j = 0; j < type; j++)if(!used[j])return false;
        }
        for(int i = 0; i < n; i++)ans[i] = color[i];
        return true;
      }
      for(int i = 0; i < type; i++){
        color[cur] = i;
        if(ok(type, gs, color, cur+1))return true;
      }
      return false;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
          n = sc.nextInt();
          int m = sc.nextInt();
          int[] start = new int[m];
          int[] end = new int[m];
          for(int i = 0; i < m; i++)start[i] = sc.nextInt()-1;
          for(int j = 0; j < m; j++)end[j] = sc.nextInt()-1;
          ArrayList<Integer> gs = new ArrayList<Integer>();
          gs.add((1<<n)-1);
          for(int i = 0; i < m; i++){
            int target = (1<<start[i]) + (1<<end[i]);
            ArrayList<Integer> ng = new ArrayList<Integer>();
            for(int j = 0; j < gs.size(); j++){
              int s = gs.get(j);
              if((s&target) == target){
                int a = target;
                int b = target;
                int small = min(start[i], end[i]);
                int big = max(start[i], end[i]);
                for(int k = 0; k < n; k++){
                  if(((s>>k)&1) == 1){
                    if(k >= small && k <= big)b |= 1<<k;
                    else a |= 1<<k;
                  }
                }
                ng.add(a); ng.add(b);
              }else{
                ng.add(s);
              }
            }
            gs = ng;
          }
          //for(int v : gs)System.out.printf("%8s\n", Integer.toBinaryString(v));
          int limit = n+1;
          for(int i = 0; i < gs.size(); i++)limit = min(limit, Integer.bitCount(gs.get(i)));
          ans = new int[n];
          for(int x = limit; x > 0; x--){
            int[] color = new int[n];
            if(ok(x, gs, color, 0)){
              System.out.printf("Case #%d: %d\n", o, x);
              for(int i = 0; i < n; i++){
                if(i > 0)System.out.print(" ");
                System.out.print(ans[i]+1);
              }
              System.out.println();
              break;
            }
          }
        }
    }
}
