import java.util.Scanner;
import java.util.Arrays;
public class Main { 
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
      	String S = reader.next();
      	int[] X = new int[10];
        for (int k = 0; k < S.length(); k++ ) {
        	X[k] = Integer.parseInt(Character.toString(S.charAt(k)));
        }
        
      	int[] nearSevenDG = new int[10];
      	int minGap = 1000;
      	for (int i = 0; i < S.length() - 2; i++) {
          int gap = Math.abs((X[i]*100 + X[i+1]*10 + X[i+2]) - 753);
          
          if (gap < minGap) {
          	minGap = gap;
          }
		}
      System.out.print(minGap);
      
    }
}