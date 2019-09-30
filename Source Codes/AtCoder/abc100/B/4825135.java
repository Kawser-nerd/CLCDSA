import java.io.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int[] DN = new int[2];
        int cont = 0;
        for (String s:str.split(" ")){
            DN[cont] = Integer.parseInt(s);
            cont++;
        }
        if (DN[1]!=100){
            System.out.println((int)Math.pow(100,DN[0])*DN[1]);
        } else {
            System.out.println((int)Math.pow(100,DN[0])*(DN[1]+1));
        }
    }
}