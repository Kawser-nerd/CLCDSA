import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x=sc.next();
		String s=sc.next();
		for(int i=0;i<s.length();i++){
			String buf=s.substring(i, i+1);
			if(!buf.equals(x)){
				System.out.print(buf);
			}
		}
		System.out.println();
	}

}