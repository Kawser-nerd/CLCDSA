import java.util.Scanner;
public class Main { 
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
      	int D = reader.nextInt();
		String result = "Christmas";
		while (D < 25) {
          result += " Eve";
        	D++;
        } 
      	System.out.print(result);
    }
}