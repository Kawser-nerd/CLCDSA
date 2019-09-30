import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	int n;
	int[] a;
	
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));
			
		int t = input.nextInt();
		
		for (int tt = 0; tt < t; tt++) {
			n = input.nextInt();
			input.nextLine();
			a = new int[n];
			for (int i = 0; i < n; i++) a[i] = -1;
			
			for (int i = 0; i < n; i++) {
				String line = input.nextLine();
				
				for (int j = 0; j < n; j++) 
					if (line.charAt(j) == '1') a[i] = Math.max(a[i], j);
			}
			
			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++)
					if (a[j] <= i) {
						ans += (j-i);
						
						for (int k = j; k > i; k--) {
							//swap k k-1
							int tmp = a[k]; a[k] = a[k-1]; a[k-1] = tmp;
						}
						//System.out.println(Arrays.toString(a));
						break;
					}
			}
			
			output.println("Case #"+(tt+1)+": "+ans);
		}
		
		
		input.close(); output.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		(new A()).run();
	}
}