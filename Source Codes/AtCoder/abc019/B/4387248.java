import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String output="";
        String str=sc.next();
        boolean haveC=false;
        char c=0;
        int length=1;
        for(int i=0;i<str.length();i++){
            if(haveC){
                if(c==str.charAt(i)){
                   length++; 
                }else{
                   output+=c;
                   output+=length;
                   length=1;
                   haveC=false;
                   i--;
                }
            }else{
                c=str.charAt(i);
                haveC=true;
            }
        }
        output+=c;
        output+=length;
        System.out.println(output);
    }

}