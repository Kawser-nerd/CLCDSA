import java.io.*;
import java.util.*;
import java.lang.*;

public class Main{
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
         int x=sc.nextInt();
         int sum=0;int count=0;
         if(x==1)
         count=1;
          for(int i=1;i<x;i++)
         { 
             if(x==2)
             {count=2;}
             
             
             
             else
            { count++;
             sum=sum+i;
              if(sum>=x)
             {break;}}
         }
         System.out.print(count);
         
    }}