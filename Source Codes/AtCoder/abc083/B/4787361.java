import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        //sc.nextLine();
        sc.close();
        
        
        //for(int i = 0; i < N; i++) {
        //	String tmp = s[i];
        //	n[i] = Integer.parseInt(tmp);
        //}
        
        System.out.println(sum(S));    
    }
    
    public static int sum(String S) {
        String s[] = S.split(" ");
        int N = Integer.parseInt(s[0]);
        int A = Integer.parseInt(s[1]);
        int B = Integer.parseInt(s[2]);
        String[] ss = new String[N+1];
        int a = 0;
        int sum = 0;
        
        
        for(int i = 1; i <= N; i++){
            ss[i] = String.valueOf(i);
        }

        for(int j = 1; j <= N; j++ ){
            String[] tmp = ss[j].split("");
            for(int k = 0; k < tmp.length; k++){
                a += Integer.parseInt(tmp[k]);
            }  
            if( a >= A && a <= B){
                sum += Integer.parseInt(ss[j]);
            }
            a = 0;
        }
		return sum;
    }
}