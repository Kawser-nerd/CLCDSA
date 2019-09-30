using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string a = ReadLine();
        string b = ReadLine();
        string c = ReadLine();
        string st = a[0].ToString();
        a = a.Remove(0,1);
        int al = a.Length,bl = b.Length,cl = c.Length;
        if(al == 0){
            WriteLine("A");
        }else{
        while(al>=0 && bl>=0 && cl>=0){
            if(st == "a"){
                if(al>0){
                    st = a[0].ToString();
                    a = a.Remove(0,1);
                    al = a.Length;
                }else{
                    al--;
                    WriteLine("A");
                }

            }else if(st == "b"){
                if(bl>0){
                    st = b[0].ToString();
                    b = b.Remove(0,1);
                    bl = b.Length;
                }else{
                    bl--;
                    WriteLine("B");
                }

            }else if(st == "c"){
                if(cl>0){
                    st = c[0].ToString();
                    c = c.Remove(0,1);
                    cl = c.Length;
                }else{
                    cl--;
                    WriteLine("C");
                }
            }
        }
        }
    }
}