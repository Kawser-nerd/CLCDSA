import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    double A = scanner.nextDouble();
    double B = scanner.nextDouble();
    double[] S = new double[N];
    for(int i = 0; i < N; i++){
      S[i] = scanner.nextDouble();
    }
    Arrays.sort(S);
    double min = S[0];
    double max = S[N-1];
    double sum = 0;
    for(int i = 0; i < N; i++){
      sum += S[i];
    }
    double P = -1;
    double Q = -1;
    if(min != max){
      P = B/(max-min);
      Q = A-(P*sum)/N;
      System.out.println(P + " " + Q);
    }else if(min == max){
      System.out.println(-1);
    }
  }
}