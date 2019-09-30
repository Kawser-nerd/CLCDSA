import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int sx = sc.nextInt();
        int sy = sc.nextInt();
        int tx = sc.nextInt();
        int ty = sc.nextInt();
        
        int gapx = tx -sx;
        int gapy = ty -sy;
        
        ArrayList<Character> list = new ArrayList<Character>();
        
      	//1??
        for(int i = 0; i < gapy; i++){
            list.add('U');
        }
        for(int i = 0; i < gapx; i++){
            list.add('R');
        }
        for(int i = 0; i < gapy; i++){
            list.add('D');
        }
        for(int i = 0; i < gapx; i++){
            list.add('L');
        }

        //2?? 
            list.add('L');
        for(int i = 0; i < gapy+1; i++){
            list.add('U');
        }
        for(int i = 0; i < gapx+1; i++){
            list.add('R');

        }
            list.add('D');
            list.add('R');
        for(int i = 0; i < gapy+1; i++){
            list.add('D');
        }
        for(int i = 0; i < gapx+1; i++){
            list.add('L');
        }
            list.add('U');

        //answer
        for(Character route: list){
            System.out.print(route);
        }
    }
}