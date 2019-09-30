import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        String output="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='B'){
                if(output.length()!=0){
                    output=output.substring(0,output.length()-1);
                }
            }else{
                output+=s.substring(i,i+1);
            }
        }
        System.out.println(output);
        
    }
    
 
}