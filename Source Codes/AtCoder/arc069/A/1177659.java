import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
	
		Scanner scanner = new Scanner(System.in);
		long n = scanner.nextLong();
		long m = scanner.nextLong();
		long s = 0;
if(m - n*2 >= 0){
s += n;
m -= n*2;
s += m/4;
}else{
s = m/2;
}
		System.out.println(s);
	}
 
}