import java.util.*;
public class Main {

	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int []A = new int[N];
	for(int i=0;i<N;i++){
		A[i] = sc.nextInt();
	}
	for(int i=0;i<N-1;i++) {
		for(int j=0;j<N-1-i;j++) {
			if(A[j]<A[j+1]) {
			int temp= A[j];
			A[j]=A[j+1];
			A[j+1]=temp;	
		}
	}
	}
    int max = A[0];
    int sum =0;
    for(int i=1;i<N;i++) {
    	sum+=A[i];
    }
    if(max>=sum){
    	System.out.println("No");
    }
    else if(max<sum){
    	System.out.println("Yes");
    }
    
}
	}