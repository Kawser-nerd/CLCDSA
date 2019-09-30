import java.util.Scanner;
import java.util.Arrays;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int D = scanner.nextInt();
    int K = scanner.nextInt();
    int[] L = new int[D+1];
    int[] R = new int[D+1];
    int[] S = new int[K];
    int[] T = new int[K];
    for(int i = 1; i <= D; i++){
      L[i] = scanner.nextInt();
      R[i] = scanner.nextInt();
    }
    for(int i = 0; i < K; i++){
      S[i] = scanner.nextInt();
      T[i] = scanner.nextInt();
    }
    for(int i = 0; i < K; i++){
      int now = S[i];
      int day = 0;
      for(int j = 1; j <= D; j++){
        day++;
        if(S[i] < T[i]){
          if(L[j] <= now && now <= R[j]){
            now = R[j];
            if(now >= T[i]){
              System.out.println(day);
              break;
            }
          }
        }else{
          if(L[j] <= now && now <= R[j]){
            now = L[j];
            if(now <= T[i]){
              System.out.println(day);
              break;
            }
          }
        }
      }
    }
  }
}