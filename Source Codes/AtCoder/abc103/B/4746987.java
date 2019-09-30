import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String str2 = sc.nextLine();
        int size = str.length();
        int size2 = str2.length();
        int flag =1;

        while(true){
            if(str.equals(str2)){
                break;
            }else{
                size2 = size2-1;
                String str3 = str.substring(0,1);
                str = str.substring(1,size);
                str = str.concat(str3);
                if(size2==0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
        
    }
}