import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int all = 0;
    for(int i = 1; i <= 9; i++){
      for(int j = 1; j <= 9; j++){
        all += i*j;
      }
    }
    for(int i = 1; i <= 9; i++){
      for(int j = 1; j <= 9; j++){
        if(all-N == i * j){
          System.out.print(i + " " + "x" + " " + j);
          System.out.println();
        }
      }
    }
  }
}