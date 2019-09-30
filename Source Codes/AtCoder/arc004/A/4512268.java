import java.util.*;
import java.lang.*;

public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int N = scan.nextInt();
      	int[] x = new int[N];
      	int[] y = new int[N];
      	for(int i = 0; i < N; i++){
        	x[i] = scan.nextInt();
          	y[i] = scan.nextInt();
        }
      	scan.close();
      	int counter = 0;
      	double[] distance = new double[N * N];
      	for(int i = 0; i < N; i++){
        	for(int j = 0; j < N; j++){
            	distance[counter] = Math.sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
            	counter++ ;
            }
          
        }
      	double max = 0.0;
      	for(int k = 0; k < N * N; k++ ){
        	if(max < distance[k]){
            	max = distance[k];
            }
        }
      	System.out.print(max);
      	
      	
      	
    }

}