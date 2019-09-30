import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String args[]) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		
		//StringBuilder sb = new StringBuilder();
		
		int n = sc.nextInt();
		double x[] = new double[n];
		double y[] = new double[n];
		
		for(int i=0;i<n;i++){
			x[i] = sc.nextDouble();
			y[i] = sc.nextDouble();
		}
		
		for(int i=0;i<n;i++){
			ArrayList<Double> s = new ArrayList<>();
			for(int j=0;j<n;j++){
				if(i!=j){
					s.add(Math.atan2(y[j]-y[i],x[j]-x[i]));
				}
			}
			
			Collections.sort(s);
			
			double max = 0;
			for(int j=0;j<n-2;j++){
				max = Math.max(s.get(j+1)-s.get(j), max);
			}
			
			max = Math.max(max, 2* Math.PI - (s.get(n-2) - s.get(0)));
			
			System.out.println(Math.max((max - Math.PI)/2/Math.PI, 0));
		}
		
		
	}
}