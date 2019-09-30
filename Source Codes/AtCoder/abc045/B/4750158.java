import java.util.Scanner;

public class Main{
	public static char abc_ans(String str_a, String str_b, String str_c){
		char[] a = str_a.toCharArray();
		char[] b = str_b.toCharArray();
		char[] c = str_c.toCharArray();

		int a_count = a.length;
		int b_count = b.length;
		int c_count = c.length;

		int a_number = 0;
		int b_number = 0;
		int c_number = 0;

		char x = a[a_number];
		while(true){
			switch (x){
				case 'a':
					if(a_number >= a.length){
						return('A');
					}
					x = a[a_number];

					a_number ++;
					break;
				case 'b':
					if(b_number >= b.length){
						return('B');
					}
					x = b[b_number];
					b_number ++;
					break;
				case 'c':
					if(c_number >= c.length){
						return('C');
					}
					x = c[c_number];
					c_number ++;
					break;
			}
		}
	}

	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		String str_a = scan.next();
		String str_b = scan.next();
		String str_c = scan.next();

		System.out.println(abc_ans(str_a,str_b,str_c));
	}
}