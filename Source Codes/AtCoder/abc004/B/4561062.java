import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner a = new Scanner(System.in);
    String c[][] = new String[4][4];
		for(int i = 0; i <= 3; i ++) {
			for(int j = 0; j <= 3; j ++) {
				c[i][j] = a.next();
			}
		}
		for(int i = 3; i >= 0; i --) {
			for(int j = 3; j >= 0; j --) {
			if(j == 0){
        	System.out.print(c[i][j]+"\n");
		}
		else{
		System.out.print(c[i][j]+" ");
        }
      }
    }
  }
}