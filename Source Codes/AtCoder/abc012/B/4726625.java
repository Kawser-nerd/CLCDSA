import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int res = N%3600;
	int h = N/3600;
	int s = res % 60;
	int m = res/60;
	if( h <= 9 ) System.out.print("0"+h+":");
	else System.out.print(h+":");
	if ( m <= 9 )System.out.print("0"+m+":");
	else System.out.print(m+":");
	if ( s <= 9 )System.out.println("0"+s);
	else System.out.println(s);		
    }
}