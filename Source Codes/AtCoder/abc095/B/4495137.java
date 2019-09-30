import java.util.*;

public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int N = scan.nextInt();
      	int X = scan.nextInt();
      	int[] m = new int[N];
      	int sum = 0;
      	for (int i = 0; i < N; i++){
        	m[i] = scan.nextInt();
        }
      	for (int i = 0; i < N; i++){
        	sum = sum + m[i] ;
        }
      	int min = m[0];
      	for (int i = 0; i < N; i++){
        	if(min > m[i]){
            	min = m[i];
            }
        }
      	int rest = X - sum;
      	int counter = N;
      	while(rest >= min){
        	rest = rest - min;
            counter++;
        }
      	System.out.print(counter);
    }
}