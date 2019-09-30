import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        char[] ch = str.toCharArray();
        int v = 0;
        int max = 0;
        
        for(int i=0;i<ch.length;i++){
            if(ch[i]=='A'||ch[i]=='C'||ch[i]=='G'||ch[i]=='T'){
                v = v+1;
            }else{
                if(max<v){
                    max = v;
                }
                v = 0;
            }
            
            if(max<v){
                max = v;
            }
        }
        System.out.println(max);
    }
}