import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        sc.close();
        
        System.out.println(calc(S));
        
    }
    
    public static int calc(String S) {
    	String[] s = S.split("");
    	int count = 0;
    	for(int i = 0; i < 3; i ++) {
        	if(s[i].equals("1")) {
        		count++;
        	}
        }
    	return count;
    }
}