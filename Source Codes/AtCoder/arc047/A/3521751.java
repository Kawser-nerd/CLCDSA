import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int L = scanner.nextInt();
    String S = "+" + scanner.next();
    int[] sum = new int[N+1];
    int count = 0;
    sum[0]=1;
    for(int i = 1; i <= N; i++){
      if(S.charAt(i)=='+'){
        sum[i] = sum[i-1]+1;
      }
      if(S.charAt(i)=='-'){
        sum[i] = sum[i-1]-1;
      }
      if(sum[i]>L){
        count++;
        sum[i]=1;
      }
    }

    System.out.println(count);
  }
}