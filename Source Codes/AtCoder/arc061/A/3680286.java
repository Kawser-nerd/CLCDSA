import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s = new String(br.readLine());
        long total = 0, bit;
        int lOprIndex, rOprIndex;
        String tmp = new String();
        for(int i=0; i<Math.pow(2, s.length()-1); i++){
            lOprIndex = 0;
            rOprIndex = 1;
            for(bit=i; bit!=0; bit=bit>>1){
                if((bit&1) == 1){
                    tmp = s.substring(lOprIndex, rOprIndex);
                    total += Long.parseLong(tmp.toString());
                    lOprIndex = rOprIndex;
                }
                rOprIndex++;
            }
            tmp = s.substring(lOprIndex, s.length());
            total += Long.parseLong(tmp.toString());
        }
        System.out.println(total);
    }
}