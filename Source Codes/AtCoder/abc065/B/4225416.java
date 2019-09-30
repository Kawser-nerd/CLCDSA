import java.util.*;

public class Main{
  
  public static void main(String[] args){
    
  Scanner scanner = new Scanner (System.in);
  
  	int totalButton = scanner.nextInt();
    
    Integer[] buttonList = new Integer[totalButton+1];
    
    for (int buttonNum=0; buttonNum<totalButton; buttonNum++){
      int temp = scanner.nextInt();
      buttonList[buttonNum+1]=temp;
    }
    int nowButton=1;
    boolean flag = false;
    int num;
    for(num=0; num<totalButton; num++){
      int temp = buttonList[nowButton];
      nowButton=temp;
      
      if (nowButton==2){
        flag=true;
        num++;
        break;
      }
    }
    if (flag==true){
      System.out.println(num);
    } else {
      System.out.println("-1");
    }
  }
}