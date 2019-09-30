import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        String S = sc.nextLine();
        sc.close();
        String[] s = S.split(" ");
        int[] n = new int[N];
        
        for(int i = 0; i < N; i++) {
        	String tmp = s[i];
        	n[i] = Integer.parseInt(tmp);
        }
        
        System.out.println(calc(n));
        
    }
    
    public static int calc(int n[]) {
    	int count = 0;
    	while(true) {
        	for(int j = 0; j < n.length; j++) {
        		if(n[j]%2 == 0) {
        			n[j] /= 2; 
        		}else {
        			return count;
                }
            }
            count++;
        }
    }
}