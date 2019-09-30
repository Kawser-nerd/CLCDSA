import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int X = sc.nextInt();
        //sc.nextLine();
        //String S = sc.nextLine();
        sc.close();
        //String[] s = S.split(" ");
        //int[] n = new int[N];
        
        //for(int i = 0; i < N; i++) {
        //	String tmp = s[i];
        //	n[i] = Integer.parseInt(tmp);
        //}
        
        System.out.println(calc(A,B,C,X));    
    }
    
    public static int calc(int A,int B,int C,int X) {
    	int count = 0;
    	for(int i = 0; i <= A; i++){
            for(int j = 0; j <= B; j++){
                for(int k = 0; k <= C; k++){
                    if( X == 500*i + 100*j + 50*k){
                        count++;
                    }
                } 
            }
        }
		return count;
    }
}