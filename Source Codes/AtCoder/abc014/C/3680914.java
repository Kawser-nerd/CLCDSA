import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] a = new int[n];
    int[] b = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextInt();
      b[i] = scanner.nextInt();
    }
    int[] colors = new int[1001000];
    for(int i = 0; i < n; i++){
      colors[a[i]] += 1;
      colors[b[i]+1] += -1;
    }
    int max = 0;
    for(int i = 0; i <= 1000000; i++){
      colors[i+1] += colors[i];
      if(colors[i]>max){
        max = colors[i];
      }
    }
    System.out.println(max);
  }
}