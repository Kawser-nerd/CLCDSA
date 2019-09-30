import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    String[] s = br.readLine().split(" ");
    int[] a = new int[10];
    for(int i = 0; i < n; i++){
      a[i] = Integer.parseInt(s[i]);
    }
    
    int max = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
      sum += a[i];
      max = Math.max(max, a[i]);
    }
    
    if(max < sum - max) System.out.println("Yes");
    else System.out.println("No");
  }
}