import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] c = new int[n+1];
    int[] s = new int[n+1];
    int[] f = new int[n+1];
    for(int i = 1; i < n; i++){
      c[i] = sc.nextInt();
      s[i] = sc.nextInt();
      f[i] = sc.nextInt();
    }
    for(int i = 1; i <= n; i++){
      int tmp = s[i] + c[i];
      for(int j = i + 1; j < n; j++){
        if(tmp < s[j]){
          tmp = s[j];
        }else{
          tmp = f[j] * (int)Math.ceil(tmp / (double)f[j]);
        }
        tmp += c[j];
      }
      System.out.println(tmp);
    }
  }
}