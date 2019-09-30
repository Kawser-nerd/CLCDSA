import java.util.Scanner;
 
class Main {
	static long gcd(long a,long b) {
		if(b == 0)
			return a;
		return gcd(b,a % b);
	}
 
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String in = scan.next();
		String[] in2 = in.split("/");
		long x = Long.parseLong(in2[0]);
		long y = Long.parseLong(in2[1]);
		long g = gcd(x,y);
		x /= g;y /= g;
		scan.close();
        long n = 2 * x / y;
        n = Math.max(n,1);
        boolean f = true;
        for(;n <= 2 * x / y + 1;n++){
            if(n % y == 0){
                System.out.println(n + " " + (n * (n + 1) / 2 - n / y * x));
                f = false;
            }
        }
        if(f)
            System.out.println("Impossible");
    }
}