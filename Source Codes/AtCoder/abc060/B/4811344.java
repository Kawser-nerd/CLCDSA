import java.util.Scanner;
     
    class Main{
    	public static void main(String arg[]) {
    		Scanner sc = new Scanner(System.in);
    		String s = sc.nextLine();
    		String[]S = s.split(" ");
    		int a = Integer.parseInt(S[0]);
    		int b = Integer.parseInt(S[1]);
    		int c = Integer.parseInt(S[2]);
    		sc.close();
    		
    		for(int i = 1; i <= b; i++) {
    			if(a*i%b == c) {
    				System.out.println("YES");
    				System.exit(0);
    			}
    		}
    		System.out.println("NO");
    	}
    }