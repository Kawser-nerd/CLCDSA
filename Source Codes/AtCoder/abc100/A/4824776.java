import java.io.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int[] AB = new int[2];
        int cont = 0;
        for (String s:str.split(" ")){
            AB[cont] = Integer.parseInt(s);
            cont++;
        }
        if (AB[0]<=8 && AB[1]<=8){
            System.out.println("Yay!");
        } else {
            System.out.println(":(");
        }
    }
}