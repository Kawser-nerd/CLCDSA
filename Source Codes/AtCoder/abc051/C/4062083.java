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
        
      	//1??
        for(int i = 0; i < gapy; i++)System.out.print("U");
        for(int i = 0; i < gapx; i++)System.out.print("R");
        for(int i = 0; i < gapy; i++)System.out.print("D");
        for(int i = 0; i < gapx; i++)System.out.print("L");

        //2?? 
        System.out.print("L");
        for(int i = 0; i < gapy+1; i++)System.out.print("U");
        for(int i = 0; i < gapx+1; i++)System.out.print("R");
        System.out.print("DR");
        for(int i = 0; i < gapy+1; i++)System.out.print("D");
        for(int i = 0; i < gapx+1; i++)System.out.print("L");
        System.out.print("U");
    }
}