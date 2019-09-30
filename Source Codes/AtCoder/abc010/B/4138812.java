import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int output=0;
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            switch(sc.nextInt()%6){
                case 1:
                case 3:
                    break;
                case 2:
                case 4:
                    output+=1;
                    break;
                case 5:
                    output+=2;
                    break;
                case 0:
                    output+=3;
                    break;
                    
            }
        }
        System.out.println(output);

}

}