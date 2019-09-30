import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.System.*;

public class A {
  public static String[] parts(BufferedReader br) throws Exception {
    String line = br.readLine();
    if (line == null) return null;
    return line.trim().split("\\s+");
  }
  
  public static void main(String args[]) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(in));
    
    int cas = parseInt(br.readLine());
    for(int z=1;z<=cas;z++) {
      String[] ss = parts(br);
      int n = parseInt(ss[0]);
      int m = parseInt(ss[1]);
      
      ss = parts(br);
      int[] arr = new int[n];
      for(int i=0;i<n;i++) arr[i] = parseInt(ss[i]);
      Arrays.sort(arr);
      
      int ans = 0;
      for(int i=0, j=n-1; i<=j;) {
        while(i<j && arr[i]+arr[j]>m) {
          j--;
          ans++;
        }
        i++;
        j--;
        ans++;
      }
      
      out.println("Case #"+z+": "+ ans);
    }
  }
}
