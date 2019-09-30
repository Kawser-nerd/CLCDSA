using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        string s = Console.ReadLine();
        int state = 0;
        for(int i=0;i<s.Length;i++){
            if(state == 0){
                if(s[i] == 'd'){
                    state = 1;
                }
                else if(s[i] == 'e'){
                    state = 8;
                }
                else{
                    state = -1;
                }
            }
            else if(state == 1){
                if(s[i] == 'r'){
                    state = 2;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 2){
                if(s[i] == 'e'){
                    state = 3;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 3){
                if(s[i] == 'a'){
                    state = 4;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 4){
                if(s[i] == 'm'){
                    state = 5;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 5){
                if(s[i] == 'e'){
                    state = 6;
                }
                else if(s[i] == 'd'){
                    state = 1;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 6){
                if(s[i] == 'r'){
                    state = 7;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 7){
                if(s[i] == 'e'){
                    state = 8;
                }
                else if(s[i] == 'd'){
                    state = 1;
                }
                else if(s[i] == 'a'){
                    state = 10;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 8){
                if(s[i] == 'r'){
                    state = 9;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 9){
                if(s[i] == 'a'){
                    state = 10;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 10){
                if(s[i] == 's'){
                    state = 11;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 11){
                if(s[i] == 'e'){
                    state = 12;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 12){
                if(s[i] == 'r'){
                    state = 13;
                }
                else if(s[i] == 'e'){
                    state = 8;
                }
                else if(s[i] == 'd'){
                    state = 1;
                }
                else{
                    state = -1;
                    break;
                }
            }
            else if(state == 13){
                if(s[i] == 'e'){
                    state = 8;
                }
                else if(s[i] == 'd'){
                    state = 1;
                }
                else{
                    state = -1;
                    break;
                }
            }
        }
        sb.Append((state == 12 || state == 13 || state == 5 || state == 7 ? "YES" : "NO" )+"\n");
    }
}