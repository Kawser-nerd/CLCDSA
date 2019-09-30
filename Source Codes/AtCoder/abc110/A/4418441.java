import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner reader = new Scanner(System.in);
    int a = reader.nextInt();
    int b = reader.nextInt();
    int c = reader.nextInt();
    int[] result = new int[6];
    
    result[0] = c * 10 + b + a;
    result[1] = a * 10 + b + c;
    result[2] = b * 10 + a + c;
    result[3] = c * 10 + a + b;
    result[4] = a * 10 + c + b;
    result[5] = b * 10 + c + a;
    
    int max = result[0];
    
    for (int i= 1; i < 6; i++) {
    	if (max < result[i]) {
        	max = result[i];
        }
    }
    
    System.out.print(max);
  }
}