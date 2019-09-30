import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int ng[] = new int[3];
        for(int i = 0;i<3;i++){
            ng[i] = sc.nextInt();
            sc.nextLine();
        }
        int count = 0;
        int tmp = n;
        if(!(n == ng[0] || (n == ng[1] || n == ng[2]) )){
            while(count <= 100){
                if(tmp > 0){
                    count++;
                }else{
                    System.out.println("YES");
                    break;
                }
                
                tmp = tmp - 3;
    
                if( !(tmp == ng[0] || (tmp == ng[1] || tmp == ng[2]) )){
                    continue;
                }
    
                tmp = tmp + 1;
    
                if( !(tmp == ng[0] || (tmp == ng[1] || tmp == ng[2]) )){                
                    continue;
                }
                
                tmp = tmp + 1;
    
                if( !(tmp == ng[0] || (tmp == ng[1] || tmp == ng[2]) )){
                    continue;
                }else{
                    System.out.println("NO");
                    break;
                }
            }
        }else{
            System.out.println("NO");
        }

        if(count > 100){
            System.out.println("NO");
        }
    }
}