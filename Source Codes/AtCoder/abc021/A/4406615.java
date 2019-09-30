import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int output=0;
        String out="";
        if(n>=8){
            out+="8";
            output++;
            n-=8;
        }
        if(n>=4){
            out+="\n4";
            output++;
            n-=4;
        }
        if(n>=2){
            out+="\n2";
            output++;
            n-=2;
        }
        if(n>=1){
            out+="\n1";
            output++;
        }
        System.out.println(output);
        System.out.println(out);
    }
        

    

}