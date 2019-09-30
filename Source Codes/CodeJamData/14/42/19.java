import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.System.*;

public class B {
  public static String[] parts(BufferedReader br) throws Exception {
    String line = br.readLine();
    if (line == null) return null;
    return line.trim().split("\\s+");
  }
  
  public static void main(String args[]) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(in));
    
    int cas = parseInt(br.readLine());
    for(int z=1;z<=cas;z++) {
      int n = parseInt(br.readLine());
      String[] ss = parts(br);
      int[] arr = new int[n];
      for(int i=0;i<n;i++) arr[i] = parseInt(ss[i]);
      
      int[] cl = new int[n];
      int[] cr = new int[n];
      HashMap<Integer, Integer> where = new HashMap<Integer, Integer>();
      for(int i=0;i<n;i++) {
        where.put(arr[i], i);
        for(int j=0;j<n;j++) {
          if (i == j) continue;
          if (i < j && arr[j] > arr[i]) cl[i]++;
          if (i > j && arr[j] > arr[i]) cr[i]++;
        }
      }
      int ans = 0;
      Arrays.sort(arr);
      for(int i=n-2;i>=0;i--) {
        int x = arr[i];
        int j = where.get(x);
        ans += min(cl[j], cr[j]);
      }
      
      out.println("Case #"+z+": "+ ans);
    }
  }
}
