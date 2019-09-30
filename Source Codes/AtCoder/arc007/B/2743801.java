import java.util.Scanner;

public class Main{
		public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int m = sc.nextInt();
            
            int[] cas = new int[n];
            for(int i=0;i<n;i++) {
            	cas[i] = i+1;
            }
            
            int now = 0;
            for(int i=0;i<m;i++) {
            	int d = sc.nextInt();
            	for(int j=0;j<n;j++) {
            		if(cas[j]==d) {
            			cas[j] = now;
            			now = d;
            			break;
            		}
            	}
            }
            for(int i=0;i<n;i++)
            	System.out.println(cas[i]);
        
	}
}