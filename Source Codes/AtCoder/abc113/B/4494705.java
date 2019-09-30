import java.util.*;
import java.lang.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int n = scan.nextInt(); //number of spot
      	int T = scan.nextInt(); //state temperature
      	int A = scan.nextInt(); // temperature that princess wants
      	int[] H = new int[n]; // list of height
      	for (int i = 0; i < n; i++){
        	H[i] = scan.nextInt();
        }
      	double[] t = new double[n]; //list of temperature
      	for (int i = 0; i < n; i++){
        	t[i] = T - 0.006 * H[i];
        }
      	double rest = Math.abs(t[0]-A);
      	int key = 0;
      	for (int i = 0; i < n; i++){
        	if(rest > Math.abs(t[i]-A)){
            	rest = Math.abs(t[i]-A);
              	key = i;
            }
        }
      	System.out.print(key + 1);
    }
}