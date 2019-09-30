import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int txa = scanner.nextInt();
    int tya = scanner.nextInt();
    int txb = scanner.nextInt();
    int tyb = scanner.nextInt();
    int T = scanner.nextInt();
    int V = scanner.nextInt();
    int n = scanner.nextInt();
    int[] x = new int[n];
    int[] y = new int[n];
    boolean[] visited = new boolean[n];
    for(int i = 0; i < n; i++){
      x[i] = scanner.nextInt();
      y[i] = scanner.nextInt();
      visited[i] = false;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
      if((double)Math.sqrt((x[i]-txa)*(x[i]-txa)+(y[i]-tya)*(y[i]-tya))/V+
      (double)Math.sqrt((x[i]-txb)*(x[i]-txb)+(y[i]-tyb)*(y[i]-tyb))/V <= T){
        visited[i] = true;
        count++;
      }
    }
    if(count>0){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}