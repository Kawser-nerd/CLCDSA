import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    char[] array = sc.nextLine().toCharArray();
    
    try{
      for(int i = array.length-1;i>=0;i--){
        if(i>=6){
          if(array[i-6] == 'd'&&array[i-5] == 'r'&&array[i-4] == 'e'&&
             array[i-3] == 'a'&&array[i-2] == 'm'&&array[i-1] == 'e'&&
             array[i] == 'r'){
            i -= 6;
            continue;
          }
        }
        if(i >=5){
          if(array[i-5] == 'e'&&array[i-4] == 'r'&&array[i-3] == 'a'&&
             array[i-2] == 's'&&array[i-1] == 'e'&&array[i] == 'r'){
            i -= 5;
            continue;
          }
        }
        if((array[i-4] == 'd'&&array[i-3] == 'r'&&array[i-2] == 'e'&&
           array[i-1] == 'a'&&array[i] == 'm')||(array[i-4] == 'e'&&
           array[i-3] == 'r'&&array[i-2] == 'a'&&
           array[i-1] == 's'&&array[i] == 'e')){
          i-=4;
        }else{
          System.out.println("NO");
          return;
        }
      }
    }catch(ArrayIndexOutOfBoundsException e){
      System.out.println("NO");
      return;
    }
    System.out.println("YES");
  }
}