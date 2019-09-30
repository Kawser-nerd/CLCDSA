import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  int N = sc.nextInt();
  int[] a = new int[N];
  int[] b = new int[N];
  for(int i = 0;i < N;i++){
    a[i] = sc.nextInt();
  }
  for(int i = 0;i < N;i++){
    b[i] = sc.nextInt();
  }
  int ans = 0;
    for(int i = 0;i < N;i++){
      int sum = 0;
      for(int j = 0;j <= i;j++){
        sum += a[j];
      }
      for(int j = i;j < N;j++){
        sum += b[j];
      }
      ans = Math.max(sum,ans);
    }
  System.out.println(ans);
}}