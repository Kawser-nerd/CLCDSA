import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int H = input.nextInt();
      	int W = input.nextInt();
      	String[] HS = new String[H];
      	boolean[] rows = new boolean[H];
      	boolean[] cols = new boolean[W];
      	Arrays.fill(rows, false);
      	Arrays.fill(cols, false);
      
      	for (int i = 0; i < H; i++) {
        	HS[i] = input.next();
        }
      
      	for (int j = 0; j < H; j++) {
          if (HS[j].indexOf("#") != -1) {
          	rows[j] = true;
          }
          	
          for (int i = 0; i < W; i++) {
            if (HS[j].charAt(i) == '#') {
            	cols[i] = true;
            }
          }
        }
      
		
		for (int i = 0; i < H; i++) {
          	if (rows[i]) {
              for (int j = 0; j < W; j++) {
                if (cols[j]) {
                  System.out.print(HS[i].charAt(j));
                }
              }
            	System.out.println();
            }
        }
		
    }
}