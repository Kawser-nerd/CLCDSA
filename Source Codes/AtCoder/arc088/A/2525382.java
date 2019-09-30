import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long y = sc.nextLong();
		long s = 0;
		for(long l = x; l <= y; l *= 2)
		{
			s++;
		}
		System.out.println(s);
		
  	}
}