package fairAndSquare;

public class FairAndSquare {
	
	public static String[] execute(String[] input) {		
		
		String[] out;
		String[] splitted;				
		
		long n, m;		
		int result;
		
		int test = 1;
		int ntests;
		
		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];
		
		for (int i = 1; test < 1+ntests;) {
			splitted = input[i++].split("\\s");
			n = Long.parseLong(splitted[0]);
			m = Long.parseLong(splitted[1]);
						
			result = countPalindromes(n, m);			
			out[test-1] = "Case #" + test + ": " + result;			
			System.out.println(out[test-1]);
			
			test++;
		}
		return out;
	}
	
	private static int countPalindromes(long n, long m) {			

		int max = (int)Math.sqrt(m);
		int maxl = ("" + max).length();		
		int top = pow(10, maxl/2+1);		
		
		int count = 0;
		long number;
		long square;
		StringBuilder s = new StringBuilder(20);		

		for (int i = 0; i < top; i++) {
			for (int j = 0; j < 10; j++) {
				s.delete(0, s.length());
				if(i>0)
					s.append(i);
				number = createPalindrome(s, j);				
				square = number*number;
				if(square>m)
					break;
				else if(square<n)
					continue;				
				if(isPalindrome(""+square)) {					
					count++;
				}
			}
			if(i==0)
				continue;
			
			s.delete(0, s.length());
			if(i>0)
				s.append(i);
			number = createPalindrome(s, -1);
			square = number*number;
			if(square>m)
				break;
			else if(square<n)
				continue;
			
			if(isPalindrome(""+square)) {				
				count++;
			}
		}
		
		return count;
	}
	

	private static boolean isPalindrome(String s) {
		int l = s.length();
		for (int i = 0; i < l/2; i++) {
			if(s.charAt(i)!=s.charAt(l-i-1))
				return false;
		}
		return true;
	}


	private static long createPalindrome(StringBuilder s, int k) {
		int l = s.length();
		if(k>=0)
			s.append(k);		
		for (int i = 0; i < l; i++) {
			s.append(s.charAt(l-i-1));
		}
		return Long.parseLong(s.toString());		
	}
	
	 
	static int pow(int x, int y)
	    {		
	        int res = 1;
	        while (y > 0) {
	            if ( (y & 1L) == 1L) {
	                res = res * x;
	            }
	            x = x * x;
	            y >>= 1;
	        }
	        return res;
	    }
}
