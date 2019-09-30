import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String str=sc.next();
        if(n%2==0){
            System.out.println(-1);
            return;
        }
        char tmp=str.charAt(0);
        for(int i=1;i<n;i++){
            switch(tmp){
                case 'a':
                    if(str.charAt(i)!='b'){
                        System.out.println("-1");
                        return;
                        
                    }
                    break;
                    case 'b':
                    if(str.charAt(i)!='c'){
                        System.out.println("-1");
                        return;
                        
                    }
                    break;
                    case 'c':
                    if(str.charAt(i)!='a'){
                        System.out.println("-1");
                        return;
                        
                    }
                    break;
                
            }
            if(i==(n-1)/2){
                if(str.charAt(i)!='b'){
                    System.out.println(-1);
                    return;
                }
            }
            tmp=str.charAt(i);
        }
        System.out.println((n-1)/2);
        

    }

}