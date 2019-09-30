import java.util.*;
public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int T = sc.nextInt();
	int A = sc.nextInt();
	double [] hairetu= new double[N];
	int []H = new int[N];
	for(int i=0;i<N;i++){
	    H[i] = sc.nextInt(); 
		hairetu[i] = T-H[i]*0.006;
	}
	double []hairetu2 = new double[N];
	for(int i=0;i<N;i++) {
		double ans = A - hairetu[i];
		hairetu2[i] = Math.abs(ans);
	}
	int i;
	int p=1;
	double min = hairetu2[0];
	for(i=1;i<N;i++) {
		if(min>hairetu2[i]){
			min=hairetu2[i];
			p=i;
		  }
	   }
	if(p==1) {System.out.println(1);}
	else {System.out.println(p+1);
	}	}
  }