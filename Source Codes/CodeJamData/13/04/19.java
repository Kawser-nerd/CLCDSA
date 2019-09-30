package qual;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class D {
  static class Chest{
    int keyType;
    int inKey[];
    Chest(int k , int[] ik){
      keyType = k;
      inKey = ik;
    }
  }
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int K = sc.nextInt();
      int N = sc.nextInt();
      int kstart[] = new int[K];
      for(int k = 0 ; k < K ; ++k){
        kstart[k] = sc.nextInt();
      }
      Chest cs[] = new Chest[N];
      for(int i = 0 ; i < N ; ++i){
        int ti = sc.nextInt();
        int ki = sc.nextInt();
        int is[] = new int[ki];
        for(int j = 0 ; j < is.length ; ++j){
          is[j] = sc.nextInt();
        }
        cs[i] = new Chest(ti, is);
      }
      int adj[][] = new int[1 << N][];
      boolean memo[] = new boolean[1 << N];
      Queue<Integer> q = new LinkedList<>();
      q.add(0);
      memo[0] = true;
      while(!q.isEmpty()){
        int cp = q.poll();
        int ks[] = new int[201];
        for(int k : kstart){
          ks[k]++;          
        }
        for(int i = 0 ; i < N ; ++i){
          if((cp & (1 << i)) != 0){
            for(int k : cs[i].inKey){
              ks[k]++;
            }
            ks[cs[i].keyType]--;
          }
        }
        List<Integer> list = new ArrayList<Integer>();
        for(int i = 0 ; i < N ; ++i){
          int next = cp | (1 << i);
          if(memo[next])continue;
          if(ks[cs[i].keyType] > 0){
            list.add(next);
            q.add(next);
            memo[next] = true;
          }
        }
        int arr[] = new int[list.size()];
        for(int i = 0 ; i < list.size(); ++i){
          arr[i] = list.get(i);
        }
        adj[cp] = arr;
      }
      if(memo[(1 << N) -1]){
        int count[] = new int[1 << N];
        for(int i = 0 ; i < adj.length ; ++i){
          if(adj[i] == null){
            continue;
          }
          for(int j : adj[i]){
            count[j]++;
          }
        }
        int radj[][] = new int[1 << N][];
        for(int i = 0 ; i < adj.length; ++i){
          radj[i] = new int[count[i]];
        }
        int ind[] = new int[1 << N];
        for(int i = 0 ; i < adj.length ; ++i){
          if(adj[i] == null){
            continue;
          }
          for(int j : adj[i]){
            radj[j][ind[j]++] = i;
          }
        }
        boolean can[] = new boolean[1 << N];
        q.add((1 << N) - 1);        
        can[can.length - 1] = true;
        while(!q.isEmpty()){
          int cp = q.poll();
          for(int r : radj[cp]){
            if(can[r]){
              continue;
            }
            can[r] = true;
            q.add(r);
          }
        }
        System.out.printf("Case #%d:" , cn);
        boolean used[] = new boolean[N];
        int cp = 0;
        for(int i = 0 ; i < N ; ++i){
          Set<Integer> next = new TreeSet<Integer>();
          for(int a : adj[cp]){
            next.add(a);
          }
          for(int j = 0 ; j < N ; ++j){
            if(used[j]){
              continue;
            }
            int np = cp | (1 << j);
            if(!next.contains(np)){
              continue;
            }
            if(!can[np]){
              continue;
            }
            cp = np;
            used[j] = true;
            System.out.print(" " + (j + 1));
            break;
          }
        }
        System.out.println();
      }else{
        System.out.printf("Case #%d: IMPOSSIBLE\n", cn);
      }
    }
    sc.close();
  }
}
