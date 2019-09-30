import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str=sc.next();
        int n=str.length();
        int output=0;
        int tmp=1;
        for(int i=0;i<n/2+1;i++){
            if(str.charAt(i*2)=='0'){
                tmp=0;
            }
            if(i*2+1==n||str.charAt(i*2+1)=='+'){
                output+=tmp;
                tmp=1;
            }
        }
        System.out.println(output);
    } 
}