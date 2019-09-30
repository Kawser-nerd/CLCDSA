import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
	    int n=sc.nextInt();
	    int m=0,a=n;
	    if(n>10100){
	    	a=n/100;
	    }
	    for(int i=2;i<a;i++){
	    	if(n%i==0){
	    		m++;
	    	}
	    }
	    if(m==0){
	    	System.out.println("YES");
	    }
	    else{
	    	System.out.println("NO");
	    }
	}
}