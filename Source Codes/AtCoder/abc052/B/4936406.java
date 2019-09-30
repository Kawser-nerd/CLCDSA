import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int output=0;
        int x=0;
        sc.nextInt();
        String s=sc.next();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='I'){
                x++;
                if(output<x){
                    output=x;
                }
            }else{
                x--;
            }
        }
        System.out.println(output);
    }

}