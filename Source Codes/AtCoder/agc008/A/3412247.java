import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long y = sc.nextLong();
      	long ans = INF;
      	for(int i = 1 ; i >= -1 ; i += -2){
			for(int j = 1 ;j >= -1; j += -2){
              	long a=0;
              	if(i == -1){
                  a++;
                }
              	if(j == -1){
                  a++;
                }
              	if(y*j >= x*i){
                  ans=Math.min(ans,(y*j-x*i)+a);
                }
         	}
    	}
      	System.out.println(ans);
	}
}