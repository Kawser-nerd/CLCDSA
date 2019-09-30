import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[] cube = sc.next().toCharArray();
        int zero = 0;
        for(int i = 0; i < cube.length; i++){
            switch(cube[i]){
                case '0':
                zero++;
            }
        }
        System.out.println(Math.min(zero, cube.length-zero)*2);
    }
}