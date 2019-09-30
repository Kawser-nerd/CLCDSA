import java.io.*;
import java.util.*;
import java.text.*;

public class Main {
	public static void main(String[] args) {
		gridColoring();
	}
	
	public static void sieve(int max) {		
		boolean[] isComposite = new boolean[max+1];
		for(int i=2; i<=max; i++) 
			if(!isComposite[i])
				for(int j=i*i; j<=max; j+=i)
					isComposite[j]=true;
					
		for(int i=2; i<=max; i++) if(!isComposite[i]) System.out.println(i + " ");
	}
	
	public static void gridColoring() {
		Reader reader = new Reader();
		int height = reader.nextInt();
		int width = reader.nextInt();
		
		int num = reader.nextInt();		
		int[] colorNums = new int[num];
		for(int j = 0; j < num; j++) colorNums[j] = reader.nextInt();
		
		int[][] solution = new int[height][width];
		int r = 0, c = 0, color = 1;
		for(int j = 0; j < height*width; j++) {
			r = j/width;
			c = (r%2 == 0)? j - j/width*width : width - (j - j/width*width) - 1;
			
			if(colorNums[color - 1] <= 0) color++;
			solution[r][c] = color;
			colorNums[color - 1]--;
		}
		
		for(int j = 0; j < height; j++) {
			for(int k = 0; k < width; k++) System.out.print(solution[j][k] + " ");
			System.out.println();
		}
	}
	
	public static void simArrays() {
		Reader reader = new Reader();
		
		int n = reader.nextInt();
		int res = 1;
		res = exponential(3, n);
		
		int[] arr = new int[n];
		for(int j = 0; j < n; j++) arr[j] = reader.nextInt();
		
		int oddWays = 1;
		for(int j = 0; j < n; j++) if(arr[j] % 2 == 0) oddWays *= 2;
		
		System.out.println(res - oddWays);
	}
	
	public static int exponential(int base, int exp) {
		if(exp == 0) return 1;
		else if(exp % 2 == 0) return exponential((base*base), exp/2);
		return base*exponential((base*base), exp/2); //integer cutoff means (exp - 1)/2 unnecessary
	}
}

class Reader {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    String next() {
        while(st==null||!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch(Exception e) {}
        }
        return st.nextToken();
    }
	
    int nextInt() {
        return Integer.parseInt(next());
    }
}