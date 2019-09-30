import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdin = new Scanner( System.in);
		String  x;
		int i=0,j=0;
		x =stdin.next();
		for(int k=1;k<=x.length();k++){
			String xx=x.substring(k-1,k);
			if(xx.equals("S")){i++;
			}else{i--;
			}
			if(i<0){
				j++;
				i=0;
			}
		}
		System.out.print(j*2);
	}
}