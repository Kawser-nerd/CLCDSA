import java.util.Scanner;
     
    class Main{
    	public static void main(String arg[]) {
    		Scanner sc = new Scanner(System.in);
    		String S = sc.nextLine();
    		int A = Integer.parseInt(S.substring(0,1));
    		int B = Integer.parseInt(S.substring(1,2));
    		int C = Integer.parseInt(S.substring(2,3));
    		int D = Integer.parseInt(S.substring(3,4));
    		sc.close();
    	
			int ans = 0;
    		String[] ope = {"+","-"};
    		for(int i = 0; i < 2; i++) {
    			String ope1 = ope[i];
    			for(int j = 0; j < 2; j++) {
    				String ope2 = ope[j];
    				for(int k = 0; k < 2; k++) {
    					String ope3 = ope[k];
    					if(ope[i].equals("+")) {
    	    				ans = A + B;
    	    			}else {
    	    				ans = A - B;
    	    			}
    					if(ope[j].equals("+")) {
        					ans += C;
            			}else {
            				ans -= C;
            			}
    					if(ope[k].equals("+")) {
    						ans += D;
            			}else {
            				ans -= D;
            			}
    					if(ans == 7) {
    						String s = A + ope1 + B + ope2 + C + ope3 + D + "=7";
    						System.out.println(s);
    						System.exit(0);
    	    			}else {
    	    				ans = 0;
    	    			}
    				}
    			}
    		}
		}
    }