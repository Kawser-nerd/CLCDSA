import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int turn=0;
        int turntmp;
        String[] cards=new String[3];
        for(int i=0;i<3;i++){
            cards[i]=sc.next();
        }
        String[] outputs={"A","B","C"};
        while(true){
            if(cards[turn].length()==0){
                System.out.println(outputs[turn]);
                return;
            }
            turntmp=turn;
            turn=(int)cards[turn].charAt(0)-97;
            cards[turntmp]=cards[turntmp].substring(1,cards[turntmp].length());
        }

    }
    
 
}