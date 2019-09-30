using System;
using System.Collections.Generic;
class Solve{
    int N;
    int[] a;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] b = new int[N];
        int[] c = new int[N];
        long count = 0;
        Stack s = new Stack(N);
        for(int i=0;i<N;i++){
            int j;
            while(true){
                j = s.pop();
                if(j == -1){
                    break;
                }
                else if(a[j] < a[i]){
                    s.push(j);
                    break;
                }
                else{
                    b[j] = i;
                }
            }
            s.push(i);
        }
        while(true){
            int j = s.pop();
            if(j == -1){
                break;
            }
            else{
                b[j] = N;
            }
        }
        for(int i=N-1;i>=0;i--){
            int j;
            while(true){
                j = s.pop();
                if(j == -1){
                    break;
                }
                else if(a[j] < a[i]){
                    s.push(j);
                    break;
                }
                else{
                    c[j] = i;
                }
            }
            s.push(i);
        }
        while(true){
            int j = s.pop();
            if(j == -1){
                break;
            }
            else{
                c[j] = -1;
            }
        }
        for(int i=0;i<N;i++){
            count += (long)(b[i]-i)*(long)(i-c[i])*(long)a[i];
        }
        Console.WriteLine(count);
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = int.Parse(str[i]);
        }
    }    
}
class Stack{
    int[] array;
    int pointer;
    public Stack(){
        array = new int[100000];
        pointer = -1;
    }
    public Stack(int i){
        array = new int[i];
        pointer = -1;
    }
    public int pop(){
	    if(pointer == -1){
            return -1;
        }
        else{
            pointer--;
            return array[pointer+1];
        }
    }
    public void push(int t){
        array[pointer+1] = t;
        pointer++; 
    }
}