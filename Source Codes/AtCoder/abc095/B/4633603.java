import java.util.*;
public class Main {

	public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int X = sc.nextInt();
    int count = N;
    int sum=0;
    int []hairetu = new int[N];
    for(int i=0;i<N;i++) {
    	hairetu[i]=sc.nextInt();
    	sum+=hairetu[i];
    }
    int min = hairetu[0];
    for(int i=0;i<N;i++) {
    	if(min>hairetu[i]) {
    		min = hairetu[i];
    	}
    }
    int ans = (X-sum)/min;
    System.out.println(ans+count);
	}
}