import java.util.*;
    public class Main {
    	public static void main(String[] args) {
    		Scanner sc = new Scanner(System.in);
    		long x = Long.parseLong(sc.next());
    		long a = x/11;
    		long b = x%11;
    		if(b == 0)
    			System.out.println(String.valueOf(a*2));
    		else if(b <= 6)
    			System.out.println(String.valueOf(a*2 + 1));
    		else
    			System.out.println(String.valueOf(a*2 + 2));
    	}
    }