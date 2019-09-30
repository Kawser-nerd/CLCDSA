using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
//        int c = int.Parse(input[2]);
//        int d = int.Parse(input[3]);*/
//        string temp = ReadLine();
//        int a = int.Parse(ReadLine());
//        int b = int.Parse(ReadLine());
//        int c = int.Parse(ReadLine());
//        int d = int.Parse(ReadLine());
//        string a = ReadLine();
//        string b = ReadLine();
//        string c = ReadLine();
//        string ko = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string[] gazo1 = new string[a];
        string[] gazo2 = new string[b];
        for(int i=0;i<a;i++){
            gazo1[i] = ReadLine();
        }
        for(int i=0;i<b;i++){
            gazo2[i] = ReadLine();
        }
        int count = 0;
        for(int i=0;i<a-b+1;i++){
            for(int j=0;j<a-b+1;j++){
                if(gazo2[0][0] == gazo1[i][j]){
                    count = 0;
                    for(int k=0;k<b;k++){
                        for(int l=0;l<b;l++){
                            if(gazo2[k][l] == gazo1[i+k][j+l]){
                                count++;
                            }
                        }
                    }
                    if(count == b*b){
                        break;
                    }
                }
            }
            if(count == b*b){
                break;
            }
        }
        if(count == b*b){
            WriteLine("Yes");
        }else{
            WriteLine("No");
        }
    }
}