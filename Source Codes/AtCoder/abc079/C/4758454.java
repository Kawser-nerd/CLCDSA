import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        
        String S = sc.nextLine();
        sc.close();
        String[] ope = {"+","-"};
        int ans = 0;
        String[] s = S.split("");

        int A = Integer.parseInt(s[0]);
        int B = Integer.parseInt(s[1]);
        int C = Integer.parseInt(s[2]);
        int D = Integer.parseInt(s[3]);
       
        for(int i = 0; i < 2; i++) {    
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    int sum = A;
                    sum += (i == 0) ? 0 - B : B;
                    sum += (j == 0) ? 0 - C : C;
                    sum += (k == 0) ? 0 - D : D;
 
                    if (sum == 7) {
                        String ope1 = (i == 0) ? "-" : "+";
                        String ope2 = (j == 0) ? "-" : "+";
                        String ope3 = (k == 0) ? "-" : "+";
                        System.out.println(A + ope1 + B + ope2 + C + ope3 + D + "=7");
                        System.exit(0);
                    }
                }
            }
        }
    }
}