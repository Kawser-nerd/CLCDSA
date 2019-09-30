import java.util.Scanner;
class Main{

    public static void main(String args[]){
        Main main = new Main();
        main.start();
    }

    public void start(){
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        String letters[] = str.split("");
        int max = 0;
        for(int i = 0; i < letters.length; i++){
            int num = countLength(letters,i);
            if(num > max) max = num;
        }
        System.out.println(max);
    }

    public int countLength(String[] letters,int index){
        int count = 0;
        for(int i = index; i < letters.length;i++){
            if(letters[i].equals("A")||letters[i].equals("C")||letters[i].equals("T")||letters[i].equals("G")){
                count++;
            }else{
                return count;
            }
        }
        return count++;
    }
}