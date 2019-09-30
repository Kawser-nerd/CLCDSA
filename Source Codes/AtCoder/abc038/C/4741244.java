import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	long sum = 0;
	long chain = 1;
	int pre = sc.nextInt();
	for(int i = 1; i<N; i++) {
	    int cur = sc.nextInt();
	    if(cur > pre) chain++;
	    else {
		while(chain>0) {
		    sum += chain;
		    chain--;
		}
		chain = 1;
	    }
	    pre = cur;
	}
	while(chain>0) {
	    sum += chain;
	    chain--;
	}
	System.out.println(sum);
    }
}