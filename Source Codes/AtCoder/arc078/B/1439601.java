import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(in.readLine());

    Map<Integer, List<Integer>> v = new HashMap<>();
    for(int i=0;i<N+1;i++){
      v.put(i, new ArrayList<Integer>());
    }
    for(int i=0;i<N-1;i++){
      Integer[] ab = Arrays.stream(in.readLine().split(" ")).map(Integer::parseInt).toArray(Integer[]::new);
      v.get(ab[0]).add(ab[1]);
      v.get(ab[1]).add(ab[0]);
    }
    int[] fenecDist = new int[N+1];
    Arrays.fill(fenecDist, -1);
    int[] snukeDist = new int[N+1];
    Arrays.fill(snukeDist, -1);
    dfs(fenecDist, v, 1, 0);
    dfs(snukeDist, v, N, 0);

    // System.out.println(Arrays.toString(fenecDist));
    // System.out.println(Arrays.toString(snukeDist));

    int[] fScore = new int[N+1];
    for(int i=1;i<=N;i++){
      if(fenecDist[i] <= snukeDist[i]){
        fScore[i] = 1;
      }
    }
    if(Arrays.stream(fScore).sum()>N/2){
      System.out.println("Fennec");
    }else{
      System.out.println("Snuke");
    }
  }

  public static void dfs(int[] dist, Map<Integer, List<Integer>> v, int start, int depth){
    if(dist[start]>-1){
      return;
    }
    dist[start] = depth;
    for(int i: v.get(start)){
      dfs(dist, v, i, depth+1);
    }
  }
}