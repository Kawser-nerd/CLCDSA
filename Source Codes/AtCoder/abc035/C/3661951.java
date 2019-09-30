import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int Q = scanner.nextInt();
    int[] l = new int[Q+1];
    int[] r = new int[Q+1];
    int[] field = new int[N+2];
    int[] sum = new int[N+2];
    sum[0] = 0;
    for(int i = 1; i <= N; i++){
      field[i] = 0;
    }
    for(int i = 0; i < Q; i++){
      l[i] = scanner.nextInt();
      r[i] = scanner.nextInt();
    }
    for(int i = 0; i < Q; i++){
      field[l[i]] += 1;
      field[r[i]+1] += -1;
    }
    for(int i = 1; i <= N; i++){
      sum[i] = sum[i-1] + field[i];
    }
    for(int i = 1; i <= N; i++){
      if(sum[i]%2==0){
        System.out.print(0);
      }else{
        System.out.print(1);
      }
    }
    System.out.println();
  }
}