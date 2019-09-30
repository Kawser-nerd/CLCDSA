import java.util.Scanner;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N=sc.next();
        char S[]=new char[N.length()];
        long ans=(N.length()-1)*2;
        for(int i=0;N.length()>i;i++){
            S[i]=N.charAt(i);
        }
        for(int j=1;N.length()-1>j;j++){
            if(S[j]=='U'){
                ans+=j*2+N.length()-j-1;
            }else{
                ans+=j+(N.length()-j-1)*2;
            }
        }
        System.out.println(ans);
    }
}