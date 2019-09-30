import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		String S=sc.next();

		String[] str=S.split("");

		int N=str.length;
		int c0=0;
		int c1=0;

		for(int i=0;i<N;i++) {

			if(str[i].equals("0")) c0++;
			if(str[i].equals("1")) c1++;


		}

		System.out.println(Math.min(c0, c1)*2);

		sc.close();
	}

}