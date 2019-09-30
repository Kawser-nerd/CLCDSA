import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int five = 0,
            seven = 0;
        for(int i = 0; i < 3; i++){
            int x = sc.nextInt();
            switch(x){
                case 5:
                    five++;
                    break;
                case 7:
                    seven++;
            }
        }
        String answer;
        if(five != 2 || seven != 1){
            answer = "NO";
        } else{
            answer = "YES";
        }
        System.out.println(answer);
    }
}