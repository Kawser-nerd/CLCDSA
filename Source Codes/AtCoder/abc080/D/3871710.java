import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int C = scanner.nextInt();
    int[] s = new int[N];
    int[] t = new int[N];
    int[] c = new int[N];
    for(int i = 0; i < N; i++){
      s[i] = scanner.nextInt();
      t[i] = scanner.nextInt();
      c[i] = scanner.nextInt();
    }
    int[] time = new int[200002];
    int[] sum = new int[200002];
    for(int i = 1; i <= C; i++){
      for(int j = 0; j < 200002; j++){
        time[j] = 0;
      }
      for(int j = 0; j < N; j++){
        if(c[j] == i){
          time[s[j]*2-1] += 1;
          time[t[j]*2] -= 1;
        }
      }
      for(int j = 1; j < 200002; j++){
        time[j] += time[j-1];
      }
      for(int j = 1; j < 200002; j++){
        if(time[j]>0){
          sum[j]++;
        }
      }
    }
    int max = -1;
    for(int i = 0; i < 200002; i++){
      max = Math.max(max, sum[i]);
    }
    System.out.println(max);
  }
}