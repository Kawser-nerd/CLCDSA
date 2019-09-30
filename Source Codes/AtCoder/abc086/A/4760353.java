import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();
        
        System.out.println(calc(a,b));
        
    }
    
    public static String calc(int a, int b) {
    	String ans = "Odd";
    	if(a*b % 2 == 0) {
    		ans = "Even";
    	}
    	return ans;
    }
}