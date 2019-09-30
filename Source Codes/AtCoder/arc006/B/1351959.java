import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Here your code !
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 1?????????int???????????????????(?????)
        int[] b = Arrays.asList(br.readLine().split(" ")).stream().mapToInt(Integer::parseInt).toArray();
        int n = b[0];
        int l = b[1];
        String[] amida = new String[l];
        for(int i=0;i<l;i++){
            amida[i] = br.readLine();
        }
        String lastline = br.readLine();
        int pos = 0;
        while(true){
            if(lastline.charAt(pos)=='o'){
                break;
            }else{
                pos++;
            }
        }
        for(int i=l-1;i>=0;i--){
            // ?????
            if(pos>0 && amida[i].charAt(pos-1)=='-'){
                pos -= 2;
            }else if(pos<2*n-2 && amida[i].charAt(pos+1)=='-'){
                pos += 2;
            }
        }
        System.out.println(pos/2+1);
    }
}