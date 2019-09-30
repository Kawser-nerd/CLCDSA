import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner a = new Scanner(System.in);
    int N = a.nextInt();
    int n = N%30;
    int[] j = {1,2,3,4,5,6};
        for(int x=0; x < n ; x++){
	
      int i = x % 5;
      int newj = j[i];
	j[i] = j[i+1];
	j[i+1] = newj;
		
    }//for???
System.out.println("" + j[0] + "" + j[1] + "" + j[2] + "" + j[3] + "" + j[4] +"" +j[5]  );
System.out.println();
  }//main???
}