import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] a = new int[N];
    int sum = 0;
    for(int i = 0; i < N; i++){
      a[i] = scanner.nextInt();
      sum += a[i];
    }
    if(sum%N != 0){
      System.out.println(-1);
    }
    if(sum%N == 0){
      int ave = sum/N;
      int count = 0;
      int t = 0;
      for(int i = 0; i < N; i++){
        t += a[i];
        if(t != (i+1)*ave){
          count++;
        }
      }
      System.out.println(count);
      }
  }
}