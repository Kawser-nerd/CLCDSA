import java.util.*;

public class Main {                  
    
    public static void main(String[] args){           
        
       Scanner sc = new Scanner(System.in);
                                                
       int N = sc.nextInt();
       
       double a = sc.nextDouble();
       double b = sc.nextDouble();
       
       int[] p = new int[N];
       
	for (int i = 0; i < N; i++) {
			p[i] = sc.nextInt();
	}
        
	Arrays.sort(p);

	if (p[0] == p[N - 1]) {
		System.out.println(-1);
		return;
	}
        
	double ave = 0;
	for (int i = 0; i < N; i++) {
		ave += p[i];
	}
	ave /= N;
	double m = p[N - 1] - p[0];
	double P, Q;
	P = b / m;
	Q = a - P * ave;

	System.out.println(P + " " + Q);
                
        
    }    
}