import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int x=0;
        int y=0;
        int free=0;
        for(int i=0;i<s.length();i++){
            switch(s.charAt(i)){
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                default:
                    free++;
            }
        }
        int abs=Math.abs(x)+Math.abs(y);
        if(sc.nextInt()==1){
            System.out.println(abs+free);
        }else{
            if(free>abs){
                System.out.println(Math.abs((abs-free)%2));
            }else{
                System.out.println(abs-free);
            }
        }
    } 
}