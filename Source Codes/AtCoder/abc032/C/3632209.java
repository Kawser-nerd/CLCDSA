import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    long K = scanner.nextLong();
    long[] s = new long[N];
    for(int i = 0; i < N; i++){
      s[i] = scanner.nextLong();
    }
    for(int i = 0; i < N; i++){
      if(s[i]==0){
        System.out.println(N);
        return;
      }
    }
    int max = 0;
    int right = 0;
    long sum = 1;
    for(int left = 0; left < N; left++){
      while(right < N && sum * s[right] <= K){
        sum *= s[right];
        right++;
      }
      max = Math.max(max, right-left);
      if(left==right){
        right++;
      }else{
        sum /= s[left];
      }
    }
    System.out.println(max);
  }
}