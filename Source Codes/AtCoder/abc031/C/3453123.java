import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] A = new int[N];
    int sumA;
    int sumT;
    int maxT =-Integer.MAX_VALUE;
    int ans = -1000000;
    for(int i = 0; i < N; i++){
      A[i] = scanner.nextInt();
    }
    for(int i = 0; i < N; i++){
      int maxA =-Integer.MAX_VALUE;
      for(int j = 0; j < N; j++){
        sumA = 0;
        sumT = 0;
        if(i == j) continue;
        if(i < j){
          for(int k = i; k <= j; k++){
            if((k-i)%2==0){
              sumT += A[k];
            }else{
              sumA += A[k];
            }
          }
        }else if(j < i){
          for(int k = j; k <= i; k++){
            if((k-j)%2==0){
              sumT += A[k];
            }else{
              sumA += A[k];
            }
          }
        }
        if(sumA > maxA){
          maxA = sumA;
          maxT = sumT;
        }
      }
      ans = Math.max(ans, maxT);
  }
  System.out.println(ans);
}
}