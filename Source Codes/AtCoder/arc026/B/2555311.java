import java.util.*;
class Main{

    static long sum(long n){

	long ret = 1;

	for(long i=2;i<=Math.sqrt(n);i++){
	    if(n%i == 0){
		if(i==Math.sqrt(n)){
		    ret += i;
		}else{
		    ret += i;
		    ret += n/i;
		}
	    }
	}
	return ret;
    }

    static void solve(long  n){
	if(n == 1)
	    System.out.println("Deficient");
	else if(sum(n) == n)
	    System.out.println("Perfect");
	else if(sum(n) < n)
	    System.out.println("Deficient");
	else
	    System.out.println("Abundant");
    }

    public static void main(String args[]){
	Scanner cin = new Scanner(System.in);
	long n = cin.nextLong();
	solve(n);
    }
}