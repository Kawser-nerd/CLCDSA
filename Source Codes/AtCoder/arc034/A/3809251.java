import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    double[] a = new double[N];
    double[] b = new double[N];
    double[] c = new double[N];
    double[] d = new double[N];
    double[] e = new double[N];
    double max = 0;
    double score = 0;
    for(int i = 0; i < N; i++){
      a[i] = scanner.nextDouble();
      b[i] = scanner.nextDouble();
      c[i] = scanner.nextDouble();
      d[i] = scanner.nextDouble();
      e[i] = scanner.nextDouble();
      score = a[i] + b[i] + c[i] + d[i] + e[i] * 110/900;
      max = Math.max(max, score);
    }
    System.out.println(max);
  }
}