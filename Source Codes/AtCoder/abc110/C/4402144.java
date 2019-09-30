import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        try{
            String s = scan.next();
            String t = scan.next();
            boolean b = true;
            for(int i = 0; i < s.length() && b; i++){
                b &= s.indexOf(s.charAt(i), i+1) == t.indexOf(t.charAt(i), i+1);
            }
            if(b){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }

        }finally{
            scan.close();
        }
    }
}