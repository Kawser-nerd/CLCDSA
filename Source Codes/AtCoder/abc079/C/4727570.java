import java.util.Scanner;
        
        class Main {
         
            public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                String N = sc.nextLine();
                sc.close();
                String[] S = N.split("");
                int[] n = new int[4];
                
                for(int i = 0; i < 4; i++) {
                	n[i] = Integer.valueOf(S[i]);
                }
                
                if(n[0] + n[1] + n[2] + n[3] == 7) {
                	System.out.println(n[0] + "+" + n[1] + "+" + n[2] + "+" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] + n[1] + n[2] - n[3] == 7) {
                	System.out.println(n[0] + "+" + n[1] + "+" + n[2] + "-" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] + n[1] - n[2] + n[3] == 7) {
                	System.out.println(n[0] + "+" + n[1] + "-" +  n[2] + "+" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] + n[1] - n[2] - n[3] == 7) {
                	System.out.println(n[0] + "+" + n[1] + "-" + n[2] + "-" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] - n[1] + n[2] + n[3] == 7) {
                	System.out.println(n[0] + "-" + n[1] + "+" +  n[2] + "+" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] - n[1] + n[2] - n[3] == 7) {
                	System.out.println(n[0] + "-" + n[1] + "+" + n[2] + "-" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] - n[1] - n[2] + n[3] == 7) {
                	System.out.println(n[0] + "-" +  n[1] + "-" + n[2]+ "+" + n[3] + "=7");
                	System.exit(0);
                }
                if(n[0] - n[1] - n[2] - n[3] == 7) {
                	System.out.println(n[0] + "-" +  n[1]+ "-" + n[2]+  "-" + n[3] + "=7");
                	System.exit(0);
                }
               
            }
        }