import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
 
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int a[] = new int[n];
		int b[] = new int[n];
		
		long result = 0;
		
		long minB = Long.MAX_VALUE;
		
		boolean same = true;
		for(int i = 0; i < n; i++){
			String[] tmpArray = br.readLine().split(" ");
			
			a[i] = Integer.parseInt(tmpArray[0]);
			b[i] = Integer.parseInt(tmpArray[1]);
			
			result += a[i];
			
			if(a[i] > b[i] && minB > b[i]){
				minB = b[i];
			}
			
			if(a[i] != b[i])
				same = false;
		}
		
		if(!same) 	result -= minB;
		else   result = 0;
		System.out.println(result);
	}
 
}