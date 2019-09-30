import java.util.*;

public class Main{
  
  public static void main(String[] args){
    
  Scanner scanner = new Scanner (System.in);
  
  	int city = scanner.nextInt();
  	int road = scanner.nextInt();
    Integer[] list = new Integer[city];
    
    for (int indexCity=0; indexCity<city; indexCity++){
       list[indexCity]=0;
    }
    
  	for (int indexRoad=0; indexRoad<road; indexRoad++){
  	
    int city1=scanner.nextInt();
  	int city2=scanner.nextInt();
      
    int temp = list[city1-1];
    list[city1-1]=temp+1;
  	
    temp = list[city2-1];
    list[city2-1]=temp+1;
  	}
    
    for(int indexCity=0; indexCity<city; indexCity++){
      System.out.println(list[indexCity]);
    }
  }
}