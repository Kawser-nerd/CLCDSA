import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner reader = new Scanner(System.in);
    int N = reader.nextInt();
    int M = reader.nextInt();
    int X = reader.nextInt();
    int Y = reader.nextInt();
    int[] xn = new int[N];
    int[] ym = new int[M];
    for (int i= 0; i < N; i++) {
    	xn[i] = reader.nextInt();
    }
    for (int i= 0; i < M; i++) {
    	ym[i] = reader.nextInt();
    }
    
    int Z = X + 1;
    while (Z < Y) {
    boolean isWar = false;
    	for (int i= 0; i < N; i++) {
            if (xn[i] >= Z) {
              isWar = true;
            }
        }
        for (int i= 0; i < M; i++) {
            if (ym[i] < Z) {
              	isWar = true;
            }
        }
      if (!isWar) {
         System.out.print("No War");
      	return;
      }
      	Z++;
      
    }
        System.out.print("War");
  
  }


}