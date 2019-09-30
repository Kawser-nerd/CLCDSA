import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int L = scanner.nextInt();
    int R = scanner.nextInt();
    int[] l = new int[L];
    boolean[] lused = new boolean[L];
    int[] r = new int[R];
    boolean[] rused = new boolean[R];
    for(int i = 0; i < L; i++){
      l[i] = scanner.nextInt();
    }
    for(int i = 0; i < R; i++){
      r[i] = scanner.nextInt();
    }
    int count = 0;
    for(int i = 0; i < L; i++){
      for(int j = 0; j < R; j++){
        if(l[i] == r[j] && lused[i] == false && rused[j] == false){
          lused[i] = true;
          rused[j] = true;
          count++;
        }
      }
    }
    System.out.println(count);
  }
}