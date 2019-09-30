import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int count=0;

		int x=(a&1)<<2 | (b&1)<<1 | (c&1);
		switch(x){
		case 0b001 :
		case 0b110 :
			a++; b++; count++; break;
		case 0b100 : 
		case 0b011 :
			b++; c++; count++; break;
		case 0b010 :
		case 0b101 :
			c++; a++; count++; break;
		}
		
		int cc= Math.max(a, Math.max(b, c));
		int aa= Math.min(a, Math.min(b, c));
		int bb= a+b+c-aa-cc;
		
		count+=(cc-bb)/2+(cc-aa)/2;
		System.out.println(count);
	}
}