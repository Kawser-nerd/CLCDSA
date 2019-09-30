import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int size = str.length();

        if("A".equals(str.substring(0,1))){
            int num =0;
            String str2 = str.substring(2,size-1);
            int size2 = str2.length();
            for(int i=0;i<size2;i++){
                String str4 = str2.substring(0,1);
                if(str4.equals("C")){
                    num = num+1;
                }
                str2 = str2.substring(1);
            }
            if(num==1){
                str2 = str.substring(2,size-1);
                str2 = str2.replace("C","c");
                str2 = str2.concat(str.substring(str.length() -1));
                str2 = str.substring(1,2).concat(str2);
                String str3 = str2.toLowerCase();

                if(str2.equals(str3)){
                    System.out.println("AC");
                }else{
                    System.out.println("WA"); 
                }

            }else{
                System.out.println("WA");    
            }
        }else{
            System.out.println("WA");
        }
    }
}