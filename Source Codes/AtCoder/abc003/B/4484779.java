import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        String t=sc.next();
        char tmpt;
        char tmps;
        for(int i=0;i<s.length();i++){
            tmpt=t.charAt(i);
            tmps=s.charAt(i);
            if(tmpt!=tmps){
                if(tmpt=='@'&&(tmps=='a'||tmps=='t'||tmps=='c'||tmps=='o'||tmps=='d'||tmps=='e'||tmps=='r')){
                    
                }else if(tmps=='@'&&(tmpt=='a'||tmpt=='t'||tmpt=='c'||tmpt=='o'||tmpt=='d'||tmpt=='e'||tmpt=='r')){
                    
                }else{
                    System.out.println("You will lose");
                    return;
                }
            }
        }
        System.out.println("You can win");

    }

}