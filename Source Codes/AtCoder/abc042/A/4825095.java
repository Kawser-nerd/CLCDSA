import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int five = 0,
            seven = 0;
        for(int i = 0; i < 3; i++){
            switch(sc.nextInt()){
                case 5:
                    five++;
                    break;
                case 7:
                    seven++;
            }
        }
        if(five != 2 || seven != 1){
             System.out.println("NO");
        } else{
            System.out.println("YES");
        }
    }
}