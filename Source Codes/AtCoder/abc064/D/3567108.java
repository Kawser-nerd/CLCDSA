import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdin = new Scanner( System.in);
		String  x;
		int i=0,j=0;
		int a=stdin.nextInt();
		x =stdin.next();
		for(int k=1;k<=x.length();k++){
			String xx=x.substring(k-1,k);
			if(xx.equals("(")){i++;
			}else{i--;
			}
			if(i<0){
				j++;
				i=0;
			}
		}
		for(int f=0;f<j;f++)System.out.print("(");
		System.out.print(x);
		for(int f=0;f<i;f++)System.out.print(")");
	}
}