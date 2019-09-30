import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        String result = "00";
        if(m > 70000){
            result = "89";
        }else{
        if(m >= 35000 && m <= 70000){
            result = String.valueOf(((((m / 1000) - 30) / 5) + 80));
        }else{
        if(m >= 6000 && m <= 30000){
            result = String.valueOf((m / 1000) + 50);
        }else{
        if((m >= 100) && (m <= 5000)){
            result = ("0" + String.valueOf((m * 10) / 1000));
            result = result.substring(result.length()-2,result.length());
        }}}}
        System.out.println(result);
    }
}