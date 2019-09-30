import java.io.InputStream;
import java.io.IOException;

class MyScanner{
    InputStream stream;
    public MyScanner(){
        stream = System.in;
    }
    
    public long nextLong(){
        long ret = 0;
        try{
            while(true){
                char readed = (char)stream.read();
                if(readed < '0' || readed > '9'){
                    break;
                }
                ret = ret * 10 + (readed - '0');
            }
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            return ret;
        }
    }
}

class Main {
    public static void main(String args[]) {
        MyScanner sc = new MyScanner();
        long n = sc.nextLong(), a = sc.nextLong(), b = sc.nextLong();
        long min = b + a * (n - 1);
        long max = a + b * (n - 1);
        if(max < min){
            System.out.println(0);
        }else{
            System.out.println(max - min + 1);
        }
    }
}